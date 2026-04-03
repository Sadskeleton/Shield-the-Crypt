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
				Rest,
				None
			};
			
			static void ChooseBehaviour(HeroData& hero, Monster::MonsterData& monster);
			
		private:
			static void Attack(const HeroData& hero, Monster::MonsterData& monster);
			static void Rest(HeroData& hero);
	};
};
