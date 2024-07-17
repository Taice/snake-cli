#include "Board.hpp"
#include "position.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <vector>

Board::Board(butt start)
{
    butts.emplace_back(start);
    length = 5;
    if (!make_food())
    {
        usleep(5000000);
    }
}

char Board::move(direction side)
{
    switch (side)
    {
    case UP:
    {
        butt new_loc = {butts[0].y - 1, butts[0].x, 0};
        if (new_loc.y < 0 || grid[butts.at(0).y - 1][butts.at(0).x] > 0)
        {
            return 'F';
        }
        else
        {
            update_vector(new_loc);
        }
        break;
    }
    case DOWN:
    {
        butt new_loc = {butts[0].y + 1, butts[0].x, 0};
        if (new_loc.y > 25 || grid[butts.at(0).y + 1][butts.at(0).x] > 0)
        {
            return 'F';
        }
        else
        {
            update_vector(new_loc);
        }
        break;
    }
    case LEFT:
    {
        butt new_loc = {butts[0].y, butts[0].x - 1, 0};
        if (new_loc.x < 0 || grid[butts.at(0).y][butts.at(0).x - 1] > 0)
        {
            return 'F';
        }
        else
        {
            update_vector(new_loc);
        }
        break;
    }
    case RIGHT:
    {
        butt new_loc = {butts[0].y, butts[0].x + 1, 0};
        if (new_loc.x > 25 || grid[butts.at(0).y][butts.at(0).x + 1] > 0)
        {
            return 'F';
        }
        else
        {
            update_vector(new_loc);
        }
        break;
    }
    }
    return 'P';
}

void Board::update_vector(butt new_loc)
{
    bool ate_fruit = grid[new_loc.y][new_loc.x] == -1;
    if (ate_fruit)
    {
        butt old = butts[0];
        butts.emplace_back(old);
        this->length++;
        if (make_food() == false)
        {
            you_won();
            sleep(5);
        }
    }
    else
    {
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                }
            }
        }
        int items[2] = {0};
        for (int i = 1; i < butts.size(); i++)
        {
            if (butts[i].counter > items[1])
            {
                items[1] = butts[i].counter;
                items[0] = i;
            }
        }
        butts[items[0]] = butts[0];
    }
    butts[0] = new_loc;
    for (int i = 0; i < butts.size(); i++)
    {
        grid[butts[i].y][butts[i].x] = 1;
        butts[i].counter++;
    }
}

void Board::render()
{
    printw("╔══════════════════════SNAKEY══════════════════════╗\n");
    for (int i = 0; i < 25; i++)
    {
        printw("║");
        for (int j = 0; j < 25; j++)
        {
            printw(
                (grid[i][j] == 0)
                    ? " ."
                    : ((grid[i][j] == -1) ? " \u2610" : "\u2588\u2588"));
        }
        printw("║\n");
    }
    printw("╚══════════════════════════════════════════════════╝");
}

int Board::get_level() { return (int)(length / 5) + 1; }

bool Board::make_food()
{
    int length = 0;
    pos choices[625];
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (grid[i][j] == 0)
            {
                choices[length] = {i, j};
                length++;
            }
        }
    }
    if (length == 0)
    {
        return false;
    }
    srand(time(0));

    int i = rand() % length;
    grid[choices[i].y][choices[i].x] = -1;

    return true;
}

void Board::you_won()
{
    clear();
    printw("╔══════════════════════SNAKEY══════════════════════╗\n");
    printw("║                   wow you won.                   ║\n");
    printw("╚══════════════════════════════════════════════════╝\n");
}
