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
	static IndexMesh* generateByRevolution(const std::vector<glm::vec2>& profile, GLuint nSamples, GLfloat angleMax = 2 * std::numbers::pi, 
		glm::vec4 color1 = glm::vec4(0,0,0,1), glm::vec4 color2 = glm::vec4(0,0,0,1));
	static IndexMesh* generateSphere(GLdouble radius, GLuint nParallel, GLuint nMeridians, GLfloat angleMax = 2 * std::numbers::pi);
	static IndexMesh* generateIndexedBox8(GLdouble l);
	static IndexMesh* generateIndexedBox(GLdouble l);
	static IndexMesh* generateHat(GLdouble r, GLuint nParallel, GLuint nMeridians);
	static IndexMesh* generateHiperboloide(GLdouble r, GLuint nParallel, GLuint nMeridian, GLfloat offset);
	static IndexMesh* generateCorolla(GLfloat height, GLfloat width, GLuint nParallels, GLuint nStops, 
		glm::vec4 color1 = glm::vec4(0, 0, 0, 1), glm::vec4 color2 = glm::vec4(0, 0, 0, 1));

protected:
	std::vector<GLuint> vIndexes;
	GLuint mIBO;
};
#endif