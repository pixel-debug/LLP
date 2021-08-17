#include "Picaria.h"
#include "ui_Picaria.h"

#include <QDebug>
#include <QMessageBox>
#include <QActionGroup>
#include <QSignalMapper>

#include <map>
#include <string>
#include <iterator>

Picaria::Player state2player(Hole::State state) {
    switch (state) {
        case Hole::RedState:
            return Picaria::RedPlayer;
        case Hole::BlueState:
            return Picaria::BluePlayer;
        default:
            Q_UNREACHABLE();
    }
}

Hole::State player2state(Picaria::Player player) {
    return player == Picaria::RedPlayer ? Hole::RedState : Hole::BlueState;
}

Picaria::Picaria(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Picaria),
      m_mode(Picaria::NineHoles),
      m_player(Picaria::RedPlayer),
      m_phase(Picaria::DropPhase),
      m_player_hole(nullptr){

    ui->setupUi(this);

    QActionGroup* modeGroup = new QActionGroup(this);
    modeGroup->setExclusive(true);
    modeGroup->addAction(ui->action9holes);
    modeGroup->addAction(ui->action13holes);

    QObject::connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(reset()));
    QObject::connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(updateMode(QAction*)));
    QObject::connect(this, SIGNAL(modeChanged(Picaria::Mode)), this, SLOT(reset()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(setNeighborhood()));
    QObject::connect(this, SIGNAL(gameOver(Picaria::Player)), this, SLOT(showGameOver(Picaria::Player)));
    QObject::connect(this, SIGNAL(gameOver(Picaria::Player)), this, SLOT(reset()));
    QObject::connect(this, SIGNAL(easterEggActivated(Picaria::Player)), this, SLOT(toggleEasterEgg()));

    QSignalMapper* map = new QSignalMapper(this);
    for (int id = 0; id < 13; ++id) {
        QString holeName = QString("hole%1").arg(id+1, 2, 10, QChar('0'));
        Hole* hole = this->findChild<Hole*>(holeName);
        Q_ASSERT(hole != nullptr);

        m_holes[id] = hole;
        map->setMapping(hole, id);
        QObject::connect(hole, SIGNAL(clicked(bool)), map, SLOT(map()));
    }
#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    QObject::connect(map, SIGNAL(mapped(int)), this, SLOT(play(int)));
#else
    QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(play(int)));
#endif
    this->setNeighborhood();
    this->reset();
    this->adjustSize();
    this->setFixedSize(this->size());

}

Picaria::~Picaria() {
    delete ui;
}

void Picaria::toggleEasterEgg ()
{
    for (int id = 0; id < 13; ++id) {
        Hole* hole = m_holes[id];
        hole->toggleEasterEgg();
    }
}

void Picaria::setMode(Picaria::Mode mode) {
    if (m_mode != mode) {
        m_mode = mode;
        emit modeChanged(mode);
    }
}

// mapeia os vizinhos no inicio do jogo
void Picaria::setNeighborhood(){
    qDebug() << "SETANDO VIZINHOS" ;
    std::map<std::string, Hole*>::iterator rdv_it;

    for (int id = 0; id < 13; ++id) {
        Hole* hole = m_holes[id];
        hole->initializeRDV();

        switch (id) {
            case 0: //primeiro buraco

                hole->rosaDosVentos["S"] = m_holes[5];
                hole->rosaDosVentos["E"] = m_holes[1];
                hole->rosaDosVentos["SE"] = m_holes[6];
                if(m_mode == Picaria::ThirteenHoles)
                    hole->rosaDosVentos["SE"] = m_holes[3];

            break;
            case 1: //segundo buraco

                hole->rosaDosVentos["S"] = m_holes[6];
                hole->rosaDosVentos["E"] = m_holes[2];
                hole->rosaDosVentos["W"] = m_holes[0];
                hole->rosaDosVentos["SE"] = m_holes[7];
                hole->rosaDosVentos["SW"] = m_holes[5];
                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[3];
                    hole->rosaDosVentos["SE"] = m_holes[4];
                }
            break;
            case 2: //terceiro buraco

                    hole->rosaDosVentos["S"] = m_holes[7];
                    hole->rosaDosVentos["W"] = m_holes[1];
                    hole->rosaDosVentos["SW"] = m_holes[6];

                if(m_mode == Picaria::ThirteenHoles)
                    hole->rosaDosVentos["SW"] = m_holes[4];
            break;
            case 3: //quarto buraco

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[5];
                    hole->rosaDosVentos["SE"] = m_holes[6];
                    hole->rosaDosVentos["NW"] = m_holes[0];
                    hole->rosaDosVentos["NE"] = m_holes[1];
                }
            break;
            case 4: //quinto buraco
                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[6];
                    hole->rosaDosVentos["SE"] = m_holes[7];
                    hole->rosaDosVentos["NW"] = m_holes[1];
                    hole->rosaDosVentos["NE"] = m_holes[2];
                }
            break;
            case 5: //sexto buraco

                hole->rosaDosVentos["N"] = m_holes[0];
                hole->rosaDosVentos["S"] = m_holes[10];
                hole->rosaDosVentos["E"] = m_holes[6];

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SE"] = m_holes[8];
                    hole->rosaDosVentos["NE"] = m_holes[3];
                }
                else{
                    hole->rosaDosVentos["SE"] = m_holes[11];
                    hole->rosaDosVentos["NE"] = m_holes[1];
                }
            break;
            case 6: //setimo buraco

                hole->rosaDosVentos["N"] = m_holes[1];
                hole->rosaDosVentos["S"]= m_holes[11];
                hole->rosaDosVentos["E"] = m_holes[7];
                hole->rosaDosVentos["W"] = m_holes[5];

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[8];
                    hole->rosaDosVentos["SE"] = m_holes[9];
                    hole->rosaDosVentos["NW"] = m_holes[3];
                    hole->rosaDosVentos["NE"] = m_holes[4];
                }
                else{
                    hole->rosaDosVentos["SW"] = m_holes[10];
                    hole->rosaDosVentos["SE"] = m_holes[12];
                    hole->rosaDosVentos["NW"] = m_holes[0];
                    hole->rosaDosVentos["NE"] = m_holes[2];
                }
            break;
            case 7: //oitavo buraco

                hole->rosaDosVentos["N"] = m_holes[2];
                hole->rosaDosVentos["S"]= m_holes[12];
                hole->rosaDosVentos["W"] = m_holes[6];

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[9];
                    hole->rosaDosVentos["NW"] = m_holes[4];
                }
                else{
                    hole->rosaDosVentos["SW"] = m_holes[11];
                    hole->rosaDosVentos["NW"] = m_holes[1];
                }
            break;
            case 8: //nono buraco

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[10];
                    hole->rosaDosVentos["SE"] = m_holes[11];
                    hole->rosaDosVentos["NW"] = m_holes[5];
                    hole->rosaDosVentos["NE"] = m_holes[6];
                }
            break;
            case 9: //decimo buraco

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["SW"] = m_holes[11];
                    hole->rosaDosVentos["SE"] = m_holes[12];
                    hole->rosaDosVentos["NW"] = m_holes[6];
                    hole->rosaDosVentos["NE"] = m_holes[7];
                }
            break;
            case 10: //decimo primeiro buraco

                hole->rosaDosVentos["N"] = m_holes[5];
                hole->rosaDosVentos["E"] = m_holes[11];

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["NE"] = m_holes[8];
                }
                else{
                    hole->rosaDosVentos["NW"] = m_holes[6];
                }
            break;
            case 11: //decimo segundo buraco

            hole->rosaDosVentos["N"] = m_holes[6];
            hole->rosaDosVentos["E"] = m_holes[12];
            hole->rosaDosVentos["W"] = m_holes[10];

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["NW"] = m_holes[8];
                    hole->rosaDosVentos["NE"] = m_holes[9];
                }
                else{
                    hole->rosaDosVentos["NW"] = m_holes[5];
                    hole->rosaDosVentos["NE"] = m_holes[7];
                }
            break;
            case 12: //decimo terceiro buraco

            hole->rosaDosVentos["N"] = m_holes[7];
            hole->rosaDosVentos["W"] = m_holes[11];

                if(m_mode == Picaria::ThirteenHoles){
                    hole->rosaDosVentos["NW"] = m_holes[9];
                }
                else{
                    hole->rosaDosVentos["NW"] = m_holes[6];
                }
                break;
            default:
                qDebug() << "Algo deu errado! ";
                break;
        }
     }

}

void Picaria::switchPlayer() {
    m_player = m_player == Picaria::RedPlayer ?
                    Picaria::BluePlayer : Picaria::RedPlayer;
    this->updateStatusBar();
}

void Picaria::play(int id) {

    Hole* hole = m_holes[id];

    qDebug() << "clicked on: " << hole->objectName();

    if(m_phase == Picaria::DropPhase)
    {

        Drop(hole);

    }
    else if(m_phase == Picaria::MovePhase){

        Move(hole);
    }
    else {

        if (hole->state() == Hole::EmptyState)
            ui->statusbar->showMessage(tr("Nao e possivel adicionar mais peças. Selecione uma peça para mover"));
        else if(hole->state() != player2state(m_player))
            ui->statusbar->showMessage(tr("Jogador errado. Selecione uma peça do jogador certo"));
    }

  //  qDebug() << "jogador: " << m_player << ", quantidade de pecas: " << pieces[m_player];

}

void Picaria::Drop(Hole* hole){
  //  qDebug() << "entrando em drop";
    if (hole->state() == Hole::EmptyState)
    {
        hole->setState(player2state(m_player));
         pieces[m_player]++;

        if(this->isGameOver())
            emit gameOver(m_player);
        else{
                 //se o azul ja tiver 3 pecas, ir para a fase de mover
            if(pieces[Picaria::BluePlayer] == 3)
            m_phase = Picaria::MovePhase;

            this->switchPlayer();
        }
    }
    else {
        ui->statusbar->showMessage(tr("Este buraco ja esta ocupado. Selecione outro buraco"));
    }
}

void Picaria::Move(Hole *hole){
    if(hole->state() == player2state(this->m_player)){
         this->m_player_hole = hole;                     // pego o buraco do jogador
         this->checkNeighborhood(hole);                   // verifico ele
     }

    if(hole->state() == Hole::SelectableState){            // se o buraco for de seleção

         ui->statusbar->showMessage(tr("Jogador selecionou algum buraco "));

         hole->setState((player2state(this->m_player))); // coloco o jogador lá
            m_player_hole->setState(Hole::EmptyState);    // buraco anterior do jogador fica disponivel

        this->clearSelectable();
        if(this->isGameOver())
            emit gameOver(m_player);
        else
            this->switchPlayer();           // troca o jogador
    }

}

// verifica se eles existem ( != nullprt ) e se estão vazios, se estiver, eles podem ser selecionados
void Picaria::checkNeighborhood(Hole* hole){

    std::map<std::string, Hole*>::iterator rdv_it;

    rdv_it = hole->rosaDosVentos.begin();

 //  qDebug() << "check Neighbor de " << hole->objectName() ;
    this->clearSelectable();


    while (rdv_it != hole->rosaDosVentos.end())
    {
        if(hole->rosaDosVentos[rdv_it->first] != nullptr && hole->rosaDosVentos[rdv_it->first]->state() == Hole::EmptyState) {
          // qDebug() << "vizinhos de " << hole->rosaDosVentos[rdv_it->first] ;
            hole->rosaDosVentos[rdv_it->first]->setState(Hole::SelectableState);
        }

        rdv_it++;
    }

 //   qDebug() << "buraco: " << hole->objectName() << ", status: " << hole->state();
}

// limpando os selecionáveis
void Picaria::clearSelectable(){
    for (int id = 0; id < 13; id++) {
           Hole* hole = m_holes[id];
           if (hole->state() == Hole::SelectableState)
               hole->setState(Hole::EmptyState);
       }
}

void Picaria::reset() {
    // Reset each hole.
    for (int id = 0; id < 13; ++id) {
        Hole* hole = m_holes[id];
        hole->reset();

        // Set the hole visibility according to the board mode.
        switch (id) {
            case 3: //quarto buraco
            case 4: //quinto buraco
            case 8: //nono buraco
            case 9: //decimo buraco
                hole->setVisible(m_mode == Picaria::ThirteenHoles);
                //mostrar os buracos apenas se estiver no modo 13 buracos
                break;
            default:
                break;
        }
    }

    // Reset the player and phase.
    m_player = Picaria::RedPlayer;
    m_phase = Picaria::DropPhase;

    pieces[Picaria::RedPlayer] = 0;
    pieces[Picaria::BluePlayer] = 0;

    // Finally, update the status bar.
    this->updateStatusBar();
}

bool Picaria::isGameOver(){
    std::map<std::string, Hole*>::iterator it;

    for (int id = 0; id < 13; id++) {

           it = this->m_holes[id]->rosaDosVentos.begin();
            //qDebug() << "buraco : " << m_holes[2]->rosaDosVentos["N"];
           if(this->m_holes[id]->state() == player2state(m_player)) {
                   if(this->m_holes[id]->rosaDosVentos["N"] != nullptr && this->m_holes[id]->rosaDosVentos["N"]->state() == player2state(m_player)
                           &&  this->m_holes[id]->rosaDosVentos["S"] != nullptr && this->m_holes[id]->rosaDosVentos["S"]->state() == player2state(m_player)){
                       // horizontal
                       return true;

                   }
                   if(this->m_holes[id]->rosaDosVentos["E"] != nullptr && this->m_holes[id]->rosaDosVentos["E"]->state() == player2state(m_player)
                          && this->m_holes[id]->rosaDosVentos["W"] != nullptr && m_holes[id]->rosaDosVentos["W"]->state() == player2state(m_player)){
                      // vertical
                       return true;

                   }
                   if(this->m_holes[id]->rosaDosVentos["NW"] != nullptr && this->m_holes[id]->rosaDosVentos["NW"]->state() == player2state(m_player)
                          && this->m_holes[id]->rosaDosVentos["SE"] != nullptr && this->m_holes[id]->rosaDosVentos["SE"]->state() == player2state(m_player)){
                        // (\)
                       return true;
                   }
                   if(this->m_holes[id]->rosaDosVentos["NE"] != nullptr && this->m_holes[id]->rosaDosVentos["NE"]->state() == player2state(m_player)
                          && this->m_holes[id]->rosaDosVentos["SW"] != nullptr && this->m_holes[id]->rosaDosVentos["SW"]->state() == player2state(m_player)){
                        // /
                        return true;
                   }

           }
    }
        return false;
}


void Picaria::showGameOver(Player player) {
    switch (player) {
        case Picaria::RedPlayer:
            QMessageBox::information(this, tr("Vencedor"), tr("Parabéns, o jogador vermelho venceu."));
            break;
        case Picaria::BluePlayer:
            QMessageBox::information(this, tr("Vencedor"), tr("Parabéns, o jogador azul venceu."));
            break;
        default:
            Q_UNREACHABLE();
    }
}



void Picaria::showAbout() {
    QMessageBox aux(this);

    QAbstractButton* auxButton = aux.addButton(tr("?"), QMessageBox::ButtonRole::YesRole);
    aux.addButton(tr("Ok"), QMessageBox::ButtonRole::NoRole);

    aux.setInformativeText(tr("Mateus Lemos de Freitas Barbosa, \"Limão\" \n\nMarina Bernardes Diniz, \"Jacare\""));
    aux.setWindowTitle(tr("About"));
    aux.exec();

    if (aux.clickedButton() == auxButton)
    {
        this->reset();
        this->toggleEasterEgg();
    }
}

void Picaria::updateMode(QAction* action) {
    if (action == ui->action9holes)
        this->setMode(Picaria::NineHoles);
    else if (action == ui->action13holes)
        this->setMode(Picaria::ThirteenHoles);
    else
        Q_UNREACHABLE();
}

void Picaria::updateStatusBar() {
    QString player(m_player == Picaria::RedPlayer ? "vermelho" : "azul");
    QString phase(m_phase == Picaria::DropPhase ? "colocar" : "mover");

    ui->statusbar->showMessage(tr("Fase de %1: vez do jogador %2").arg(phase).arg(player));
}
