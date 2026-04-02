#include "Entity/Monster/MonsterBehaviour.h"
#include "Entity/Monster/MonsterData.h"
#include "Entity/Hero/HeroData.h"
#include <iostream>
#include <random>
using namespace Monster;

void MonsterBehaviour::ChooseBehaviour(MonsterData& monster, Hero::HeroData& hero)
{
	// 创建随机数引擎
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0); // 生成 [0.0,1.0) 的 double
    double randomValue = dis(gen);

    if (randomValue < 0.7)
    {
        AttackInfo(monster);  // 70% 概率攻击
        monster.next_behaviour = Behaviour::Attack;
    }
    else
    {
        RestInfo(monster);           // 30% 概率休息
        monster.next_behaviour = Behaviour::Rest;
    }
}

void MonsterBehaviour::ExecuteBehaviour(MonsterData& monster, Hero::HeroData& hero)
{
    switch(monster.next_behaviour)
    {
        case Behaviour::Attack:
            Attack(monster, hero);
            monster.next_behaviour = Behaviour::None;
            break;

        case Behaviour::Rest:
            Rest(monster);
            monster.next_behaviour = Behaviour::None;
            break;
    };
}

void MonsterBehaviour::Attack(MonsterData& monster, Hero::HeroData& hero)
{
    hero.currentHp = (hero.currentHp - monster.damage) > 0 ? (hero.currentHp - monster.damage) : 0;
    monster.text = "";
}

void MonsterBehaviour::Rest(MonsterData& monster)
{
    monster.currentHp += static_cast<int>(monster.maxHp * 0.05);
    
    if (monster.currentHp > monster.maxHp)
    {
        monster.currentHp = monster.maxHp;
    }

    monster.text = "";
}

void MonsterBehaviour::AttackInfo(MonsterData& monster)
{
    monster.text = "这个敌人将要对你造成" + std::to_string(monster.damage) + "点伤害";
}

void MonsterBehaviour::RestInfo(MonsterData& monster)
{
    monster.text = "这个敌人将要回复生命";
}