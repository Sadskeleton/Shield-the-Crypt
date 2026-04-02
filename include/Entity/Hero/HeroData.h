#pragma once
#include "Entity/EntityData.h"

namespace Hero
{
	class HeroData : public Entity::EntityData
	{	
		public:
		HeroData(int hp, int damage);
	};
};
