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
 *  FILENAME:   CigiPositionRespV4_1.h
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
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Moved Packet information to base packet.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiPositionRespV3.h
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_POSITION_RESP_V4_1_INCLUDED_)
#define _CIGI_POSITION_RESP_V4_1_INCLUDED_

#include "CigiBasePositionResp.h"


class CIGI_SPEC CigiPositionRespV4_1 : public CigiBasePositionResp
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiPositionRespV4_1();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiPositionRespV4_1();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 4
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
   //! The virtual Unpack function for CIGI 4
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
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
   //! \param XIn - X
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetX(const double XIn, bool bndchk = true) {
       LatOrXoff = XIn;
       return(CIGI_SUCCESS);
   }


   //=========================================================
   //! Gets the X value.
   //! \return the current X.
   double GetX(void) const { return(LatOrXoff); }

   //+> Y

   //=========================================================
   //! Sets the Y with bound checking control
   //! \param YIn - Y
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetY(const double YIn, bool bndchk = true) {
       LonOrYoff = YIn;
       return(CIGI_SUCCESS);
   }


   //=========================================================
   //! Gets the Y value.
   //! \return the current Y.
   double GetY(void) const { return(LonOrYoff); }

   //+> Z

   //=========================================================
   //! Sets the Z with bound checking control
   //! \param ZIn - Z
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetZ(const double ZIn, bool bndchk = true) {
       AltOrZoff = ZIn;
       return(CIGI_SUCCESS);
   }


   //=========================================================
   //! Gets the Z value.
   //! \return the current Z.
   double GetZ(void) const { return(AltOrZoff); }


};

#endif // #if !defined(_CIGI_POSITION_RESP_V4_1_INCLUDED_)
