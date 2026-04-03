#pragma once

namespace Hero {class HeroData;}
namespace Monster {class MonsterData;}
namespace UI
{
    class Text
    {
        public:
        static void firstRunText(Hero::HeroData& hero);
        static void refreshUI(int rounds, Hero::HeroData& hero, Monster::MonsterData& monster);
    };

}