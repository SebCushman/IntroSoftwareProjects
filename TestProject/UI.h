#pragma once
#include <string>

namespace nc
{
	static class UI
	{
	public:
		static int promptForInt(std::string prompt, int min, int max);
		static bool promptForBoolean(std::string prompt, std::string trueString, std::string falseString);
		static int promptForMenuSelection(std::string options[], bool withQuit, std::string quitString);
	};

}