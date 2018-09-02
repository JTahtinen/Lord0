#pragma once
#include <gl/glew.h>
#include <vector>

namespace lord { namespace graphics {

	struct LayoutElement
	{
		GLuint		count;
		GLenum		type;
		GLboolean	normalized;
	};

	class VBOLayout
	{
		std::vector<LayoutElement>		_elements;
		GLuint							_stride{ 0 };
	public:
		template <typename T>
		void push(GLuint count);
		inline const auto& getElements() const { return _elements; }
		inline GLuint getStride() const { return _stride; }
	};

}}