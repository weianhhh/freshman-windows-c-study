
// hongzhaDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "hongzha.h"
#include "hongzhaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChongzhaDlg 对话框



ChongzhaDlg::ChongzhaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HONGZHA_DIALOG, pParent)
	, m_strServer(_T("smtp"))
	, m_strUser(_T(""))
	, m_strPassword(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChongzhaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strServer);
	DDX_Text(pDX, IDC_EDIT2, m_strUser);
	DDX_Text(pDX, IDC_EDIT3, m_strPassword);
}

BEGIN_MESSAGE_MAP(ChongzhaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT5, &ChongzhaDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &ChongzhaDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &ChongzhaDlg::OnBnClickedBtnLogin)
	ON_EN_CHANGE(IDC_EDIT3, &ChongzhaDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &ChongzhaDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &ChongzhaDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// ChongzhaDlg 消息处理程序

BOOL ChongzhaDlg::OnInitDialog()
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

void ChongzhaDlg::OnPaint()
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
HCURSOR ChongzhaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ChongzhaDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChongzhaDlg::OnEnChangeEdit6()
{

}


void ChongzhaDlg::OnBnClickedBtnLogin()
{
	UpdateData(TRUE);
	if (m_strServer.IsEmpty() || m_strUser.IsEmpty() || m_strPassword.IsEmpty())
	{

		MessageBox(L"请输入服务器或者用户名或者密码.");
		return;
	}
}


void ChongzhaDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChongzhaDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChongzhaDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
