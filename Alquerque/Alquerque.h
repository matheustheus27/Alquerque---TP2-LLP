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
    Alquerque(QWidget *parent = nullptr);
    ~Alquerque();

private:
    Ui::Alquerque *ui;
    Hole* m_holes[25];

private slots:
    void Play(int id);
    void Restart();
    void About();
};
#endif // ALQUERQUE_H
