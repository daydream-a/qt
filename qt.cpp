#include "qt.h"

qt::qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.tabWidget->tabBar()->hide();

    
    connect(ui.pushButton, &QPushButton::clicked, this, &qt::onFunc);
    connect(ui.returnbtn_1,&QPushButton::clicked,this, [=]()
    {
            qt::changeIndex(0);
    });
    connect(ui.changebtn_1,&QPushButton::clicked,this,[=]()
    {
            qt::changeIndex(1);
    });
    
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
