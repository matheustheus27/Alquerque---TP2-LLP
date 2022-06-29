#include "Alquerque.h"
#include "ui_Alquerque.h"

#include <QSignalMapper>
#include <QMessageBox>
#include <iostream>
#include <list>
#include <vector>
#include <string>

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

    //Finaliza Jogada
    //QObject::connect(ui->playerTurnEnd, SIGNAL(clicked(bool)), this, ExecuteTurn());

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

void Alquerque::ExecuteTurn(Hole* hole) {

}

void Alquerque::Play(int id) {
    Hole* hole = m_holes[id / 5][id % 5];

    if(m_play == Alquerque::Origin) {
        if(HoleState(m_player) == hole->state()) {
            hole->setMarked(true);
            hole->setState(HoleState(m_player));
            m_oldHole = hole;
            m_play = Alquerque::Destiny;
        } else {
            this->SendMessage("Não é permitido selecionar peças do outro jogador.");
        }
    } else {
        if(m_oldHole->objectName() != hole->objectName()) {
            if(hole->state() == Hole::EmptyState) {
                hole->setState(HoleState(m_player));
                m_oldHole->setState(Hole::EmptyState);

                this->EatPiece(hole);

                this->LockButtons(hole);

                this->UnlockButtons();

                m_oldHole->setEnabled(true);
                m_oldHole->setMarked(false);
                m_play = Alquerque::Origin;

                emit endTurn();
            } else {
                this->SendMessage("Não é permitido sobrepor uma peça.");
            }
        } else {
            this->SendMessage("O destino da peça não pode ser a sua origem.");
        }
    }
}

void Alquerque::SendMessage(const char* message) {
    QMessageBox::warning(this, tr("Jogada Invalida"), tr(message));
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

}

// Rules
void Alquerque::UnlockButtons() {
    Hole* neigthbors[8];
    this->NeighboringHoles(m_oldHole, neigthbors);

    for(int i = 0; i < 8; i++){
        if(neigthbors[i] != NULL) {
            neigthbors[i]->setEnabled(true);
        } else {
            break;
        }
    }
}

void Alquerque::LockButtons(Hole* hole) {
    Hole* neigthbors[8];
    this->NeighboringHoles(hole, neigthbors);

    for(int i = 0; i < 8; i++){
        if(neigthbors[i] != NULL) {
            Hole* aux[8];
            this->NeighboringHoles(neigthbors[i], aux);

            for(int j = 0; j < 8; j++){
                if(aux[j] != NULL) {
                    if(aux[j]->state() == Hole::EmptyState) {
                        neigthbors[i]->setEnabled(true);
                        break;
                    } else {
                        neigthbors[i]->setEnabled(false);
                    }
                } else {
                    break;
                }
            }
        }
    }

}

void Alquerque::EatPiece(Hole* hole) {
    Hole* eHole = NULL;

    if(m_oldHole->row() == hole->row()) {
        if(m_oldHole->col() + 1 == hole->col() - 1){
            eHole = m_holes[m_oldHole->row()][m_oldHole->col() + 1];
        } else if(m_oldHole->col() - 1 == hole->col() + 1){
            eHole = m_holes[m_oldHole->row()][m_oldHole->col() - 1];
        }
    } else if(m_oldHole->col() == hole->col()) {
        if(m_oldHole->row() + 1 == hole->row() - 1){
            eHole = m_holes[m_oldHole->row() + 1][m_oldHole->col()];
        } else if(m_oldHole->row() - 1 == hole->row() + 1){
            eHole = m_holes[m_oldHole->row() - 1][m_oldHole->col()];
        }
    } else if(m_oldHole->row() + 1 == hole->row() - 1 && m_oldHole->col() + 1 == hole->col() - 1) {
            eHole = m_holes[m_oldHole->row() + 1][m_oldHole->col() + 1];
    } else if(m_oldHole->row() - 1 == hole->row() + 1 && m_oldHole->col() - 1 == hole->col() + 1) {
        eHole = m_holes[m_oldHole->row() - 1][m_oldHole->col() - 1];
    }


    if(eHole != NULL){
        eHole->setState(Hole::EmptyState);
    }
}

// Funções Auxiliares

void Alquerque::NeighboringHoles(Hole* hole, Hole* negithbors[]) {
    for(int i = 0; i < 8; i++) {
        negithbors[i] = NULL;
    }
    switch (hole->row()) {
        case 0:
            switch (hole->col()) {
                case 0:
                    negithbors[0] = m_holes[0][1];
                    negithbors[1] = m_holes[1][0];
                    negithbors[2] = m_holes[1][1];
                    break;
                case 1:
                    negithbors[0] = m_holes[0][0];
                    negithbors[1] = m_holes[0][2];
                    negithbors[2] = m_holes[1][1];
                    break;
                case 2:
                    negithbors[0] = m_holes[0][1];
                    negithbors[1] = m_holes[0][3];
                    negithbors[2] = m_holes[1][1];
                    negithbors[3] = m_holes[1][2];
                    negithbors[4] = m_holes[1][3];
                    break;
                case 3:
                    negithbors[0] = m_holes[0][2];
                    negithbors[1] = m_holes[0][4];
                    negithbors[2] = m_holes[1][3];
                    break;
                case 4:
                    negithbors[0] = m_holes[0][3];
                    negithbors[1] = m_holes[1][3];
                    negithbors[2] = m_holes[1][4];
                    break;
            }
            break;
        case 1:
            switch (hole->col()) {
                case 0:
                    negithbors[0] = m_holes[0][0];
                    negithbors[1] = m_holes[1][1];
                    negithbors[2] = m_holes[2][0];
                    break;
                case 1:
                    negithbors[0] = m_holes[0][0];
                    negithbors[1] = m_holes[0][1];
                    negithbors[2] = m_holes[0][2];
                    negithbors[3] = m_holes[1][0];
                    negithbors[4] = m_holes[1][2];
                    negithbors[5] = m_holes[2][0];
                    negithbors[6] = m_holes[2][1];
                    negithbors[7] = m_holes[2][2];
                    break;
                case 2:
                    negithbors[0] = m_holes[0][2];
                    negithbors[1] = m_holes[1][1];
                    negithbors[2] = m_holes[1][3];
                    negithbors[3] = m_holes[2][2];
                    break;
                case 3:
                    negithbors[0] = m_holes[0][2];
                    negithbors[1] = m_holes[0][3];
                    negithbors[2] = m_holes[0][4];
                    negithbors[3] = m_holes[1][2];
                    negithbors[4] = m_holes[1][4];
                    negithbors[5] = m_holes[2][2];
                    negithbors[6] = m_holes[2][3];
                    negithbors[7] = m_holes[2][4];
                    break;
                case 4:
                    negithbors[0] = m_holes[0][4];
                    negithbors[1] = m_holes[1][3];
                    negithbors[2] = m_holes[2][4];
                    break;
            }
            break;
        case 2:
            switch (hole->col()) {
                case 0:
                    negithbors[0] = m_holes[1][0];
                    negithbors[1] = m_holes[2][1];
                    negithbors[2] = m_holes[3][0];
                    break;
                case 1:
                    negithbors[0] = m_holes[1][1];
                    negithbors[1] = m_holes[2][0];
                    negithbors[2] = m_holes[2][2];
                    negithbors[3] = m_holes[3][1];
                    break;
                case 2:
                    negithbors[0] = m_holes[1][1];
                    negithbors[1] = m_holes[1][2];
                    negithbors[2] = m_holes[1][3];
                    negithbors[3] = m_holes[2][1];
                    negithbors[4] = m_holes[2][3];
                    negithbors[5] = m_holes[3][1];
                    negithbors[6] = m_holes[3][2];
                    negithbors[7] = m_holes[3][3];
                    break;
                case 3:
                    negithbors[0] = m_holes[1][3];
                    negithbors[1] = m_holes[2][2];
                    negithbors[2] = m_holes[2][4];
                    negithbors[3] = m_holes[3][3];
                    break;
                case 4:
                    negithbors[0] = m_holes[1][4];
                    negithbors[1] = m_holes[2][3];
                    negithbors[2] = m_holes[3][4];
                    break;
            }
            break;
        case 3:
            switch (hole->col()) {
                case 0:
                    negithbors[0] = m_holes[2][0];
                    negithbors[1] = m_holes[3][1];
                    negithbors[2] = m_holes[4][0];
                    break;
                case 1:
                    negithbors[0] = m_holes[2][0];
                    negithbors[1] = m_holes[2][1];
                    negithbors[2] = m_holes[2][2];
                    negithbors[3] = m_holes[3][0];
                    negithbors[4] = m_holes[3][2];
                    negithbors[5] = m_holes[4][0];
                    negithbors[6] = m_holes[4][1];
                    negithbors[7] = m_holes[4][2];
                    break;
                case 2:
                    negithbors[0] = m_holes[2][2];
                    negithbors[1] = m_holes[3][1];
                    negithbors[2] = m_holes[3][3];
                    negithbors[3] = m_holes[4][2];
                    break;
                case 3:
                    negithbors[0] = m_holes[2][2];
                    negithbors[1] = m_holes[2][3];
                    negithbors[2] = m_holes[2][4];
                    negithbors[3] = m_holes[3][2];
                    negithbors[4] = m_holes[3][4];
                    negithbors[5] = m_holes[4][2];
                    negithbors[6] = m_holes[4][3];
                    negithbors[7] = m_holes[4][4];
                    break;
                case 4:
                    negithbors[0] = m_holes[2][4];
                    negithbors[1] = m_holes[3][3];
                    negithbors[2] = m_holes[4][4];
                    break;
            }
            break;
        case 4:
            switch (hole->col()) {
                case 0:
                    negithbors[0] = m_holes[3][0];
                    negithbors[1] = m_holes[3][1];
                    negithbors[2] = m_holes[4][1];
                    break;
                case 1:
                    negithbors[0] = m_holes[4][0];
                    negithbors[1] = m_holes[3][1];
                    negithbors[2] = m_holes[4][2];
                    break;
                case 2:
                    negithbors[0] = m_holes[3][1];
                    negithbors[1] = m_holes[3][2];
                    negithbors[2] = m_holes[3][3];
                    negithbors[3] = m_holes[4][1];
                    negithbors[4] = m_holes[4][3];
                    break;
                case 3:
                    negithbors[0] = m_holes[3][3];
                    negithbors[1] = m_holes[4][2];
                    negithbors[2] = m_holes[4][4];
                    break;
                case 4:
                    negithbors[0] = m_holes[3][3];
                    negithbors[1] = m_holes[3][4];
                    negithbors[2] = m_holes[4][3];
                    break;
            }
            break;
    }
}

bool Alquerque::isNeighbor(Hole* hole, Hole* supNeighbor) {
    Hole* neighbors[8];
    this->NeighboringHoles(hole, neighbors);
    for (int i = 0; i < 8; i++) {
        if(neighbors[i]->objectName() == supNeighbor->objectName()){
            return true;
        }
    }

    return false;
}

