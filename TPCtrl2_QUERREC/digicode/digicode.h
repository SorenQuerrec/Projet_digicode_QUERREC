#ifndef DIGICODE_H
#define DIGICODE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QJSEngine>
#include <QMessageBox>
#include "porte.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Digicode;
}
QT_END_NAMESPACE

class Digicode : public QWidget
{
    Q_OBJECT

public:
    explicit Digicode(QWidget *parent = nullptr,QString _code = nullptr, QString _codeSecret = "1234");
    ~Digicode() override;

private slots:
        void onQPushButtonClicked();
        void onTimerTempoGache_timeout();

private:
    Ui::Digicode *ui;

    QString code;
    QString codeSecret;

    QGridLayout *grille;
    QPushButton **touches;
    QLineEdit *afficheur;

    Porte *laPorte;

    QTimer tempoGache;
};
#endif // DIGICODE_H
