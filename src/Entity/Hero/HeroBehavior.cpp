#include "Entity/Hero/HeroBehaviour.h"
#include "Entity/Hero/HeroData.h"
#include "Entity/Monster/MonsterData.h"
#include <iostream>
using namespace Hero;

void HeroBehaviour::ChooseBehaviour(HeroData& hero, HeroBehaviour::Behaviour behaviour, Monster::MonsterData& monster)
{
	switch(behaviour)
    {
        case HeroBehaviour::Behaviour::Attack:
            Attack(hero, monster);
            break;
        
        case HeroBehaviour::Behaviour::Rest:
            Rest(hero);
            break;
        
        default:
            std::cout << "未知行为" << std::endl;
            break;
    }
}

void HeroBehaviour::Attack(const HeroData& hero, Monster::MonsterData& monster)
{
    monster.currentHp = (monster.currentHp - hero.damage) > 0 ? (monster.currentHp - hero.damage) : 0;
}

void HeroBehaviour::Rest(HeroData& hero)
{
    hero.currentHp += static_cast<int>(hero.maxHp * 0.1); // 恢复10%最大hp
    
    if (hero.currentHp > hero.maxHp)
    {
        hero.currentHp = hero.maxHp;
    }
}
