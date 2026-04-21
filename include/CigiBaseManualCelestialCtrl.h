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
 *  FILENAME:   CigiBasePositionCtrl.h
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

#if !defined(_CIGI_BASE_MANUAL_CELESTIAL_CTRL_INCLUDED_)
#define _CIGI_BASE_MANUAL_CELESTIAL_CTRL_INCLUDED_

#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_MANUAL_CELESTIAL_CTRL_PACKET_ID_V4_1 0x27
#define CIGI_MANUAL_CELESTIAL_CTRL_PACKET_SIZE_V4_1 56


class CigiManualCelestialCtrlV4_1;


//=========================================================
//! The base class for the Entity Control packet
//!
class CIGI_SPEC CigiBaseManualCelestialCtrl : public CigiBasePacket  
{

friend class CigiManualCelestialCtrlV4_1;

public:



   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiBaseManualCelestialCtrl();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiBaseManualCelestialCtrl();



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

   //+> Entity ID

   //=========================================================
   //! Sets the Entity ID with bound checking control
   //! \param EntityIDIn - Uniquely identifies the specific entity
   //!   0 - The ownship
   //!   All other values - An Application defined entity
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetEntityID(const Cigi_uint16 EntityIDIn, bool bndchk=true)
   {
      EntityID = EntityIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Entity ID value
   //! \return EntityID uniquely identifies the specific entity
   //!   0 - The ownship
   //!   All other values - An Application defined entity
   //!
   Cigi_uint16 GetEntityID(void) const { return(EntityID); }

   //+> MoonOrientation

   //=========================================================
   //! Sets the MoonOrientation with bound checking control
   //! \param MoonOrientationIn - specifies to the orientation of the moon,
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetMoonOrientation(const float MoonOrientationIn, bool bndchk=true)
   {
      MoonOrientation = MoonOrientationIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the MoonOrientation value
   //! \return MoonOrientation specifies to the orientation of the moon,
   //!   if this is an attached entity.
   //!
   float GetMoonOrientation(void) const { return(MoonOrientation); }

   //+> MoonPhase

   //=========================================================
   //! Sets the MoonPhase with bound checking control
   //! \param MoonPhaseIn - specifies to the Phaseation of the moon,
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetMoonPhase(const float MoonPhaseIn, bool bndchk = true)
   {
       MoonPhase = MoonPhaseIn;
       return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the MoonPhase value
   //! \return MoonPhase specifies to the Phaseation of the moon,
   //!   if this is an attached entity.
   //!
   float GetMoonPhase(void) const { return(MoonPhase); }

   //+> Attach State

   //=========================================================
   //! Sets the Attach State with bound checking control
   //! \param EntityReferenceEnIn - Specifies source coordinates are relative to specified entity
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetEntityReferenceEn(const bool EntityReferenceEnIn, bool bndchk = true)
   {
       EntityReferenceEn = EntityReferenceEnIn;
       return(CIGI_SUCCESS);

    }

   //=========================================================
   //! Gets the Attach State value
   //! \return EntityReferenceEn specifies whether this entity is independant
   //!   or attached to a parent entity.
   //!   0 Detach
   //!   1 Attach
   //!
   bool GetEntityReferenceEn(void) const { return(EntityReferenceEn); }


   //+> SunEn

   //=========================================================
   //! Sets the SunEn with bound checking control
   //! \param SunEnIn - Specifies if manual sun position is enabled
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
    int SetSunEn(const bool SunEnIn, bool bndchk=true)
    {
	SunEn = SunEnIn;
	return(CIGI_SUCCESS);
    }


   //=========================================================
   //! Gets the Attach State Flag value
   //! \return SunEnIn - Specifies if manual sun position is enabled
   //!
   bool GetSunEn(void) const { return(SunEn); }


   //+> MoonEn

   //=========================================================
   //! Sets the MoonEn with bound checking control
   //! \param MoonEnIn - Specifies if manual sun position is enabled
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetMoonEn(const bool MoonEnIn, bool bndchk = true)
   {
       MoonEn = MoonEnIn;
       return(CIGI_SUCCESS);
   }


   //=========================================================
   //! Gets the Attach State Flag value
   //! \return MoonEnIn - Specifies if manual sun position is enabled
   //!
   bool GetMoonEn(void) const { return(MoonEn); }

   //+> SunAzimuth

   //=========================================================
   //! Sets the SunAzimuth with bound checking control
   //! \param SunAzimuthIn - Specifies the SunAzimuth
   //!   (0.0 to +360.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSunAzimuth(const float SunAzimuthIn, bool bndchk=true);

   //=========================================================
   //! Gets the SunAzimuth value
   //! \return SunAzimuth specifies the SunAzimuth
   //!   (-90.0 to +90.0)
   //!
   float GetSunAzimuth(void) const { return(SunAzimuth); }


   //+> SunElevation

   //=========================================================
   //! Sets the SunElevation with bound checking control
   //! \param SunElevationIn - Specifies the SunElevation
   //!   (-90.0 to +90.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSunElevation(const float SunElevationIn, bool bndchk=true);

   //=========================================================
   //! Gets the SunElevation value
   //! \return SunElevation specifies the SunElevation of the entity
   //!   (-180.0 to +180.0)
   //!
   float GetSunElevation(void) const { return(SunElevation); }

   //+> MoonAzimuth

   //=========================================================
   //! Sets the MoonAzimuth with bound checking control
   //! \param MoonAzimuthIn - The MoonAzimuth in degrees.<br>
   //!   (0 - 360.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetMoonAzimuth(const float MoonAzimuthIn, bool bndchk=true);

   //=========================================================
   //! Gets the MoonAzimuth value
   //! \return The MoonAzimuth of the entity in degrees.<br>
   //!   (0 to 360.0)
   //!
   float GetMoonAzimuth(void) const { return(MoonAzimuth); }


   //+> MoonElevation

   //=========================================================
   //! Sets the MoonElevation with bound checking control
   //! \param MoonElevationIn - Specifies the MoonElevation
   //!   (-90.0 to +90.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetMoonElevation(const float MoonElevationIn, bool bndchk = true);

   //=========================================================
   //! Gets the MoonElevation value
   //! \return MoonElevation specifies the MoonElevation of the entity
   //!   (-180.0 to +180.0)
   //!
   float GetMoonElevation(void) const { return(MoonElevation); }

   //+> X Offset

   //=========================================================
   //! Sets the X Offset with bound checking control
   //! \param Xoff - Specifies the X axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSourceXoff(const double Xoff,bool bndchk=true)
   {
      SourceLatOrXoff = Xoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the X Offset value
   //! \return SourceLatOrXoff specifies the X axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetSourceXoff(void) const { return(SourceLatOrXoff); }

   //+> Y Offset

   //=========================================================
   //! Sets the Y Offset with bound checking control
   //! \param Yoff - Specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSourceYoff(const double Yoff, bool bndchk=true)
   {
      SourceLonOrYoff = Yoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Y Offset value
   //! \return SourceLonOrYoff specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetSourceYoff(void) const { return(SourceLonOrYoff); }


   //+> Z Offset

   //=========================================================
   //! Sets the Z Offset with bound checking control
   //! \param Zoff - Specifies the Z axis Offset from 
   //!   the Parent entity's origin.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSourceZoff(const double Zoff, bool bndchk=true)
   {
      SourceAltOrZoff = Zoff;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Y Offset value
   //! \return SourceLonOrYoff specifies the Y axis Offset from 
   //!   the Parent entity's origin.
   //!
	double GetSourceZoff(void) const { return(SourceAltOrZoff); }

	//+> X

	//=========================================================
	//! Sets the X with bound checking control
	//! \param Xoff - Specifies the X 
	//! \param bndchk - Enables (true) or disables (false) bounds checking
	//!
	//! \return This returns CIGI_SUCCESS or an error code 
	//!   defined in CigiErrorCodes.h
	//!
	int SetSourceX(const double X, bool bndchk = true)
	{
	    SourceLatOrXoff = X;
	    return(CIGI_SUCCESS);
	}

	//=========================================================
	//! Gets the X value
	//! \return SourceLatOrXoff specifies the X 
	//!
	double GetSourceX(void) const { return(SourceLatOrXoff); }

	//+> Y

	//=========================================================
	//! Sets the Y with bound checking control
	//! \param Yoff - Specifies the Y 
	//! \param bndchk - Enables (true) or disables (false) bounds checking
	//!
	//! \return This returns CIGI_SUCCESS or an error code 
	//!   defined in CigiErrorCodes.h
	//!
	int SetSourceY(const double Y, bool bndchk = true)
	{
	    SourceLonOrYoff = Y;
	    return(CIGI_SUCCESS);
	}

	//=========================================================
	//! Gets the Y Offset value
	//! \return SourceLonOrYoff specifies the Y axis Offset from 
	//!   the Parent entity's origin.
	//!
	double GetSourceY(void) const { return(SourceLonOrYoff); }


	//+> Z

	//=========================================================
	//! Sets the Z with bound checking control
	//! \param Zoff - Specifies the Z
	//! \param bndchk - Enables (true) or disables (false) bounds checking
	//!
	//! \return This returns CIGI_SUCCESS or an error code 
	//!   defined in CigiErrorCodes.h
	//!
	int SetSourceZ(const double Z, bool bndchk = true)
	{
	    SourceAltOrZoff = Z;
	    return(CIGI_SUCCESS);
	}

	//=========================================================
	//! Gets the Y Offset value
	//! \return SourceLonOrYoff specifies the Y axis Offset from 
	//!   the Parent entity's origin.
	//!
	double GetSourceZ(void) const { return(SourceAltOrZoff); }

   //+> Source Latitude

   //=========================================================
   //! Sets the Source Latitude with bound checking control
   //! \param Lat - Specifies the Latitude of the entity
   //!   (-90.0 to +90.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSourceLat(const double Lat, bool bndchk=true);

   //=========================================================
   //! Gets the Source Latitude value
   //! \return SourceLatOrXoff specifies the Latitude of the entity
   //!   (-90.0 to +90.0)
   //!
   double GetSourceLat(void) const { return(SourceLatOrXoff); }



   //+> SourceLongitude

   //=========================================================
   //! Sets the SourceLongitude with bound checking control
   //! \param Lon - Specifies the Longitude of the entity
   //!   (-180.0 to +180.0)
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSourceLon(const double Lon, bool bndchk=true);

   //=========================================================
   //! Getting the Longitude value
   //! \return SourceLonOrYoff specifies the Longitude of the entity
   //!   (-180.0 to +180.0)
   //!
   double GetSourceLon(void) const { return(SourceLonOrYoff); }

   //+> SourceAltitude

   //=========================================================
   //! Sets the Altitude with bound checking control
   //! \param Alt - Specifies the Altitude
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetSourceAlt(const double Alt, bool bndchk=true)
   {
      SourceAltOrZoff = Alt;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Alt Offset value
   //! \return SourceAltOrZoff specifies the Altitude
   //!   the Parent entity's origin.
   //!
	double GetSourceAlt(void) const { return(SourceAltOrZoff); }




protected:

   //==> Member variables

   //=========================================================
   //! Entity ID<br>
   //! Uniquely identifies the specific entity<br>
   //!   0 - The ownship<br>
   //!   All other values - An Application defined entity
   //!
	Cigi_uint16 EntityID;

   //=========================================================
   //! MoonOrientation<br>
   //! Moon orientation.
   //!
	float MoonOrientation;


    //=========================================================
    //! MoonPhase<br>
    //! Moon Phase.
    //!
	float MoonPhase;

   //=========================================================
   //! SunElevation
   //! Specifies the SunElevation of the entity<br>
   //!   (-90.0 to +90.0)
   //!
	float SunElevation;

   //=========================================================
   //! SunAzimuth
   //! Specifies the SunAzimuth of the entity<br>
   //!   (0.0 to +360.0)
   //!
	float SunAzimuth;


    //=========================================================
    //! MoonElevation
    //! Specifies the SunElevation of the entity<br>
    //!   (-90.0 to +90.0)
    //!
    float MoonElevation;
    //=========================================================

   //! MoonAzimuth
   //! Specifies the MoonAzimuth or Heading of the entity<br>
   //!   (0.0 to 360.0)
	float MoonAzimuth;

   //=========================================================
   //! Latitude or X Offset from parent entity origin<br>
   //! Specifies the latitude or X Offset from parent entity origin<br>
   //!   (-90.0 to +90.0 if latitude)<br>
   //!   no bounds if X Offset
   //!
	double SourceLatOrXoff;

   //=========================================================
   //! Longitude or Y Offset from parent entity origin<br>
   //! Specifies the longitude or Y Offset from parent entity origin<br>
   //!   (-180.0 to +180.0 if longitude)<br>
   //!   no bounds if Y Offset
   //!
	double SourceLonOrYoff;

   //=========================================================
   //! Altitude or Z Offset from parent entity origin.<br>
   //! Specifies the longitude or Z Offset from parent entity origin<br>
   //!   (no bounds)
   //!
	double SourceAltOrZoff;

   //==> Member flags

   //=========================================================
   //! Attach State<br>
   //! 0 Detach<br>
   //! 1 Attach<br>
   //!
   bool EntityReferenceEn;


   //=========================================================
   //! Manual Sun Enable<br>
   //! false - sun not manually controlled<br>
   //! true - Sun Manually controlled<br>
   //!
    bool SunEn;

    //=========================================================
    //! Manual moon Enable<br>
    //! false - sun not manually controlled<br>
    //! true - Sun Manually controlled<br>
    //!
    bool MoonEn;

};

#endif  //#if !defined(_CIGI_BASE_MANUAL_CELESTIAL_CTRL_INCLUDED_)
