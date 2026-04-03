#include "Entity/Hero/HeroBehaviour.h"
#include "Entity/Hero/HeroData.h"
#include "Entity/Monster/MonsterData.h"
#include <iostream>
using namespace Hero;

void HeroBehaviour::ChooseBehaviour(HeroData& hero, Monster::MonsterData& monster)
{
    std::cout << "请输入你要选择的动作:1.攻击    2.休息(回复最大血量的10%)";
    bool cinFlag = false;
    HeroBehaviour::Behaviour behaviour = Behaviour::None;

    while (!cinFlag)
    {
        int num;
        std::cin >> num;
        switch(num)
        {
            case 1:
                behaviour = Behaviour::Attack;
                cinFlag = true;
                break;
            case 2:
                behaviour = Behaviour::Rest;
                cinFlag = true;
                break;
            default:
                std::cout << "请输入1或2";
        }
    }

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
