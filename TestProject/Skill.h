#pragma once
#include <string>

namespace nc {
	class Skill {
	public:
		Skill(float accuracy, int minDam, int maxDam, int range, bool isMagic, int maxCharges, std::string name) : m_accuracy{ accuracy }, m_minDam{ minDam }, m_maxDam{ maxDam }, m_range{ range }, m_isMagic{ isMagic }, m_maxCharges{ maxCharges }, m_currentCharges{ maxCharges }, m_name{ name }{}

		friend class Items;
		friend class Item;
		friend class UI;
		friend class Character;
		friend class Game;

	protected:
		int m_currentCharges{ 0 };
		int m_maxCharges{ 30 };
		float m_accuracy{ 1 };
		int m_minDam{ 1 };
		int m_maxDam{ 3 };
		int m_range{ 1 };
		bool m_isMagic{ false };
		std::string m_name;
	};
}