#include "digicode.h"
#include "ui_digicode.h"



Digicode::Digicode(QWidget *parent, QString _code, QString _codeSecret)
    : QWidget(parent)
    , ui(new Ui::Digicode)
    ,code(_code)
    ,codeSecret(_codeSecret)
{
    laPorte = new Porte;
    laPorte->show();

    ui->setupUi(this);

    connect(&tempoGache,&QTimer::timeout,this,&Digicode::onTimerTempoGache_timeout);

    grille = new QGridLayout(this);
    afficheur = new QLineEdit(this);
    touches = new QPushButton*[12];// 12 étant le nb de touches max

    int colonne=0, ligne=0;

    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    afficheur->setEchoMode(QLineEdit::Password);
    afficheur->setMinimumHeight(80);
    grille->addWidget(afficheur,ligne,colonne,1,3);
    // Création du clavier
    QString TableDesSymboles[4][3] = {{"7","8","9"},{"4","5","6"},
                                      {"1","2","3"},{"On","0","Ok"}};

    int indice = 0;
    for(int ligne = 1; ligne < 5; ligne++){
        for(int colonne = 0; colonne < 3 ; colonne++)
        {
            touches[indice] = new QPushButton;
            touches[indice]->setMinimumHeight(80);
            touches[indice]->setMaximumWidth(80);
            touches[indice]->setText(TableDesSymboles[ligne-1][colonne]);
            touches[indice]->setStyleSheet("font: 36pt;background-color: rgb(154, 153, 150);");

            grille->addWidget(touches [indice],ligne,colonne);

            connect(touches[indice], &QPushButton::clicked,
                    this, &Digicode::onQPushButtonClicked);
            indice++;

        }
    }
    this->resize(400,480);
    this->setLayout(grille);
}

Digicode::~Digicode()
{
    delete ui;
    delete laPorte;
}

void Digicode::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());

    QString valTouche = touche->text();
    QString code = afficheur->text();


    if(valTouche != "On" && valTouche != "Ok")
    {
        afficheur->setText(afficheur->text() + valTouche);

    } else {

        if(valTouche == "Ok"){
            if(code != codeSecret){
                QMessageBox Verification;
                Verification.setText("Code faux");
                Verification.exec();
                laPorte->Verouiller();

            }else{
                QMessageBox Verification;
                Verification.setText("la porte est dévérouillée");
                Verification.exec();
                laPorte->Deverouiller();
                tempoGache.start(3000);

            }
        }

        if(valTouche == "On")
            afficheur->clear();
    }

}

void Digicode::onTimerTempoGache_timeout()
{
    laPorte->Verouiller();
}
