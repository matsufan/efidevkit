/*++

Copyright (c) 2006, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

Module Name:
  HobGeneration.h

Abstract:

Revision History:

--*/

#ifndef _DXELDR_HOB_GENERATION_H_
#define _DXELDR_HOB_GENERATION_H_

#include "Tiano.h"
#include "PeiLib.h"
#include "PeiHob.h"
#include "EfiHobLib.h"
#include "EfiCommonLib.h"
#include "EfiImage.h"
#include "EfiImageFormat.h"

#include EFI_PROTOCOL_CONSUMER (LoadedImage)
#include EFI_PROTOCOL_CONSUMER (DevicePath)
#include EFI_PROTOCOL_CONSUMER (SimpleFileSystem)
#include EFI_PROTOCOL_CONSUMER (FirmwareVolume)
#include EFI_PROTOCOL_CONSUMER (FileInfo)
#include EFI_GUID_DEFINITION   (PeiPeCoffLoader)
#include EFI_GUID_DEFINITION   (MemoryAllocationHob)
#include EFI_GUID_DEFINITION   (DebugImageInfoTable)
#include EFI_GUID_DEFINITION   (MemoryTypeInformation)
#include EFI_GUID_DEFINITION   (SmBios)
#include EFI_GUID_DEFINITION   (Acpi)
#include EFI_GUID_DEFINITION   (Mps)
#include EFI_GUID_DEFINITION   (PciExpressBaseAddress)

#include "EfiLdrHandoff.h"

#define EFI_MEMORY_BELOW_1MB_START     0x86000
#define EFI_MEMORY_BELOW_1MB_END       0x9F800
#define EFI_MEMORY_STACK_PAGE_NUM      0x20
#define CONSUMED_MEMORY                0x400000

#define EFI_LDR_MEMORY_DESCRIPTOR_GUID \
  { 0x7701d7e5, 0x7d1d, 0x4432, 0xa4, 0x68, 0x67, 0x3d, 0xab, 0x8a, 0xde, 0x60 }

#pragma pack(1)

typedef struct {
  EFI_HOB_GUID_TYPE             Hob;
  EFI_MEMORY_TYPE_INFORMATION   Info[10];
} MEMORY_TYPE_INFORMATION_HOB;

typedef struct {
  EFI_HOB_GUID_TYPE             Hob;
  EFI_PHYSICAL_ADDRESS          Table;
} TABLE_HOB;

typedef struct {
  EFI_HOB_GUID_TYPE             Hob;
  VOID                          *Interface;
} PROTOCOL_HOB;

typedef struct {
  EFI_HOB_GUID_TYPE             Hob;
  UINTN                         MemDescCount;
  EFI_MEMORY_DESCRIPTOR         *MemDesc;
} MEMORY_DESC_HOB;

typedef struct {
  EFI_HOB_GUID_TYPE                         Hob;
  // Note: we get only one PCI Segment now.
  EFI_PCI_EXPRESS_BASE_ADDRESS_INFORMATION  PciExpressBaseAddressInfo;
} PCI_EXPRESS_BASE_HOB;

typedef struct {
  EFI_HOB_HANDOFF_INFO_TABLE        Phit;
  EFI_HOB_FIRMWARE_VOLUME           Bfv;
  EFI_HOB_RESOURCE_DESCRIPTOR       BfvResource;
  EFI_HOB_CPU                       Cpu;
  EFI_HOB_MEMORY_ALLOCATION_STACK   Stack;
  EFI_HOB_MEMORY_ALLOCATION         MemoryAllocation;
  EFI_HOB_RESOURCE_DESCRIPTOR       MemoryFreeUnder1MB;
  EFI_HOB_RESOURCE_DESCRIPTOR       MemoryAbove1MB;
  EFI_HOB_RESOURCE_DESCRIPTOR       MemoryAbove4GB;
  EFI_HOB_MEMORY_ALLOCATION_MODULE  DxeCore;
  MEMORY_TYPE_INFORMATION_HOB       MemoryTypeInfo;
  TABLE_HOB                         Acpi;
  TABLE_HOB                         Acpi20;
  TABLE_HOB                         Smbios;
  TABLE_HOB                         Mps;
  PROTOCOL_HOB                      FlushInstructionCache;
  PROTOCOL_HOB                      TransferControl;
  PROTOCOL_HOB                      PeCoffLoader;
  PROTOCOL_HOB                      EfiDecompress;
  PROTOCOL_HOB                      TianoDecompress;
  PROTOCOL_HOB                      SerialStatusCode;
  MEMORY_DESC_HOB                   MemoryDescriptor;
  PCI_EXPRESS_BASE_HOB              PciExpress;
  EFI_HOB_GENERIC_HEADER            EndOfHobList;
} HOB_TEMPLATE;

#pragma pack()

extern HOB_TEMPLATE  *gHob;

VOID *
PrepareHobStack (
  IN VOID *StackTop
  );

VOID
PrepareHobBfv (
  VOID  *Bfv,
  UINTN BfvLength
  );

VOID *
PrepareHobMemory (
  IN UINTN                    NumberOfMemoryMapEntries,
  IN EFI_MEMORY_DESCRIPTOR    *EfiMemoryDescriptor
  );

VOID
PrepareHobDxeCore (
  VOID                  *DxeCoreEntryPoint,
  EFI_PHYSICAL_ADDRESS  DxeCoreImageBase,
  UINT64                DxeCoreLength
  );

VOID *
PrepareHobPageTable (
  VOID *PageNumberTop
  );

VOID *
PrepareHobMemoryDescriptor (
  VOID                          *MemoryDescriptorTop,
  UINTN                         MemDescCount,
  EFI_MEMORY_DESCRIPTOR         *MemDesc
  );

VOID
PrepareHobPhit (
  VOID *MemoryTop,
  VOID *FreeMemoryTop
  );

VOID
CompleteHobGeneration (
  VOID
  );

#endif
