#include "UI/Text.h"
#include "Entity/Hero/HeroData.h"
#include "Entity/Monster/MonsterData.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace UI;

void Text::firstRunText(Hero::HeroData& hero)
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

void Text::refreshUI(int rounds, Hero::HeroData& hero, Monster::MonsterData& monster)
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

    std::cout << " ";
    Sleep(10);
    std::cout << "(";
    Sleep(10);
    for (const char& c : std::to_string(monster.currentHp))
    {
        std::cout << c;
        Sleep(10);
    }

    std::cout << "/";
    Sleep(10);
    
    for (const char& c : std::to_string(monster.maxHp))
    {
        std::cout << c;
        Sleep(10);
    }
    std::cout << ")";
    Sleep(10);


    std::cout << std::endl << std::endl << std::endl;

    for (const char& c : monster.text)
    {
        std::cout << c;
        Sleep(10);
    }

}

void Text::updateData(int rounds, Hero::HeroData& hero, Monster::MonsterData& monster)
{
    system("cls");

    for (const char& c : hero.name)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    std::cout << "[";

    int hpWidth = hero.currentHp/10;    // 每10点HP显示一个#
    int pointHp = hero.currentHp % 10; // 余数部分
    int emptyWidth = (hero.maxHp - hero.currentHp)/10; // 空白部分
    std::string pointSymbol = pointHp >= 5 ? "*" : "+"; // 余数部分大于等于5显示*，否则显示+

    for (int i = 0; i < hpWidth; i++)
    {
        std::cout << "#";
    }

    if (pointHp > 0)
    {
        std::cout << pointSymbol;
    }

    for (int i = 0; i < emptyWidth; i++)
    {
        std::cout << " ";
    }

    std::cout << "]";
    std::cout << " ";
    std::cout << "H";
    std::cout << "P";
    std::cout << " ";
    std::cout << ":";
    std::cout << " ";

    for (const char& c : std::to_string(hero.currentHp))
    {
        std::cout << c;
    }

    std::cout << "/";

    for (const char& c : std::to_string(hero.maxHp))
    {
        std::cout << c;
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << " ";
    }

    std::cout << "攻";
    std::cout << "击";
    std::cout << "力";
    std::cout << " ";
    std::cout << ":";
    std::cout << " ";

    for (const char& c : std::to_string(hero.damage))
    {
        std::cout << c;
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << " ";
    }

    std::cout << "回";
    std::cout << "合";
    std::cout << "数";
    std::cout << " ";
    std::cout << ":";
    std::cout << " ";
    std::cout << rounds << std::endl << std::endl << std::endl;

    for (int i = 0; i < 4; i++)
    {
        std::cout << " ";
    }

    std::cout << "你";

    for (int i = 0; i < 27; i++)
    {
        std::cout << " ";
    }

    for (const char& c : monster.name)
    {
        std::cout << c;
    }

    std::cout << " ";
    std::cout << "(";
    for (const char& c : std::to_string(monster.currentHp))
    {
        std::cout << c;
    }

    std::cout << "/";

    for (const char& c : std::to_string(monster.maxHp))
    {
        std::cout << c;
    }
    std::cout << ")";

    std::cout << std::endl << std::endl << std::endl;

    for (const char& c : monster.text)
    {
        std::cout << c;
    }

}