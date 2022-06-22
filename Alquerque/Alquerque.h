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

    Alquerque(QWidget *parent = nullptr);
    ~Alquerque();

signals:
    void endTurn();

private:
    Ui::Alquerque *ui;
    Hole* m_holes[5][5];
    Player m_player;

private slots:
    void Play(int id);
    void Restart();
    void SwitchPlayer();

    void About(); 
    void UpdateGameStatus();
};
#endif // ALQUERQUE_H
