#include "CommandParser.h"

CommandParser::CommandParser(crypt_info* info)
    : _info(info)
{
}

CommandParser::~CommandParser()
{
}

std::tuple<CommandLineParseResult, QString> CommandParser::ParseCommandLine()
{
    return std::tuple<CommandLineParseResult, QString>();
}

void CommandParser::Init()
{
}
