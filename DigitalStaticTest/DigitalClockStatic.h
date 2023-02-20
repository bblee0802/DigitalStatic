#pragma once
#include "CDCBuffer.h"

// CDigitalClockStatic

class CDigitalClockStatic : public CStatic
{
	DECLARE_DYNAMIC(CDigitalClockStatic)

public:
	CDigitalClockStatic();
	virtual ~CDigitalClockStatic();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
	void DrawNumber(CDC *pMemDC, int nPos, int nNumber);
	void DrawColon(CDC *pMemDC);
	void DrawTimes(CDC *pDC);

protected:
	int  m_nHour = 0 ;
	int  m_nMinute = 0 ;
	int  m_nSecond = 0;

public:
	CDCBuffer  m_dcImage;
	UINT  m_nNumberWidth = 0;
	UINT  m_nNumberHeight = 0;
	UINT  m_nClientWidth = 0;
	UINT  m_nClientHeight = 0;


public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void SetNumbersImage(HINSTANCE hInstance, UINT nID);
	void PutTime(int nHour, int nMinute, int nSecond);
	void DoMove(int x, int y);
};


