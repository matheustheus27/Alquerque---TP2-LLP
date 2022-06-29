#ifndef ALQUERQUE_H
#define ALQUERQUE_H

#include <QMainWindow>

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
    Hole* m_destinations[25];
    Jogada m_play;
    Player m_player;

private slots:
    void SendMessage(const char* message);
    void EatPiece(Hole* hole);
    void Play(int id);
    void ExecuteTurn(Hole* hole);
    void Restart();
    void Rulebook();
    void UnlockButtons();
    void LockButtons(Hole* hole);
    void NeighboringHoles(Hole* hole,  Hole* negithbors[]);
    void SwitchPlayer();

    void About(); 
    void UpdateGameStatus();

    bool isNeighbor(Hole* hole, Hole* supNeighbor);
};
#endif // ALQUERQUE_H
