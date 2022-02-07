//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// Cette classe permet de Gérer les paquets :
// Une variable par type de paquet
// Une fonction qui permet de déterminer le type de paquet
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//


#ifndef DEF_PACKETMANAGER
#define DEF_PACKETMANAGER
#include <QObject>
#include "packets-structures/carSetup.hpp"
#include "packets-structures/carStatus.hpp"
#include "packets-structures/carTelemetry.hpp"
#include "packets-structures/event.hpp"
#include "packets-structures/finalClassification.hpp"
#include "packets-structures/header.hpp"
#include "packets-structures/lapData.hpp"
#include "packets-structures/lobbyInfo.hpp"
#include "packets-structures/motion.hpp"
#include "packets-structures/participants.hpp"
#include "packets-structures/session.hpp"
#include "../../games/games.hpp"



class F12020_packetManager : public QObject {
  Q_OBJECT

private:
  packetHeader header;

  packetMotionData motion;
  packetSessionData session;
  packetLapData lap;
  packetEventData event;
  packetParticipantsData participants;
  packetCarSetupData setup;
  packetCarTelemetryData telemetry;
  packetCarStatusData carStatus;
  packetFinalClassificationData finalClassification;
  PacketLobbyInfoData lobbyInfo;

  //Array contenants les adresses de tous les paquets
  //Transformer en enum class ???
  void* packetTypes[10] = {
    &motion,
    &session,
    &lap,
    &event,
    &participants,
    &setup,
    &telemetry,
    &carStatus,
    &finalClassification,
    &lobbyInfo
  };

  int packetSizes[10] {
    sizeof(motion),
    sizeof(session),
    sizeof(lap),
    sizeof(event),
    sizeof(participants),
    sizeof(setup),
    sizeof(telemetry),
    sizeof(carStatus),
    sizeof(finalClassification),
    sizeof(lobbyInfo)
  };


public:
  //Cette fonction permet de déterminer le type de paquet, et selon, mettre à jour les données
  void handlePacket(void* rawPacket, int* rawPacketSize) {
    memset(&header, 0, sizeof header);
    //L'on vérifie s'il y a au moins un header
    if (*rawPacketSize < (int)sizeof(header)) {
      return;
    }
    //On copie les données du header
    std::memcpy(&header, rawPacket, sizeof(header));

    //L'on vérifie si la taille du paquet est correct
    if (*rawPacketSize < packetSizes[header.m_packetId]) {
      return;
    }

    //Si c'est bon, on copie les données au bon endroit
    std::memcpy(packetTypes[header.m_packetId], rawPacket, packetSizes[header.m_packetId]);

    //Envoi du signal, données prêtes !
    emit dataReady(header.m_packetId, packetTypes[header.m_packetId]);
    return;
  };
  signals:
    void dataReady(uint8_t packetId, void* packet);

};

#endif
