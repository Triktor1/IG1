#include "IndexedBox.h"

IndexedBox::IndexedBox(GLdouble l) : ColorMaterialEntity()
{
	mMesh = IndexMesh::generateIndexedBox8(l);
}
