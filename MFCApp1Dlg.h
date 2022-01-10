
// MFCApp1Dlg.h : header file
//

#pragma once
#include "Memory.h"
#include "Calculate.h"

// CMFCApp1Dlg dialog
class CMFCApp1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApp1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox combo_data;
	CEdit edit_cluster;
	CEdit edit_epsilon;
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonCount();
	CEdit edit_m;
	CEdit edit_ml;
	CEdit edit_mu;
	CEdit edit_alpha;
	CListCtrl listcontrol_vecto;
	CListCtrl listcontrol_cluster;
	afx_msg void OnBnClickedRadioFcm();
	afx_msg void OnBnClickedRadioMcfcm();
	int radio,c,n,d;
	float epsilon,mL,mU,alpha;
	float m;
	Memory memory;
	Calculate calculate;
	float** X, ** U, ** C;
	CString Str,Str1, Str2, Str3, Str4, Str5, Str6;

	CStatic static_dunn;
	CStatic static_aswc;
	CStatic static_swc;
	CStatic static_pbm;
	CStatic static_db;
};
