#include "iniRead.h"

#include <QSettings>
#include <QString>

struct IniRead::IniReadPrivate
{
	QSettings * iniRead;
};


IniRead::IniRead(QObject * _prent) :
    QObject(_prent),
    data(new IniReadPrivate)
{
	data->iniRead = nullptr;
}

IniRead::~IniRead()
{

}

void IniRead::loadIni(const QString & _path)
{
	if (data->iniRead == nullptr)
	{
		data->iniRead = new QSettings(_path, QSettings::IniFormat);
	}
	else
	{
		return;
    }
}

QSize IniRead::windowFormSize()
{
    return QSize(data->iniRead->value("/windowFormSize/width").toInt(),
        data->iniRead->value("/windowFormSize/height").toInt());
}

QString IniRead::localIpAddress()
{
    return data->iniRead->value("/localIP/address").toString();
}

QString IniRead::localIpPort()
{
    return data->iniRead->value("/localIP/port").toString();
}

QString IniRead::iosIpAddress()
{
    return data->iniRead->value("/iosIP/address").toString();
}

QString IniRead::iosIpPort()
{
    return data->iniRead->value("/iosIP/port").toString();
}
