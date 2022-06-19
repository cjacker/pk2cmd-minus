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
#include "P24F_PE.h"

CP24F_PE::CP24F_PE(void)
{
}

CP24F_PE::~CP24F_PE(void)
{
}

        // Trimmed down Program Executive version 0x0026
        // -- fits in 1st page of exec mem, so cal words don't have to be saved & restored.
        // -- No blank check, no CRC
const unsigned int CP24F_PE::PIC24F_PE_Code[K_PE24F_LEN] =  {
		0x00040080, 0x00000080, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 0x0080011E, 
		0x00FA0000, 0x00208CEF, 0x00227F80, 0x00880100, 0x00000000, 0x00070002, 0x00FA8000, 0x00060000, 
		0x00FA0000, 0x00EB0000, 0x00883A20, 0x00070150, 0x000700D8, 0x0007000B, 0x0037FFFD, 0x00F80034, 
		0x00781F88, 0x00B3C008, 0x008801A8, 0x0078044F, 0x00FA0000, 0x00FE0000, 0x00FA8000, 0x00F90034, 
		0x00064000, 0x00FA0002, 0x00804000, 0x00DE004C, 0x00FB8000, 0x00780F00, 0x0078001E, 0x00500FE5, 
		0x00320015, 0x0078009E, 0x00508FE5, 0x003C0005, 0x0078009E, 0x00408060, 0x00500FE2, 0x003E0014, 
		0x00370007, 0x0078001E, 0x00500FEA, 0x0032000C, 0x0078009E, 0x00508FEB, 0x0032000B, 0x0037000C, 
		0x00A888C7, 0x00A9A8C7, 0x00A9C8C7, 0x00A9E8C7, 0x0007000E, 0x0037000B, 0x00070040, 0x00370009, 
		0x00070081, 0x00370007, 0x000700A1, 0x00370005, 0x00A888C7, 0x00A8A8C7, 0x00A9C8C7, 0x00A9E8C7, 
		0x00070002, 0x00FA8000, 0x00060000, 0x00FA0000, 0x00804631, 0x002F0000, 0x00608080, 0x00210000, 
		0x00508F80, 0x00320006, 0x00804631, 0x002F0000, 0x00608080, 0x00230000, 0x00508F80, 0x003A0003, 
		0x00EB4000, 0x00B7E8C6, 0x00370002, 0x00B3C010, 0x00B7E8C6, 0x00804000, 0x00DE004C, 0x00FB8000, 
		0x0060006F, 0x00DD0148, 0x00804631, 0x002F0FF0, 0x00608000, 0x00700002, 0x00884630, 0x00804631, 
		0x0020F000, 0x00608080, 0x00202000, 0x00508F80, 0x003A000D, 0x00804010, 0x00D10000, 0x00B90063, 
		0x00E88000, 0x00884640, 0x00804010, 0x00600061, 0x00E00400, 0x00320006, 0x00804640, 0x00E88000, 
		0x00884640, 0x00370002, 0x00200020, 0x00884640, 0x00070082, 0x00FA8000, 0x00060000, 0x00240010, 
		0x00883B00, 0x00208005, 0x00EB0000, 0x00904425, 0x009004A5, 0x00428366, 0x00880198, 0x00780389, 
		0x00200100, 0x00BB0BB6, 0x00BBDBB6, 0x00BBEBB6, 0x00BB1BB6, 0x00BB0BB6, 0x00BBDBB6, 0x00BBEBB6, 
		0x00BB1BB6, 0x00E90000, 0x003AFFF6, 0x00090005, 0x00780B46, 0x00200080, 0x00538380, 0x00BB0BB6, 
		0x00A8C761, 0x00200557, 0x00883B37, 0x00200AA7, 0x00883B37, 0x00A8E761, 0x00000000, 0x00000000, 
		0x00803B00, 0x00A3F000, 0x0031FFFD, 0x00070005, 0x00DD004C, 0x00208C61, 0x00780880, 0x0007FFA3, 
		0x00060000, 0x00208000, 0x00EB0080, 0x00904420, 0x009004A0, 0x002000C7, 0x004001E6, 0x00880198, 
		0x00780289, 0x002001F4, 0x00BA0315, 0x00E13033, 0x003A000B, 0x00BADBB5, 0x00BAD3D5, 0x00E13033, 
		0x003A0007, 0x00BA0335, 0x00E13033, 0x003A0004, 0x00E90204, 0x003BFFF4, 0x00200010, 0x00370001, 
		0x00200020, 0x00060000, 0x00EF2032, 0x002FFFE7, 0x00370000, 0x00EB8200, 0x002FFFE6, 0x00208000, 
		0x00900190, 0x00900120, 0x00B10012, 0x00B18003, 0x0032000E, 0x00BA0057, 0x00E78004, 0x00370009, 
		0x00BAC017, 0x00E78404, 0x00370006, 0x00E13007, 0x003AFFF5, 0x00800190, 0x00E80000, 0x00880190, 
		0x0037FFF1, 0x002000F1, 0x00370001, 0x00200F01, 0x0021A000, 0x00700001, 0x00208C63, 0x00781980, 
		0x00200020, 0x00780980, 0x0007001C, 0x00060000, 0x00200261, 0x0021B000, 0x00700001, 0x00208C61, 
		0x00781880, 0x00200020, 0x00780880, 0x00070013, 0x00060000, 0x00070067, 0x00208007, 0x00781B80, 
		0x0020FFF3, 0x00600183, 0x00E90183, 0x00320004, 0x00070060, 0x00781B80, 0x00E90183, 0x003AFFFC, 
		0x00A9E241, 0x00205000, 0x00881210, 0x00EFA248, 0x00A8E241, 0x00EFA248, 0x00060000, 0x00EF2240, 
		0x0009001D, 0x00000000, 0x00204000, 0x00881210, 0x00A94085, 0x00A8E241, 0x00208C67, 0x00780037, 
		0x00881240, 0x00780037, 0x0007004F, 0x00208C60, 0x00900290, 0x00E98285, 0x00320038, 0x00904010, 
		0x00B240F0, 0x00B3C011, 0x00E10401, 0x003A000A, 0x00208000, 0x009040A0, 0x00FB8081, 0x00880191, 
		0x009003A0, 0x00BA0037, 0x0007003F, 0x00E90285, 0x003AFFFC, 0x00370029, 0x00B3C021, 0x00E10401, 
		0x003A002E, 0x00208000, 0x00900290, 0x00D10305, 0x00B00040, 0x00784090, 0x00780401, 0x007800D0, 
		0x00780381, 0x00E90005, 0x00320015, 0x00200001, 0x00880198, 0x00000000, 0x00BA0897, 0x0007002A, 
		0x00BAD897, 0x00B00027, 0x00B08008, 0x00880198, 0x00000000, 0x00BAD097, 0x00070023, 0x00BA0017, 
		0x00070021, 0x00B00027, 0x00B08008, 0x00880198, 0x00E90306, 0x003AFFEE, 0x00A60005, 0x00370007, 
		0x00880198, 0x00000000, 0x00BA0017, 0x00070016, 0x00BAC017, 0x00FB8000, 0x00070013, 0x00AE4085, 
		0x0037FFFE, 0x00A94085, 0x00A9E241, 0x00A86243, 0x00A8E241, 0x00801241, 0x00060000, 0x00B3C0C1, 
		0x00E10401, 0x003AFFF5, 0x00780037, 0x00070006, 0x0037FFF2, 0x00AE4085, 0x0037FFFE, 0x00A94085, 
		0x00801240, 0x00060000, 0x00781F81, 0x00AE4085, 0x0037FFFE, 0x00AE4085, 0x0037FFFC, 0x00A94085, 
		0x00801241, 0x00881240, 0x007800CF, 0x00060000, 0x00800210, 0x00B30A00, 0x00880210, 0x0020C000, 
		0x00881210, 0x00A94085, 0x00EF20A8, 0x00A800A9, 0x00A84095, 0x00280000, 0x00881200, 0x00EF2762, 
		0x00EF2764, 0x00060000, 0x000008CC, 0x00000002, 0x00000000, 0x00000800, 0x000000CC, 0x00000000, 
		0x00000000, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
		0x0000009B, 0x00000026, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF };


