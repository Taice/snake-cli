#pragma once
#include "direction.hpp"
#include <vector>

struct butt
{
    int y;
    int x;
    int counter;
};

class Board
{
  private:
    int grid[25][25] = {0};

	int length = 1;
	
    std::vector<butt> butts;

    void update_vector(butt new_loc);
	bool make_food();
	void you_won();

  public:
    Board(butt start);
    char move(direction side);
    void render();
	int get_level();
};
