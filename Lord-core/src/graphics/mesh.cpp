#include "mesh.h"
#include "renderers/renderer3d.h"

namespace lord { namespace graphics {

	Mesh::Mesh(Buffer* vbo, const std::vector<unsigned int>& indices)
	{
		_vao.push(vbo);
		_vao.bind();
		_ibo = new IndexBuffer(indices);
	}

	Mesh::~Mesh()
	{
		delete _ibo;
	}

	void Mesh::bind() const
	{
		_vao.bind();
		_ibo->bind();
	}

	void Mesh::unbind() const
	{
		_vao.unbind();
		_ibo->unbind();
	}

}}