#pragma once

#define	MAX_MEM	262144
#define	MAX_EE	8192
#define	MAX_CFG	18 // Changed on 1.22.04 9 -> 18 to support Q83/Q84 devices
#define	MAX_UID	128		// Changed on 1.22.02 128->256 to support devices with 128 UserID words - not needed, changed back

class CDeviceData
{
	public:
		CDeviceData(void);
		~CDeviceData(void);
		void ClearAllData(unsigned int progMemSize, unsigned short int eeMemSize, unsigned char numConfigs, 
							   unsigned char  numIDs, unsigned int memBlankVal, int eeBytes, int idBytes, 
							   unsigned short int configBlank[], unsigned int OSCCALInit);
		void ClearProgramMemory(unsigned int progMemSize, unsigned int memBlankVal);
		void ClearConfigWords(unsigned char numConfigs, unsigned short int configBlank[]);
		void ClearUserIDs(unsigned char numIDs, int idBytes, unsigned int memBlankVal);
		void ClearEEPromMemory(unsigned short int eeMemSize, int eeBytes, unsigned int memBlankVal);

		unsigned int ProgramMemory[MAX_MEM];
		unsigned int EEPromMemory[MAX_EE];
		unsigned int ConfigWords[MAX_CFG];
		unsigned int UserIDs[MAX_UID];
		unsigned int OSCCAL;
		unsigned int BandGap;
};
