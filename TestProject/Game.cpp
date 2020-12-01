#include "Game.h"
#include "Player.h"
#include "NPC.h"
#include <iostream>

void nc::Game::run()
{
	Player player{ 30, 5, 4, 8, 7, .2, 1, "fred" };
	NPC enemy{ 20, 6, 7, 5, 4, .1, 1, "bob" };

	characters.push_back(&player);
	characters.push_back(&enemy);

	player.setOwner(this);
	enemy.setOwner(this);

	Skill skill{ .6, 3, 6, 3, false, 40 };

	std::cout << enemy.currentHP << std::endl;
	player.attack(&enemy, skill);
	std::cout << enemy.currentHP << std::endl;
}
