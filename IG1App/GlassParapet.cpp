#include "GlassParapet.h"
#include "Texture.h"

GlassParapet::GlassParapet(GLdouble l, Texture* tex):EntityWithTexture(tex){
	mMesh = Mesh::generateBoxOutlineTexCor(l);
}