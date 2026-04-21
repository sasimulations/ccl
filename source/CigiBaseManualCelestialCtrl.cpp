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
 *  FILENAME:   CigiBasePositionCtrl.cpp
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
 *  Author: TJ Inc.
 *
 */


#define _EXPORT_CCL_

#include "CigiBaseManualCelestialCtrl.h"
#include "CigiExceptions.h"

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseManualCelestialCtrl::CigiBaseManualCelestialCtrl()
{
    EntityID = 0;
    MoonOrientation = 0.0f;
    MoonPhase = 0.0f;

    SunElevation = 0.0f;
    SunAzimuth = 0.0f;
    MoonElevation = 0.0f;
    MoonAzimuth = 0.0f;
    SourceLatOrXoff = 0.0f;
    SourceLonOrYoff = 0.0f;
    SourceAltOrZoff = 0.0f;

    EntityReferenceEn = false;
    SunEn = false;
    MoonEn = false;
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseManualCelestialCtrl::~CigiBaseManualCelestialCtrl()
{

}


// ====================================================================
// Conversion Control
// ====================================================================


// ================================================
// GetCnvt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::GetCnvt(CigiVersionID &CnvtVersion,
                                CigiCnvtInfoType::Type &CnvtInfo)
{
    if (CnvtVersion.CigiMajorVersion < 4)
    {
	CnvtInfo.ProcID = CigiProcessType::ProcNone;
	CnvtInfo.CnvtPacketID = 0;
    }
    else {
	CnvtInfo.ProcID = CigiProcessType::ProcStd;
	CnvtInfo.CnvtPacketID = CIGI_MANUAL_CELESTIAL_CTRL_PACKET_ID_V4_1;
    }
   return(CIGI_SUCCESS);
}


// ====================================================================
// Accessors
// ====================================================================

// ================================================
// SetSunAzimuth
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::SetSunAzimuth(const float SunAzimuthIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((SunAzimuthIn < 0.0f)||(SunAzimuthIn > 360.0f)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("SunAzimuth",(double)SunAzimuthIn,00.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   SunAzimuth = SunAzimuthIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetSunElevation
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::SetSunElevation(const float SunElevationIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((SunElevationIn < -90.0f)||(SunElevationIn > 90.0f)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("SunElevation",(double)SunElevationIn,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   SunElevation = SunElevationIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetMoonAzimuth
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::SetMoonAzimuth(const float MoonAzimuthIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((MoonAzimuthIn < 0.0f)||(MoonAzimuthIn > 360.0f)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("MoonAzimuth",(double)MoonAzimuthIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   MoonAzimuth = MoonAzimuthIn;
   return(CIGI_SUCCESS);

}

// ================================================
// SetMoonElevation
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::SetMoonElevation(const float MoonElevationIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
    if (bndchk && ((MoonElevationIn < -90.0f) || (MoonElevationIn > 90.0f)))
    {
#ifndef CIGI_NO_EXCEPT
	throw CigiValueOutOfRangeException("MoonElevation", (double)MoonElevationIn, -90.0, 90.0);
#endif
	return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
    }
#endif

    MoonElevation = MoonElevationIn;

    return(CIGI_SUCCESS);

}

// ================================================
// SetLat
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::SetSourceLat(const double Lat, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((Lat < -90.0f)||(Lat > 90.0f)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Lat",Lat,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   SourceLatOrXoff = Lat;

   return(CIGI_SUCCESS);

}

// ================================================
// SetLon
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseManualCelestialCtrl::SetSourceLon(const double Lon, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((Lon < -180.0f)||(Lon > 180.0f)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Lon",Lon,-180.0,180.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   SourceLonOrYoff = Lon;

   return(CIGI_SUCCESS);

}


