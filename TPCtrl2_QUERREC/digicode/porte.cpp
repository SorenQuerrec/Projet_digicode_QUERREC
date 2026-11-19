#include "porte.h"
#include "ui_porte.h"

Porte::Porte(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Porte)
{
    ui->setupUi(this);
    Verouiller();
}

void Porte::Verouiller()
{
    ui->labelImage->setPixmap(QPixmap(":/img/images/porte_fermee.png"));
    ui->labelEtat->setText("Porte Fermée");
}

void Porte::Deverouiller()
{
    ui->labelImage->setPixmap(QPixmap(":/img/images/porte_ouverte.png"));
    ui->labelEtat->setText("Porte Ouverte");
}
