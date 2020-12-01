#include "NPC.h"

void nc::NPC::takeTurn()
{
	if (playerInSight) {
		std::vector<Skill> skills;
		std::vector<int> deltas;
		for (Skill skill : currentSkills) {
			int delta = playerInRange(skill);
			if (delta != 0) {
				deltas.push_back(delta);
				skills.push_back(skill);
			}
		}
		if (skills.size() > 0) {
			int skill = random(0, skills.size() - 1);
			//rotate enemy sprite to face player's direction
			//play the appropriate skill animation skills[skill].animation
			attack(owner->player, skills.at(skill));
		}
	}
}

void nc::NPC::move()
{
	//pick a direction, towards the player if they're near enough, or a random direction, and adjust the position of the NPC
}

int nc::NPC::playerInRange(Skill skill)
{
	int delta = 0;
	//check 8 directions up to the range of the passed in skill
	//if player detected, returns an int representing either the direction or directional delta, else it returns 0
	//I'll need to work with sage on getting detection in directions working in a 1D array
	
	return delta;
}

bool nc::NPC::playerInSight()
{
	bool inSight = false;

	//work with sage on detecting distance in his 1D array

	return inSight;
}
