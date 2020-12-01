#pragma once
#include "Character.h"

namespace nc {
	class Player : public Character {
	public:
		Player(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, int _evasion, int _position, std::string _name)
			: Character(_maxHP, _mDefense, _mAttack, _pDefense, _pAttack, _evasion, _position, _name) {
		}

		void levelUp();



	protected:

		std::vector<class Item> inventory{};
		int money{ 0 };
	};
}