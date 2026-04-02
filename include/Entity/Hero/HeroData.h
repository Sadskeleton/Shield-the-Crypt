#pragma once
#include "Entity/EntityData.h"
#include <string>

namespace Hero
{
	class HeroData : public Entity::EntityData
	{	
		public:
		std::string name;

		HeroData(int hp, int damage);
	};
};
