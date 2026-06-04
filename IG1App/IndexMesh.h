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
	static IndexMesh* generateByRevolution(const std::vector<glm::vec2>& profile, GLuint nSamples, GLfloat angleMax = 2 * std::numbers::pi);
	static IndexMesh* generateSphere(GLdouble radius, GLuint nParallel, GLuint nMeridians, GLfloat angleMax = 2 * std::numbers::pi);
	static IndexMesh* generateCorolla(GLfloat w, GLfloat h, GLuint points = 40, GLuint Samples = 40);
	static IndexMesh* generateCorollaGradient(GLfloat w, GLfloat h, GLuint points = 40, GLuint Samples = 40);
	static IndexMesh* generateIndexedBox8(GLdouble l);
	static IndexMesh* generateIndexedBox(GLdouble l);

protected:
	std::vector<GLuint> vIndexes;
	GLuint mIBO;
};
#endif