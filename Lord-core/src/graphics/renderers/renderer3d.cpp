#include "renderer3d.h"
#include <iostream>
#include <GL/glew.h>

namespace lord { namespace graphics {

	using namespace math;

	Renderer3D::Renderer3D()
	{
		_transformationStack.reserve(10);
		_transformationStack.push_back(Matrix4f::identity());
	}


	void Renderer3D::render(const Mesh* mesh, Shader* shader)
	{
		mesh->bind();
		shader->setUniformMat4("u_model", _transformationStack.back());
		glDrawElements(GL_TRIANGLES, mesh->getNumIndices(), GL_UNSIGNED_INT, NULL);
		mesh->unbind();
	}

	void Renderer3D::pushMatrix(const Matrix4f& matrix)
	{
		_transformationStack.push_back(_transformationStack.back() * matrix);
	}

	void Renderer3D::popMatrix()
	{
		if (_transformationStack.size() > 1)
			_transformationStack.pop_back();
	}
}}