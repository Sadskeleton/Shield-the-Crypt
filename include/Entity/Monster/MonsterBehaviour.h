#pragma once

namespace Hero { class HeroData; }

namespace Monster
{
    class MonsterData;

    class MonsterBehaviour
    {
        public:
            enum class Behaviour
                {
                    Attack,
                    Rest,
                    None
                };

			static void ChooseBehaviour(MonsterData& monster, Hero::HeroData& hero);
            static void ExecuteBehaviour(MonsterData& monster, Hero::HeroData& hero);
        
        private:
			static void Attack(MonsterData& monster, Hero::HeroData& hero);
			static void Rest(MonsterData& monster);
            static void AttackInfo(MonsterData& monster);
            static void RestInfo(MonsterData& monster);
    };
}