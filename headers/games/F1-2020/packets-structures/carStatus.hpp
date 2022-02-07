//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// This packet details car statuses for all the cars in the race.
// It includes values such as the damage readings on the car.

// Frequency: Rate as specified in menus
// Size: 1344 bytes (Packet updated in Beta 3)
// Version: 1
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_F120PACKCARSTATUS
#define DEF_F120PACKCARSTATUS

#include "header.hpp"

struct __attribute__((packed)) carStatusData {

  uint8_t       m_tractionControl;          // 0 (off) - 2 (high)
  uint8_t       m_antiLockBrakes;           // 0 (off) - 1 (on)
  uint8_t       m_fuelMix;                  // Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
  uint8_t       m_frontBrakeBias;           // Front brake bias (percentage)
  uint8_t       m_pitLimiterStatus;         // Pit limiter status - 0 = off, 1 = on
  float         m_fuelInTank;               // Current fuel mass
  float         m_fuelCapacity;             // Fuel capacity
  float         m_fuelRemainingLaps;        // Fuel remaining in terms of laps (value on MFD)
  uint16_t      m_maxRPM;                   // Cars max RPM, point of rev limiter
  uint16_t      m_idleRPM;                  // Cars idle RPM
  uint8_t       m_maxGears;                 // Maximum number of gears
  uint8_t       m_drsAllowed;               // 0 = not allowed, 1 = allowed, -1 = unknown

  // Added in Beta3:
  uint16_t      m_drsActivationDistance;    // 0 = DRS not available, non-zero - DRS will be available
                                          // in [X] metres

  uint8_t       m_tyresWear[4];             // Tyre wear percentage
  uint8_t       m_actualTyreCompound;	    // F1 Modern - 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1
   					                                // 7 = inter, 8 = wet
   					                                // F1 Classic - 9 = dry, 10 = wet
   					                                // F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard
   					                                // 15 = wet
  uint8_t       m_visualTyreCompound;        // F1 visual (can be different from actual compound)
                                            // 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
                                            // F1 Classic – same as above
                                            // F2 – same as above
  uint8_t       m_tyresAgeLaps;             // Age in laps of the current set of tyres
  uint8_t       m_tyresDamage[4];           // Tyre damage (percentage)
  uint8_t       m_frontLeftWingDamage;      // Front left wing damage (percentage)
  uint8_t       m_frontRightWingDamage;     // Front right wing damage (percentage)
  uint8_t       m_rearWingDamage;           // Rear wing damage (percentage)

  // Added Beta 3:
  uint8_t       m_drsFault;                 // Indicator for DRS fault, 0 = OK, 1 = fault

  uint8_t       m_engineDamage;             // Engine damage (percentage)
  uint8_t       m_gearBoxDamage;            // Gear box damage (percentage)
  int8_t        m_vehicleFiaFlags;          // -1 = invalid/unknown, 0 = none, 1 = green
                                            // 2 = blue, 3 = yellow, 4 = red
  float         m_ersStoreEnergy;           // ERS energy store in Joules
  uint8_t       m_ersDeployMode;            // ERS deployment mode, 0 = none, 1 = medium
                                            // 2 = overtake, 3 = hotlap
  float         m_ersHarvestedThisLapMGUK;  // ERS energy harvested this lap by MGU-K
  float         m_ersHarvestedThisLapMGUH;  // ERS energy harvested this lap by MGU-H
  float         m_ersDeployedThisLap;       // ERS energy deployed this lap

};

struct __attribute__((packed)) packetCarStatusData {

  packetHeader    	m_header;           // Header
  carStatusData	    m_carStatusData[22];
};

#endif
