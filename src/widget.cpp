#include "widget.h"
#include <QApplication>

struct Widget::WidgetPrivate
{
    QSystemTrayIcon * tray;
};

Widget::Widget(QWidget * _parent)
    : QWidget(_parent),
      data(new WidgetPrivate)
{
    setObjectName("LoginForm");
    setWindowFlags(Qt::WindowCloseButtonHint);
    data->tray = new QSystemTrayIcon(this);
    data->tray->setIcon(QIcon(":icon"));
    data->tray->setToolTip("汪洋测试用计算机管理系统");
    data->tray->hide();

    connect(data->tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotTroyActivated(QSystemTrayIcon::ActivationReason)));
}

Widget::~Widget()
{
    delete data;
}

void Widget::closeEvent(QCloseEvent *_ev)
{
    _ev->ignore();
    hide();
    data->tray->show();
}

void Widget::slotTroyActivated(QSystemTrayIcon::ActivationReason _reason)
{
    switch (_reason) {
    case QSystemTrayIcon::Trigger:

        break;
    case QSystemTrayIcon::DoubleClick:
        show();
        break;
    default:
        break;
    }
}
