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
    QObject::connect(ui->playerTurnEnd, SIGNAL(clicked(bool)), this, SLOT(ExecuteTurn()));

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

void Alquerque::ExecuteTurn() {
    m_oldHole->setState(Hole::EmptyState);

    for(Hole* hole : m_destinations) {
        this->EatPiece(hole);

        this->LockButtons(hole);

        this->UnlockButtons(m_oldHole);

        this->UnlockEnemyButtons(hole);

        m_oldHole->setEnabled(true);
        m_oldHole->setMarked(false);

        m_oldHole = hole;
    }

    m_oldHole->setState(HoleState(m_player));

    m_play = Alquerque::Origin;

    qDebug() << "Red Pieces: " << m_RedPieces << " | Blue Pieces: " << m_BluePieces;

    if(m_RedPieces <= 0) {
        this->SendMessage("O Jogador Azul Venceu", "Fim de Jogo", "i");
    } else if(m_BluePieces <= 0) {
        this->SendMessage("O Jogador Vermelho Venceu", "Fim de Jogo", "i");
    }

    emit endTurn();
}

void Alquerque::Play(int id) {
    Hole* hole = m_holes[id / 5][id % 5];

    if(m_player == Alquerque::RedPlayer) {
        hole->setSelectable(Hole::Red);
    } else {
        hole->setSelectable(Hole::Blue);
    }

    if(m_play == Alquerque::Origin) {
        if(HoleState(m_player) == hole->state()) {
            hole->setMarked(true);
            hole->setState(HoleState(m_player));
            m_oldHole = hole;
            m_destinations.clear();
            m_play = Alquerque::Destiny;
        } else {
            this->SendMessage("Não é permitido selecionar peças do outro jogador.", "Jogada Invalida", "w");
        }
    } else {
        if(m_oldHole->objectName() != hole->objectName()) {
            if(hole->state() == Hole::EmptyState && this->isValidPlay(hole)) {
                hole->setMarked(true);
                m_destinations.push_back(hole);
            } else {
                this->SendMessage("Não é permitido mover a peça para a posição indicada.", "Jogada Invalida", "w");
            }
        } else {
            this->SendMessage("O destino da peça não pode ser a sua origem.", "Jogada Invalida", "w");
        }
    }

    m_afterHole = hole;
}

void Alquerque::SendMessage(const char* message, const char* title, const char* type) {
    if(type == "w") {
        QMessageBox::warning(this, tr(title), tr(message));
    } else if(type == "i") {
        QMessageBox::information(this, tr(title), tr(message));
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
    m_RedPieces  = 12;
    m_RedPieces  = 12;
    this->UpdateGameStatus();
}

void Alquerque::About() {
    this->SendMessage("Alquerque\n\nAuthor: Matheus Thiago de Souza Ferreira\nEmail: matheustheus27@gmail.com\nGitHub: matheustheus27", "Sobre",  "i");
}

void Alquerque::UpdateGameStatus() {
    if(m_player == Alquerque::RedPlayer) {
        ui->playerTurn->setIcon(QPixmap(":/RedTurn"));
        ui->playerTurnEnd->setIcon(QPixmap(":/RedEnd"));
    } else {
        ui->playerTurn->setIcon(QPixmap(":/BlueTurn"));
        ui->playerTurnEnd->setIcon(QPixmap(":/BlueEnd"));
    }

    this->RedPiecesStatus();
    this->BluePiecesStatus();
}

void Alquerque::UnlockEnemyButtons(Hole* hole) {
    if(hole->row() == m_oldHole->row()) {
        if(m_holes[hole->col()][hole->col() + 1]->state() != HoleState(m_player)) {
            m_holes[hole->row()][hole->col() + 1]->setEnabled(true);
        } else if(m_holes[hole->col()][hole->col() - 1]->state() != HoleState(m_player)) {
            m_holes[hole->row()][hole->col() - 1]->setEnabled(true);
        }
    } else if(hole->col() == m_oldHole->col()) {
        if(m_holes[hole->row() + 1][hole->col()]->state() != HoleState(m_player)) {
            m_holes[hole->row() + 1][hole->col()]->setEnabled(true);
        } else if(m_holes[hole->row() - 1][hole->col()]->state() != HoleState(m_player)) {
            m_holes[hole->row() - 1][hole->col()]->setEnabled(true);
        }
    }  else if(m_holes[hole->row() + 1][hole->col() + 1]->state() != HoleState(m_player)) {
       m_holes[hole->row() + 1][hole->col() + 1]->setEnabled(true);
    } else if(m_holes[hole->row() - 1][hole->col() - 1]->state() != HoleState(m_player)) {
       m_holes[hole->row() - 1][hole->col() - 1]->setEnabled(true);
    }
}

void Alquerque::UnlockButtons(Hole* hole) {
    this->NeighboringHoles(hole);

    for(Hole* current : m_neighbors){
        current->setEnabled(true);
    }
}

void Alquerque::LockButtons(Hole* hole) {
    this->NeighboringHoles(hole);

    std::vector<Hole*> aux = m_neighbors;

    for(Hole* current : aux){
        this->NeighboringHoles(current);

        for(Hole* aux_current : m_neighbors){
            bool isEnabled = false;
            if(!isEnabled) {
                if(aux_current->state() == Hole::EmptyState) {
                current->setEnabled(true);
                isEnabled = true;
                } else {
                    current->setEnabled(false);
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
        this->UnlockButtons(eHole);

        if(m_player == Alquerque::RedPlayer) {
            m_BluePieces--;
        } else {
            m_RedPieces--;
        }
    }
}

// Rules

void Alquerque::NeighboringHoles(Hole* hole) {
    m_neighbors.clear();

    switch (hole->row()) {
        case 0:
            switch (hole->col()) {
                case 0:
                    m_neighbors.push_back(m_holes[0][1]);
                    m_neighbors.push_back(m_holes[1][0]);
                    m_neighbors.push_back(m_holes[1][1]);
                    break;
                case 1:
                    m_neighbors.push_back(m_holes[0][0]);
                    m_neighbors.push_back(m_holes[0][2]);
                    m_neighbors.push_back(m_holes[1][1]);
                    break;
                case 2:
                    m_neighbors.push_back(m_holes[0][1]);
                    m_neighbors.push_back(m_holes[0][3]);
                    m_neighbors.push_back(m_holes[1][1]);
                    m_neighbors.push_back(m_holes[1][2]);
                    m_neighbors.push_back(m_holes[1][3]);
                    break;
                case 3:
                    m_neighbors.push_back(m_holes[0][2]);
                    m_neighbors.push_back(m_holes[0][4]);
                    m_neighbors.push_back(m_holes[1][3]);
                    break;
                case 4:
                    m_neighbors.push_back(m_holes[0][3]);
                    m_neighbors.push_back(m_holes[1][3]);
                    m_neighbors.push_back(m_holes[1][4]);
                    break;
            }
            break;
        case 1:
            switch (hole->col()) {
                case 0:
                    m_neighbors.push_back(m_holes[0][0]);
                    m_neighbors.push_back(m_holes[1][1]);
                    m_neighbors.push_back(m_holes[2][0]);
                    break;
                case 1:
                    m_neighbors.push_back(m_holes[0][0]);
                    m_neighbors.push_back(m_holes[0][1]);
                    m_neighbors.push_back(m_holes[0][2]);
                    m_neighbors.push_back(m_holes[1][0]);
                    m_neighbors.push_back(m_holes[1][2]);
                    m_neighbors.push_back(m_holes[2][0]);
                    m_neighbors.push_back(m_holes[2][1]);
                    m_neighbors.push_back(m_holes[2][2]);
                    break;
                case 2:
                    m_neighbors.push_back(m_holes[0][2]);
                    m_neighbors.push_back(m_holes[1][1]);
                    m_neighbors.push_back(m_holes[1][3]);
                    m_neighbors.push_back(m_holes[2][2]);
                    break;
                case 3:
                    m_neighbors.push_back(m_holes[0][2]);
                    m_neighbors.push_back(m_holes[0][3]);
                    m_neighbors.push_back(m_holes[0][4]);
                    m_neighbors.push_back(m_holes[1][2]);
                    m_neighbors.push_back(m_holes[1][4]);
                    m_neighbors.push_back(m_holes[2][2]);
                    m_neighbors.push_back(m_holes[2][3]);
                    m_neighbors.push_back(m_holes[2][4]);
                    break;
                case 4:
                    m_neighbors.push_back(m_holes[0][4]);
                    m_neighbors.push_back(m_holes[1][3]);
                    m_neighbors.push_back(m_holes[2][4]);
                    break;
            }
            break;
        case 2:
            switch (hole->col()) {
                case 0:
                    m_neighbors.push_back(m_holes[1][0]);
                    m_neighbors.push_back(m_holes[2][1]);
                    m_neighbors.push_back(m_holes[3][0]);
                    break;
                case 1:
                    m_neighbors.push_back(m_holes[1][1]);
                    m_neighbors.push_back(m_holes[2][0]);
                    m_neighbors.push_back(m_holes[2][2]);
                    m_neighbors.push_back(m_holes[3][1]);
                    break;
                case 2:
                    m_neighbors.push_back(m_holes[1][1]);
                    m_neighbors.push_back(m_holes[1][2]);
                    m_neighbors.push_back(m_holes[1][3]);
                    m_neighbors.push_back(m_holes[2][1]);
                    m_neighbors.push_back(m_holes[2][3]);
                    m_neighbors.push_back(m_holes[3][1]);
                    m_neighbors.push_back(m_holes[3][2]);
                    m_neighbors.push_back(m_holes[3][3]);
                    break;
                case 3:
                    m_neighbors.push_back(m_holes[1][3]);
                    m_neighbors.push_back(m_holes[2][2]);
                    m_neighbors.push_back(m_holes[2][4]);
                    m_neighbors.push_back(m_holes[3][3]);
                    break;
                case 4:
                    m_neighbors.push_back(m_holes[1][4]);
                    m_neighbors.push_back(m_holes[2][3]);
                    m_neighbors.push_back(m_holes[3][4]);
                    break;
            }
            break;
        case 3:
            switch (hole->col()) {
                case 0:
                    m_neighbors.push_back(m_holes[2][0]);
                    m_neighbors.push_back(m_holes[3][1]);
                    m_neighbors.push_back(m_holes[4][0]);
                    break;
                case 1:
                    m_neighbors.push_back(m_holes[2][0]);
                    m_neighbors.push_back(m_holes[2][1]);
                    m_neighbors.push_back(m_holes[2][2]);
                    m_neighbors.push_back(m_holes[3][0]);
                    m_neighbors.push_back(m_holes[3][2]);
                    m_neighbors.push_back(m_holes[4][0]);
                    m_neighbors.push_back(m_holes[4][1]);
                    m_neighbors.push_back(m_holes[4][2]);
                    break;
                case 2:
                    m_neighbors.push_back(m_holes[2][2]);
                    m_neighbors.push_back(m_holes[3][1]);
                    m_neighbors.push_back(m_holes[3][3]);
                    m_neighbors.push_back(m_holes[4][2]);
                    break;
                case 3:
                    m_neighbors.push_back(m_holes[2][2]);
                    m_neighbors.push_back(m_holes[2][3]);
                    m_neighbors.push_back(m_holes[2][4]);
                    m_neighbors.push_back(m_holes[3][2]);
                    m_neighbors.push_back(m_holes[3][4]);
                    m_neighbors.push_back(m_holes[4][2]);
                    m_neighbors.push_back(m_holes[4][3]);
                    m_neighbors.push_back(m_holes[4][4]);
                    break;
                case 4:
                    m_neighbors.push_back(m_holes[2][4]);
                    m_neighbors.push_back(m_holes[3][3]);
                    m_neighbors.push_back(m_holes[4][4]);
                    break;
            }
            break;
        case 4:
            switch (hole->col()) {
                case 0:
                    m_neighbors.push_back(m_holes[3][0]);
                    m_neighbors.push_back(m_holes[3][1]);
                    m_neighbors.push_back(m_holes[4][1]);
                    break;
                case 1:
                    m_neighbors.push_back(m_holes[4][0]);
                    m_neighbors.push_back(m_holes[3][1]);
                    m_neighbors.push_back(m_holes[4][2]);
                    break;
                case 2:
                    m_neighbors.push_back(m_holes[3][1]);
                    m_neighbors.push_back(m_holes[3][2]);
                    m_neighbors.push_back(m_holes[3][3]);
                    m_neighbors.push_back(m_holes[4][1]);
                    m_neighbors.push_back(m_holes[4][3]);
                    break;
                case 3:
                    m_neighbors.push_back(m_holes[3][3]);
                    m_neighbors.push_back(m_holes[4][2]);
                    m_neighbors.push_back(m_holes[4][4]);
                    break;
                case 4:
                    m_neighbors.push_back(m_holes[3][3]);
                    m_neighbors.push_back(m_holes[3][4]);
                    m_neighbors.push_back(m_holes[4][3]);
                    break;
            }
            break;
    }
}

bool Alquerque::isNeighbor(Hole* hole, Hole* supNeighbor) {
    this->NeighboringHoles(hole);
    for (Hole* current : m_neighbors) {
        if(current->objectName() == supNeighbor->objectName()){
            return true;
        }
    }

    return false;
}

bool Alquerque::isValidPlay(Hole* hole) {
    if(hole->row() == m_afterHole->row()) {
        if((hole->col() + 2) == m_afterHole->col() && m_holes[hole->row()][hole->col() + 1]->state() != Hole::EmptyState  && m_holes[hole->row()][hole->col()  + 1]->state() != m_afterHole->state()) {
            return true;
        } else if((hole->col() - 2) == m_afterHole->col() && m_holes[hole->row()][hole->col() - 1]->state() != Hole::EmptyState  && m_holes[hole->row()][hole->col() - 1]->state() != m_afterHole->state()) {
            return true;
        } else if((hole->col() + 1) == m_afterHole->col() && m_afterHole->state() != Hole::EmptyState) {
            return true;
        } else if((hole->col() - 1) == m_afterHole->col() && m_afterHole->state() != Hole::EmptyState) {
            return true;
        } else {
            return false;
        }
    } else if(hole->col() == m_afterHole->col()) {
        if((hole->row() + 2) == m_afterHole->row() && m_holes[hole->row() + 1][hole->col()]->state() != Hole::EmptyState && m_holes[hole->row() + 1][hole->col()]->state() != m_afterHole->state()) {
            return true;
        } else if((hole->row() - 2) == m_afterHole->row() && m_holes[hole->row() - 1][hole->col()]->state() != Hole::EmptyState && m_holes[hole->row() - 1][hole->col()]->state() != m_afterHole->state()) {
            return true;
        } else if((hole->row() + 1) == m_afterHole->row() && m_afterHole->state() != Hole::EmptyState) {
            return true;
        } else if((hole->row() - 1) == m_afterHole->row() && m_afterHole->state() != Hole::EmptyState) {
            return true;
        } else {
            return false;
        }
    } else if((hole->row() + 2) == m_afterHole->row() && (hole->col() + 2) == m_afterHole->col() && m_holes[hole->row() + 1][hole->col() + 1]->state() != Hole::EmptyState && m_holes[hole->row() + 1][hole->col() + 1]->state() != m_afterHole->state()) {
        return true;
    } else if((hole->row() - 2) == m_afterHole->row() && (hole->col() - 2) == m_afterHole->col() && m_holes[hole->row() - 1][hole->col() - 1]->state() != Hole::EmptyState && m_holes[hole->row() - 1][hole->col() - 1]->state() != m_afterHole->state()) {
        return true;
    } else if((hole->row() + 1) == m_afterHole->row() && (hole->col() + 1) == m_afterHole->col() && m_afterHole->state() != Hole::EmptyState) {
        return true;
    } else if((hole->row() - 1) == m_afterHole->row() && (hole->col() - 1) == m_afterHole->col() && m_afterHole->state() != Hole::EmptyState) {
        return true;
    } else if(this->isNeighbor(m_afterHole, hole) && m_afterHole->state() != Hole::EmptyState) {
        return true;
    }

    return false;
}

void Alquerque::RedPiecesStatus() {
    switch(m_RedPieces) {
        case 12:
            ui->redPiecesCounter->setIcon(QPixmap(":/R12"));
        break;
        case 11:
            ui->redPiecesCounter->setIcon(QPixmap(":/R11"));
        break;
        case 10:
            ui->redPiecesCounter->setIcon(QPixmap(":/R10"));
        break;
        case 9:
            ui->redPiecesCounter->setIcon(QPixmap(":/R09"));
        break;
        case 8:
            ui->redPiecesCounter->setIcon(QPixmap(":/R08"));
        break;
        case 7:
            ui->redPiecesCounter->setIcon(QPixmap(":/R07"));
        break;
        case 6:
            ui->redPiecesCounter->setIcon(QPixmap(":/R06"));
        break;
        case 5:
            ui->redPiecesCounter->setIcon(QPixmap(":/R05"));
        break;
        case 4:
            ui->redPiecesCounter->setIcon(QPixmap(":/R04"));
        break;
        case 3:
            ui->redPiecesCounter->setIcon(QPixmap(":/R03"));
        break;
        case 2:
            ui->redPiecesCounter->setIcon(QPixmap(":/R02"));
        break;
        case 1:
            ui->redPiecesCounter->setIcon(QPixmap(":/R01"));
        break;
        case 0:
            ui->redPiecesCounter->setIcon(QPixmap(":/R00"));
        break;
    }
}

void Alquerque::BluePiecesStatus() {
    switch(m_BluePieces) {
        case 12:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B12"));
        break;
        case 11:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B11"));
        break;
        case 10:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B10"));
        break;
        case 9:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B09"));
        break;
        case 8:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B08"));
        break;
        case 7:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B07"));
        break;
        case 6:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B06"));
        break;
        case 5:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B05"));
        break;
        case 4:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B04"));
        break;
        case 3:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B03"));
        break;
        case 2:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B02"));
        break;
        case 1:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B01"));
        break;
        case 0:
            ui->bluePiecesCounter->setIcon(QPixmap(":/B00"));
        break;
    }
}
