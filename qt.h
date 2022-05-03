#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt.h"
#include <qlabel.h>
#include <qmessagebox.h>
#include <QTabWidget>
#include <QTabBar>

class qt : public QMainWindow
{
	Q_OBJECT

public:
	qt(QWidget* parent = Q_NULLPTR);

public slots:
	void onFunc();
	void changeIndex(int index);

private:
	Ui::qtClass ui;
};
