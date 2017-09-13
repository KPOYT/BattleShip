#include "Menu.h"

Menu::Menu(const string desc)
{
	position.X = 0;
	position.Y = 0;
	description = desc;
	console = Console::Instance();
};

Menu::Menu(const COORD pos, const string desc)
{
	position = pos;
	description = desc;
	console = Console::Instance();
};

Menu::Menu(const int x,
			const int y,
			const string desc)
{
	position.X = x;
	position.Y = y;
	description = desc;
	console = Console::Instance();
};

void Menu::redrawMenu(const int){};

const int Menu::checkKeys(int mode){ return mode; };

const int Menu::show()
{
	int mode = 0;
	bool choise = false;

	console->setColor(Console::Black,Console::Black);
    system("cls");
	
	console->drawText(position.X, position.Y, description);

	redrawMenu(mode);

	mode = checkKeys(mode);
	
	return mode;
};