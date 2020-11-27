#pragma once
#include "Character.h"

namespace nc {
	class NPC : public Character {
	public:
		NPC(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, int _evasion, int _position, std::string _name, std::string _tag) 
			: Character(_maxHP, _mDefense, _mAttack, _pDefense, _pAttack, _evasion, _position, _name) {	tag = _tag; }

		void takeTurn();
		void move();



	protected:

		std::string tag;
	};
}