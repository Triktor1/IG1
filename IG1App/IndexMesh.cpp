#include "IndexMesh.h"

using namespace std;
using namespace glm;
// Placeholder for the pending index of a GPU object
constexpr GLuint NONE = numeric_limits<GLuint>::max();

IndexMesh::IndexMesh() : mIBO(NONE) {}

IndexMesh::~IndexMesh() {
	unload();
}

void IndexMesh::load() {
	Mesh::load(); glBindVertexArray(mVAO);
	glGenBuffers(1, &mIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		vIndexes.size() * sizeof(GLuint),
		vIndexes.data(), GL_STATIC_DRAW);
	glBindVertexArray(0);
}

void IndexMesh::draw() const
{
	glDrawElements(
		mPrimitive, // primitiva ( GL_TRIANGLES , etc.)
		vIndexes.size(), // número de índices
		GL_UNSIGNED_INT, // tipo de los índices
		nullptr // offset en el VBO de índices
	);
}

void
IndexMesh::unload()
{
	Mesh::unload();
	if (mIBO != NONE) {
		glDeleteBuffers(1, &mIBO);
		mIBO = NONE;
	}
}

IndexMesh*
IndexMesh::generateByRevolution(const vector<vec2>& perfil, GLuint nSamples, GLfloat angleMax, glm::vec4 color1, glm::vec4 color2) {
	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;

	int tamPerfil = perfil.size();
	mesh->vVertices.reserve(nSamples * tamPerfil);
	mesh->vTexCoords.reserve(nSamples * tamPerfil);
	mesh->vColors.reserve(nSamples * tamPerfil);

	// Genera los v�rtices de las muestras
	GLdouble theta1 = angleMax / nSamples;
	for (int i = 0; i <= nSamples; ++i) { // muestra i-�sima
		GLdouble c = cos(i * theta1), s = sin(i * theta1);
		for (int j = 0; j < perfil.size(); j++) {
			mesh->vVertices.emplace_back(perfil[j].x * c, perfil[j].y, -perfil[j].x * s);

			GLfloat u = (GLfloat)i / nSamples;
			GLfloat v = (GLfloat)j / tamPerfil;
			mesh->vTexCoords.emplace_back(u, v);

			//Añadimos vértice de color
			GLfloat lambda = (float)j / (tamPerfil - 1);
			glm::vec4 color = glm::vec4(lambda * color1.r + (1 - lambda) * color2.r, //Interpolación lineal del rojo
				lambda * color1.g + (1 - lambda) * color2.g, //Interpolación lineal del verde
				lambda * color1.b + (1 - lambda) * color2.b, //Interpolación lineal del azul
				1);											 //Alpha siempre en 1 (obvio)
			mesh->vColors.push_back(color);
		}
	}
	for (int i = 0; i < nSamples; ++i) { // caras i a i + 1
		GLuint nextI = i + 1;
		for (int j = 0; j < tamPerfil - 1; ++j) { // una cara
			if (perfil[j].x != 0.0) // tri�ngulo inferior
				for (auto [s, t] : { pair{i, j}, {nextI, j}, { i, j + 1 } })
					mesh->vIndexes.push_back(s * tamPerfil + t);
			if (perfil[j + 1].x != 0.0) // tri�ngulo superior
				for (auto [s, t] : { pair{i, j + 1}, {nextI, j}, {nextI, j + 1} })
					mesh->vIndexes.push_back(s * tamPerfil + t);
		}
	}
	mesh->mNumVertices = mesh->vVertices.size();
	mesh->buildNormalVectors();
	return mesh;
}

IndexMesh*
IndexMesh::generateCorolla(GLfloat height, GLfloat width, GLuint nParallels, GLuint nStops, glm::vec4 color1, glm::vec4 color2) {
	std::vector<glm::vec2> profile;

	//Se puede hacer diffX pero no diffY ya que sus distancias no son la misma
	float diffX = width / nParallels;

	for (int i = 0; i < nParallels; i++) {
		//Lineal de toda la vida facilico
		float x = diffX * i;

		//Se hace (i/(nParallels-1))^2, porque estará en un rango [0, 1] y se multiplica por height para
		//pase a tener un rango [0, height]
		float y = pow((float)i / (nParallels-1), 2) * height;
		profile.emplace_back(x, y);
	}
	//Vértice extra
	profile.emplace_back(width * 1.1, height * 0.9);

	return generateByRevolution(profile, nStops, std::numbers::pi*2, color1, color2);
}


void
IndexMesh::buildNormalVectors() {
	//Resetear el vector de normales y ajustar el tamaño acorde a los vértices
	vNormals.clear();
	vNormals.resize(vVertices.size(), vec3(0.0f));

	//Cálculo de normales
	for (int i = 0; i < vIndexes.size(); i += 3) {
		GLuint i0 = vIndexes[i];
		GLuint i1 = vIndexes[i + 1];
		GLuint i2 = vIndexes[i + 2];

		vec3 n = normalize(cross(vVertices[i1] - vVertices[i0], vVertices[i2] - vVertices[i0]));
		vNormals[i0] += n;
		vNormals[i1] += n;
		vNormals[i2] += n;
	}

	for (auto& n : vNormals) n = normalize(n);
}

IndexMesh*
IndexMesh::generateSphere(GLdouble radius, GLuint nParallel, GLuint nMeridians, GLfloat angleMax) {
	std::vector<glm::vec2> profile;

	GLdouble alphaStep = 2 * std::numbers::pi / (float)nParallel;
	GLdouble alpha = std::numbers::pi / 2;
	for (int i = 0; i <= nParallel / 2; ++i) {
		profile.emplace_back(radius * cos(alphaStep * i - alpha), radius * sin(alphaStep * i - alpha));
	}
	IndexMesh* mesh = IndexMesh::generateByRevolution(profile, nMeridians, angleMax);
	return mesh;
}

IndexMesh*
IndexMesh::generateHat(GLdouble r, GLuint nParallel, GLuint nMeridians) {
	std::vector<glm::vec2> profile;
	profile.reserve(nParallel);

	GLfloat diffX = r / (nParallel - 1);
	GLfloat diffY = (std::numbers::pi * 2) / (nParallel - 1);

	for (int i = 0; i < nParallel; ++i) {
		GLdouble theta = std::numbers::pi * 2.0 - (diffY * i);

		GLfloat x = diffX * ((nParallel - 1) - i);
		GLfloat y = r / 2 * sin(theta);

		profile.emplace_back(x, y);
	}

	return IndexMesh::generateByRevolution(profile, nMeridians);
}

IndexMesh*
IndexMesh::generateHiperboloide(GLdouble r, GLuint nParallel, GLuint nMeridian, GLfloat offset) {
	std::vector<glm::vec2> profile;
	profile.reserve(nParallel);

	GLfloat diffX = (std::numbers::pi * 2) / (nParallel - 1);
	GLfloat diffY = r * 2 / (nParallel - 1);

	for (int i = nParallel - 1; i >= 0; i--) {
		GLfloat theta = (diffX * i);

		GLfloat x = offset + cos(theta) * r / 2;
		GLfloat y = diffY * (nParallel - 1 - i);

		profile.emplace_back(x, y);
	}

	return generateByRevolution(profile, nMeridian);
}

IndexMesh*
IndexMesh::generateIndexedBox8(GLdouble l) {
	IndexMesh* mesh = new IndexMesh();
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->vVertices.reserve(8);
	mesh->mNumVertices = 8;

	mesh->vVertices.emplace_back(l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, -l / 2);

	//Índices en el orden correcto
	mesh->vIndexes = {
		2, 1, 0, 3, 1, 2,
		4, 3, 2, 5, 3, 4,
		6, 5, 4, 7, 5, 6,
		0, 7, 6, 1, 7, 0,
		2, 6, 4, 0, 6, 2,
		3, 7, 1, 5, 7, 3
	};

	mesh->buildNormalVectors();
	return mesh;
}

IndexMesh*
IndexMesh::generateIndexedBox(GLdouble l) {
	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->vVertices.reserve(24);
	mesh->mNumVertices = 24;

	//Cara 1 (+X)
	mesh->vVertices.emplace_back(l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, l / 2);

	//Cara 2 (-X)
	mesh->vVertices.emplace_back(-l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, -l / 2);

	//Cara 3 (+Z)
	mesh->vVertices.emplace_back(-l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, l / 2);
	mesh->vVertices.emplace_back(l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, l / 2);

	//Cara 4 (-Z)
	mesh->vVertices.emplace_back(-l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, -l / 2);

	//Cara 5 (+Y)
	mesh->vVertices.emplace_back(-l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, l / 2, l / 2);
	mesh->vVertices.emplace_back(l / 2, l / 2, -l / 2);

	//Cara 6 (-Y)
	mesh->vVertices.emplace_back(-l / 2, -l / 2, l / 2);
	mesh->vVertices.emplace_back(-l / 2, -l / 2, -l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, l / 2);
	mesh->vVertices.emplace_back(l / 2, -l / 2, -l / 2);

	//Índices en el orden correcto
	mesh->vIndexes = {
		1, 0, 2, 2, 3, 1,
		4, 7, 5, 7, 4, 6,
		10, 9, 11, 10, 8, 9,
		12, 14, 13, 14, 15, 13,
		17, 16, 18, 18, 19, 17,
		22, 20, 21, 22, 21, 23
	};

	mesh->buildNormalVectors();
	return mesh;
}