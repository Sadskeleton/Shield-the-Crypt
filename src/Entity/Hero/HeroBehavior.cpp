#include "Entity/Hero/HeroBehaviour.h"
#include "Entity/Hero/HeroData.h"
#include <iostream>
using namespace Hero;

void HeroBehaviour::ChooseBehaviour(HeroData& hero, Behaviour behaviour)
{
	switch(behaviour)
    {
        case Behaviour::Attack:
            int id;
            std::cout << "请输入目标ID:";
            std::cin >> id;
            Attack(hero, id);
            break;
        
        case Behaviour::Rest:
            Rest(hero);
            break;
        
        default:
            std::cout << "未知行为" << std::endl;
            break;
    }
}

void HeroBehaviour::Attack(const HeroData& hero, int targetID)
{

}

void HeroBehaviour::Rest(HeroData& hero)
{
    hero.currentHp += hero.maxHp * 0.1; // 恢复10%最大hp
    
    if (hero.currentHp > hero.maxHp)
    {
        hero.currentHp = hero.maxHp;
    }
}
