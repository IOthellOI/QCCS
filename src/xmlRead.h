#pragma once
#ifndef XMLREAD_H
#define XMLREAD_H

#include <QObject>
#include <QDomDocument>

class XmlRead : public QObject
{
	Q_OBJECT
public:
	explicit XmlRead();
	virtual ~XmlRead();

public:
	void loadFile(const QString & _path);
	QDomElement rootElement();

private:
	struct XmlReadPrivate;
	XmlReadPrivate * data;
};

#endif // !XMLREAD_H
