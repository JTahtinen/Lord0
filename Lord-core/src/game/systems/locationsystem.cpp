#include "locationsystem.h"
#include <vector>

namespace lord { namespace game { namespace system {

	namespace locationSystem {

		static std::vector<GUID>						_entities;

		struct LocationData
		{
			LocationsMap&								components;
		};

		static LocationData*							_data;

		void init(LocationsMap& components)
		{
			_data = new LocationData{ components };
		}
	
		void update()
		{
			for (GUID entity : _entities)
			{
				LocationComponent* com = _data->components[entity];
				com->pos += com->vel;
				com->vel.mul(0);
			}
		}

		void quit()
		{
			delete _data;
			_data = nullptr;
		}

		void addEntity(GUID entity)
		{
			for (GUID e : _entities)
			{
				if (e == entity)
				{
					return;
				}
			}
			_entities.push_back(entity);
		}
	
	
	}




}}}