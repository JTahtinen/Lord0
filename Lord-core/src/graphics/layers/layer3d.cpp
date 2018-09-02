#include "layer3d.h"
#include "../../defs.h"

namespace lord { namespace graphics {

	using namespace math;

	Layer3D::Layer3D(Shader* shader)
		: _projection(Matrix4f::perspective(70.0f, 16.0f / 9.0f, 0.1f, 200.0f))
		, _shader(shader)
	{
		ASSERT(_shader)
	}

	void Layer3D::submit(const Mesh* renderable, const Matrix4f& transform)
	{
		if (renderable)
		{
			_renderQueue.push_back(Renderable3D{ renderable, transform });
		}
	}

	void Layer3D::render()
	{
		_shader->setUniformMat4("u_projection", _projection);
		for (auto& renderable : _renderQueue)
		{
			_renderer.pushMatrix(renderable.transformation);
			_renderer.render(renderable.mesh, _shader);
			_renderer.popMatrix();
			_renderQueue.pop_front();
		}
	}

}}