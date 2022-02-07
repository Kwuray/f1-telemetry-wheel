//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// Cette classe définit le thread qui va recevoir les paquets UDP
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_FEEDTHREAD
#define DEF_FEEDTHREAD

#define INVALID_SOCKET -1
#define PORT "20778"
#include "../headers/games/games.hpp"
#include "../headers/games/F1-2020/packetManager.hpp"
#include "display-modes/raceDisplay.hpp"
#include <QThread>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <poll.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <cstddef>




//Cette classe permet de recevoir les différents paquets du jeu F1 2021
class dataListenerThread : public QThread {
  Q_OBJECT

public:

  //Initialisation de tout le nécessaire pour recevoir des paquets UDP.
  dataListenerThread(Game* selectedGame, raceDisplay* display) {
    QObject::connect(this, SIGNAL(managerReady(void*)), display, SLOT(initDisplay(void*)));
    m_selectedGame = selectedGame;
  };

signals:
    void managerReady(void* manager);

private:
  Game* m_selectedGame;
  void* m_manager;

protected:
  void run() {
    //Le thread patiente le temps que l'application se charge
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    sockaddr_in gameAddress; //Ici sera stocké les informations de connexion du jeu (ip..)
    socklen_t gameAddressSize = sizeof gameAddress;

    addrinfo hints, *res; //Ces structures de données contiendront les informations de connexion de l'application
    int appSocket; //Ici, la socket qui servira à enclencher la connexion
    char rawPacket[2048];
    int rawPacketSize;

    timeval socketTimeout;

    int sockErr; //gestion erreur

    //Paramétrage de la socket
    memset(&hints, 0, sizeof hints); //Remise à zéro de hints
    hints.ai_family = AF_INET; //IPv4
    hints.ai_socktype = SOCK_DGRAM; //UDP type
    hints.ai_flags = AI_PASSIVE; //L'adresse IP de la machine obtenu automatiquement

    sockErr = getaddrinfo(NULL, PORT, &hints, &res);
    if (sockErr == 0) {
      std::cout << "Paramétrage de l'adresse ok !" << '\n';
    } else {
      perror("Erreur du paramétrage de l'adresse  ");
    exit(1);
    }

    appSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol); //Initialisation de la SOCKET
    if (appSocket != INVALID_SOCKET) {
      std::cout << "Socket valide" << '\n';
    } else {
      perror("Erreur de la socket  ");
      exit(1);
    }

    //Ici, l'on va ignorer l'erreur "address already in use"
    int yes = 1;
    setsockopt(appSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes);

    //Ici, nous allons définir le timeout de 5sec
    socketTimeout.tv_sec = 5;
    socketTimeout.tv_usec = 5000;
    setsockopt(appSocket, SOL_SOCKET, SO_RCVTIMEO, &socketTimeout, sizeof socketTimeout);

    //Activation du mode "Écoute"
    sockErr = bind(appSocket, res->ai_addr, res->ai_addrlen); //Connexion de la socket au bon PORT
    if (sockErr != INVALID_SOCKET) {
      std::cout << "Bind valide" << '\n';
    } else {
      perror("Erreur du bind ");
      exit(1);
    }

    //Sélection du packetManager selon le jeu
    switch (*m_selectedGame) {
      case Game::F12020:
        m_manager = new F12020_packetManager;
        emit managerReady(m_manager);
        while (true) {
          rawPacketSize = recvfrom(appSocket, &rawPacket, sizeof rawPacket, 0, (sockaddr*)&gameAddress, &gameAddressSize);
          //On envoi le paquet au packetManager pour traitement
          static_cast<F12020_packetManager*>(m_manager)->handlePacket(&rawPacket, &rawPacketSize);
        }
        break;

      default:
        m_manager = new F12020_packetManager;
        emit managerReady(m_manager);
        while (true) {
          rawPacketSize = recvfrom(appSocket, &rawPacket, sizeof rawPacket, 0, (sockaddr*)&gameAddress, &gameAddressSize);
          //On envoi le paquet au packetManager pour traitement
          static_cast<F12020_packetManager*>(m_manager)->handlePacket(&rawPacket, &rawPacketSize);
        }
        break;
    };
    close(appSocket);
    exit(1);
  }

};
#endif
