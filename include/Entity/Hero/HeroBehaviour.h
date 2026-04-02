#pragma once
#include "Entity/Hero/HeroData.h"

namespace Hero
{
	class HeroBehaviour
	{
		public:
			enum class Behaviour
			{
				Attack,
				Rest
			};
			
			void ChooseBehaviour(HeroData& hero, Behaviour behaviour);
			
		private:
			void Attack(const HeroData& hero, int targetID);
			void Rest(HeroData& hero);
	};
};
