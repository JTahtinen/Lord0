#pragma once
#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"
#include <vector>

namespace lord { namespace graphics {

	class Renderer3D;

	class Mesh
	{
		VertexArray			_vao;
		IndexBuffer*		_ibo;
	public:
		Mesh(Buffer* vbo, const std::vector<unsigned int>& indices);
		~Mesh();
		void bind() const;
		void unbind() const;
		inline unsigned int getNumIndices() const { return _ibo->getNumIndices(); }
	};
}}