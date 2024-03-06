#include "includes.h"
#include "ContextOptionsHandler.h"

class Menu {
public:
	Menu();

private:
	int optionsCount = 0;

	void forceConsoleANSI();
	void showMenu();
	void coutASCII();
	void setCoutCoords(int x, int y);
	COORD getCoutCoords();
	void addOption(std::string text);
	void handleOption(int option);
	void invalidOption();
};