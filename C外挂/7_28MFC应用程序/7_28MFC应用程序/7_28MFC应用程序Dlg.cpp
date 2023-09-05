
// 7_28MFC应用程序Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "7_28MFC应用程序.h"
#include "7_28MFC应用程序Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy728MFC应用程序Dlg 对话框



CMy728MFC应用程序Dlg::CMy728MFC应用程序Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY7_28MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy728MFC应用程序Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy728MFC应用程序Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMy728MFC应用程序Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK3, &CMy728MFC应用程序Dlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK2, &CMy728MFC应用程序Dlg::OnBnClickedOk3)
END_MESSAGE_MAP()


// CMy728MFC应用程序Dlg 消息处理程序

BOOL CMy728MFC应用程序Dlg::OnInitDialog()
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

void CMy728MFC应用程序Dlg::OnPaint()
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
HCURSOR CMy728MFC应用程序Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//点击“注入”的响应函数
void CMy728MFC应用程序Dlg::OnBnClickedOk()
{
#if 0
	// TODO: 在此添加控件通知处理程序代码
	
	MessageBox(L"你被注入了",L"注入-TEXT",0);
	//关闭对话框
	CDialogEx::OnOK();
#endif
	//1.提升进程权限
	HANDLE hToken;
	if(FALSE == OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
	{
		MessageBox(L"打开进程访问令牌失败.");
		return;
	}
	//2.查看进程里面的特权信息
	LUID luid;
	if (FALSE == LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
	{
		MessageBox(L"查看进程里面的特权信息失败.");
		return;
	}
	//3.调节进程的权限
	TOKEN_PRIVILEGES tkp;
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes + SE_PRIVILEGE_ENABLED;
	tkp.Privileges[0].Luid = luid;
	if (FALSE == AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL))
	{
		MessageBox(L"调节进程的权限失败.");
		return;
	}
	//4.查找窗口
	HWND hNotepadWnd = ::FindWindow(L"Notepad", L"无标题 - 记事本");
	if (hNotepadWnd == NULL)
	{
		MessageBox(L"没有打开记事本.");
		return;
	}
	//获取进程PID (Process ID进程ID)
	//5.根据窗口句柄获取PID
	/*DWORD 是 unsigned long*/
	DWORD dwPID = 0;
	GetWindowThreadProcessId(hNotepadWnd,&dwPID);
	if (dwPID == 0) {
		MessageBox(L"获取进程PID失败");
		return;
	}

	//进程是什么:一个运行的程序 可以有多个窗口
	//6.跟据PID获取进程句柄
	HANDLE hNotepad =  OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	if (hNotepad == NULL) 
	{
		MessageBox(L"打开进程失败.");
		return;
	}
}

void CMy728MFC应用程序Dlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMy728MFC应用程序Dlg::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码

	MessageBox(L"嘿嘿,关闭不了了吧!", L"注入-TEXT", 0);
	
}




