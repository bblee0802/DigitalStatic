
// DigitalStaticTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalStaticTest.h"
#include "DigitalStaticTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDigitalStaticTestDlg dialog



CDigitalStaticTestDlg::CDigitalStaticTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIGITALSTATICTEST_DIALOG, pParent)
	, m_nHour(0)
	, m_nMinute(0)
	, m_nSecond(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDigitalStaticTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Hour, m_nHour);
	DDX_Text(pDX, IDC_EDIT_Minute, m_nMinute);
	DDX_Text(pDX, IDC_EDIT_Second, m_nSecond);
	DDX_Control(pDX, IDC_Timer, m_digiTimer);
}

BEGIN_MESSAGE_MAP(CDigitalStaticTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Set, &CDigitalStaticTestDlg::OnBnClickedSet)
	ON_BN_CLICKED(IDOK, &CDigitalStaticTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDigitalStaticTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_STR, &CDigitalStaticTestDlg::OnBnClickedStr)
	ON_BN_CLICKED(IDC_Stop, &CDigitalStaticTestDlg::OnBnClickedStop)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDigitalStaticTestDlg message handlers

BOOL CDigitalStaticTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	m_digiTimer.SetNumbersImage(AfxGetInstanceHandle(), IDB_NUMBER);
	m_digiTimer.PutTime(m_nHour, m_nMinute, m_nSecond);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDigitalStaticTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDigitalStaticTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDigitalStaticTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDigitalStaticTestDlg::OnBnClickedSet()
{
	UpdateData();
	m_digiTimer.PutTime(m_nHour, m_nMinute, m_nSecond);

}


void CDigitalStaticTestDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CDigitalStaticTestDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CDigitalStaticTestDlg::OnBnClickedStr()
{
	SetTimer(100, 500, NULL);
}


void CDigitalStaticTestDlg::OnBnClickedStop()
{
	KillTimer(100);
}


void CDigitalStaticTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 100) {
		
		CTime t = CTime::GetCurrentTime();
		m_digiTimer.PutTime(t.GetHour(), t.GetMinute(), t.GetSecond());

	}

	CDialogEx::OnTimer(nIDEvent);
}
