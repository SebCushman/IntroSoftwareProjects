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
		void selectItem();
		void pickSkill();
		void generateEnemy();
		bool checkIfDead(Character* character);
		void rewardPlayer();

		friend class NPC;
		friend class Skill;
		friend class Player;

		inline float random() { return rand() / static_cast<float>(RAND_MAX); }

		inline float random(float min, float max) {
			if (min > max) {
				std::swap(min, max);
			}
			return min + ((max - min) * random());
		}
		inline float randomInt(int min, int max) {
			if (min > max) {
				std::swap(min, max);
			}
			return min + ((max - min) * random());
		}

	protected:
		std::vector<Character*> characters{};
		bool isPlayerTurn{ true };
		UI ui;
		Player* player;
		NPC* enemy;


	};

}