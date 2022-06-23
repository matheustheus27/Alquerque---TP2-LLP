#ifndef HOLE_H
#define HOLE_H

#include <QPushButton>

class Hole : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int row READ row WRITE setRow)
    Q_PROPERTY(int col READ col WRITE setCol)
    Q_PROPERTY(State state READ state WRITE setState NOTIFY changedState)
    Q_PROPERTY(bool marked READ isMarked WRITE setMarked NOTIFY changedMarked)
    Q_PROPERTY(bool e_enabled READ isEnabled WRITE setEnabled NOTIFY changedEnabled)

public:
    enum State {
        EmptyState,
        RedState,
        BlueState
    };
    Q_ENUM(State)

    explicit Hole(QWidget *parent = nullptr);
    virtual ~Hole();

    int row() const {return m_row;}
    void setRow(int row){m_row = row;}

    int col() const {return m_col;}
    void setCol(int col){m_col = col;}

    State state() const {return m_state;}
    void setState(State state);

    bool isMarked() const {return m_marked;}
    void setMarked(bool marked);

    bool isEnabled() const {return m_enabled;}
    void setEnabled(bool e_enabled);

signals:
    void changedState(Hole::State state);
    void changedMarked(bool marked);
    void changedEnabled(bool e_enabled);

private:
    int m_row;
    int m_col;
    bool m_marked;
    bool m_enabled;
    State m_state;

public slots:
    void Reset();

private slots:
    void UpdateHole();
};

#endif // HOLE_H
