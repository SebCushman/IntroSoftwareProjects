#include "Game.h"
#include "Items/Item.h"
#include <iostream>

void nc::Game::run()
{
	player = new Player{ 30, 5, 4, 8, 7, .2, 1, "fox thing" };
	enemy = new NPC{ 20, 6, 7, 5, 4, .1, 1, "a bat?" };

	characters.push_back(player);
	characters.push_back(enemy);

	player->setOwner(this);
	enemy->setOwner(this);

	Skill skill{ .6, 3, 6, 3, false, 40, "test" };
	player->currentSkills.push_back(&skill);

	Item healing(5, 0, 0, 25);
	Item healing(0, 5, 0, 25);

	std::cout << enemy->currentHP << std::endl;
	player->attack(enemy, &skill);
	std::cout << enemy->currentHP << std::endl;
	healing.Use(enemy);
	std::cout << enemy->currentHP << std::endl;



}

void nc::Game::playGame()
{
	bool playerAlive{ true };

	do {
		if (isPlayerTurn) {
			std::cout << "It's your turn! what will you do?" << std::endl;
			takePlayerTurn();
			!isPlayerTurn;
		}
		else {
			!isPlayerTurn;
		}
	} while (playerAlive);
}

void nc::Game::takePlayerTurn()
{
	std::vector<std::string> options;
	for (int i = 0; i < player->currentSkills.size(); i++) {
		std::string option = (i + 1) + ". " + player->currentSkills[i]->m_name;
	}
	bool confirmed{ false };
	int selection;
	do {
		selection = ui.promptForMenuSelection(options, false, "");
		confirmed = ui.promptForBoolean("Are you sure you want to use this ability? ", "yes", "no");
	} while (!confirmed);
	player->attack(characters[1], player->currentSkills[selection - 1]);
}


