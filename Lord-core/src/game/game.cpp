#include "game.h"
#include "systems/system.h"

namespace lord { namespace game {

	using namespace graphics;
	using namespace math;
	using namespace system;

	Game::Game()
	{
		system::init();
	}
	
	Game::~Game()
	{
		system::quit();
	}
	
	void Game::update()
	{
		system::update();
	}

	void Game::addEntity(const Vec3& pos, const Mesh* mesh, Layer3D* layer)
	{
		GUID entity = system::createEntity();
		
		system::addComponents(entity, COMPONENT_LOCATION | COMPONENT_GRAPHICS | COMPONENT_INPUT);
		LocationComponent* location = system::getLocationComponent(entity);
		GraphicsComponent* graphics = system::getGraphicsComponent(entity);
		location->pos = pos;
		graphics->_mesh = mesh;
		graphics->_layer = layer;
		_entities.push_back(entity);
	}

}}