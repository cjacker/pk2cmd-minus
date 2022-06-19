// pk2cmd.cpp : Defines the entry point for the console application.
//
//                            Software License Agreement
//
// Copyright (c) 2005-2009, Microchip Technology Inc. All rights reserved.
//
// You may use, copy, modify and distribute the Software for use with Microchip
// products only.  If you distribute the Software or its derivatives, the
// Software must have this entire copyright and disclaimer notice prominently
// posted in a location where end users will see it (e.g., installation program,
// program headers, About Box, etc.).  To the maximum extent permitted by law,
// this Software is distributed "AS IS" and WITHOUT ANY WARRANTY INCLUDING BUT
// NOT LIMITED TO ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR
// PARTICULAR PURPOSE, or NON-INFRINGEMENT. IN NO EVENT WILL MICROCHIP OR ITS
// LICENSORS BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
// DAMAGES OF ANY KIND ARISING FROM OR RELATED TO THE USE, MODIFICATION OR
// DISTRIBUTION OF THIS SOFTWARE OR ITS DERIVATIVES.
//
//---------------------------------------------------------------------------
// version 1.00.00  -  16 October 2007 WEK
// Initial release 
//
// version 1.01.00  -  6 December 2007 WEK
// Added -T and -H options.
//  
// version 1.10.00  -  27 June 2008 WEK, JP, XC, SK
// Source changes for multi-OS support
//      Linux and MacOS platform support was made possible through the contributions 
//      of the following individuals:
//          Jeff Post
//          Xiaofan Chen
//          Shigenobu Kimura
//          Francis Perea
// Add -N option
// Add -S option
// Min FW version is 2.31.00
// Add LastVerifyLocation and VERIFY_MEM_SHORT so the verify on a -M program command of
//     program memory only verifies the portion of memory that was written.  This speeds
//     up programming.  (Excludes PIC18 J-series and PIC24FJ)
// Updated config handling for PIC18 J-Series and PIC24FJ on programming / erasing to
//     match PICkit 2 Programmer v2.5x and MPLAB.
// device file compatibility upped to 5, to use DF v1.51
//     Added support for MCP250xx, 11LCxxx, and PIC32 devices.
// Allows spacing between options and parameters, with the following exceptions:
//     -G option memory ranges must not include a space, i.e. x-y. 
//
// version 1.12.00  -  July 2008 WEK, JP, XC
// Changes to read UnitID via USB Serial Number String descriptor and no longer get FW version
//     when polling for multiple units.  This prevents HID transactions when polling from
//     messing up other software already communicating with a PICkit 2 unit.
// Bug fix - handles programming PIC32 with blank Boot Flash section without error or crash.
// Now executes commands not requiring PICkit 2 hardware (such as checksum on hex file) 
//     without requiring a Pk2 unit.
//
// version 1.20.00 - 7 January 2008 WEK
// Bug fix - deprecated RunScriptUploadNoLen2() as it was causing problems on MacOS X systems
//     due to the handling of the multiple blocking reads.
// Added PE support for PIC24 and dsPIC33 devices.  "-Q" option added to disable use of the PE.
// -B option added to specify the device file location.
// Added "fflush(stdout);" to most printf sections to assist with GUI integration.
// -i option now also shows device revison and part name.
// Bug Fix: fixed an issue with displaying 14 character UnitID strings, and limits Unit IDs
//     to 14 characters.
// -j option added: Provides a % completion on Writes, Reads, Verifies, and Blank Checks of
//     Program Memory (Flash) and Data EEPROM. -jn prints each % update on a newline for GUI
//     interfaces (requested by Alain Gibaud).
// -l (L) option added to allow ICSP clock rate to be specified.
// Bug Fix: LastVerifyLocation was not getting set in CPICkitFunctions::EepromWrite, which
//     caused serial EEPROM devices to not be verified.
// Bug Fix: ComputeChecksum change to correctly compute Baseline checksums when CP is enabled.
// Increased the size of the array "DevicePartParams PartsList[1024]" from 512 in DeviceFile.h
//     as the latest device file has exceeded 512 parts.
// -P modified to support autodetection.  auto detection cannot be used with -V or -X.
//     Added new return code AUTODETECT_FAILED, which means no known part was found.
//     -P with no -T or -R will now always turn VDD off, hold MCLR. (-p requires Pk2 operation)
// Updated PIC32 PE from version 0106 to 0109.  This fixes verify problems with some devices,
//     including PIC32MX320F parts.
// Broke up checkHelp into checkHelp1 and checkHelp2.  The latter has help commands that need
//     the device file, like -?v and -?p
// Added help command "-?P<string>" which allows listing of supported parts and listing of
//     supported parts beginning with the given string.  This uses the natural string sorting
//     algorithm developed by Martin Pool <mbp sourcefrog net>
//     See algorithm files strnatcmp.c/h
// Added -mv, -gv (undocumented)
// Added support for import/export of BIN files for serial EEPROMs.
// Fixed a bug that may have appended a space at the end of -gf file names on Linux.
//
// version 1.21.00 RC1 - 3.12.2010 MichaelS / Microchip
// Updated to work with version 2.6x device files
//
// version 1.21.00 - 25.2.2021 Miklos Marton
// Updated to work with both PICkit2 and PICkit3
// Updated Linux and Mac source files with device file v2.6x support (based on 1.21.00. RC1 WIN32 source)
//
// version 1.22.00 - 4.7.2021 JAKA
// Updated also Windows source files with PICkit3 support (based on work by Miklos Marton)
// Updated to work with new PIC16 and PIC18 families which use SPI-type programming (MSB1st in
// family name). Based on work by bequest333.
//
// version 1.22.01 - 8.7.2021 JAKA
// Updated also Mac OSX source files with PICkit3 support
// Display version on general help
//
// version 1.22.02 - 13.7.2021 JAKA
// Fixed devices with more than 32 UserID words
//
// version 1.22.03 - 16 August 2021 JAKA
// Bug Fix: Fix Q40,Q41,Q43 families. Configuration memory needs to be written or read byte at
//          a time on these devices, not word at a time. Added swap2Bytes() function to arrange
//          configuration bytes to correct order. Regocnized from 0x000c as 'IgnoreBytes'
// 
// version 1.22.04 - 31 August 2021 JAKA
// Bug Fix: Fix PIC18 Msb1 family devices with more than 64 kB of prog. flash
// Add support for devices with more than 9 config words (Q83 and Q84 families so far)
// Config masks and config blanks for the extra config words are set to 0xffff
// If even number of config bytes, like 35 in Q83 and Q84, the last one must be indicated
// by IgnoreAddress (0x00300023 in this case)
// 
// version 1.22.05 - 23 September 2021 JAKA
// Feature: Added Skip Blank Sections feature, active by default. Use -O to disable. Write and verify
//          skip program memory sections which are blank (e.g. 0x3fff or 0xffff). Many compilers
//          place some parts of code to very end of program memory, and default behavior was to
//          write and verify to last used memory address. Skipping the blank sections also from
//          the middle can greatly reduce programming time if program memory is not full.
//          The address set script of SPI-type PICs was updated in the device file to support
//          all 3 address bytes. Also, the address set function is changed, because with the new
//          script the bits must be reversed for SPI-type PICs. So the device file must be updated
//          together with the application to maintain compatibility! Device file needs to be 2.63.222
//          or later. Many other SPI-type PIC scripts on the 2.63.222 device file are also optimized
//          which has reduced write and read times substantially, 20...50%. In case of K40,42,83
//          EEPROM write the time has been reduced by 80%!
//
// version 1.22.06 - 6 December 2021 JAKA
// Bug Fix: Fix blank checking on devices which have Bandgap bits on configuration word
//
// version 1.23.00 - 15 June 2022 JAKA
// Feature: Compile option define to select between two types of address set script for MSB1st
//          families. (#define OLDSTYLE_MSB1ST_SETADDR at stdafx.h)
//          Note! Probably needs fixing with PIC18F either in software or a new script.
//          Current advise; do not use this define. It was intended just for performace test usage.
// Bug Fix: Disable resetting of PICkit3 if -T and/or -R options are used - otherwise those options
//          are useless.
// Feature: Support for PIC32MX1xx and 2xx. Based on work of Microchip forum users timijk, scasis
//          and TrevorW on thread https://www.microchip.com/forums/m764694.aspx
// Bug Fix: Increased the size of the array "DevicePartParams PartsList[1500]" from 1024 in DeviceFile.h
//          as the latest device file has exceeded 1024 parts.


#include "stdafx.h"
#include "stdio.h"
#include "cmd_app.h"

Ccmd_app pk2app;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char *argv[])
#endif
{
	pk2app.PK2_CMD_Entry(argc, argv);

	printf("\n");

	if (pk2app.ReturnCode == 0)
	{
		printf("Operation Succeeded\n");
	}

	pk2app.ResetAtExit();
	pk2app.PicFuncs.USBClose();

	//while(1);
	return pk2app.ReturnCode;
}


