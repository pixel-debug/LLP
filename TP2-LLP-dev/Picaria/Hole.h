#ifndef HOLE_H
#define HOLE_H

#include <QObject>
#include <QPushButton>

#include <map>
#include <string>

class Hole : public QPushButton {
    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:
    enum State {
        EmptyState,
        RedState,
        BlueState,
        SelectableState
    };
    Q_ENUM(State)

    explicit Hole(QWidget *parent = nullptr);
    virtual ~Hole();

    State state() const { return m_state; }
    void setState(State State);

    //Hole *N, *S, *E, *W, *NE, *NW, *SE, *SW;
    std::map<std::string, Hole*> rosaDosVentos;
    void initializeRDV();

public slots:
    void reset();
    void toggleEasterEgg();
    bool getEasterEgg();

signals:
    void stateChanged(State State);

private:
    State m_state;
    bool easterEgg;

    static QPixmap stateToPixmap(State state, bool easterEgg);

private slots:
    void updateHole(State state);


};

#endif // HOLE_H
