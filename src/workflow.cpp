#include <iostream>
#include <windows.h>
#include <string>
#include "Entity/Hero/HeroData.h"
#include "Entity/Hero/HeroBehaviour.h"
#include "Entity/Monster/MonsterData.h"
#include "Entity/Monster/MonsterBehaviour.h"
#include "Entity/Monster/MonsterInfo.h"
#include "UI/Text.h"

bool g_running = true;

// 控制台事件回调
BOOL WINAPI ConsoleHandler(DWORD signal) {
    if (signal == CTRL_CLOSE_EVENT) {
        g_running = false; // 通知主循环退出
        Sleep(1000);       // 给程序一点时间清理
    }
    return TRUE; // 告诉系统事件已处理
}

//角色数据
Hero::HeroData hero(100, 10);

int main()
{
    SetConsoleOutputCP(CP_UTF8);    // 控制台 UTF-8
    SetConsoleCtrlHandler(ConsoleHandler, TRUE); // 注册控制台事件处理程序，用于解决用户直接关闭控制台导致的程序仍在运行问题

    // 游戏主循环
    bool terminated = false;
    bool failed = false;
    bool firstRun = true;
    int total_rounds = 0;

    while(g_running && !terminated && !failed)
    {
        total_rounds++;
        int rounds = 0;
        bool monsterDefeated = false;

        //生成Monster
        const auto& monsterStat = Monster::MonsterInfo::info.at(total_rounds);
        Monster::MonsterData monster(monsterStat.hp, monsterStat.attack, monsterStat.name);

        if (firstRun)
        {
            Monster::MonsterBehaviour::ChooseBehaviour(monster, hero);

            UI::Text::firstRunText(hero);

            UI::Text::refreshUI(rounds, hero, monster);

            firstRun = false;
        }

        while (g_running && !monsterDefeated)
        {
            rounds++;
            Monster::MonsterBehaviour::ChooseBehaviour(monster, hero);
            monsterDefeated = true; // 目前先直接结束循环，后续会根据怪物状态来设置这个变量
        }

        Sleep(50);
        terminated = true; // 目前先直接结束循环，后续会根据游戏状态来设置这个变量
    }
    return 0;
}