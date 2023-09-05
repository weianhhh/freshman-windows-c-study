
// 05ListCtrlDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "05ListCtrl.h"
#include "05ListCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy05ListCtrlDlg 对话框



CMy05ListCtrlDlg::CMy05ListCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY05LISTCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy05ListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMy05ListCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMy05ListCtrlDlg 消息处理程序

BOOL CMy05ListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString str[] = {TEXT("姓名"),TEXT("性别"), TEXT("年龄")};  
	int len = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < len; i++)
	{
		//MessageBox(str[i]);
		m_list.InsertColumn(i, str[i],LVCFMT_LEFT,140);
	}


 	//CString name[] = {TEXT("张三"),TEXT("李四"),TEXT("王五")};
	CString name;

	CString sex;
	CString age;
 	for(int i = 0;i < 10; i++)
	{
		int j = 0;
		
		name.Format(TEXT("张%d"), i);
		if (i % 2 == 0)
		{
			sex = TEXT("女");
		}
		else {
			sex = TEXT("男");
		}
		age.Format(TEXT("%d"), i);
 		m_list.InsertItem(i, name);
		m_list.SetItemText(i, ++j, sex);
		m_list.SetItemText(i, ++j, age);
 	}

	//显示网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
 
/*
	CString line;
	CStdioFile file;
	if (file.Open(_T("filename.txt"), CFile::modeRead | CFile::typeText))
	{
		int row = 0;
		while (file.ReadString(line))
		{
			// Convert CString to ANSI
			CStringA ansiLine(line);

			// Convert ANSI to Unicode
			int unicodeLength = MultiByteToWideChar(CP_ACP, 0, ansiLine, -1, NULL, 0);
			CStringW unicodeLine;
			wchar_t* buffer = unicodeLine.GetBuffer(unicodeLength);
			MultiByteToWideChar(CP_ACP, 0, ansiLine, -1, buffer, unicodeLength);

			m_list.InsertItem(row, unicodeLine);
			row++;

			unicodeLine.ReleaseBuffer();
		}
		file.Close();
	}
*/
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy05ListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy05ListCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy05ListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

