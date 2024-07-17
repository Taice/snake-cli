#include "game.hpp"
#include "Board.hpp"
#include "delay.hpp"
#include "input.hpp"
#include "ncurses.h"
#include <memory>
#include <unistd.h>

void start_game(char binds[4])
{

    butt pos1 = {0, 0, 0};
    direction dir = RIGHT;

    std::shared_ptr<Board> board = std::make_shared<Board>(pos1);
    while (1)
    {
        clear();
        board->render();
        refresh();
        usleep(calc_delay(board->get_level()));
        if (board->move(handle_input(&dir, binds)) == 'F')
        {
            break;
        }
    }
}
