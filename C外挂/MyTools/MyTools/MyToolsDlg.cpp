
// MyToolsDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MyTools.h"
#include "MyToolsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyToolsDlg 对话框



CMyToolsDlg::CMyToolsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYTOOLS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyToolsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyToolsDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMyToolsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMyToolsDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CMyToolsDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CMyToolsDlg::OnBnClickedOk3)
END_MESSAGE_MAP()


// CMyToolsDlg 消息处理程序

BOOL CMyToolsDlg::OnInitDialog()
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

void CMyToolsDlg::OnPaint()
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
HCURSOR CMyToolsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyToolsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//确定
	CDialogEx::OnOK();
}


void CMyToolsDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	// 取消
	//CDialogEx::OnCancel();
}

//注入
void CMyToolsDlg::OnBnClickedOk2()
{
#if 0
	// TODO: 在此添加控件通知处理程序代码

	MessageBox(L"你被注入了", L"注入-TEXT", 0);
	//关闭对话框
	CDialogEx::OnOK();
#endif
	//1.提升进程权限
	HANDLE hToken;
	if (FALSE == OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
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
	GetWindowThreadProcessId(hNotepadWnd, &dwPID);
	if (dwPID == 0) {
		MessageBox(L"获取进程PID失败");
		return;
	}

	//进程是什么:一个运行的程序 可以有多个窗口
	//6.跟据PID获取进程句柄
	HANDLE hNotepad = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	if (hNotepad == NULL)
	{
		MessageBox(L"打开进程失败.");
		return;
	}

	//7.远程进程中申请内存内存空间
	LPVOID lpAddr = VirtualAllocEx(hNotepad, NULL, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (lpAddr == NULL)
	{
		MessageBox(L"在远程进程中申请内存失败.");
		return;
	}
	//8.将dll路径写入到远程进程中
	TCHAR szDllPath[] = L"E:\\vscode2022_Project\\C外挂\\Injectdll\\x64\\Debug\\Inject.dll";
	if (FALSE == WriteProcessMemory(hNotepad, lpAddr, szDllPath, sizeof(szDllPath), NULL))
	{
		MessageBox(L"在远程进程中写入数据失败.");
		return;
	}
	PTHREAD_START_ROUTINE pfnStartAddr = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"kernel32.dll"),"LoadLibraryW");
	
	//9.在远程进程当中开辟一个线程
	HANDLE hRemote =  CreateRemoteThread(hNotepad, NULL, 0, pfnStartAddr, lpAddr, 0, NULL);
	if (hRemote == NULL)
	{ 
		CString str;
		str.Format(L"创建远程线程失败.错误代号:%d", GetLastError());
		MessageBox(str);
		return;
	}
	MessageBox(L"创建远程线程成功.");
}


void CMyToolsDlg::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"嘿嘿!", L"注入-TEXT", 0);
}
