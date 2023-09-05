#include "DrawText.h"
CMyApp myapp;
BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow,CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(NULL, _T("hello world"));
}
void CMainWindow::OnPaint()
{
	CRect rect;
	GetClientRect(&rect);

	CPaintDC dc(this);
	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	dc.SetBkMode(TRANSPARENT);

	for (int i = 0; i < 3600; i += 150)
	{
		LOGFONT lf;
		::ZeroMemory(&lf, sizeof(lf));
		lf.lfHeight = 160;
		lf.lfWeight = FW_BOLD;
		lf.lfEscapement = i;
		lf.lfOrientation = i;
		::lstrcpy(lf.lfFaceName, _T("微软雅黑"));
		CFont font;
		font.CreatePointFontIndirect(&lf);

		CFont* pOldFont = dc.SelectObject(&font);
		dc.TextOutW(0, 0, CString(_T("                   Hello,World!")));	//前面保留足够多的空格是为了保证不内卷，如果你把空格删了，肯定内卷
		dc.SelectObject(pOldFont);

	}
}


//void CMainWindow::OnPaint()
//{
//	CPaintDC dc(this);
//
//	CRect rect;
//	GetClientRect(&rect);
//
//	CFont font;
//	font.CreatePointFont(720, _T("微软雅黑"));
//
//	dc.SelectObject(&font);
//	dc.SetBkMode(TRANSPARENT);
//
//	CString str = _T("hello world!");
//	rect.OffsetRect(2, 2);
//	dc.SetTextColor(RGB(0, 0, 0));
//	dc.DrawText(str, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//
//	rect.OffsetRect(-2, -2);
//	dc.SetTextColor(RGB(255, 255, 0));
//	dc.DrawText(str,&rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//}