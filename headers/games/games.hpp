//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// Cette classe définit les différents jeux
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_SELECTEDGAMES
#define DEF_SELECTEDGAMES

#include "F1-2020/packetManager.hpp"

enum class Game {F12020, F12021};

union managerUnion {
  F12020_packetManager* F12020_manager;
};

#endif
