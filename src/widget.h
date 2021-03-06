﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QApplication>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget * _parent = 0);
    ~Widget();

private:
    void closeEvent(QCloseEvent * _ev);

private slots:
    void slotTroyActivated(QSystemTrayIcon::ActivationReason _reason);
    void slotShowAction();
    void slotExitAction();

private:
    struct WidgetPrivate;
    WidgetPrivate * data;
};

#endif // WIDGET_H
