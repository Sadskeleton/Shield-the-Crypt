#pragma once
#include "Entity/EntityData.h"
#include "Entity/Monster/MonsterBehaviour.h"
#include <string>

namespace Monster
{
    class MonsterData : public Entity::EntityData
    {
        public:
        std::string name;
        std::string text = "";
        MonsterBehaviour::Behaviour next_behaviour = MonsterBehaviour::Behaviour::None;

        MonsterData(int hp, int damage, const std::string& name);
    };
};