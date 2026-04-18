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
	if (mIBO != NONE) {
		glDeleteBuffers(1, &mIBO);
		mIBO = NONE;
	}
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

	for (auto& n : vNormals)
		n = normalize(n);

}

IndexMesh*
IndexMesh::generateByRevolution(const vector<vec2>& perfil, GLuint nSamples) {
	GLfloat angleMax = 2 * 3.1415926;

	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;

	int tamPerfil = perfil.size();
	mesh->vVertices.reserve(nSamples * tamPerfil);

	// Genera los vértices de las muestras
	GLdouble theta1 = angleMax / nSamples;
	for (int i = 0; i <= nSamples; ++i) { // muestra i-ésima
		GLdouble c = cos(i * theta1), s = sin(i * theta1);
		for (auto p : perfil) // rota el perfil
			mesh->vVertices.emplace_back(p.x * c, p.y, -p.x * s);
	}
	for (int i = 0; i <= nSamples; ++i) { // caras i a i + 1
		GLuint nextI = (i + 1) % nSamples;
		for (int j = 0; j < tamPerfil - 1; ++j) { // una cara
			if (perfil[j].x != 0.0) // triángulo inferior
				for (auto [s, t] : { pair{i, j}, {nextI, j}, { i, j + 1 } })
					mesh->vIndexes.push_back(s * tamPerfil + t);
			if (perfil[j + 1].x != 0.0) // triángulo superior
				for (auto [s, t] : { pair{i, j + 1}, {nextI, j}, {nextI, j + 1} })
					mesh->vIndexes.push_back(s * tamPerfil + t);
		}
	}
	mesh->mNumVertices = mesh->vVertices.size();
	mesh->buildNormalVectors();
	return mesh;
}