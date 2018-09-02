#include "application.h"
#include <GL/glew.h>
#include "util/file.h"
#include "defs.h"
#include "graphics/shader.h"
#include "graphics/buffers/vertexarray.h"
#include "graphics/buffers/buffer.h"
#include "math/math.h"
#include "input/input.h"
#include "graphics/buffers/indexbuffer.h"
#include "graphics/mesh.h"
#include "graphics/renderers/renderer3d.h"
#include "graphics/layers/layer3d.h"

namespace lord	
{
	Application::Application(int width, int height, const char* title)
		: _window(width, height, title)
	{
	}

	void Application::run()
	{
		using namespace graphics;
		using namespace math;
		using namespace input;
		using namespace game;

		Input& in = Input::instance();

		VBOLayout layout;
		layout.push<float>(3);
		layout.push<float>(4);
		std::vector<float> vertices;
		
		vertices.push_back(-0.5f);
		vertices.push_back(-0.5f);
		vertices.push_back(0.5f);

		vertices.push_back(0.2f);
		vertices.push_back(0.5f);
		vertices.push_back(0.9f);
		vertices.push_back(1.0f);

		vertices.push_back(0.0f);
		vertices.push_back(0.5f);
		vertices.push_back(0.0f);

		vertices.push_back(0.3f);
		vertices.push_back(0.2f);
		vertices.push_back(0.8f);
		vertices.push_back(1.0f);

		vertices.push_back(0.5f);
		vertices.push_back(-0.5f);
		vertices.push_back(0.5f);

		vertices.push_back(0.7f);
		vertices.push_back(0.2f);
		vertices.push_back(0.1f);
		vertices.push_back(1.0f);

		vertices.push_back(0.5f);
		vertices.push_back(-0.5f);
		vertices.push_back(-0.5f);

		vertices.push_back(0.8f);
		vertices.push_back(0.1f);
		vertices.push_back(0.8f);
		vertices.push_back(1.0f);

		vertices.push_back(-0.5f);
		vertices.push_back(-0.5f);
		vertices.push_back(-0.5f);

		vertices.push_back(0.4f);
		vertices.push_back(0.6f);
		vertices.push_back(0.2f);
		vertices.push_back(1.0f);

		std::vector<unsigned int> indices;

		indices.push_back(2);
		indices.push_back(1);
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(3);
		indices.push_back(1);
		indices.push_back(4);
		indices.push_back(0);
		indices.push_back(4);
		indices.push_back(1);
		indices.push_back(3);

		float aspect = (float)_window.getWidth() / (float)_window.getHeight();

		Buffer* vbo = new Buffer(&vertices[0], vertices.size() * sizeof(float), layout);
		
		Mesh mesh(vbo, indices);

		vertices.clear();

		vertices.push_back(-1.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(2.0f);

		vertices.push_back(0.1f);
		vertices.push_back(0.0f);
		vertices.push_back(0.5f);
		vertices.push_back(1.0f);

		vertices.push_back(-1.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(-2.0f);

		vertices.push_back(0.1f);
		vertices.push_back(0.0f);
		vertices.push_back(0.5f);
		vertices.push_back(1.0f);
		
		vertices.push_back(1.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(-2.0f);

		vertices.push_back(0.1f);
		vertices.push_back(0.0f);
		vertices.push_back(0.5f);
		vertices.push_back(1.0f);

		vertices.push_back(1.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(2.0f);

		vertices.push_back(0.1f);
		vertices.push_back(0.0f);
		vertices.push_back(0.5f);
		vertices.push_back(1.0f);

		indices.clear();

		indices.push_back(2);
		indices.push_back(1);
		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(0);
		indices.push_back(3);
		
		Buffer* vbo2 = new Buffer(&vertices[0], vertices.size() * sizeof(float), layout);

		Mesh meshB(vbo2, indices);


		Shader* shader = Shader::loadShader("res/shaders/basic");
		shader->bind();
		
		Vec3 position;
		shader->setUniformMat4("u_view", Matrix4f::translate(position));
		//shader->setUniformMat4("u_model", Matrix4f::translate(Vec3(0.3f, 0, -4.0f)));
		//shader->setUniformMat4("u_model", e->getTransform());
		shader->setUniformMat4("u_projection", math::Matrix4f::perspective(70.0f, aspect, 0.1f, 200.0f));

		Layer3D layer3D(shader);

		Vec3 forward(0, 0, -1);
		Vec3 up(0, 1, 0);
		Vec3 right(1, 0, 0);

		float speed = 0.1f;
		float yaw = 0.0f;
		float pitch = 0.0f;

		_game.addEntity(Vec3(0, 0, -4.0f), &mesh, &layer3D);

		bool running = true;
		while (running)
		{
			in.update();

			if (in.poll(KEY_ESCAPE))
			{
				running = false;
			}
			if (in.poll(KEY_W)) position -= forward * speed;
			if (in.poll(KEY_S)) position += forward * speed;
			if (in.poll(KEY_A)) position += right * speed;
			if (in.poll(KEY_D)) position -= right * speed;
			if (in.poll(KEY_LEFT))	yaw -= 0.5f;
			if (in.poll(KEY_RIGHT))	yaw += 0.5f;
			if (in.poll(KEY_UP))	pitch -= 0.25f;
			if (in.poll(KEY_DOWN))	pitch += 0.25f;
			
			yaw += (float)in.getMouseDeltaX();
			pitch += (float)in.getMouseDeltaY();

	//		while (pitch > 360.0f) pitch -= 360.f;
			while (yaw < 0.0f) yaw += 360.f;
			while (yaw > 360.f) yaw -= 360.0f;
			
			if (pitch > 90.0f) pitch = 90.0f;
			if (pitch < -90.0f) pitch = -90.f;

			//std::cout << "MouseX: " << in.getMouseX() << " | MouseY: " << in.getMouseY() << std::endl;

			_game.update();


			forward = Matrix4f::rotation(-yaw, Vec3(0, 1, 0)) *
				Matrix4f::rotation(-pitch, Vec3(1, 0, 0)) * Vec3(0, 0, -1);
			right = forward.cross(up);
			shader->setUniformMat4("u_view", 
				Matrix4f::rotation(pitch, Vec3(1, 0, 0)) * 
				Matrix4f::rotation(yaw, Vec3(0, 1, 0)) *
				Matrix4f::translate(position)
			);
		
		
		
			_window.clear();
			layer3D.render();
			_window.update();
		}
		delete shader;
	}
}