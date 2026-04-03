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
        int rounds = 1;
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
            UI::Text::updateData(rounds, hero, monster); //更新数据
            std::cout << std::endl;
            Hero::HeroBehaviour::ChooseBehaviour(hero, monster);        //获取玩家输入并执行动作
            Monster::MonsterBehaviour::ExecuteBehaviour(monster, hero); //执行怪物动作

            if(monster.currentHp <= 0)
                monsterDefeated = true;
            
            if(hero.currentHp <= 0)
                break;
        }

        Sleep(50);

        if (Monster::MonsterInfo::info.find(total_rounds+1) == Monster::MonsterInfo::info.end() && monsterDefeated)
            terminated = true;
        
        else if (!monsterDefeated)
            failed = true;
    }

    system("cls");

    if (terminated)
        std::cout << "SUCCESSFUL!";

    else
        std::cout << "YOU ARE FAILED.";

    return 0;
}