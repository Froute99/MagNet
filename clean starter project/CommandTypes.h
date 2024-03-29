#pragma once
#include <string>

enum class eCommandTypes
{
	INVALID = 0,
	LevelChangeCommand,


	QuitCommand,
	Count
};


inline eCommandTypes StringToCommand(const std::string& string)
{
	if (string == "QuitCommand")				    return eCommandTypes::QuitCommand;
	if (string == "LevelChangeCommand")				    return eCommandTypes::LevelChangeCommand;
	return eCommandTypes::INVALID;
}

inline std::string CommandToString(eCommandTypes type)
{
	if (type == eCommandTypes::QuitCommand)				        return "QuitCommand";
	if (type == eCommandTypes::LevelChangeCommand)				        return "LevelChangeCommand";

	return "Invalid";
}