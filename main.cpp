#include <QtCore/QCoreApplication>

#include <QDebug>

#include "QtCryptTool.h"
#include "CommandParser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("QtCryptTool");

    QtCryptTool tool;
    auto info = crypt_info();

    CommandParser parser(&info);
    parser.Process(a);
    auto res = parser.ParseCommandLine();

    switch (std::get<0>(res))
    {
    case CommandLineParseResult::ArgParseError:
    case CommandLineParseResult::CommandNotFoundError:
    case CommandLineParseResult::KeyNotFoundError:
    case CommandLineParseResult::PathNotFoundError:
        qInfo() << "[Error]" << std::get<1>(res);
        break;

    case CommandLineParseResult::NoError:
        tool.Start(info);
        break;
    }

    return 0;
    //return a.exec();
}

