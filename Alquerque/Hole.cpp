#include "Hole.h"

Hole::Hole(QWidget *parent) : QPushButton(parent), m_row(0), m_col(0), m_state(Hole::EmptyAbleState), m_marked(false) {
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
    m_state = Hole::EmptyAbleState;
    m_marked = false;

    this->UpdateHole();
}

void Hole::UpdateHole() {
    QIcon icon;

    switch (m_state) {
        case Hole::EmptyAbleState:
            icon.addPixmap(QPixmap(m_marked ? ":/EmptySelectable" : ":/Empty"));
            icon.addPixmap(QPixmap(":/EmptyDisabled"), QIcon::Disabled);
            break;
        case Hole::EmptyDisabledState:
            icon.addPixmap(QPixmap(":/EmptyDisabled"));
            icon.addPixmap(QPixmap(":/EmptyDisabled"), QIcon::Disabled);
            break;
        case Hole::RedAbleState:
            icon.addPixmap(QPixmap(m_marked ? ":/RedSelected" : ":/RedAble"));
            icon.addPixmap(QPixmap(":/RedDisabled"), QIcon::Disabled);
            break;
        case Hole::RedDisabledState:
            icon.addPixmap(QPixmap(":/RedDisabled"));
            icon.addPixmap(QPixmap(":/RedDisabled"), QIcon::Disabled);
            break;
        case Hole::BlueAbleState:
            icon.addPixmap(QPixmap(m_marked ? ":/BlueSelected" : ":/BlueAble"));
            icon.addPixmap(QPixmap(":/BlueDisabled"), QIcon::Disabled);
            break;
        case Hole::BlueDisabledState:
            icon.addPixmap(QPixmap(":/BlueDisabled"));
            icon.addPixmap(QPixmap(":/BlueDisabled"), QIcon::Disabled);
            break;
        default:
            Q_UNREACHABLE();
            break;
    }

    this->setIcon(icon);
}
