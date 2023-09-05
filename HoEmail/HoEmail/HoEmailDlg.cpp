
// HoEmailDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "HoEmail.h"
#include "HoEmailDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHoEmailDlg 对话框



CHoEmailDlg::CHoEmailDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOEMAIL_DIALOG, pParent)
	, m_strServer(_T("smtp.qq.com"))
	, m_strUsername(_T("root"))
	, m_strPassword(_T("toor"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHoEmailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_strServer);
	DDX_Text(pDX, IDC_EDIT7, m_strUsername);
	DDX_Text(pDX, IDC_EDIT4, m_strPassword);
}

BEGIN_MESSAGE_MAP(CHoEmailDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CHoEmailDlg::OnBnClickedBtnLogin)
END_MESSAGE_MAP()


// CHoEmailDlg 消息处理程序

BOOL CHoEmailDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHoEmailDlg::OnPaint()
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
HCURSOR CHoEmailDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHoEmailDlg::OnBnClickedBtnLogin()
{
	if (m_strServer.IsEmpty() || m_strUsername.IsEmpty() || m_strPassword.IsEmpty())
	{
		MessageBox(L"请输入服务器或者用户名或者密码.");
		return;
	}
	m_socket = socket(AF_INET,SOCK_STREAM,0);
	if (m_socket == INVALID_SOCKET)
	{
		MessageBox(L"初始化网络失败.");
		return;
	}
	m_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (m_socket == INVALID_SOCKET)
	{
		MessageBox(L"");
		return;
	}
	gethostbyname(m_strServer)
}
