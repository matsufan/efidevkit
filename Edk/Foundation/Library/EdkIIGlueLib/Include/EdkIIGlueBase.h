/*++

Copyright (c) 2004 - 2006, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  


Module Name:

  EdkIIGlueBase.h
  
Abstract: 

  Root include file for Base modules

--*/

#ifndef __EDKII_GLUE_BASE_H__
#define __EDKII_GLUE_BASE_H__

//
// General Type & API definitions
//

#include "EfiBind.h"
#include "EfiTypes.h"
#include "EfiError.h"
#include "Common\EdkIIGlueBaseTypes.h"
#include "EfiImage.h"
#include "EfiPeOptionalHeader.h"
#include "EfiStdArg.h"
#include "EfiDebug.h"
#include "EdkIIGlueProcessorBind.h"

//
// Some Status Code data type definitions are in TianoSpecTypes.h in R8.5
//
#if (TIANO_RELEASE_VERSION <= 0x00080005)
#include "TianoSpecTypes.h"
#endif
#include "EfiStatusCode.h"

//
// R8.x Library headers used by EdkII Glue Libraries
//
#include "LinkedList.h"
#include "EfiCommonLib.h"

#include "Common\EdkIIGlueDefinitionChangesBase.h"

//
// EdkII Glue Library Class headers
//

#include "Library\EdkIIGlueBaseLib.h"
#include "Library\EdkIIGlueBaseMemoryLib.h"
#include "Library\EdkIIGlueCacheMaintenanceLib.h"
#include "Library\EdkIIGlueIoLib.h"
#include "Library\EdkIIGluePciCf8Lib.h"
#include "Library\EdkIIGluePciExpressLib.h"
#include "Library\EdkIIGluePciLib.h"
#include "Library\EdkIIGluePeCoffGetEntryPointLib.h"
#include "Library\EdkIIGluePeCoffLib.h"
#include "Library\EdkIIGluePostCodeLib.h"
#include "Library\EdkIIGluePrintLib.h"
#include "Library\EdkIIGlueTimerLib.h"
#include "Library\EdkIIGlueUefiDecompressLib.h"
#include "Library\EdkIIGlueDebugLib.h"

#endif