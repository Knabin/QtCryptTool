#include <QtCore/QCoreApplication>

#include "QtCryptTool.h"
#include "CommandParser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("QtCryptTool");

    QtCryptTool tool;
    auto info = crypt_info();

    CommandParser parser(&info);

    return a.exec();
}

