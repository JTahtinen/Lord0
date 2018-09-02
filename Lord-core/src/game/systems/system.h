#pragma once
#include "../component.h"
#include <unordered_map>

namespace lord { namespace game {

	typedef unsigned long GUID; // Globally unique identifier

	typedef std::unordered_map<GUID, LocationComponent*>	LocationsMap;
	typedef std::unordered_map<GUID, GraphicsComponent*>	GraphicsMap;
	typedef std::unordered_map<GUID, InputComponent*>		InputsMap;

	namespace system 
	{
		enum
		{
			INVALID_COMPONENT  = 0,
			COMPONENT_LOCATION = (1 << 0),
			COMPONENT_GRAPHICS = (1 << 2),
			COMPONENT_INPUT	   = (1 << 3)
		};

		void init();
		void update();
		void quit();
		
		/**
		 * @param entity	Entity GUID to be bound with component
		 * @param types		Component type enum, can be OR'd together for multiple components  
		 **/
		void addComponents(GUID entity, unsigned int types);

		LocationComponent* getLocationComponent(GUID entity);
		GraphicsComponent* getGraphicsComponent(GUID entity);
		InputComponent*	   getInputComponent(GUID entity);


		GUID createEntity();
		void destroyEntity(GUID entity);
	}

}}