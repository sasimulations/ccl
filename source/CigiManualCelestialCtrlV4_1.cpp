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
 *  FILENAME:   CigiEntityCtrlV4.cpp
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
 *
 *  2/26/2026 Paul Slade                      Version 4.1.0
 *  Initial implementation.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiManualCelestialCtrlV4_1.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiManualCelestialCtrlV4_1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiManualCelestialCtrlV4_1::CigiManualCelestialCtrlV4_1() : CigiBaseManualCelestialCtrl()
{

   PacketID = CIGI_MANUAL_CELESTIAL_CTRL_PACKET_ID_V4_1;
   PacketSize = CIGI_MANUAL_CELESTIAL_CTRL_PACKET_SIZE_V4_1;
   Version = 4;
   MinorVersion = 1;

}

// ================================================
// ~CigiManualCelestialCtrlV4_1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiManualCelestialCtrlV4_1::~CigiManualCelestialCtrlV4_1()
{

}


// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiManualCelestialCtrlV4_1::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseManualCelestialCtrl *Data = ( CigiBaseManualCelestialCtrl *) Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   Cigi_uint8 HDta = (Cigi_uint8)((Data->EntityReferenceEn ? 0x04 : 0) |
                                 (Data->SunEn ? 0x01 : 0) |
				 (Data->MoonEn ? 0x02 : 0));

   *CDta.c++ = HDta;
   *CDta.c++ = 0; // reserved
   *CDta.s++ = Data->EntityID;
   
   *CDta.d++ = Data->SourceLatOrXoff;
   *CDta.d++ = Data->SourceLonOrYoff;
   *CDta.d++ = Data->SourceAltOrZoff;

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
int CigiManualCelestialCtrlV4_1::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{

   PackPointer CDta;

   Cigi_uint8 HDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size

   if(!Swap)
   {
	   HDta = *CDta.c++;
	   *CDta.c++; // reserved

	   EntityID = *CDta.s++;

	   SourceLatOrXoff = *CDta.d++;
	   SourceLonOrYoff = *CDta.d++;
	   SourceAltOrZoff = *CDta.d++;

	   SunAzimuth = *CDta.f++;
	   SunElevation = *CDta.f++;
	   MoonAzimuth = *CDta.f++;
	   MoonElevation = *CDta.f++;

	   MoonOrientation = *CDta.f++;
	   MoonPhase = *CDta.f++;
   }
   else
   {
	   HDta = *CDta.c++;
	   *CDta.c++; // reserved

	   CigiSwap2(&EntityID, CDta.s++);

	   CigiSwap8(&SourceLatOrXoff, CDta.d++);
	   CigiSwap8(&SourceLonOrYoff, CDta.d++);
	   CigiSwap8(&SourceAltOrZoff, CDta.d++);

	   CigiSwap4(&SunAzimuth, CDta.f++);
	   CigiSwap4(&SunElevation, CDta.f++);
	   CigiSwap4(&MoonAzimuth, CDta.f++);
	   CigiSwap4(&MoonElevation, CDta.f++);

	   CigiSwap4(&MoonOrientation, CDta.f++);
	   CigiSwap4(&MoonPhase, CDta.f++);

   }

   EntityReferenceEn = (HDta & 0x04) != 0;
   SunEn = (HDta & 0x01) != 0;
   MoonEn = (HDta & 0x02) != 0;

   return(CIGI_SUCCESS);

}


// ====================================================================
// Accessors
// ====================================================================

