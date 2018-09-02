#pragma once
#include <GL/glew.h>
#include "vbolayout.h"
#include <vector>

namespace lord { namespace graphics {

	class Buffer
	{
		GLuint		_id;
		VBOLayout	_layout;
	public:
		Buffer(const void* data, unsigned int size, const VBOLayout& layout);
		void bind() const;
		void unbind() const;
		const VBOLayout& getLayout() const { return _layout; }
	};

}}