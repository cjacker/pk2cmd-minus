#define	K_P32_PROGRAM_FLASH_START_ADDR 0x1D000000
#define	K_P32_BOOT_FLASH_START_ADDR    0x1FC00000

#define	K_PE_LOADER_LEN	42
#define K_PE_LEN		1231

//#define K_PIC32_PE_VERSION	0x0301
#define K_PIC32_PE_RS128_VERSION	0x0109
#define K_PIC32_PE_RS32_VERSION		0x0301

class CPIC32PE
{
	public:
		CPIC32PE(void);
		~CPIC32PE(void);

		static const unsigned int pe_Loader[K_PE_LOADER_LEN];		//PIC32
		static const unsigned int PIC32_PE_RS128[K_PE_LEN];		//PIC32
		static const unsigned int PIC32_PE_RS32[K_PE_LEN];		//PIC32
		static const unsigned int* PIC32_PE;		//PIC32
		static unsigned int pe_Version;
};

