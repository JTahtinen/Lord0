#include "inputsystem.h"
#include <vector>

namespace lord { namespace game { namespace system {

	namespace inputSystem
	{
		using namespace input;
		using namespace math;

		static std::vector<GUID>		_entities;

		struct InputData
		{
			InputsMap&					inputs;
			LocationsMap&				locations;
		};

		static InputData*		_data;

		void init(InputsMap& inputs, LocationsMap& locations)
		{
			_data = new InputData
			{
				inputs,
				locations
			};
		}

		void update()
		{
			for (GUID entity : _entities)
			{
				InputComponent* input = _data->inputs[entity];
				LocationComponent* location = _data->locations[entity];
				Input& in = input->_in;
				
				if (in.poll(KEY_H))
				{
					location->vel += Vec3(0.1f, 0, 0);
				}
				if (in.poll(KEY_F))
				{
					location->vel += Vec3(-0.1f, 0, 0);
				}
				if (in.poll(KEY_T))
				{
					location->vel += Vec3(0, 0, -0.1);
				}
				if (in.poll(KEY_G))
				{
					location->vel += Vec3(0, 0, 0.1);
				}
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