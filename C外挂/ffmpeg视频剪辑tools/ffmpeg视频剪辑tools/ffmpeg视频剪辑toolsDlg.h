
// ffmpeg视频剪辑toolsDlg.h: 头文件
//

#pragma once


// Cffmpeg视频剪辑toolsDlg 对话框
class Cffmpeg视频剪辑toolsDlg : public CDialogEx
{
// 构造
public:
	Cffmpeg视频剪辑toolsDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FFMPEGTOOLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
