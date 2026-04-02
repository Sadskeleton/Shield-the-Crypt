#pragma once

namespace Monster { class MonsterData; }
namespace Hero
{
	class HeroData;

	class HeroBehaviour
	{
		public:
			enum class Behaviour
			{
				Attack,
				Rest
			};
			
			static void ChooseBehaviour(HeroData& hero, Behaviour behaviour, Monster::MonsterData& monster);
			
		private:
			static void Attack(const HeroData& hero, Monster::MonsterData& monster);
			static void Rest(HeroData& hero);
	};
};
