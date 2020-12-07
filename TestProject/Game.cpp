#include "Game.h"
#include "Items/Item.h"
#include <iostream>

void nc::Game::run()
{
	player = new Player{ 30, 5, 4, 8, 7, .2, { 1, 1 }, "fox thing" };
	enemy = new NPC{ 20, 6, 7, 5, 4, .1, { 1, 1 }, "a bat?"};

	characters.push_back(player);
	characters.push_back(enemy);

	player->setOwner(this);
	enemy->setOwner(this);

	//Skill skill{ .6, 3, 6, 3, false, 40, "test" };
	Skill skillBite{ 1, 2, 5, 1, false, 30, "Bite" };//Wolf and Snake get this
	Skill skillFoxFire1{ .9, 3, 7, 5, true, 20, "Fox Fire, Minor" };
	Skill skillStaticTackle{ 1, 3, 6, 1, true, 20, "Static Tackle" };
	
	//Raven skills
	Skill skillPeck{ 1, 3, 6, 1, false, 30, "Peck" };

	//Wolf skills
	Skill skillFlameTackle{ 1, 3, 6, 1, true, 20, "Flame Tackle" };
	Skill skillFireBlastMinor{.8, 3, 7, 3, true, 15, "Fire Blast, Minor"};

	//Snake skills
	Skill skillPoisonBite{1, 3, 5, 1, true, 20, "Poison Bite"};
	Skill skillToxicSpit{ .9, 2, 5, 5, true, 15, "Toxic Spit" };
	
	player->currentSkills.push_back(&skillBite);
	player->currentSkills.push_back(&skillFoxFire1);
	player->currentSkills.push_back(&skillStaticTackle);

	/*if (enemy->eType == Raven) {
		enemy->currentSkills.push_back(&skillPeck);
	}
	else if (enemy->eType == Wolf) {
		enemy->currentSkills.push_back(&skillBite);
		enemy->currentSkills.push_back(&skillFlameTackle);
		enemy->currentSkills.push_back(&skillFireBlastMinor);
	}
	else if (enemy->eType == Snake) {
		enemy->currentSkills.push_back(&skillBite);
		enemy->currentSkills.push_back(&skillPoisonBite);
		enemy->currentSkills.push_back(&skillToxicSpit);
	}*/

	//Item healing(5, 0, 0, 25);
	//Item healing2(0, 5, 0, 25);

	//std::cout << enemy->currentHP << std::endl;
	//player->attack(enemy, &skill);
	//std::cout << enemy->currentHP << std::endl;
	//healing.Use(enemy);
	//std::cout << enemy->currentHP << std::endl;

	playGame();

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
		options.push_back(option);
	}
	bool confirmed{ false };
	int selection;
	do {
		selection = ui.promptForMenuSelection(options, false, "");
		confirmed = ui.promptForBoolean("Are you sure you want to use this ability? yes/no: ", "yes", "no");
	} while (!confirmed);
	player->attack(enemy, player->currentSkills[selection - 1]);
}


