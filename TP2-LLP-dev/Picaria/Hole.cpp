#include "Hole.h"

#include <stdbool.h>
#include <string>
#include <QString>

Hole::Hole(QWidget *parent)
        : QPushButton(parent),
          m_state(Hole::EmptyState),
            easterEgg(false) {
    this->updateHole(m_state);

    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateHole(State)));
}

Hole::~Hole() {
}

void Hole::initializeRDV()
{
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("N", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("S", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("E", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("W", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("SW", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("SE", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("NW", nullptr));
    this->rosaDosVentos.insert(std::pair<std::string, Hole*>("NE", nullptr));
}

void Hole::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

void Hole::reset() {
    m_state = Hole::EmptyState;
    this->updateHole(m_state);
}

QPixmap Hole::stateToPixmap(State state, bool easterEgg) {
    QPixmap qaux;

    switch (state) {
        case Hole::EmptyState:
            return QPixmap(":empty");
        case Hole::RedState:
            easterEgg ? (qaux = QPixmap(":lemon")) : (qaux = QPixmap(":red"));
            return QPixmap(qaux);
            break;
        case Hole::BlueState:
            easterEgg ? (qaux = QPixmap(":crocodile")) : QPixmap(qaux = QPixmap(":blue"));
            return QPixmap(qaux);
        case Hole::SelectableState:
            return QPixmap(":selectable");
        default:
            return QPixmap();
    }
}

void Hole::updateHole(State state) {
    this->setIcon(Hole::stateToPixmap(state, this->easterEgg));
}

void Hole::toggleEasterEgg()
{
    this->easterEgg = true;
}

bool Hole::getEasterEgg()
{
    return (this->easterEgg);
}
