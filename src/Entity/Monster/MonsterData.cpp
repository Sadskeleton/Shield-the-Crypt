#include "Entity/Monster/MonsterData.h"
using namespace Monster;

MonsterData::MonsterData(int hp, int damage, const std::string& name) : EntityData(hp, damage)
{
    this->name = name;
}