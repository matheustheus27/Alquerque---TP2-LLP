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
    Jogada m_play;
    Player m_player;

    int m_RedPoint;
    int m_BluePoint;

private slots:
    void SendMessage(const char* message);
    void EatPiece(Hole* hole);
    void Play(int id);
    void ExecuteTurn();
    void Restart();
    void UnlockEnemyButtons(Hole* hole);
    void UnlockButtons(Hole* hole);
    void LockButtons(Hole* hole);
    void NeighboringHoles(Hole* hole,  Hole* negithbors[]);
    void SwitchPlayer();

    void About(); 
    void UpdateGameStatus();

    bool isNeighbor(Hole* hole, Hole* supNeighbor);
    bool isValidPlay(Hole* hole);

    int redPoint() {return m_RedPoint;};
    void setRedPoint(int point) {m_RedPoint = point;};

    int bluePoint() {return m_BluePoint;};
    void setBluePoint(int point) {m_BluePoint = point;};
};
#endif // ALQUERQUE_H
