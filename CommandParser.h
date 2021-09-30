#pragma once

#include <QObject>
#include <QCommandLineParser>

enum class CommandLineParseResult
{
	ArgParseError,
	CommandNotFoundError,
	KeyNotFoundError,
	PathNotFoundError,

	NoError,
};

struct crypt_info;

class CommandParser : public QObject
{
	Q_OBJECT

public:
	CommandParser(crypt_info* info);
	~CommandParser();

	inline void Process(QCoreApplication& app) { _parser.process(app); }

	std::tuple<CommandLineParseResult, QString> ParseCommandLine();

private:
	void Init();

	QCommandLineParser _parser;
	crypt_info* _info;
};

