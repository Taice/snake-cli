#include "input.hpp"
#include "ncurses.h"

direction handle_input(direction *current_dir, char binds[4])
{
    timeout(0);
    char ch = getch();
    if (ch == ERR)
    {
        return *current_dir;
    }
    if (ch == binds[0])
    {
        if (*current_dir != RIGHT)
        {
            *current_dir = LEFT;
            return LEFT;
        }
        return *current_dir;
    }
    else if (ch == binds[3])
    {
        if (*current_dir != UP)
        {
            *current_dir = DOWN;
            return DOWN;
        }
        return *current_dir;
    }
    else if (ch == binds[2])
    {
        if (*current_dir != DOWN)
        {
            *current_dir = UP;
            return UP;
        }
        return *current_dir;
    }
    if (ch == binds[1])
    {
        if (*current_dir != LEFT)
        {
            *current_dir = RIGHT;
            return RIGHT;
        }
        return *current_dir;
    }
    else
    {
        return *current_dir;
    }
}
