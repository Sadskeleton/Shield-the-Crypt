#include "Entity/Monster/MonsterData.h"
using namespace Monster;

MonsterData::MonsterData(int hp, int damage, const std::string name, int id) : EntityData(hp, damage)
{
    this->name = name;
    this->id = id;
}