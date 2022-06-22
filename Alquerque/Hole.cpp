#include "Hole.h"

Hole::Hole(QWidget *parent) : QPushButton(parent), m_row(0), m_col(0) {

}

Hole::~Hole() {

}

void Hole::setState(State state) {
    if(m_state != state) {
        m_state = state;
        emit changedState(state);
    }
}
