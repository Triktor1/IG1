#include "IG1App.h"

#include <iostream>
#include <vector>
#include "stb_image_write.h"


using namespace std;

// static single instance (singleton pattern)
IG1App IG1App::s_ig1app; // default constructor (constructor with no parameters)

// Print OpenGL errors and warnings
void GLAPIENTRY debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
	GLsizei length, const GLchar* message, const void* userParam)
{
	const char* prefix = (type == GL_DEBUG_TYPE_ERROR)
		? "\x1b[31m[ERROR]\x1b[0m "
		: "\x1b[33m[WARNING]\x1b[0m ";
	cout << prefix << message << endl;
}

void
IG1App::close()
{
	cout << "Closing GLFW...\n";
	glfwSetWindowShouldClose(mWindow, true); // stops main loop
}

void
IG1App::run() // enters the main event processing loop
{
	if (mWindow == 0) // if not intilialized
		init();

	mNextUpdate = glfwGetTime() + FRAME_DURATION;

	// IG1App main loop
	while (!glfwWindowShouldClose(mWindow)) {
		// Redisplay the window if needed
		if (mUpdateEnabled && glfwGetTime() >= mNextUpdate) {
			update();
			mNextUpdate = glfwGetTime() + FRAME_DURATION;
			mNeedsRedisplay = true;
		}

		if (mNeedsRedisplay) {
			display();
			mNeedsRedisplay = false;
		}

		// Stop and wait for new events (glfwWaitEvents();)
		mUpdateEnabled ?
			glfwWaitEventsTimeout(mNextUpdate - glfwGetTime()) :
			glfwWaitEvents();
	}

	destroy();
}

void
IG1App::update()
{
	mScenes[mCurrentScene]->update();
	mNeedsRedisplay = true;
}

void
IG1App::init()
{
	// create an OpenGL Context
	iniWinOpenGL();

	// create the scene after creating the context
	// allocate memory and resources
	mViewPort = new Viewport(mWinW, mWinH);
	mCamera = new Camera(mViewPort);
	mScenes.push_back(new Scene);
	mScenes.push_back(new Scene1);
	mScenes.push_back(new Scene2);
	mScenes.push_back(new Scene3);
	mScenes.push_back(new Scene4);
	mScenes.push_back(new Scene5);

	mCamera->set2D();
	for (Scene* s : mScenes) s->init();
	mScenes[mCurrentScene]->load();
}

void
IG1App::iniWinOpenGL()
{ // Initialization
	cout << "Starting GLFW...\n";
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // enable on macOS
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	// Create window with its associated OpenGL context, return window's pointer
	mWindow = glfwCreateWindow(mWinW, mWinH, "IG1App", nullptr, nullptr);

	if (mWindow == nullptr) {
		glfwTerminate();
		throw std::logic_error("cannot create GLFW window");
	}

	glfwMakeContextCurrent(mWindow);

	// Initialize OpenGL extension library
	if (GLenum err = glewInit(); err != GLEW_OK) {
		glfwTerminate();
		throw std::logic_error("Error while loading extensions: "s +
			reinterpret_cast<const char*>(glewGetErrorString(err)));
	}

	// Callback registration
	glfwSetWindowSizeCallback(mWindow, s_resize);
	glfwSetCharCallback(mWindow, s_key);
	glfwSetKeyCallback(mWindow, s_specialkey);
	glfwSetWindowRefreshCallback(mWindow, s_display);

	glfwSetMouseButtonCallback(mWindow, s_mouse);
	glfwSetCursorPosCallback(mWindow, s_motion);
	glfwSetScrollCallback(mWindow, s_mouseWheel);

	// Error message callback (all messages)
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0u, 0, GL_TRUE);
	glDebugMessageCallback(debugCallback, nullptr);

	cout << glGetString(GL_VERSION) << '\n';
	cout << glGetString(GL_VENDOR) << '\n';
}

void
IG1App::destroy()
{ // release memory and resources
	for (Scene* scene : mScenes)
		delete scene;
	mScenes.clear();

	delete mCamera;
	mCamera = nullptr;
	delete mViewPort;
	mViewPort = nullptr;

	glfwTerminate();
}

void
IG1App::display() const
{ // double buffering

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the back buffer

	if (!m2Vistas) mScenes[mCurrentScene]->render(*mCamera); // uploads the viewport and camera to the GPU
	else {
		Camera auxCam = *mCamera;
		Viewport auxVP = *mViewPort;
		mViewPort->setSize(mWinW / 2, mWinH);
		auxCam.setSize(mViewPort->width(), mViewPort->height());
		auxCam.set3D();

		mViewPort->setPos(0, 0);
		if (mCurrentScene != 4) mScenes[4]->load();
		mScenes[4]->render(auxCam);
		if (mCurrentScene != 4) mScenes[4]->unload();

		mViewPort->setPos(mWinW / 2, 0);
		if (mCurrentScene != 2) mScenes[2]->load();
		mScenes[2]->render(auxCam);
		if (mCurrentScene != 2) mScenes[2]->unload();

		*mViewPort = auxVP;
	}
	glfwSwapBuffers(mWindow); // swaps the front and back buffer
}

void
IG1App::resize(int newWidth, int newHeight)
{
	mWinW = newWidth;
	mWinH = newHeight;

	// Resize Viewport to the new window size
	mViewPort->setSize(newWidth, newHeight);

	// Resize Scene Visible Area such that the scale is not modified
	mCamera->setSize(mViewPort->width(), mViewPort->height());
}

void
IG1App::key(unsigned int key)
{
	bool need_redisplay = true;

	switch (key) {
		//ZOOM
	case '+':
		mCamera->setScale(+0.01); // zoom in  (increases the scale)
		break;
	case '-':
		mCamera->setScale(-0.01); // zoom out (decreases the scale)
		break;
		//VISTAS
	case 'l':
		mCamera->set3D();
		break;
	case 'o':
		mCamera->set2D();
		break;
	case 'k':
		m2Vistas = !m2Vistas;
		break;
		//UPDATE
	case 'u':
		if (m2Vistas) {
			if (mMouseCoord.x < mWinW / 2) mScenes[4]->update();
			else mScenes[2]->update();
			mNeedsRedisplay = true;
		}
		else if (!mUpdateEnabled) {
			mScenes[mCurrentScene]->update();
			mNeedsRedisplay = true;
		}

		break;
	case 'U':
		mUpdateEnabled = !mUpdateEnabled;
		break;
	case 'f':
		takeScreenshot("screenshot.png", mViewPort->width(), mViewPort->height(), GL_FRONT);
		break;
		//MOVER LA CAMARA 
	case 'a':
		mCamera->moveLR(-3);
		break;
	case 'd':
		mCamera->moveLR(3);
		break;
	case 'w':
		mCamera->moveUD(3);
		break;
	case 's':
		mCamera->moveUD(-3);
		break;
	case 'W':
		mCamera->moveFB(3);
		break;
	case 'S':
		mCamera->moveFB(-3);
		break;
		//CAMBIO DE PROYECCION
	case 'p':
        mCamera->changePrj();
		break;
	default:
		if (key >= '0' && key <= '9') {
			if (changeScene(key - '0')) break;
			cout << "[NOTE] There is no scene " << char(key) << ".\n";
		}
		need_redisplay = false;
		break;
	} // switch

	if (need_redisplay)
		mNeedsRedisplay = true;
}

void
IG1App::specialkey(int key, int scancode, int action, int mods)
{
	// Only interested in press events
	if (action == GLFW_RELEASE)
		return;

	bool need_redisplay = true;

	// Handle keyboard input
	// (key reference: https://www.glfw.org/docs/3.4/group__keys.html)
	switch (key) {
	case GLFW_KEY_ESCAPE:                     // Escape key
		glfwSetWindowShouldClose(mWindow, true); // stops main loop
		break;
	case GLFW_KEY_RIGHT:
		if (mods == GLFW_MOD_CONTROL)
			mCamera->rollReal(-1); // rotates -1 on the X axis
		else
			mCamera->yawReal(1); // rotates 1 on the X axis
		break;
	case GLFW_KEY_LEFT:
		if (mods == GLFW_MOD_CONTROL)
			mCamera->rollReal(1); // rotates 1 on the Y axis
		else
			mCamera->yawReal(-1); // rotate -1 on the Y axis
		break;
	case GLFW_KEY_UP:
		mCamera->pitchReal(1); // rotates 1 on the Z axis
		break;
	case GLFW_KEY_DOWN:
		mCamera->pitchReal(-1); // rotates -1 on the Z axis
		break;
	default:
		need_redisplay = false;
		break;
	} // switch

	if (need_redisplay)
		mNeedsRedisplay = true;
}

bool
IG1App::changeScene(size_t sceneNr)
{
	// Check whether the scene exists
	if (sceneNr >= mScenes.size())
		return false;

	// Change only if a different scene
	if (sceneNr != mCurrentScene) {
		mScenes[mCurrentScene]->unload();
		mCurrentScene = sceneNr;
		mScenes[mCurrentScene]->load();
	}

	return true;
}

void IG1App::takeScreenshot(std::string name, GLuint width, GLuint height, GLuint buffer) {

	//Vector de p�xeles con todos los p�xeles de la pantalla
	std::vector<Image::rgba_color> pixels(width * height);

	//Se leen los p�xeles de pantalla y se guardan en pixels
	glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());

	Image screenshot;

	//Carga en la imagen el vector pixels
	screenshot.load(pixels.data(), width, height);

	//Flip para que la imagen no salga al rev�s
	stbi_flip_vertically_on_write(1);

	//Guarda la imagen en el ordenador
	screenshot.save("../assets/" + name);
}

void IG1App::mouse(int button, int state, int mods) {
	if (mMouseButt == button) mMouseButt = -1;
	else mMouseButt = button;
	
	double x, y;
	glfwGetCursorPos(mWindow, &x, &y);
	int height;
	glfwGetWindowSize(mWindow, nullptr, &height);
	y = height - y;

	mMouseCoord = glm::dvec2(x, y);
}
void IG1App::motion(double x, double y) {
	//Guardar en una variable auxiliar mp la diferencia entre mCoord y(x, y)
	int height;
	glfwGetWindowSize(mWindow, nullptr, &height);
	y = height - y;
	glm::dvec2 currentCoord(x, y);

	glm::dvec2 mp = currentCoord - mMouseCoord;

	//Guardar en mCoord la posici�n (x, y) del rat�n
	mMouseCoord = currentCoord;

	//mBot es boton izquierdo
	if (mMouseButt == GLFW_MOUSE_BUTTON_LEFT) mCamera->orbit(mp.x * 0.05, mp.y);
	//mBot es boton derecho
	else if (mMouseButt == GLFW_MOUSE_BUTTON_RIGHT) {
		mCamera->moveLR(mp.x);
		mCamera->moveUD(mp.y);
	}

	mNeedsRedisplay = true;
}

void IG1App::mouseWheel(double dx, double dy) {
	if (glfwGetKey(mWindow, GLFW_KEY_LEFT_CONTROL) != GLFW_PRESS && glfwGetKey(mWindow, GLFW_KEY_RIGHT_CONTROL) != GLFW_PRESS) {
		mCamera->moveFB(dy);
	}
	else mCamera->setScale(dy);
	mNeedsRedisplay = true;
}