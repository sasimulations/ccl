/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiCelestialRespV4_1.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  2/26/2026 Paul Slade                      Version 4.1.0
 *  Initial implementation.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiCelestialRespV4_1.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiCelestialRespV4_1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiCelestialRespV4_1::CigiCelestialRespV4_1() : CigiBaseCelestialResp()
{

   PacketID = CIGI_CELESTIAL_RESP_PACKET_ID_V4_1;
   PacketSize = CIGI_CELESTIAL_RESP_PACKET_SIZE_V4_1;
   Version = 4;
   MinorVersion = 1;

}

// ================================================
// ~CigiCelestialRespV4_1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiCelestialRespV4_1::~CigiCelestialRespV4_1()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiCelestialRespV4_1::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseCelestialResp * Data = ( CigiBaseCelestialResp *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.f++ = Data->SunAzimuth;
   *CDta.f++ = Data->SunElevation;
   *CDta.f++ = Data->MoonAzimuth;
   *CDta.f++ = Data->MoonElevation;
   *CDta.f++ = Data->MoonOrientation;
   *CDta.f++ = Data->MoonPhase;


   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiCelestialRespV4_1::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
      SunAzimuth = *CDta.f++;
      SunElevation = *CDta.f++;
      MoonAzimuth = *CDta.f++;
      MoonElevation = *CDta.f++;
      MoonOrientation = *CDta.f++;
      MoonPhase = *CDta.f++;
   }
   else
   {
      CigiSwap4(&SunAzimuth, CDta.f++);
      CigiSwap4(&SunElevation, CDta.f++);
      CigiSwap4(&MoonAzimuth, CDta.f++);
      CigiSwap4(&MoonElevation, CDta.f++);
      CigiSwap4(&MoonOrientation, CDta.f++);
      CigiSwap4(&MoonPhase, CDta.f++);
   }

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


