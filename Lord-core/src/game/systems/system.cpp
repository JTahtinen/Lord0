#include "system.h"
#include <string>
#include "../component.h"
#include "locationsystem.h"
#include "graphicssystem.h"
#include <deque>
#include <vector>
#include <unordered_map>
#include "inputsystem.h"

namespace lord { namespace game {

	namespace system
	{

		static std::deque<GUID>									_freeIDList;
		static std::vector<GUID>								_entities;
		static std::unordered_map<GUID, LocationComponent*>		_locationComponents;
		static std::unordered_map<GUID, GraphicsComponent*>		_graphicsComponents;
		static std::unordered_map<GUID, InputComponent*>		_inputComponents;

		void init()
		{
			locationSystem::init(_locationComponents);
			graphicsSystem::init(_graphicsComponents, _locationComponents);
			inputSystem::init(_inputComponents, _locationComponents);
		}

		template <typename T>
		inline bool componentExists(std::unordered_map<GUID, T*>& map, GUID entity)
		{
			return map.find(entity) != map.end();
		}

		void addComponents(GUID entity, unsigned int type)
		{
			for (GUID e : _entities)
			{
				if (entity == e)
				{
					if (type & COMPONENT_LOCATION)
					{
						if (!componentExists(_locationComponents, entity)) // If entity does not already have the component;
						{
							_locationComponents.insert({ entity, new LocationComponent() });
							locationSystem::addEntity(entity);
						}
					}

					if (type & COMPONENT_GRAPHICS)
					{
						if (!componentExists(_graphicsComponents, entity))
						{
							_graphicsComponents.insert({ entity, new GraphicsComponent()});
							graphicsSystem::addEntity(entity);
						}
					}
					if (type & COMPONENT_INPUT)
					{
						if (!componentExists(_inputComponents, entity))
						{
							_inputComponents.insert({ entity, new InputComponent()});
							inputSystem::addEntity(entity);
						}
					}
				}
			}
		}

		template <typename T>
		T* getComponent(GUID entity, std::unordered_map<GUID, T*>& components)
		{
			if (componentExists(components, entity))
			{
				return components[entity];
			}
			std::cout << "[WARNING] Could not find component for GUID: " << entity << std::endl;
			return nullptr;
		}

		template <typename T>
		void destroyComponent(GUID entity, std::unordered_map<GUID, T*>& components)
		{
			if (componentExists(components, entity))
			{
				delete components[entity];
				components.erase(entity);
			}
		}

		LocationComponent* getLocationComponent(GUID entity)
		{
			return getComponent(entity, _locationComponents);
		}

		GraphicsComponent* getGraphicsComponent(GUID entity)
		{
			return getComponent(entity, _graphicsComponents);
		}

		InputComponent* getInputComponent(GUID entity)
		{
			return getComponent(entity, _inputComponents);
		}

		void update()
		{
			inputSystem::update();
			locationSystem::update();
			graphicsSystem::update();
		}

		void quit()
		{
			for (GUID entity : _entities)
			{
				destroyEntity(entity);
			}
			inputSystem::quit();
			locationSystem::quit();
			graphicsSystem::quit();
		}

		GUID createEntity()
		{
			static GUID biggestID = 0;

			GUID id = 0;
			if (!_freeIDList.empty())
			{
				id = _freeIDList.front();
				_freeIDList.pop_front();
			}
			else
			{
				id = biggestID++;
			}
			_entities.push_back(id);
			std::cout << "Created Entity, GUID: " << id << std::endl;
			return id;
		}

		void destroyEntity(GUID entity)
		{
			for (unsigned int i = 0; i < _entities.size(); ++i)
			{
				if (_entities[i] == entity)
				{
					destroyComponent(entity, _inputComponents);
					destroyComponent(entity, _locationComponents);
					destroyComponent(entity, _graphicsComponents);
					_entities.erase(_entities.begin() + i);
					return;
				}
			}
			std::cout << "[WARNING] Tried to destroy non-existent Entity, GUID " << entity << std::endl;
		}
	}

}}