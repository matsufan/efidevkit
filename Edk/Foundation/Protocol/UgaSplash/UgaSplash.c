/*++

Copyright 2004, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

Module Name:
  
    UgaSplash.c

Abstract:

  UGA Splash protocol from the EFI 1.1 specification.

  Abstraction of a very simple graphics device splash screen.

--*/

#include "Tiano.h"
#include EFI_PROTOCOL_DEFINITION (UgaSplash)


EFI_GUID gEfiUgaSplashProtocolGuid = EFI_UGA_SPLASH_PROTOCOL_GUID;

EFI_GUID_STRING (&gEfiUgaSplashProtocolGuid, "UGA Splash Protocol", "EFI 1.1 UGA Splash Protocol");

