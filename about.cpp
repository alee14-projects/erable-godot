/*
    Alee Audio Player: Audio player in Qt
    Copyright (C) 2020 Alee Productions

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "about.h"
#include "ui_about.h"
#include <QDebug>

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
    qDebug() << "Closing about dialog";
    delete ui;
}
