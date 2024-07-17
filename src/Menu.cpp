#include "Menu.hpp"
#include "game.hpp"
#include <ncurses.h>

Menu::Menu()
{
    clear();
    printw("╔════════════MENU════════════╗\n");
    printw("║                            ║\n");
    printw("║ k : open the keybinds menu ║\n");
    printw("║                            ║\n");
    printw("║ e : enter the game         ║\n");
    printw("║                            ║\n");
    printw("╚════════════════════════════╝\n");
    timeout(-1);
    char ch;
    ch = getch();

    switch (ch)
    {
    case 'k':
        open_keybinds();
        break;
    case 'e':
        run_game();
        break;
    }
}

void Menu::open_keybinds()
{
    while (1)
    {
        render_binds();
        char ch = getch();

        if (ch == binds[2])
        {
            highlight = highlight == 0 ? highlight : highlight - 1;
        }
        else if (ch == binds[3])
        {

            highlight = highlight == 3 ? highlight : highlight + 1;
        }
        else if (ch == 27)
        {
            run_game();
            break;
        }
        else
        {
            binds[highlight] = ch;
        }
    }
}

void Menu::render_binds()
{
    clear();
    printw("╔═══BINDS═══╗\n");
    {
        printw("║ ");
        if (highlight == 0)
        {
            printw("\u2588");
        }
        else
        {
            printw("%c", binds[0]);
        }
        printw(" : left  ║\n");
        printw("║ ");
        if (highlight == 1)
        {
            printw("\u2588");
        }
        else
        {
            printw("%c", binds[1]);
        }
        printw(" : right ║\n");
        printw("║ ");
        if (highlight == 2)
        {
            printw("\u2588");
        }
        else
        {
            printw("%c", binds[2]);
        }
        printw(" : up    ║\n");
        printw("║ ");
        if (highlight == 3)
        {
            printw("\u2588");
        }
        else
        {
            printw("%c", binds[3]);
        }
        printw(" : down  ║\n");
    }
    printw("╚═══════════╝\n");
}

void Menu::run_game() { start_game(binds); }
