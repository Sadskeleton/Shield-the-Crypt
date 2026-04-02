#pragma once
namespace Entity
{
    class EntityData
    {
        public:
            int maxHp;
            int currentHp;
            int damage;

        EntityData(int hp, int damage);
    };
};