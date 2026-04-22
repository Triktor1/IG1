#include "SphereWithTexture.h"
#include "Texture.h"


SphereWithTexture::SphereWithTexture(GLdouble radius, GLuint nParallels, GLuint nMeridians, Texture* tex):
EntityWithTexture(tex){
	mMesh = IndexMesh::generateSphere(radius, nParallels, nMeridians);
}
