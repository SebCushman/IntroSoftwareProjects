#pragma once
#include "Character.h"
#include <vector>

namespace nc {
	class Game {
	public:
		void run();
		void playGame();

		friend class NPC;
		friend class Player;

	protected:
		std::vector<Character*> characters{};
		bool isPlayerTurn{ true };

	};

}