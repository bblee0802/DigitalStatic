
// DigitalStaticTestDlg.h : header file
//

#pragma once
#include "DigitalClockStatic.h"
#include "afxwin.h"

// CDigitalStaticTestDlg dialog
class CDigitalStaticTestDlg : public CDialogEx
{
// Construction
public:
	CDigitalStaticTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIGITALSTATICTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSet();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
	CDigitalClockStatic m_digiTimer;

	afx_msg void OnBnClickedStr();
	afx_msg void OnBnClickedStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	
};
