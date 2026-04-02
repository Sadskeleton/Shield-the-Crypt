#include <iostream>
#include <windows.h>
#include "Entity/Hero/HeroData.h"
#include "Entity/Hero/HeroBehaviour.h"

bool g_running = true;

// 控制台事件回调
BOOL WINAPI ConsoleHandler(DWORD signal) {
    if (signal == CTRL_CLOSE_EVENT) {
        g_running = false; // 通知主循环退出
        Sleep(1000);       // 给程序一点时间清理
    }
    return TRUE; // 告诉系统事件已处理
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);    // 控制台 UTF-8
    SetConsoleCtrlHandler(ConsoleHandler, TRUE); // 注册控制台事件处理程序，用于解决用户直接关闭控制台导致的程序仍在运行问题

    // 游戏主循环
    bool terminated = false;
    bool failed = false;
    bool firstRun = true;
    int total_rounds = 0;

    //角色数据
    Hero::HeroData hero(100, 10);

    while(g_running && !terminated && !failed)
    {
        if (firstRun)
        {
            std::cout << "欢迎来到" << std::endl;
            Sleep(1000);
            std::cout << "----------Shield The Crypt----------" << std::endl;
            Sleep(1000);
            std::cout << "这是个回合制游戏，玩家需要在每个回合选择一个行为。" << std::endl;
            Sleep(1000);
            std::cout << "击败众多怪物，保护你的墓穴！" << std::endl;
            Sleep(1000);
            std::cout << "OK" << std::endl;
            Sleep(1000);
            std::cout << "接下来..." << std::endl;
            Sleep(1000);
            for (int i = 0; i < 50; i++)
            {
                std::cout << "made by Sadskeleton" << std::endl;
                Sleep(10);
            }

            system("cls");
            firstRun = false;
        }

        Sleep(50);
        terminated = true; // 目前先直接结束循环，后续会根据游戏状态来设置这个变量
    }
    return 0;
}