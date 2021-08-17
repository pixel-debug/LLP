#ifndef PICARIA_H
#define PICARIA_H

#include <QMainWindow>

#include <map>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Picaria;
}
QT_END_NAMESPACE

class Hole;

class Picaria : public QMainWindow {
    Q_OBJECT
    Q_PROPERTY(Picaria::Mode mode READ mode WRITE setMode NOTIFY modeChanged)

public:
    enum Mode {
        NineHoles,
        ThirteenHoles
    };
    Q_ENUM(Mode)

    enum Player {
        RedPlayer,
        BluePlayer
    };
    Q_ENUM(Player)

    enum Phase {
        DropPhase,
        MovePhase
    };
    Q_ENUM(Phase)

    //mapa de pecas de cada jogador
    std::map<Player, int> pieces;

    Picaria(QWidget *parent = nullptr);
    virtual ~Picaria();

    Picaria::Mode mode() const { return m_mode; }
    void setMode(Picaria::Mode mode);

signals:
    void modeChanged(Picaria::Mode mode);
    void gameOver(Picaria::Player player);

private:
    Ui::Picaria *ui;
    Hole* m_holes[13];
    Mode m_mode;
    Player m_player;
    Phase m_phase;
    Hole* m_player_hole;
    bool easterEgg = false;

    void switchPlayer();
    void checkNeighborhood(Hole* hole);
    void clearSelectable();

    void Drop(Hole* hole);
    void Move(Hole* hole);

    bool isGameOver();

private slots:
    void play(int id);
    void reset();

    void showAbout();
    void updateMode(QAction* action);
    void updateStatusBar();

    void setNeighborhood();
    void toggleEasterEgg();

    void showGameOver(Picaria::Player player);
};

#endif // PICARIA_H
