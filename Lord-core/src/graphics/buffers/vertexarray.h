#pragma once
#include <GL/glew.h>
#include "buffer.h"
#include <vector>

namespace lord { namespace graphics {

	class VertexArray
	{
		GLuint					_id;
		GLuint					_numAttributes{ 0 };
		std::vector<Buffer*>	_buffers;
	public:
		VertexArray();
		~VertexArray();
		void bind() const;
		void unbind() const;
		void push(Buffer* vbo);
	};

}}