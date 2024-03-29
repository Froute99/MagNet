#include "RegisterCommands.h"
#include "engine/State.h"
#include "engine/CommandBuilder.h"
#include "QuitCommand.h"
#include "LevelChangeCommand.h"

void RegisterCommands()
{
	State::AddCommandBuilder(eCommandTypes::QuitCommand,
		new CommandTBuilder<QuitCommand>);
	State::AddCommandBuilder(eCommandTypes::LevelChangeCommand,
		new CommandTBuilder<LevelChangeCommand>);
}

void UnregisterCommands()
{
	State::RemoveCommandBuilder(eCommandTypes::LevelChangeCommand);
	State::RemoveCommandBuilder(eCommandTypes::QuitCommand);
}
