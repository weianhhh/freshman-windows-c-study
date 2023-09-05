
// CSstaticTextDlg.h: 头文件
//

#pragma once


// CCSstaticTextDlg 对话框
class CCSstaticTextDlg : public CDialogEx
{
// 构造
public:
	CCSstaticTextDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CSSTATICTEXT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CStatic m_text;
public:
	afx_msg void OnBnClickedButton2();
	CStatic m_pic;
	afx_msg void OnBnClickedButton3();
private:
	CButton m_btn;
};
