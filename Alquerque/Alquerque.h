#ifndef ALQUERQUE_H
#define ALQUERQUE_H

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Alquerque;
}
QT_END_NAMESPACE

class Hole;

class Alquerque : public QMainWindow {
    Q_OBJECT

public:
    enum Player {
        RedPlayer,
        BluePlayer
    };

    enum Jogada {
        Origin,
        Destiny
    };

    Alquerque(QWidget *parent = nullptr);
    ~Alquerque();

signals:
    void endTurn();

private:
    Ui::Alquerque *ui;
    Hole* m_holes[5][5];
    Hole* m_oldHole;
    Hole* m_afterHole;
    std::vector<Hole*> m_destinations;
    std::vector<Hole*> m_neighbors;
    Jogada m_play;
    Player m_player;

    int m_RedPieces = 12;
    int m_BluePieces = 12;

    bool m_SingleMove = false;

private slots:
    void SendMessage(const char* message, const char* title, const char* type);
    void EatPiece(Hole* hole);
    void Play(int id);
    void ExecuteTurn();
    void Restart();
    void UnlockEnemyButtons(Hole* hole);
    void UnlockButtons(Hole* hole);
    void LockButtons(Hole* hole);
    void NeighboringHoles(Hole* hole);
    void SwitchPlayer();

    void About(); 
    void UpdateGameStatus();
    void RedPiecesStatus();
    void BluePiecesStatus();

    bool isNeighbor(Hole* hole, Hole* supNeighbor);
    bool isValidPlay(Hole* hole);

    int redPieces() {return m_RedPieces;};
    void setRedPieces(int pieces) {m_RedPieces = pieces;};

    int bluePieces() {return m_BluePieces;};
    void setBluePieces(int pieces) {m_BluePieces = pieces;};
};
#endif // ALQUERQUE_H
