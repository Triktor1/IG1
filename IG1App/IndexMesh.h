#ifndef _H_IndexMesh_H_
#define _H_IndexMesh_H_
#include "Mesh.h"

class IndexMesh :
    public Mesh
{
public:
	IndexMesh();
	virtual ~IndexMesh();

	IndexMesh(const IndexMesh& m) = delete;            // no copy constructor
	IndexMesh& operator=(const IndexMesh& m) = delete; // no copy assignment

	void load() override;
	void unload() override;
	void draw() const override;

	static IndexMesh* generateByRevolution(
		const std::vector<glm::vec2>& profile, GLuint nSamples);

protected:
	std::vector<GLuint> vIndexes;
	GLuint mIBO;
};
#endif