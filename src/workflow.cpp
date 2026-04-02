#include <iostream>
#include <windows.h>
#include <string>
#include "Entity/Hero/HeroData.h"
#include "Entity/Hero/HeroBehaviour.h"
#include "Entity/Monster/MonsterData.h"
#include "Entity/Monster/MonsterBehaviour.h"
#include "Entity/Monster/MonsterInfo.h"

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

    //函数声明
    void firstRunText();
    void refreshUI(int rounds, Monster::MonsterData monster);

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

            firstRunText();

            refreshUI(rounds, monster);

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

void firstRunText()
{
        std::cout << "欢迎来到" << std::endl;
        Sleep(1000);
        std::cout << "----------Shield The Crypt----------" << std::endl;
        Sleep(1000);
        std::cout << "这是个回合制游戏，玩家需要在每个回合选择一个行为。" << std::endl;
        Sleep(1000);
        std::cout << "击败众多怪物，保护你的地穴！" << std::endl;
        Sleep(1000);
        std::cout << "那么" << std::endl;
        Sleep(1000);
        std::cout << "你的名字是(请输入你的名字):";
        std::string name;
        std::cin >> name;
        hero.name = name;
        Sleep(1000);
        std::cout << "你好啊 " << hero.name << "！" << std::endl;
        Sleep(1000);
        std::cout << "接下来..." << std::endl;
        Sleep(1000);
        for (int i = 0; i < 50; i++)
        {
            std::cout << "made by Sadskeleton" << std::endl;
            Sleep(10);
        }

        system("cls");
}

void refreshUI(int rounds, Monster::MonsterData monster)
{
    for (const char& c : hero.name)
    {
        std::cout << c;
        Sleep(10);
    }
    std::cout << std::endl;

    std::cout << "[";
    Sleep(10);

    int hpWidth = hero.currentHp/10;    // 每10点HP显示一个#
    int pointHp = hero.currentHp % 10; // 余数部分
    int emptyWidth = (hero.maxHp - hero.currentHp)/10; // 空白部分
    std::string pointSymbol = pointHp >= 5 ? "*" : "+"; // 余数部分大于等于5显示*，否则显示+

    for (int i = 0; i < hpWidth; i++)
    {
        std::cout << "#";
        Sleep(10);
    }

    if (pointHp > 0)
    {
        std::cout << pointSymbol;
        Sleep(10);
    }

    for (int i = 0; i < emptyWidth; i++)
    {
        std::cout << " ";
        Sleep(10);
    }

    std::cout << "]";
    Sleep(10);
    std::cout << " ";
    Sleep(10);
    std::cout << "H";
    Sleep(10);
    std::cout << "P";
    Sleep(10);
    std::cout << " ";
    Sleep(10);
    std::cout << ":";
    Sleep(10);
    std::cout << " ";
    Sleep(10);

    for (const char& c : std::to_string(hero.currentHp))
    {
        std::cout << c;
        Sleep(10);
    }

    std::cout << "/";
    Sleep(10);

    for (const char& c : std::to_string(hero.maxHp))
    {
        std::cout << c;
        Sleep(10);
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << " ";
        Sleep(10);
    }

    std::cout << "攻";
    Sleep(10);
    std::cout << "击";
    Sleep(10);
    std::cout << "力";
    Sleep(10);
    std::cout << " ";
    Sleep(10);
    std::cout << ":";
    Sleep(10);
    std::cout << " ";
    Sleep(10);

    for (const char& c : std::to_string(hero.damage))
    {
        std::cout << c;
        Sleep(10);
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << " ";
        Sleep(10);
    }

    std::cout << "回";
    Sleep(10);
    std::cout << "合";
    Sleep(10);
    std::cout << "数";
    Sleep(10);
    std::cout << " ";
    Sleep(10);
    std::cout << ":";
    Sleep(10);
    std::cout << " ";
    Sleep(10);
    std::cout << rounds << std::endl << std::endl << std::endl;
    Sleep(10);

    for (int i = 0; i < 4; i++)
    {
        std::cout << " ";
        Sleep(10);
    }

    std::cout << "你";
    Sleep(10);

    for (int i = 0; i < 27; i++)
    {
        std::cout << " ";
        Sleep(10);
    }

    for (const char& c : monster.name)
    {
        std::cout << c;
        Sleep(10);
    }

    std::cout << std::endl << std::endl << std::endl;

    for (const char& c : monster.text)
    {
        std::cout << c;
        Sleep(10);
    }

}