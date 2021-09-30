#include "CommandParser.h"
#include "QtCryptTool.h"

CommandParser::CommandParser(crypt_info* info)
    : _info(info)
{
}

CommandParser::~CommandParser()
{
}

std::tuple<CommandLineParseResult, QString> CommandParser::ParseCommandLine()
{
    if (_parser.parse(QCoreApplication::arguments()))
    {
        return std::make_tuple(CommandLineParseResult::ArgParseError, "Cannot parse argument. Please check your input.");
    }

    if (_parser.isSet("key"))
    {
        _info->key = _parser.value("key").toInt();
    }
    else
    {
        return std::make_tuple(CommandLineParseResult::KeyNotFoundError, "Cannot find crypt key.");
    }

    if (_parser.isSet("path"))
    {
        _info->filePath = _parser.value("path");
    }
    else
    {
        return std::make_tuple(CommandLineParseResult::PathNotFoundError, "Cannot find file path.");
    }

    if (_parser.isSet("overwrite"))
    {
        _info->isOverwriteMode = true;
    }

    if (_parser.isSet("encrypt"))
    {
        _info->type = CryptType::Encrypt;
        return std::make_tuple(CommandLineParseResult::NoError, "");
    }
    else if (_parser.isSet("decrypt"))
    {
        _info->type = CryptType::Decrypt;
        return std::make_tuple(CommandLineParseResult::NoError, "");
    }
    else
    {
        return std::make_tuple(CommandLineParseResult::CommandNotFoundError, "Cannot find work command(encrypt, decrypt). Please check your input.");
    }
}

void CommandParser::Init()
{
    _parser.setApplicationDescription("QtCryptTool");
    _parser.addHelpOption();

    // --encrypt, --decrypt
    QCommandLineOption encryptOption({ "encrypt", "e" }, "설명");
    QCommandLineOption decryptOption({ "decrypt", "d" }, "설명");

    // --key, --path
    QCommandLineOption keyOption({ "key", "k" }, "설명");
    QCommandLineOption pathOption({ "path", "p" }, "설명");

    // --overwrite (optional)
    QCommandLineOption overwriteOption({ "overwrite", "o" }, "설명");

    _parser.addOptions({
        encryptOption,
        decryptOption,
        keyOption,
        pathOption,
    });
}
