#ifndef PORTE_H
#define PORTE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QJSEngine>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Porte;
}
QT_END_NAMESPACE

class Porte : public QWidget
{
    Q_OBJECT
public:
    explicit Porte(QWidget *parent = nullptr);
    void Verouiller();
    void Deverouiller();

private:
    Ui::Porte *ui;
};

#endif // PORTE_H
