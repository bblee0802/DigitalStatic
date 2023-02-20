// DigitalStatic.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalStaticTest.h"
#include "DigitalClockStatic.h"


// CDigitalClockStatic

IMPLEMENT_DYNAMIC(CDigitalClockStatic, CStatic)

CDigitalClockStatic::CDigitalClockStatic()
{

}

CDigitalClockStatic::~CDigitalClockStatic()
{
}


BEGIN_MESSAGE_MAP(CDigitalClockStatic, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CDigitalClockStatic message handlers




void CDigitalClockStatic::PreSubclassWindow()
{
	ModifyStyle(0, SS_NOTIFY);
	CStatic::PreSubclassWindow();
}


void CDigitalClockStatic::OnPaint()
{
	CPaintDC dc(this);
	DrawTimes(&dc);
}


BOOL CDigitalClockStatic::OnEraseBkgnd(CDC* pDC)
{
	
	return 1;
	//return CStatic::OnEraseBkgnd(pDC);
}


void CDigitalClockStatic::SetNumbersImage(HINSTANCE hInstance, UINT nID)
{
	CPaintDC dc(this);

	if (m_dcImage.IsValid())
		m_dcImage.DeleteObject();

	m_dcImage.LoadBitmap(hInstance, nID, &dc);
	m_nNumberWidth = m_dcImage.m_sizeBitmap.cx / 11;
	m_nNumberHeight = m_dcImage.m_sizeBitmap.cy ;
	m_nClientWidth = m_nNumberWidth * 8;
	m_nClientHeight = m_nNumberHeight;
}

void CDigitalClockStatic::PutTime(int nHour, int nMinute, int nSecond)
{
	m_nHour = nHour;
	m_nMinute = nMinute;
	m_nSecond = nSecond;

	Invalidate();
}


void CDigitalClockStatic::DrawNumber(CDC *pMemDC, int nPos, int nNumber)
{
	pMemDC->BitBlt(nPos*m_nNumberWidth, 0, m_nNumberWidth, m_nNumberHeight, &m_dcImage.m_dcMemory, nNumber*m_nNumberWidth, 0, SRCCOPY);
}

void CDigitalClockStatic::DrawColon(CDC *pMemDC)
{
	pMemDC->BitBlt(2 * m_nNumberWidth, 0, m_nNumberWidth, m_nNumberHeight, &m_dcImage.m_dcMemory, 10 * m_nNumberWidth, 0, SRCCOPY);
	pMemDC->BitBlt(5 * m_nNumberWidth, 0, m_nNumberWidth, m_nNumberHeight, &m_dcImage.m_dcMemory, 10 * m_nNumberWidth, 0, SRCCOPY);
}

void CDigitalClockStatic::DrawTimes(CDC *pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, m_nClientWidth, m_nClientHeight);

	CBitmap *pOldBitmap = memDC.SelectObject(&bitmap);
    
	//Draw hours
	int number0 = m_nHour / 10;
	int number1 = m_nHour % 10;
	DrawNumber(&memDC, 0, number0);
	DrawNumber(&memDC, 1, number1);
      
	//Draw Minute 
	number0 = m_nMinute / 10;
	number1 = m_nMinute % 10;
	DrawNumber(&memDC, 3, number0);
	DrawNumber(&memDC, 4, number1);

	//Draw Second 
	number0 = m_nSecond / 10;
	number1 = m_nSecond % 10;
	DrawNumber(&memDC, 6, number0);
	DrawNumber(&memDC, 7, number1);
	
	//Draw Colon
	DrawColon(&memDC);

	pDC->BitBlt(0, 0, m_nClientWidth, m_nClientHeight, &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldBitmap);
}

void CDigitalClockStatic::DoMove(int x, int y) {
	MoveWindow(x, y, m_nClientWidth, m_nClientHeight);
}