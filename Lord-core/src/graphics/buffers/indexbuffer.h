#pragma once
#include <GL/glew.h>
#include <vector>

namespace lord { namespace graphics {

	class IndexBuffer
	{
		GLuint			_id;
		unsigned int	_numIndices;
	public:
		IndexBuffer(const std::vector<unsigned int>& indices);
		void bind() const;
		void unbind() const;
		inline unsigned int getNumIndices() const { return _numIndices; }
	};

}}