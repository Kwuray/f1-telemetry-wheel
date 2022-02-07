//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// The motion packet gives physics data for all the cars being driven.
// There is additional data for the car being driven with the goal of being able
// to drive a motion platform setup.

// N.B. For the normalised vectors below, to convert to float values
// divide by 32767.0f – 16-bit signed values are used to pack the data and on
// the assumption that direction values are always between -1.0f and 1.0f.

// Frequency: Rate as specified in menus
// Size: 1464 bytes (Packet size updated in Beta 3)
// Version: 1
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_F120PACKMOTION
#define DEF_F120PACKMOTION

#include "header.hpp"

struct __attribute__((packed)) carMotionData {

  float         m_worldPositionX;           // World space X position
  float         m_worldPositionY;           // World space Y position
  float         m_worldPositionZ;           // World space Z position
  float         m_worldVelocityX;           // Velocity in world space X
  float         m_worldVelocityY;           // Velocity in world space Y
  float         m_worldVelocityZ;           // Velocity in world space Z
  int16_t       m_worldForwardDirX;         // World space forward X direction (normalised)
  int16_t       m_worldForwardDirY;         // World space forward Y direction (normalised)
  int16_t       m_worldForwardDirZ;         // World space forward Z direction (normalised)
  int16_t       m_worldRightDirX;           // World space right X direction (normalised)
  int16_t       m_worldRightDirY;           // World space right Y direction (normalised)
  int16_t       m_worldRightDirZ;           // World space right Z direction (normalised)
  float         m_gForceLateral;            // Lateral G-Force component
  float         m_gForceLongitudinal;       // Longitudinal G-Force component
  float         m_gForceVertical;           // Vertical G-Force component
  float         m_yaw;                      // Yaw angle in radians
  float         m_pitch;                    // Pitch angle in radians
  float         m_roll;                     // Roll angle in radians
};


struct __attribute__((packed)) packetMotionData {

  packetHeader   m_header;               	// Header
  carMotionData  m_carMotionData[22];    	// Data for all cars on track$

  // Extra player car ONLY data
  float         m_suspensionPosition[4];      // Note: All wheel arrays have the following order:
  float         m_suspensionVelocity[4];      // RL, RR, FL, FR
  float         m_suspensionAcceleration[4];	// RL, RR, FL, FR
  float         m_wheelSpeed[4];           	  // Speed of each wheel
  float         m_wheelSlip[4];               // Slip ratio for each wheel
  float         m_localVelocityX;           	// Velocity in local space
  float         m_localVelocityY;         	  // Velocity in local space
  float         m_localVelocityZ;         	  // Velocity in local space
  float         m_angularVelocityX;		        // Angular velocity x-component
  float         m_angularVelocityY;           // Angular velocity y-component
  float         m_angularVelocityZ;           // Angular velocity z-component
  float         m_angularAccelerationX;       // Angular velocity x-component
  float         m_angularAccelerationY;	      // Angular velocity y-component
  float         m_angularAccelerationZ;       // Angular velocity z-component
  float         m_frontWheelsAngle;           // Current front wheels angle in radians
};

#endif
