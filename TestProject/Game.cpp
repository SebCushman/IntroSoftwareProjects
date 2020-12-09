#include "Game.h"
#include "Items/Item.h"
#include <iostream>

namespace nc {

	void Game::run()
	{
		player = new Player{ 30, 5, 4, 8, 7, .2, { 1, 1 }, "fox thing" };
		

		characters.push_back(player);
		characters.push_back(enemy);

		player->setOwner(this);


		//Skill skill{ .6, 3, 6, 3, false, 40, "test" };
		Skill skillBite{ 1, 2, 5, 1, false, 30, "Bite" };//Wolf and Snake get this
		Skill skillFoxFire1{ .9, 3, 7, 5, true, 20, "Fox Fire, Minor" };
		Skill skillStaticTackle{ 1, 3, 6, 1, true, 20, "Static Tackle" };

		player->currentSkills.push_back(&skillBite);
		player->currentSkills.push_back(&skillFoxFire1);
		player->currentSkills.push_back(&skillStaticTackle);

		Item* item1 = new Item{ 8, 0, "Health Potion" };
		Item* item2 = new Item{ 0, 3, "Skill Charge Potion" };

		player->inventory.push_back(*item1);
		player->inventory.push_back(*item2);

		generateEnemy();
		playGame();

	}

	void Game::playGame()
	{
		bool playerAlive{ true };

		do {
			if (isPlayerTurn) {
				std::cout << "It's your turn! what will you do?" << std::endl;
				takePlayerTurn();
				bool dead = checkIfDead(enemy);
				if (dead) {
					rewardPlayer();
					generateEnemy();
				}
				isPlayerTurn = false;
			}
			else {
				enemy->takeTurn();
				playerAlive = !checkIfDead(player);
				isPlayerTurn = true;
			}
		} while (playerAlive);

		std::cout << "After all your struggles, you have died. At least it was a more interesting way to go than disentary" << std::endl;
	}

	void Game::takePlayerTurn()
	{
		int selection;
		
		selection = ui.promptForMenuSelection({ "Fight", "Inventory" }, false, "");

		if (selection == 1) {
			pickSkill();
		}
		else if (selection == 2) {
			selectItem();
		}

	}

	void Game::selectItem()
	{
		int selection;
		std::vector<std::string> options;
		for (int i = 0; i < player->inventory.size(); i++) {
			std::string option = (i + 1) + ". " + (player->inventory[i].m_name);
			options.push_back(option);
			
		}
		bool confirmed{ false };
		do {
			selection = ui.promptForMenuSelection(options, true, "Back");
			if (selection == 0) {
				confirmed = ui.promptForBoolean("Are you sure you want to go back? y/n: ", "y", "n");
			}
			else {
				confirmed = ui.promptForBoolean("Are you sure you want to use this item? y/n: ", "y", "n");
			}
		} while (!confirmed);
		if (selection == 0) {
			takePlayerTurn();
		}
		else {
			player->inventory[selection - 1].Use(player);
			player->inventory.erase(player->inventory.begin() + selection - 1);
		}
	}

	void Game::pickSkill()
	{
		int selection;
		std::vector<std::string> options;
		for (int i = 0; i < player->currentSkills.size(); i++) {
			if (player->currentSkills[1]->m_currentCharges > 0) {
				std::string option = (i + 1) + ". " + player->currentSkills[i]->m_name;
				options.push_back(option);
			}
		}
		bool confirmed{ false };
		do {
			selection = ui.promptForMenuSelection(options, true, "Back");
			if (selection == 0) {
				confirmed = ui.promptForBoolean("Are you sure you want to go back? y/n: ", "y", "n");
			}
			else {
				confirmed = ui.promptForBoolean("Are you sure you want to use this ability? y/n: ", "y", "n");
			}
		} while (!confirmed);
		if (selection == 0) {
			takePlayerTurn();
		}
		else {
			player->attack(enemy, player->currentSkills[selection - 1]);
		}
	}

	void Game::generateEnemy()
	{
		int typeNum = std::rand() % 3;

		if (typeNum == 0)
		{
			enemy = new NPC{ 20, 6, 7, 5, 4, .1, { 1, 1 }, "Raven", NPC::eType::Raven };

			Skill skillPeck{ 1, 3, 6, 1, false, 30, "Peck" };

			enemy->currentSkills.push_back(&skillPeck);
		}
		else if (typeNum == 1) {
			enemy = new NPC{ 20, 6, 7, 5, 4, .1, { 1, 1 }, "Wolf", NPC::eType::Wolf };

			Skill skillFlameTackle{ 1, 3, 6, 1, true, 20, "Flame Tackle" };
			Skill skillFireBlastMinor{ .8, 3, 7, 3, true, 15, "Fire Blast, Minor" };

			Skill skillBite{ 1, 2, 5, 1, false, 30, "Bite" };

			enemy->currentSkills.push_back(&skillBite);
			enemy->currentSkills.push_back(&skillFlameTackle);
			enemy->currentSkills.push_back(&skillFireBlastMinor);
		}
		else if (typeNum == 2) {
			enemy = new NPC{ 20, 6, 7, 5, 4, .1, { 1, 1 }, "Snake", NPC::eType::Snake };

			Skill skillBite{ 1, 2, 5, 1, false, 30, "Bite" };
			Skill skillPoisonBite{ 1, 3, 5, 1, true, 20, "Poison Bite" };
			Skill skillToxicSpit{ .9, 2, 5, 5, true, 15, "Toxic Spit" };


			enemy->currentSkills.push_back(&skillBite);
			enemy->currentSkills.push_back(&skillPoisonBite);
			enemy->currentSkills.push_back(&skillToxicSpit);
		}
		enemy->setOwner(this);
		
	}

	bool Game::checkIfDead(Character* character)
	{
		bool isDead{ false };
		if(character->currentHP <= 0) {
			isDead = true;
		}

		return isDead;
	}

	void Game::rewardPlayer()
	{
		player->currentHP += 10;
		if (player->currentHP > player->maxHP) {
			player->currentHP = player->maxHP;
		}
		Item* item1 = new Item{ 8, 0, "Health Potion" };
		Item* item2 = new Item{ 0, 3, "Skill Charge Potion" };

		int item = std::rand() % 2;

		if (item == 0) {
			player->inventory.push_back(*item1);
			std::cout << "You found a Health Potion!" << std::endl;
		}
		else if (item == 1) {
			player->inventory.push_back(*item2);
			std::cout << "You found a Skill Charge Potion!" << std::endl;
		}
		
	}

}


