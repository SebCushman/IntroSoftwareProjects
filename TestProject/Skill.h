#pragma once
#include "pch.h"

namespace nc {
	class Attack {
	public:
		Attack(float accuracy, int minDam, int maxDam, bool isMagic) : m_accuracy{accuracy}, m_minDam { minDam }, m_maxDam{ maxDam }, m_isMagic{ isMagic }{}

		friend class Character;

	protected:
		float m_accuracy{ 1 };
		int m_minDam{ 1 };
		int m_maxDam{ 3 };
		bool m_isMagic{ false };
	};

	class Skill : public Attack {
	public:
		Skill(float accuracy, int minDam, int maxDam, bool isMagic, int maxCharges) : Attack(accuracy, minDam, maxDam, isMagic), m_maxCharges{ maxCharges }, m_currentCharges{maxCharges}{}

	protected:
		int m_currentCharges{ 0 };
		int m_maxCharges{ 30 };
	};
}