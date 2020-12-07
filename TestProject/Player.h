#pragma once
#include "Character.h"
#include "Items/Item.h"
#include <vector>

namespace nc {
	class Player : public Character {
	public:
		Player(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, float _evasion, Vector2 _position, std::string _name)
			: Character(_maxHP, _mDefense, _mAttack, _pDefense, _pAttack, _evasion, _position, _name) {
		}

		void levelUp();

		friend Items;
		friend Item;
		friend class Game;
		friend class UI;


	protected:

		std::vector<Item> inventory{};
		int money{ 0 };
	};
}