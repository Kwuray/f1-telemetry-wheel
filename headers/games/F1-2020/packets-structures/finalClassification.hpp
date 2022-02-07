//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// This packet details the final classification at the end of the race,
// and the data will match with the post race results screen.
// This is especially useful for multiplayer games where it is not always
// possible to send lap times on the final frame because of network delay.

// Frequency: Once at the end of a race
// Size: 839 bytes (Packet size updated in Beta 3)
// Version: 1
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_F120PACKFINALCLASSIF
#define DEF_F120PACKFINALCLASSIF

#include "header.hpp"

struct __attribute__((packed)) finalClassificationData {

  uint8_t     m_position;              // Finishing position
  uint8_t     m_numLaps;               // Number of laps completed
  uint8_t     m_gridPosition;          // Grid position of the car
  uint8_t     m_points;                // Number of points scored
  uint8_t     m_numPitStops;           // Number of pit stops made
  uint8_t     m_resultStatus;          // Result status - 0 = invalid, 1 = inactive, 2 = active
                                       // 3 = finished, 4 = disqualified, 5 = not classified
                                       // 6 = retired
  float       m_bestLapTime;           // Best lap time of the session in seconds
  double      m_totalRaceTime;         // Total race time in seconds without penalties
  uint8_t     m_penaltiesTime;         // Total penalties accumulated in seconds
  uint8_t     m_numPenalties;          // Number of penalties applied to this driver
  uint8_t     m_numTyreStints;         // Number of tyres stints up to maximum
  uint8_t     m_tyreStintsActual[8];   // Actual tyres used by this driver
  uint8_t     m_tyreStintsVisual[8];   // Visual tyres used by this driver

};

struct __attribute__((packed)) packetFinalClassificationData {

  packetHeader    	         m_header;           // Header
  uint8_t                    m_numCars;                 // Number of cars in the final classification
  finalClassificationData    m_classificationData[22];
};

#endif
