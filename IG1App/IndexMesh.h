#ifndef _H_IndexMesh_H_
#define _H_IndexMesh_H_
#include <numbers>
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

	void buildNormalVectors();
	static IndexMesh* generateByRevolution(
		const std::vector<glm::vec2>& profile, GLuint nSamples,
		GLfloat angleMax = 2 * std::numbers::pi);

protected:
	std::vector<GLuint> vIndexes;
	GLuint mIBO;
};
#endif