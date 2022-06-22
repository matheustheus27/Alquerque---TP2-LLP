#include "Alquerque.h"
#include "ui_Alquerque.h"

#include <QSignalMapper>
#include <QMessageBox>

Alquerque::Alquerque(QWidget *parent) : QMainWindow(parent), ui(new Ui::Alquerque) {
    ui->setupUi(this);

    //Resetar Jogo
    QObject::connect(ui->actionNovo, SIGNAL(triggered(bool)), this, SLOT(Restart()));
    QObject::connect(ui->restart, SIGNAL(clicked(bool)), this, SLOT(Restart()));

    //Sobre o Jogo
    QObject::connect(ui->actionAjuda, SIGNAL(triggered(bool)), this, SLOT(About()));
    QObject::connect(ui->help, SIGNAL(clicked(bool)), this, SLOT(About()));

    //Sair do Jogo
    QObject::connect(ui->actionSair, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(ui->exit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    QSignalMapper* map = new QSignalMapper(this);
    for(int id = 0; id < 25; id++) {
        int r = id / 5;
        int c = id % 5;

        Hole* hole = this->findChild<Hole*>(QString("hole%1%2").arg(r).arg(c));
        Q_ASSERT(hole != 0);

        m_holes[id] = hole;

        map->setMapping(hole, id);
        QObject::connect(hole, SIGNAL(clicked(bool)), map, SLOT(map()));
    }

   // Restart();

    QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(Play(int)));
}

Alquerque::~Alquerque() {
    delete ui;
}

void Alquerque::Play(int id) {
    Hole* hole = m_holes[id];
    qDebug() << "row: " << hole->row();
    qDebug() << "col: " << hole->col();

    hole->setIcon(QPixmap(":/BlueAble"));
}

void Alquerque::Restart() {
    for(int i = 0; i < 25; i++) {
        Hole* hole = m_holes[i];

        if(i < 12) {
            if((i > 5 && i < 9) || (i == 11)){
                hole->setIcon(QPixmap(":/RedAble"));
            } else {
                hole->setIcon(QPixmap(":/RedDisabled"));
            }
        } else if (i == 12) {
            hole->setIcon(QPixmap(":/Empty"));
        } else {
            if((i > 15 && i < 19) || (i == 13)){
                hole->setIcon(QPixmap(":/BlueAble"));
            } else {
                hole->setIcon(QPixmap(":/BlueDisabled"));
            }
        }
    }
}

void Alquerque::About() {
    QMessageBox::information(this, tr("About"), tr("Alquerque\n\nAuthor: Matheus Thiago de Souza Ferreira\nEmail: matheustheus27@gmail.com\nGitHub: matheustheus27"));
}

