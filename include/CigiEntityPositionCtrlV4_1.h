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
 *  FILENAME:   CigiEntityPositionCtrlV4.h
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
 *  07/29/2015 Chas Whitley                       Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiEntityCtrlV3_3.h"
  *  
 *  02/23/2026 Paul Slade                       Version 4.1.0
 *  Updated to support CIGI 4.1
*
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_ENTITY_POSITION_CONTROL_V4_1)
#define _CIGI_ENTITY_POSITION_CONTROL_V4_1



#include "CigiBaseEntityPositionCtrl.h"





//=========================================================
//! The class for the Entity Control packet for CIGI version 4
//!
class CIGI_SPEC CigiEntityPositionCtrlV4_1 : public CigiBaseEntityPositionCtrl
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiEntityPositionCtrlV4_1();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiEntityPositionCtrlV4_1();



   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 1
   //! \param Base - A pointer to the instance of the packet 
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const;

   //=========================================================
   //! The virtual Unpack function for CIGI 1
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - Byte swapping required.
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec);


   //==> Accessing Member Variable Values functions

   //+> X 
   //=========================================================
   //! Sets the X with bound checking control
   //! \param X - Specifies the X value.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
    int SetX(const double X, bool bndchk = true)
    {
	LatOrXoff = X;
	return(CIGI_SUCCESS);
    }

    //=========================================================
    //! Gets the X value
    //! \return LatOrXoff specifies the X value
    //!
    double GetX(void) const { return(LatOrXoff); }

    //+> Y 

    //=========================================================
    //! Sets the Y value with bound checking control
    //! \param Y - Specifies the Y value.
    //! \param bndchk - Enables (true) or disables (false) bounds checking
    //!
    //! \return This returns CIGI_SUCCESS or an error code 
    //!   defined in CigiErrorCodes.h
    //!
    int SetY(const double Y, bool bndchk = true)
    {
	LonOrYoff = Y;
	return(CIGI_SUCCESS);
    }

    //=========================================================
    //! Gets the Y value
    //! \return LonOrYoff specifies the Y value.
    //!
    double GetY(void) const { return(LonOrYoff); }


    //+> Z

    //=========================================================
    //! Sets the Z value with bound checking control
    //! \param Z - Specifies the Z value.
    //! \param bndchk - Enables (true) or disables (false) bounds checking
    //!
    //! \return This returns CIGI_SUCCESS or an error code 
    //!   defined in CigiErrorCodes.h
    //!
    int SetZ(const double Z, bool bndchk = true)
    {
	AltOrZoff = Z;
	return(CIGI_SUCCESS);
    }

    //=========================================================
    //! Gets the Z value
    //! \return LonOrZoff specifies the Z value.
    //!
    double GetZ(void) const { return(AltOrZoff); }


    //+> Lerp duration
    //=========================================================
    //! Sets the lerp duration
    //! \param lerpDurationIn - Specifies the lerp duration.
    //! \param bndchk - Enables (true) or disables (false) bounds checking
    //!
    //! \return This returns CIGI_SUCCESS or an error code 
    //!   defined in CigiErrorCodes.h
    //!
    int SetLerpDuration(const Cigi_uint8 lerpDurationIn, bool bndchk = true)
    {
	LerpDuration = lerpDurationIn;
	return(CIGI_SUCCESS);
    }

    //=========================================================
    //! Gets the lerp duration
    //! \return lerp duration
    //!
    Cigi_uint8 GetLerpDuration(void) const { return(LerpDuration); }

    //+> Parent Attach Point ID
    //=========================================================
    //! Sets the Parent Attach Point ID
    //! \param attachPointIDIn - Specifies the Parent Attach Point ID.
    //! \param bndchk - Enables (true) or disables (false) bounds checking
    //!
    //! \return This returns CIGI_SUCCESS or an error code 
    //!   defined in CigiErrorCodes.h
    //!
    int SetParentAttachPointID(const Cigi_uint16 attachPointIDIn, bool bndchk = true)
    {
	ParentAttachPointID = attachPointIDIn;
	return(CIGI_SUCCESS);
    }

    //=========================================================
    //! Gets the Parent Attach Point ID
    //! \return Parent Attach Point ID
    //!
    Cigi_uint16 GetParentAttachPointID(void) const { return(ParentAttachPointID); }
 
    //+> Child Attach Point ID
    //=========================================================
    //! Sets the Child Attach Point ID
    //! \param attachPointIDIn - Specifies the Child Attach Point ID.
    //! \param bndchk - Enables (true) or disables (false) bounds checking
    //!
    //! \return This returns CIGI_SUCCESS or an error code 
    //!   defined in CigiErrorCodes.h
    //!
    int SetChildAttachPointID(const Cigi_uint16 attachPointIDIn, bool bndchk = true)
    {
	ChildAttachPointID = attachPointIDIn;
	return(CIGI_SUCCESS);
    }

    //=========================================================
    //! Gets the Child Attach Point ID
    //! \return Child Attach Point ID
    //!
    Cigi_uint16 GetChildAttachPointID(void) const { return(ChildAttachPointID); }


};

#endif // #if !defined(_CIGI_ENTITY_CONTROL_V4)
