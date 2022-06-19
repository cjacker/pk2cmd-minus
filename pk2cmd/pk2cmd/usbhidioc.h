// usbhidiocDlg.h : header file
//

typedef enum {
    Pickit2,
    Pickit3
} PickitType_t;
extern PickitType_t deviceType;

/////////////////////////////////////////////////////////////////////////////
// CUsbhidiocDlg dialog

class CUsbhidioc //: public CDialog
{
public:
	CUsbhidioc(void);
    PickitType_t type() const { return m_type; }
    char* GetPK2UnitID(void);
	bool FindTheHID(int unitIndex);
    bool ReadReport (char *);
    bool WriteReport(char *, unsigned int);
    void CloseReport ();

protected:
    void GetDeviceCapabilities();
    void PrepareForOverlappedTransfer();

	char m_UnitID[32];
    PickitType_t m_type = Pickit2;

};


