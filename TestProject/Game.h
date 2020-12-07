#pragma once
#include "Player.h"
#include "NPC.h"
#include "UI.h"

namespace nc {
	class Game {
	public:
		void run();
		void playGame();
		void takePlayerTurn();

		friend class NPC;
		friend class Skill;
		friend class Player;

	protected:
		std::vector<Character*> characters{};
		bool isPlayerTurn{ true };
		UI ui;
		Player* player;
		NPC* enemy;


	};

}