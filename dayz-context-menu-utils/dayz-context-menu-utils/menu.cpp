#include "menu.h"

/* Publics */
Menu::Menu() {
	forceConsoleANSI();
	showMenu();
}

/* Privates */
void Menu::forceConsoleANSI() {
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD consoleMode;

	GetConsoleMode(consoleOutput, &consoleMode);

	consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;

	SetConsoleMode(consoleOutput, consoleMode);
}

void Menu::showMenu() {
	int option;

	optionsCount = 0;

	system("cls");

	coutASCII();

	std::cout << color::white("Select an option: \n") << std::endl;

	addOption("Add convert config options");
	addOption("Remove convert config options");

	std::cout << color::white("\nOption: ", false);

	std::cin >> option;

	handleOption(option);
}

void Menu::coutASCII() {
	std::cout << "\x1b[38;2;138;43;226m" << R"(    _____                    _   
   / ____|                  | |  
  | (___   ___  ___ _ __ ___| |_ 
   \___ \ / _ \/ __| '__/ _ \ __|
   ____) |  __/ (__| | |  __/ |_ 
  |_____/ \___|\___|_|  \___|\__|
)" << std::endl;
}

void Menu::setCoutCoords(int x, int y) {
	COORD coords;

	coords = getCoutCoords();

	coords.X = coords.X + x;
	coords.Y = coords.Y + y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

COORD Menu::getCoutCoords() {
	COORD coords;
	CONSOLE_SCREEN_BUFFER_INFO CBSI;

	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CBSI)) {
		coords = CBSI.dwCursorPosition;
	}
	else {
		coords.X = 0;
		coords.Y = 0;
	}

	return coords;	
}

void Menu::addOption(std::string text) {
	optionsCount++;

	setCoutCoords(2, 0);

	std::cout << color::blueViolet(std::format("{}) ", optionsCount)) << color::white(text) << std::endl;
}

void Menu::handleOption(int option) {
	ContextOptionsHandler contextOptionsHandler;

	system("cls");
	coutASCII();

	switch (option) {
		case 1:
			contextOptionsHandler.registerOption(OPTION_CONFIG);

			break;
		case 2:
			contextOptionsHandler.clearRegisteredValues(OPTION_CONFIG, false);

			showMenu();

			break;
		default:
			invalidOption();

			break;
	}

	system("cls");
}

void Menu::invalidOption() {
	std::cout << color::red("\nInvalid option.");

	Sleep(1000);

	showMenu();
}