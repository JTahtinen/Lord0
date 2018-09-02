#include "indexbuffer.h"
#include "../../defs.h"

namespace lord { namespace graphics {

	IndexBuffer::IndexBuffer(const std::vector<unsigned int>& indices)
		: _numIndices(indices.size())
	{
		ASSERT(!indices.empty());

		glCreateBuffers(1, &_id);
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	}

	void IndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
	}

	void IndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}}