#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt.h"
#include <qlabel.h>
#include <qmessagebox.h>
#include <QTabWidget>
#include <QTabBar>
#include <QString>
#include <QLineEdit>


class qt : public QMainWindow
{
	Q_OBJECT

public:
	qt(QWidget* parent = Q_NULLPTR);

public slots:
	void onFunc();
	void changeIndex(int index);
	void qt::sendMessage(QLineEdit* line1, QLineEdit* line2, QTextEdit* edit, int i);

private:
	Ui::qtClass ui;
};
