#include "Hole.h"

Hole::Hole(QWidget *parent) : QPushButton(parent), m_row(0), m_col(0), m_state(Hole::EmptyState), m_marked(false) {
    QObject::connect(this, SIGNAL(changedState(Hole::State)), this, SLOT(UpdateHole()));
    QObject::connect(this, SIGNAL(changedMarked(bool)), this, SLOT(UpdateHole()));

    this->UpdateHole();
}

Hole::~Hole() {

}

void Hole::setState(State state) {
    if(m_state != state) {
        m_state = state;
        emit changedState(state);
    }
}

void Hole::setMarked(bool marked) {
    if(m_marked != marked) {
        m_marked = marked;
        emit changedMarked(marked);
    }
}

void Hole::Reset() {
    m_state = Hole::EmptyState;
    m_marked = false;

    this->UpdateHole();
}

void Hole::UpdateHole() {
    QIcon icon;

    switch (m_state) {
        case Hole::EmptyState:
            icon.addPixmap(QPixmap(m_marked ? ":/EmptySelectable" : ":/Empty"));
            icon.addPixmap(QPixmap(":/EmptyDisabled"), QIcon::Disabled);
            break;
        case Hole::RedState:
            icon.addPixmap(QPixmap(m_marked ? ":/BlueSelected" : ":/BlueAble"));
            icon.addPixmap(QPixmap(":/BlueDisabled"), QIcon::Disabled);
            break;
        case Hole::BlueState:
            icon.addPixmap(QPixmap(m_marked ? ":/RedSelected" : ":/RedAble"));
            icon.addPixmap(QPixmap(":/RedDisabled"), QIcon::Disabled);
            break;
        default:
            Q_UNREACHABLE();
            break;
    }

    this->setIcon(icon);
}
