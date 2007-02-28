/*++

Copyright (c) 2004 - 2006, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  


Module Name:

  asm.h
  
Abstract: 

--*/

#ifndef _ASM_H
#define _ASM_H

#define TRUE  1
#define FALSE 0
#define PROCEDURE_ENTRY(name)   .##text;            \
  .##type name, @function; \
  .##proc name; \
  name::

#define PROCEDURE_EXIT(name)  .##endp name

#endif // _ASM_H
