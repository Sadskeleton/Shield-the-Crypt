#pragma once
#include "Entity/EntityData.h"
#include <string>

namespace Monster
{
    class MonsterData : public Entity::EntityData
    {
        public:
        std::string name;
        int id;

        MonsterData(int hp, int damage, const std::string& name, int id);
    };
};