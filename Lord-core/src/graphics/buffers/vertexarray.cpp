#include "vertexarray.h"
#include "../../defs.h"

namespace lord { namespace graphics {

	VertexArray::VertexArray()
	{
		GLCALL(glCreateVertexArrays(1, &_id));
	}

	VertexArray::~VertexArray()
	{
		GLCALL(glDeleteVertexArrays(1, &_id));
		for (auto* vbo : _buffers)
		{
			delete vbo;
		}
		_buffers.clear();
	}

	void VertexArray::bind() const
	{
		GLCALL(glBindVertexArray(_id));
	}

	void VertexArray::unbind() const
	{
		GLCALL(glBindVertexArray(0));
	}

	void VertexArray::push(Buffer* vbo)
	{
		if (!vbo)
		{
			return;
		}

		bind();
		vbo->bind();
		const auto& layout = vbo->getLayout();
		const auto& elements = layout.getElements();
		unsigned int offset = 0;
		for (const auto& element : elements)
		{
			GLCALL(glEnableVertexAttribArray(_numAttributes));
			GLCALL(glVertexAttribPointer(_numAttributes, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset));
			++_numAttributes;
			offset += element.count * getSizeOfType(element.type);
		}
		vbo->unbind();
		_buffers.push_back(vbo);
	}

}}