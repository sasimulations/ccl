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
 *  FILENAME:   CigiBaseCelestialResp.cpp
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

#include "CigiBaseCelestialResp.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiBaseCelestialResp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCelestialResp::CigiBaseCelestialResp()
{
    SunAzimuth = 0.0;
    SunElevation = 0.0;
    MoonAzimuth = 0.0;
    MoonElevation = 0.0;
    MoonOrientation = 0.0;
    MoonPhase = 0.0;
}



// ================================================
// ~CigiBaseCelestialResp
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseCelestialResp::~CigiBaseCelestialResp()
{

}


// ====================================================================
// Conversion Control
// ====================================================================


// ================================================
// GetCnvt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCelestialResp::GetCnvt(CigiVersionID &CnvtVersion,
                                     CigiCnvtInfoType::Type &CnvtInfo)
{
   if(CnvtVersion.CigiMajorVersion < 4 || (CnvtVersion.CigiMajorVersion == 4 && CnvtVersion.CigiMinorVersion < 1))
   {
      CnvtInfo.ProcID = CigiProcessType::ProcNone;
      CnvtInfo.CnvtPacketID = 0;
   }
   else
   {
      CnvtInfo.ProcID = CigiProcessType::ProcStd;
      CnvtInfo.CnvtPacketID = CIGI_CELESTIAL_RESP_PACKET_ID_V4_1;
   }

   return(CIGI_SUCCESS);
}

// ====================================================================
// Accessors
// ====================================================================


// ================================================
// SetSunAzimuth
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCelestialResp::SetSunAzimuth(const float SunAzimuthIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
    if (bndchk && ((SunAzimuthIn < 0.0f) || (SunAzimuthIn > 360.0f)))
    {
#ifndef CIGI_NO_EXCEPT
	throw CigiValueOutOfRangeException("SunAzimuth", (double)SunAzimuthIn, 00.0, 360.0);
#endif
	return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
    }
#endif

    SunAzimuth = SunAzimuthIn;

    return(CIGI_SUCCESS);

}


// ================================================
// SunElevation
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCelestialResp::SetSunElevation(const float SunElevationIn, bool bndchk)
{
#ifndef CIGI_NO_BND_CHK
    if (bndchk && ((SunElevationIn < -90.0f) || (SunElevationIn > 90.0f)))
    {
#ifndef CIGI_NO_EXCEPT
	throw CigiValueOutOfRangeException("SunElevation", (double)SunElevationIn, -90.0, 90.0);
#endif
	return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
    }
#endif

   SunElevation = SunElevationIn;
   return(CIGI_SUCCESS);

}


// ================================================
// MoonAzimuth
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCelestialResp::SetMoonAzimuth(const float MoonAzimuthIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (MoonAzimuthIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("MoonAzimuth",(float)MoonAzimuthIn,">",0.0);
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
int CigiBaseCelestialResp::SetMoonElevation(const float MoonElevationIn, bool bndchk)
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
// MoonOrientation
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCelestialResp::SetMoonOrientation(const float MoonOrientationIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((MoonOrientationIn < 0.0)||(MoonOrientationIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("MoonOrientation",(float)MoonOrientationIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   MoonOrientation = MoonOrientationIn;
   return(CIGI_SUCCESS);

}


// ================================================
// MoonPhase
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseCelestialResp::SetMoonPhase(const float MoonPhaseIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((MoonPhaseIn < 0.0) || ((MoonPhaseIn > 1.0))))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("MoonPhase",(float)MoonPhaseIn,">",0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   MoonPhase = MoonPhaseIn;
   return(CIGI_SUCCESS);

}


