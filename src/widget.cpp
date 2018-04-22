#include "widget.h"
#include "computerTable.h"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>
#include <QLayout>

struct Widget::WidgetPrivate
{
    QSystemTrayIcon * tray;
    QMenu * menu;
    ComputerTable * table;
    QPushButton * button;
    QGridLayout * layout;
};

Widget::Widget(QWidget * _parent)
    : QWidget(_parent),
      data(new WidgetPrivate)
{
    setObjectName("Widget");
    setWindowFlags(Qt::WindowCloseButtonHint);
    setWindowTitle(QString::fromUtf8("汪洋测试用计算机管理系统"));
    data->tray = new QSystemTrayIcon(this);
    data->tray->setIcon(QIcon(":icon"));
    data->tray->setToolTip(QString::fromUtf8("汪洋测试用计算机管理系统"));
    data->tray->hide();

    connect(data->tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotTroyActivated(QSystemTrayIcon::ActivationReason)));

    data->menu = new QMenu(this);
    QAction * action = new QAction(QString::fromUtf8("显示主界面"), this);
    data->menu->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(slotShowAction()));
    action = new QAction(QString::fromUtf8("关闭"), this);
    data->menu->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(slotExitAction()));
    data->tray->setContextMenu(data->menu);

    setWindowIcon(QIcon(":icon"));
    QFile file("./res/qss/styleSheet.css");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
    }

    data->table = new ComputerTable;
    data->table->loadConfig("./data/table/computerTable.xml");

    data->layout = new QGridLayout(this);
    data->layout->addWidget(data->table, 0, 0, 1, 4);

    data->button = new QPushButton(QString::fromUtf8("一键关机"));
    data->button->setObjectName("ComputerTableShutdownButton");
    data->layout->addWidget(data->button, 1, 3, 1, 1);

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
        data->menu->show();
        break;
    case QSystemTrayIcon::DoubleClick:
        show();
        break;
    default:
        break;
    }
}

void Widget::slotShowAction()
{
    show();
}

void Widget::slotExitAction()
{
    QMessageBox box(QMessageBox::Warning, QString::fromUtf8("关闭程序"), QString::fromUtf8("是否关闭计算机监控程序？"), QMessageBox::Yes | QMessageBox::No);
    box.setButtonText(QMessageBox::Yes, QString::fromUtf8("确定"));
    box.setButtonText(QMessageBox::No, QString::fromUtf8("取消"));
    box.setWindowIcon(QIcon(":icon"));
    if (box.exec() == QMessageBox::Yes)
    {
        QApplication * app;
        app->quit();
    }
}
