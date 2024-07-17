#pragma once

class Menu 
{
private:
    char binds[4] = {
        'h',
        'l',
        'k',
        'j',
    };
	char highlight = 0;
	void open_keybinds();
	void run_game();
	void render_binds();
public:
	Menu();
};
