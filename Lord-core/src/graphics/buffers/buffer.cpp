#include "buffer.h"
#include "../../defs.h"

namespace lord { namespace graphics {

	Buffer::Buffer(const void* data, unsigned int size, const VBOLayout& layout)
		: _layout(layout)
	{
		GLCALL(glCreateBuffers(1, &_id));
		bind();
		GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	void Buffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _id));
	}
	
	void Buffer::unbind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}}