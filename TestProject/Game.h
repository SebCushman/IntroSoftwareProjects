#pragma once
#include "Player.h"
#include "NPC.h"
#include <vector>

namespace nc {
	class Game {
	public:
		void run();
		void playGame(Player* player, NPC* enemy);
		void takePlayerTurn(Player* player);

		friend class NPC;
		friend class Player;


	protected:
		std::vector<Character*> characters{};
		bool isPlayerTurn{ true };

	};

}