#include "Photo.h"
#include "IG1App.h"
Photo::Photo(GLdouble w, GLdouble h, Texture* tex) : EntityWithTexture()
{
	mMesh = Mesh::generateRectangleTexCor(w, h, 1.0, 1.0);
	setTexture(tex);
}

void
Photo::update() {
	mTexture->loadColorBuffer(IG1App::s_ig1app.viewPort().width(), IG1App::s_ig1app.viewPort().height(), GL_FRONT);
}