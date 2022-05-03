#include "qt.h"

qt::qt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ui.menuBar->hide();
	//ui.mainToolBar->hide();
	ui.tabWidget->tabBar()->hide();

	auto change_btn_all = { ui.changebtn_1,ui.changebtn_2,ui.changebtn_3,ui.changebtn_4,ui.changebtn_5,ui.changebtn_6 };
	auto return_btn_all = { ui.returnbtn_1,ui.returnbtn_2,ui.returnbtn_3,ui.returnbtn_4,ui.returnbtn_5,ui.returnbtn_6 };

	connect(ui.pushButton, &QPushButton::clicked, this, &qt::onFunc);
	int j = 0;
	for (auto i : change_btn_all)
	{
		j++;
		connect(i, &QPushButton::clicked, this, [=]()
			{
				qt::changeIndex(j);
			});
	}

	for (auto i : return_btn_all)
	{
		connect(i, &QPushButton::clicked, this, [=]()
			{
				qt::changeIndex(0);
			});
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