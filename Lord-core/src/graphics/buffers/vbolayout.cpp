#include "vbolayout.h"

namespace lord { namespace graphics {

	template<>
	void VBOLayout::push<float>(GLuint count)
	{
		_elements.emplace_back(LayoutElement{ count, GL_FLOAT, false });
		_stride += count * sizeof(float);
	}

	template<>
	void VBOLayout::push<unsigned int>(GLuint count)
	{
		_elements.emplace_back(LayoutElement{ count, GL_UNSIGNED_INT, false });
		_stride += count * sizeof(unsigned int);
	}

	template<>
	void VBOLayout::push<unsigned char>(GLuint count)
	{
		_elements.emplace_back(LayoutElement{ count, GL_BYTE, false });
		_stride += count * sizeof(unsigned char);
	}

	template<>
	void VBOLayout::push<int>(GLuint count)
	{
		_elements.emplace_back(LayoutElement{ count, GL_INT, false });
		_stride += count * sizeof(int);
	}

}}