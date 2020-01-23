#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    ui->label_3->setTextFormat(Qt::RichText);

    ui->label_3->setTextInteractionFlags(Qt::TextBrowserInteraction);

    ui->label_3->setOpenExternalLinks(true);
}

About::~About()
{
    delete ui;
}
