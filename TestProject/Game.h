#pragma once
#include "Character.h"
#include <vector>

namespace nc {
	class Game {
	public:
		void run();

		friend class NPC;
		friend class Skill;
		friend class Player;

	protected:
		std::vector<Character*> characters{};

	};

}