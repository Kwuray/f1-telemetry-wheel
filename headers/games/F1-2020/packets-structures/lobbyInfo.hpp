//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// This packet details the players currently in a multiplayer lobby.
// It details each player’s selected car, any AI involved in the game and also
// the ready status of each of the participants.

// Frequency: Two every second when in the lobby
// Size: 1169 bytes (Packet size updated in Beta 3)
// Version: 1
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_F120PACKLOBBYINFO
#define DEF_F120PACKLOBBYINFO

#include "header.hpp"

struct __attribute__((packed)) lobbyInfoData {

  uint8_t     m_aiControlled;            // Whether the vehicle is AI (1) or Human (0) controlled
  uint8_t     m_teamId;                  // Team id - see appendix (255 if no team currently selected)
  uint8_t     m_nationality;             // Nationality of the driver
  char        m_name[48];                // Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with ... (U+2026) if too long
  uint8_t     m_readyStatus;             // 0 = not ready, 1 = ready, 2 = spectating
};

struct __attribute__((packed)) PacketLobbyInfoData {

  packetHeader        m_header;                       // Header

  // Packet specific data
  uint8_t               m_numPlayers;               // Number of players in the lobby data
  lobbyInfoData         m_lobbyPlayers[22];
};

#endif
