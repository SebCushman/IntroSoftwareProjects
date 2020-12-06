#include "Game.h"
#include "Player.h"
#include "NPC.h"
#include "Items/Item.h"
#include <iostream>

void nc::Game::run()
{
	Player player{ 30, 5, 4, 8, 7, .2, 1, "fox thing" };
	NPC enemy{ 20, 6, 7, 5, 4, .1, 1, "a bat?" };

	characters.push_back(&player);
	characters.push_back(&enemy);

	player.setOwner(this);
	enemy.setOwner(this);

	Skill skill{ .6, 3, 6, 3, false, 40 };
	player.currentSkills.push_back(&skill);

	Item healing(5, 0, 0, 25);
	Item healing(0, 5, 0, 25);

	std::cout << enemy.currentHP << std::endl;
	player.attack(&enemy, &skill);
	std::cout << enemy.currentHP << std::endl;
	healing.Use(&enemy);
	std::cout << enemy.currentHP << std::endl;



}

void nc::Game::playGame(Player* player, NPC* enemy)
{
	bool playerAlive{ true };

	do {
		if (isPlayerTurn) {
			std::cout << "It's your turn! what will you do?" << std::endl;
			takePlayerTurn(player);
		}
		else {

		}
	} while (playerAlive);
}

void nc::Game::takePlayerTurn(Player* player)
{
	UI.promptForMenuSelection
}


