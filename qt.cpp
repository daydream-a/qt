#include "qt.h"
#include "test.h"
using namespace std;

qt::qt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.menuBar->hide();
	ui.mainToolBar->hide();
	ui.tabWidget->tabBar()->hide();
	this->setFixedSize(this->width(), this->height());
	vector<QPushButton*> change_btn_all = { ui.changebtn_1,ui.changebtn_2,ui.changebtn_3,ui.changebtn_4,ui.changebtn_5,ui.changebtn_6 };
	vector<QPushButton*> return_btn_all = { ui.returnbtn_1,ui.returnbtn_2,ui.returnbtn_3,ui.returnbtn_4,ui.returnbtn_5,ui.returnbtn_6 };
	vector<QLineEdit*> line1 = { ui.func1_line1,ui.func2_line1,ui.func3_line1,ui.func4_line1,ui.func5_line1,ui.func6_line1 };
	vector<QLineEdit*> line2 = { ui.func1_line2,ui.func2_line2,ui.func3_line2,ui.func4_line4,ui.func5_line2,ui.func6_line2 };
	vector<QPushButton*> sendBtn = { ui.func1_send,ui.func2_send,ui.func3_send,ui.func4_send,ui.func5_send,ui.func6_send };
	vector<QTextEdit*> showline_all = { ui.func1_re,ui.func2_re,ui.func3_re,ui.func4_re,ui.func5_re,ui.func6_re };

	for (auto i : showline_all)
	{
		i->setReadOnly(true);
	}
	ui.func3_line1->setReadOnly(true);
	ui.func3_line2->setReadOnly(true);
	ui.func6_line1->setReadOnly(true);

	//connect(ui.pushButton, &QPushButton::clicked, this, &qt::onFunc);
	int j = 0;
	for (auto i : change_btn_all)
	{
		j++;
		connect(i, &QPushButton::clicked, this, [=]()
			{
				qt::changeIndex(j);
			});
		connect(i, &QPushButton::clicked, this, [=]()
			{
				qt::clearall(line1, line2, showline_all);
			});
	}

	for (auto i : return_btn_all)
	{
		connect(i, &QPushButton::clicked, this, [=]()
			{
				qt::changeIndex(0);
			});
	}
	j = 0;
	for (auto i : sendBtn)
	{
		connect(i, &QPushButton::clicked, this, [=]()
			{
				qt::sendMessage(line1[j], line2[j], showline_all[j], j + 1);
			});
		j++;
	}
	//connect(ui.returnbtn_1,&QPushButton::clicked,this, [=]()
	//{
	//        qt::changeIndex(0);
	//});
	//connect(ui.changebtn_1,&QPushButton::clicked,this,[=]()
	//{
	//        qt::changeIndex(1);
	//});
}

void qt::onFunc()
{
	QPushButton* pbtn = (QPushButton*)sender();
	QMessageBox::about(this, "tips", pbtn->text());
}

void qt::changeIndex(int index)
{
	ui.tabWidget->setCurrentIndex(index);
}

void qt::sendMessage(QLineEdit* line1, QLineEdit* line2, QTextEdit* edit, int i)
{
	int adress = line1->text().toInt();
	int num = line2->text().toInt();
	int flag = check(i, adress, num);
	QString show;
	if (flag == 1)
	{
		show = send(adress, i, num);
	}
	else
	{
		show = "Register out of range!!!\n";
	}
	edit->setText(show);
}

void qt::clearall(vector<QLineEdit*> line1, vector<QLineEdit*> line2, vector<QTextEdit*> showline_all)
{
	for (auto i : line1)
		i->setText("");
	for (auto i : line2)
		i->setText("");
	for (auto i : showline_all)
		i->setText("");
	ui.func3_line1->setText("787");
	ui.func3_line2->setText("1");
	ui.func6_line1->setText("787");
}