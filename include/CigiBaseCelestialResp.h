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
 *  FILENAME:   CigiBaseCelestialResp.h
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


#if !defined(_CIGI_BASE_CELESTIAL_RESP_INCLUDED_)
#define _CIGI_BASE_CELESTIAL_RESP_INCLUDED_

#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_CELESTIAL_RESP_PACKET_ID_V4_1 0x0fEf
#define CIGI_CELESTIAL_RESP_PACKET_SIZE_V4_1 32


class CigiCelestialRespV4_1;


class CIGI_SPEC CigiBaseCelestialResp : public CigiBasePacket
{

friend class CigiCelestialRespV4_1;

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseCelestialResp();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseCelestialResp();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A pure virtual Pack function.  
   //! This function is not implemented in this class.
   //! \param Base - A pointer to the instance of the packet 
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const=0;

   //=========================================================
   //! A pure virtual Unpack function.
   //! This function is not implemented in this class.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec) =0;

   //=========================================================
   //! A virtual Conversion Information function.
   //! This function provides conversion information for this
   //!  packet.
   //! \param CnvtVersion - The CIGI version to which this packet
   //!    is being converted.
   //! \param CnvtInfo - The information needed for conversion
   //!    
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int GetCnvt(CigiVersionID &CnvtVersion,
                       CigiCnvtInfoType::Type &CnvtInfo);



   //==> Accessing Member Variable Values functions


   //+> SunAzimuth

   //=========================================================
   //! Sets the SunAzimuth with bound checking control
   //! \param SunAzimuthIn - air temperature
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
    int SetSunAzimuth(const float SunAzimuthIn, bool bndchk = true);

   //=========================================================
   //! Gets the SunAzimuth value.
   //! \return the current SunAzimuth.
   float GetSunAzimuth(void) const { return(SunAzimuth); }


   //+> SunElevation

   //=========================================================
   //! Sets the SunElevation with bound checking control
   //! \param SunElevationIn - SunElevation range
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSunElevation(const float SunElevationIn, bool bndchk=true);

   //=========================================================
   //! Gets the SunElevation value.
   //! \return the current SunElevation.
   float GetSunElevation(void) const { return(SunElevation); }


   //+> MoonAzimuth

   //=========================================================
   //! Sets the MoonAzimuth with bound checking control
   //! \param MoonAzimuthIn - Horizontal wind speed
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetMoonAzimuth(const float MoonAzimuthIn, bool bndchk=true);

   //=========================================================
   //! Gets the MoonAzimuth value.
   //! \return the current MoonAzimuth.
   float GetMoonAzimuth(void) const { return(MoonAzimuth); }


   //+> MoonElevation

   //=========================================================
   //! Sets the MoonElevation with bound checking control
   //! \param MoonElevationIn - Vertical wind speed
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetMoonElevation(const float MoonElevationIn, bool bndchk = true);

   //=========================================================
   //! Gets the MoonElevation value.
   //! \return the current MoonElevation.
   float GetMoonElevation(void) const { return(MoonElevation); }


   //+> MoonOrientation

   //=========================================================
   //! Sets the MoonOrientation with bound checking control
   //! \param MoonOrientationIn - Wind direction
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetMoonOrientation(const float MoonOrientationIn, bool bndchk=true);

   //=========================================================
   //! Gets the MoonOrientation value.
   //! \return the current MoonOrientation.
   float GetMoonOrientation(void) const { return(MoonOrientation); }


   //+> MoonPhase

   //=========================================================
   //! Sets the MoonPhase with bound checking control
   //! \param MoonPhaseIn - Barometric pressure
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetMoonPhase(const float MoonPhaseIn, bool bndchk=true);

   //=========================================================
   //! Gets the MoonPhase value.
   //! \return the current MoonPhase.
   float GetMoonPhase(void) const { return(MoonPhase); }



protected:

   //==> Member variables

   //=========================================================
   //! SunAzimuth<br>
   //! Air temperature
   //!
   float SunAzimuth;

   //=========================================================
   //! SunElevation<br>
   //! SunElevation range
   //!
   float SunElevation;

   //=========================================================
   //! MoonAzimuth<br>
   //! Horizontal wind speed
   //!
   float MoonAzimuth;

   //=========================================================
   //! MoonElevation<br>
   //! Vertical wind speed
   //!
   float MoonElevation;

   //=========================================================
   //! MoonOrientation<br>
   //! Wind direction
   //!
   float MoonOrientation;

   //=========================================================
   //! MoonPhase<br>
   //! Barometric pressure
   //!
   float MoonPhase;


};

#endif // #if !defined(_CIGI_BASE_CELESTIAL_RESP_INCLUDED_)
