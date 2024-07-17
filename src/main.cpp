#include "Menu.hpp"
#include <locale.h>
#include <memory>
#include <ncurses.h>

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    nodelay(stdscr, true);
	std::shared_ptr<Menu> Game = std::make_shared<Menu>();
    endwin();
}
