#pragma once
#include <string>
#include <vector>

namespace nc
{
	
	class UI
	{
	public:
		static int promptForInt(std::string prompt, int min, int max);
		static bool promptForBoolean(std::string prompt, std::string trueString, std::string falseString);
		static int promptForMenuSelection(std::vector<std::string> options, bool withQuit, std::string quitString);
	};

}