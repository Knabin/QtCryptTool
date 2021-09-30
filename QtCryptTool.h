#pragma once

#include <QObject>

enum class CryptType {
	Encrypt,
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
	Q_OBJECT

public:
	QtCryptTool(QObject* parent = Q_NULLPTR);
	~QtCryptTool();

	void Start(const crypt_info& cryptInfo);
};

