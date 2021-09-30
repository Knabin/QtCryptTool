#pragma once

#include <QObject>

enum class CryptType {
	Crypt,
	Decrypt,
	None,
};

struct crypt_info {
	QString filePath;
	CryptType type;
	int key;
	bool isOverwriteMode;

	crypt_info()
		: filePath(QString()), type(CryptType::None), key(-1), isOverwriteMode(false)
	{

	}
};

class QtCryptTool : public QObject
{
};

