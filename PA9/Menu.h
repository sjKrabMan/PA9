#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


class Menu
{
public:
	Menu();
	~Menu();

	void displaymenu()
	{
		system("cls");
		cout << " __                    __      __      __                    __                          __                 " << endl;
		cout << "/  |                  /  |    /  |    /  |                  /  |                        /  |                " << endl;
		cout << "$$ |____    ______   _$$ |_  _$$ |_   $$ |  ______         _$$ |_     ______   _______  $$ |   __   _______ " << endl;
		cout << "$$      \\  /      \\ / $$   |/ $$   |  $$ | /     \\       / $$   |   /     \\ /    \\ $$ |  /  | /       |" << endl;
		cout << "$$$$$$$  | $$$$$$  |$$$$$$/ $$$$$$/   $$ |/$$$$$$  |      $$$$$$/    $$$$$$  |$$$$$$$  |$$ |_/$$/ /$$$$$$$/ " << endl;
		cout << "$$ |  $$ | /    $$ |  $$ | __ $$ | __ $$ |$$    $$ |        $$ | __  /    $$ |$$ |  $$ |$$   $$<  $$      \\ " << endl;
		cout << "$$ |__$$ |/$$$$$$$ |  $$ |/  |$$ |/  |$$ |$$$$$$$$/         $$ |/  |/$$$$$$$ |$$ |  $$ |$$$$$$  \\  $$$$$$  |" << endl;
		cout << "$$    $$/ $$    $$ |  $$  $$/ $$  $$/ $$ |$$       |        $$  $$/ $$    $$ |$$ |  $$ |$$ | $$  |/     $$/ " << endl;
		cout << "$$$$$$$/   $$$$$$$/    $$$$/   $$$$/  $$/  $$$$$$$/          $$$$/   $$$$$$$/ $$/   $$/ $$/   $$/ $$$$$$$/  " << endl;
		
		cout << endl;
		cout << endl;
		cout << "1. Instructions" << endl;
		cout << endl;
		cout << "2. Play Game" << endl;
		cout << endl;
		cout << "3. test cases" << endl;
		cout << endl;
		cout << "4, Exit" << endl;
		cout << endl;
	}

	void displayInstructuions()
	{
		system("cls");
		cout << "GRAB A FRIEND AND GET READY FOR A FUN FILLED TIME OF KILLING EACH OTHER" << endl<< endl;
		
		cout << "In this game there are two players who are gunning for being the last one alive on the battle feild." << endl;
		cout << "player 1 is the top left green tank & player 2 is the bottom right white tank" << endl;
		cout << "Each tank has 3 lifes to win this battle and with the new SUPER COOL BULLETS it's one shot, ONE KILL" << endl;
		cout << "but make sure to watch your corners because these bullets ricochet and come at you fast" << endl;
		cout << endl;

		cout << "Player 1:						Player 2:" << endl;
		cout << "W -> Move Up						UP Arrow -> Move Up " << endl;
		cout << "A -> Move Left						Left Arrow -> Move Left" << endl;
		cout << "S -> Move Down						Down Arrow -> Move Down" << endl;
		cout << "D -> Move Right						Right Arrow -> Move Right" << endl;
		cout << "Left shift -> Shoot					Right Shift -> Shoot" << endl;
		cout << endl;
		system("pause");
	}

	int grabChoice()
	{
		int option = 0;
		cin >> option;
		return option;
	}


};

Menu::Menu()
{
}

Menu::~Menu()
{
}



