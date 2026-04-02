#pragma once
#include <map>
#include <string>

namespace Monster
{
    struct MonsterStat {
        int hp;
        int attack;
        std::string name;
    };

    class MonsterInfo
    {
    public:
        // 静态只读字典
        static const std::map<int, MonsterStat> info;
    };
    
    // 静态成员初始化（类外定义）
    const std::map<int, MonsterStat> MonsterInfo::info = {
        {1, MonsterStat{20, 5, "史莱姆"}},
        {2, MonsterStat{50, 10, "哥布林"}}
    };
};