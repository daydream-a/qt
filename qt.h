#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt.h"
#include <qlabel.h>
#include <qmessagebox.h>
#include <QTabWidget>
#include <QTabBar>
#include <QString>
#include <QLineEdit>
using namespace std;

class qt : public QMainWindow
{
	Q_OBJECT

public:

	qt(QWidget* parent = Q_NULLPTR);

public slots:
	void onFunc();
	void changeIndex(int index);
	void sendMessage(QLineEdit* line1, QLineEdit* line2, QTextEdit* edit, int i);
	void clearall(vector<QLineEdit*> line1, vector<QLineEdit*> line2, vector<QTextEdit*> showline_all);

private:
	Ui::qtClass ui;
};
