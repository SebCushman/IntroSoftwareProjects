#pragma once
#include "Character.h"

namespace nc {



	class NPC : public Character {
	public:
		enum class eType
		{
			
			Raven,
			Wolf,
			Snake
		};

		NPC(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, float _evasion, Vector2 _position, std::string _name, eType _type)
			: Character(_maxHP, _mDefense, _mAttack, _pDefense, _pAttack, _evasion, _position, _name) {
			type = _type;
		}

		void takeTurn();
		void move();
				
		Vector2 playerInRange(Skill* skill);
		bool playerInSight();

		friend class Game;
		friend class UI;


	protected:

		eType type;

		//int xpValue{ 0 };
		//Vector2 attackDelta{ 0, 0 };
		
	};
}