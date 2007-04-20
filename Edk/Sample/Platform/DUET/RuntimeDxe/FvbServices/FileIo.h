/*++

Copyright (c) 2007, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

Module Name:

  FileIo.h
  
Abstract:

  File operation for Firmware volume block driver

--*/

#ifndef _FW_BLOCK_SERVICE_FILE_IO_H
#define _FW_BLOCK_SERVICE_FILE_IO_H

#include "Tiano.h"
#include EFI_PROTOCOL_DEFINITION (SimpleFileSystem)

EFI_STATUS
FileWrite (
  IN EFI_FILE  *File,
  IN UINTN     Offset,
  IN UINTN     Buffer,
  IN UINTN     Size
  );

EFI_STATUS
CheckStore (
  IN  EFI_HANDLE                 SimpleFileSystemHandle,
  IN  UINT32                     VolumeId,
  OUT EFI_DEVICE_PATH_PROTOCOL   **Device
  );

EFI_STATUS
CheckStoreExists (
  IN  EFI_DEVICE_PATH_PROTOCOL   *Device
  );

EFI_STATUS
FileOpen (
  IN  EFI_DEVICE_PATH_PROTOCOL   *Device,
  IN  CHAR16                     *MappedFile,
  OUT EFI_FILE                   **File,
  IN  UINT64                     OpenMode
  );

VOID
FileClose (
  IN  EFI_FILE                   *File
  );

#endif // _FW_BLOCK_SERVICE_FILE_IO_H
