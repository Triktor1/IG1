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
IndexMesh::generateByRevolution(const vector<vec2>& perfil, GLuint nSamples, GLfloat angleMax) {
	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;

	int tamPerfil = perfil.size();
	mesh->vVertices.reserve(nSamples * tamPerfil);
	mesh->vTexCoords.reserve(nSamples * tamPerfil);

	// Genera los v�rtices de las muestras
	GLdouble theta1 = angleMax / nSamples;
	for (int i = 0; i <= nSamples; ++i) { // muestra i-�sima
		GLdouble c = cos(i * theta1), s = sin(i * theta1);
		for (int j = 0; j < perfil.size(); j++) {
			mesh->vVertices.emplace_back(perfil[j].x * c, perfil[j].y, -perfil[j].x * s);

			GLfloat u = (GLfloat)i / nSamples;
			GLfloat v = (GLfloat)j / tamPerfil;
			mesh->vTexCoords.emplace_back(u, v);
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
IndexMesh::generateCorolla(GLfloat w, GLfloat h, GLuint points, GLuint Samples) {
	std::vector<glm::vec2> profile;
	float x, y;
	float wOff = w / points;
	profile.emplace_back(1.1 * w, 0.9 * h);

	for (int i = points - 1; i > 0; --i) {
		x = wOff * i;
		y = pow((float)i / (points - 1), 2) * h;
		profile.emplace_back(x, y);
	}
	IndexMesh* mesh = IndexMesh::generateByRevolution(profile, Samples);
	return mesh;
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