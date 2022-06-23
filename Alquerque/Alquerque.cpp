#include "Alquerque.h"
#include "ui_Alquerque.h"

#include <QSignalMapper>
#include <QMessageBox>

Alquerque::Player PlayerState(Hole::State state) {
    switch (state) {
        case Hole::RedState:
            return Alquerque::RedPlayer;
            break;
        case Hole::BlueState:
            return Alquerque::BluePlayer;
            break;
        default:
            Q_UNREACHABLE();
            break;
    }
}

Hole::State HoleState(Alquerque::Player player) {
    return player == Alquerque::RedPlayer ? Hole::RedState : Hole::BlueState;
}

Alquerque::Player PlayerTurn(Alquerque::Player player) {
    return (player == Alquerque::RedPlayer ? Alquerque::BluePlayer
                                           : Alquerque::RedPlayer);
}

Alquerque::Alquerque(QWidget *parent) : QMainWindow(parent), ui(new Ui::Alquerque), m_player(Alquerque::RedPlayer) {
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
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            QString h_name = QString("hole%1%2").arg(r).arg(c);
            Hole* hole = this->findChild<Hole*>(h_name);

            Q_ASSERT(hole != 0);

            m_holes[r][c] = hole;
            int id = r * 5 + c;
            map->setMapping(hole, id);
            QObject::connect(hole, SIGNAL(clicked(bool)), map, SLOT(map()));
        }
    }

    #if QT_VERSION < QT_VERSION_CHECK(6,0,0)
        QObject::connect(map, SIGNAL(mapped(int)), this, SLOT(Play(int)));
    #else
        QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(Play(int)));
    #endif

    QObject::connect(this, SIGNAL(endTurn()), this, SLOT(SwitchPlayer()));

    this->Restart();
}

Alquerque::~Alquerque() {
    delete ui;
}

void Alquerque::SwitchPlayer() {
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            Hole* hole = m_holes[r][c];
            hole->setMarked(false);
        }
    }

    m_player = PlayerTurn(m_player);

    this->UpdateGameStatus();
}

void Alquerque::Play(int id) {
    Hole* hole = m_holes[id / 5][id % 5];

    if(m_play == Alquerque::Origin) {
        hole->setMarked(true);
        hole->setState(HoleState(m_player));
        m_oldHole = hole;
        m_play = Alquerque::Destiny;
    } else {
        hole->setState(HoleState(m_player));
        m_oldHole->setState(Hole::EmptyState);
        this->Rulebook();
        m_play = Alquerque::Origin;
        emit endTurn();
    }

    qDebug() << "Origem: " << m_oldHole->objectName();
    qDebug() << "Destino: " << hole->objectName();
    if(m_play == Alquerque::Origin){
        qDebug() << "ORIGEM";
    } else {
        qDebug() << "DESTINO";
    }
}

void Alquerque::Restart() {
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            Hole* hole = m_holes[r][c];
            hole->Reset();

            if(r < 2 || (r == 2 && c < 2)) {
                if((r == 2 && c == 1) || (r == 1 && (c > 0 && c < 4))) {
                    hole->setEnabled(true);
                } else {
                    hole->setEnabled(false);
                }

                hole->setState(Hole::RedState);
            } else if(r == 2 && c == 2) {
                hole->setEnabled(true);
                hole->setState(Hole::EmptyState);
            } else {
                if((r == 2 && c == 3) || (r == 3 && (c > 0 && c < 4))) {
                    hole->setEnabled(true);
                } else {
                    hole->setEnabled(false);
                }

                hole->setState(Hole::BlueState);
            }
        }
    }

    m_player = Alquerque::RedPlayer;
    m_play = Alquerque::Origin;
    this->UpdateGameStatus();
}

void Alquerque::About() {
    QMessageBox::information(this, tr("About"), tr("Alquerque\n\nAuthor: Matheus Thiago de Souza Ferreira\nEmail: matheustheus27@gmail.com\nGitHub: matheustheus27"));
}

void Alquerque::UpdateGameStatus() {
    if(m_player == Alquerque::RedPlayer) {
        ui->playerTurn->setIcon(QPixmap(":/RedTurn"));
    } else {
        ui->playerTurn->setIcon(QPixmap(":/BlueTurn"));
    }
}

void Alquerque::Rulebook() {
    switch (m_oldHole->row()) {
        case 0:
            switch (m_oldHole->col()) {
                case 0:
                    m_holes[0][1]->setEnabled(true);
                    m_holes[1][0]->setEnabled(true);
                    m_holes[1][1]->setEnabled(true);
                    break;
                case 1:
                    m_holes[0][0]->setEnabled(true);
                    m_holes[0][2]->setEnabled(true);
                    m_holes[1][1]->setEnabled(true);
                    break;
                case 2:
                    m_holes[0][1]->setEnabled(true);
                    m_holes[0][3]->setEnabled(true);
                    m_holes[1][1]->setEnabled(true);
                    m_holes[1][2]->setEnabled(true);
                    m_holes[1][3]->setEnabled(true);
                    break;
                case 3:
                    m_holes[0][2]->setEnabled(true);
                    m_holes[0][4]->setEnabled(true);
                    m_holes[1][3]->setEnabled(true);
                    break;
                case 4:
                    m_holes[0][3]->setEnabled(true);
                    m_holes[1][3]->setEnabled(true);
                    m_holes[1][4]->setEnabled(true);
                    break;
            }
            break;
        case 1:
            switch (m_oldHole->col()) {
                case 0:
                    m_holes[0][0]->setEnabled(true);
                    m_holes[1][1]->setEnabled(true);
                    m_holes[2][0]->setEnabled(true);
                    break;
                case 1:
                    m_holes[0][0]->setEnabled(true);
                    m_holes[0][1]->setEnabled(true);
                    m_holes[0][2]->setEnabled(true);
                    m_holes[1][0]->setEnabled(true);
                    m_holes[1][2]->setEnabled(true);
                    m_holes[2][0]->setEnabled(true);
                    m_holes[2][1]->setEnabled(true);
                    m_holes[2][2]->setEnabled(true);
                    break;
                case 2:
                    m_holes[0][2]->setEnabled(true);
                    m_holes[1][1]->setEnabled(true);
                    m_holes[1][3]->setEnabled(true);
                    m_holes[2][2]->setEnabled(true);
                    break;
                case 3:
                    m_holes[0][2]->setEnabled(true);
                    m_holes[0][3]->setEnabled(true);
                    m_holes[0][4]->setEnabled(true);
                    m_holes[1][2]->setEnabled(true);
                    m_holes[1][4]->setEnabled(true);
                    m_holes[2][2]->setEnabled(true);
                    m_holes[2][3]->setEnabled(true);
                    m_holes[2][4]->setEnabled(true);
                    break;
                case 4:
                    m_holes[0][4]->setEnabled(true);
                    m_holes[1][3]->setEnabled(true);
                    m_holes[2][4]->setEnabled(true);
                    break;
            }
            break;
        case 2:
            switch (m_oldHole->col()) {
                case 0:
                    m_holes[1][0]->setEnabled(true);
                    m_holes[2][1]->setEnabled(true);
                    m_holes[3][0]->setEnabled(true);
                    break;
                case 1:
                    m_holes[1][1]->setEnabled(true);
                    m_holes[2][0]->setEnabled(true);
                    m_holes[2][2]->setEnabled(true);
                    m_holes[3][1]->setEnabled(true);
                    break;
                case 2:
                    m_holes[1][1]->setEnabled(true);
                    m_holes[1][2]->setEnabled(true);
                    m_holes[1][3]->setEnabled(true);
                    m_holes[2][1]->setEnabled(true);
                    m_holes[2][3]->setEnabled(true);
                    m_holes[3][1]->setEnabled(true);
                    m_holes[3][2]->setEnabled(true);
                    m_holes[3][3]->setEnabled(true);
                case 3:
                    m_holes[1][3]->setEnabled(true);
                    m_holes[2][2]->setEnabled(true);
                    m_holes[2][4]->setEnabled(true);
                    m_holes[3][3]->setEnabled(true);
                    break;
                case 4:
                    m_holes[1][4]->setEnabled(true);
                    m_holes[2][3]->setEnabled(true);
                    m_holes[3][4]->setEnabled(true);
                    break;
            }
            break;
        case 3:
        switch (m_oldHole->col()) {
            case 0:
                m_holes[2][0]->setEnabled(true);
                m_holes[3][1]->setEnabled(true);
                m_holes[4][0]->setEnabled(true);
                break;
            case 1:
                m_holes[2][0]->setEnabled(true);
                m_holes[2][1]->setEnabled(true);
                m_holes[2][2]->setEnabled(true);
                m_holes[3][0]->setEnabled(true);
                m_holes[3][2]->setEnabled(true);
                m_holes[4][0]->setEnabled(true);
                m_holes[4][1]->setEnabled(true);
                m_holes[4][2]->setEnabled(true);
                break;
            case 2:
                m_holes[2][2]->setEnabled(true);
                m_holes[3][1]->setEnabled(true);
                m_holes[3][3]->setEnabled(true);
                m_holes[4][2]->setEnabled(true);
                break;
            case 3:
                m_holes[2][2]->setEnabled(true);
                m_holes[2][3]->setEnabled(true);
                m_holes[2][4]->setEnabled(true);
                m_holes[3][2]->setEnabled(true);
                m_holes[3][4]->setEnabled(true);
                m_holes[4][2]->setEnabled(true);
                m_holes[4][3]->setEnabled(true);
                m_holes[4][4]->setEnabled(true);
                break;
            case 4:
                m_holes[2][4]->setEnabled(true);
                m_holes[3][3]->setEnabled(true);
                m_holes[4][4]->setEnabled(true);
                break;
        }
            break;
        case 4:
            switch (m_oldHole->col()) {
                case 0:
                    m_holes[3][0]->setEnabled(true);
                    m_holes[3][1]->setEnabled(true);
                    m_holes[4][1]->setEnabled(true);
                    break;
                case 1:
                    m_holes[4][0]->setEnabled(true);
                    m_holes[3][1]->setEnabled(true);
                    m_holes[4][2]->setEnabled(true);
                    break;
                case 2:
                    m_holes[3][1]->setEnabled(true);
                    m_holes[3][2]->setEnabled(true);
                    m_holes[3][3]->setEnabled(true);
                    m_holes[4][1]->setEnabled(true);
                    m_holes[4][3]->setEnabled(true);
                    break;
                case 3:
                    m_holes[3][3]->setEnabled(true);
                    m_holes[4][2]->setEnabled(true);
                    m_holes[4][4]->setEnabled(true);
                    break;
                case 4:
                    m_holes[3][3]->setEnabled(true);
                    m_holes[3][4]->setEnabled(true);
                    m_holes[4][3]->setEnabled(true);
                    break;
            }
            break;
    }
}
