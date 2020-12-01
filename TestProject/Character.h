#pragma once
#include "Skill.h"
#include "Game.h"
#include <vector>
#include <string>

namespace nc {

	class Character {
	public:
		Character(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, float _evasion, int _position, std::string _name) {
			maxHP = _maxHP;
			currentHP = maxHP;
			mDefense = _mDefense;
			mAttack = _mAttack;
			pAttack = _pAttack;
			pDefense = _pDefense;
			evasion = _evasion;
			position = _position;
			name = _name;

		}

		friend class Items;
		friend class Item;
		friend class Game;

		void attack(Character* target, Attack skill);

		void setOwner(Game* game);

		inline float random() { return rand() / static_cast<float>(RAND_MAX); }

		inline float random(float min, float max) {
			if (min > max) {
				std::swap(min, max);
			}
			return min + ((max - min) * random());
		}

	protected:
		int maxHP;
		int currentHP;
		int mDefense;
		int mAttack;
		int pDefense;
		int pAttack;
		float evasion;
		int position;
		std::string name;
		std::vector<Skill> allSkills{};
		std::vector<Skill> currentSkills{};
		int level;
		int xp;
		std::vector<int> xpThresh{ 0, 5, 12, 25, 40, 60 };
		Game* owner{ nullptr };

	};
}