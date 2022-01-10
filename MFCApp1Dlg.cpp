
// MFCApp1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApp1.h"
#include "MFCApp1Dlg.h"
#include "afxdialogex.h"
#include <math.h>
#include "Memory.h"
#include "Calculate.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApp1Dlg dialog



CMFCApp1Dlg::CMFCApp1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPP1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DATA, combo_data);
	DDX_Control(pDX, IDC_EDIT_CLUSTER, edit_cluster);
	DDX_Control(pDX, IDC_EDIT_EPSILON, edit_epsilon);
	DDX_Control(pDX, IDC_EDIT_M, edit_m);
	DDX_Control(pDX, IDC_EDIT_ML, edit_ml);
	DDX_Control(pDX, IDC_EDIT_MU, edit_mu);
	DDX_Control(pDX, IDC_EDIT_ALPHA, edit_alpha);
	DDX_Control(pDX, IDC_LIST_CONTROL_VECTO, listcontrol_vecto);
	DDX_Control(pDX, IDC_LIST_CONTROL_CLUSTER, listcontrol_cluster);
	DDX_Control(pDX, IDC_STATIC_DUNN, static_dunn);
	DDX_Control(pDX, IDC_STATIC_ASWC, static_aswc);
	DDX_Control(pDX, IDC_STATIC_SWC, static_swc);
	DDX_Control(pDX, IDC_STATIC_PBM, static_pbm);
	DDX_Control(pDX, IDC_STATIC_DB, static_db);
}

BEGIN_MESSAGE_MAP(CMFCApp1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CMFCApp1Dlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_COUNT, &CMFCApp1Dlg::OnBnClickedButtonCount)
	ON_BN_CLICKED(IDC_RADIO_FCM, &CMFCApp1Dlg::OnBnClickedRadioFcm)
	ON_BN_CLICKED(IDC_RADIO_MCFCM, &CMFCApp1Dlg::OnBnClickedRadioMcfcm)
END_MESSAGE_MAP()


// CMFCApp1Dlg message handlers

BOOL CMFCApp1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	combo_data.AddString(_T("Iris"));
	combo_data.AddString(_T("Abalone"));
	combo_data.AddString(_T("Balance-Scale"));
	combo_data.SetCurSel(0);

	listcontrol_vecto.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	listcontrol_cluster.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApp1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApp1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApp1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApp1Dlg::OnBnClickedButtonLoad()
{
	// TODO: Add your control notification handler code here


	Str.Format(_T(" %d"), d);
	static_db.SetWindowTextW(Str);

	listcontrol_vecto.DeleteAllItems();
	listcontrol_cluster.DeleteAllItems();
	for (int i = 0; i < d; i++) {
		listcontrol_cluster.DeleteColumn(i);
		listcontrol_vecto.DeleteColumn(i);
	}
	int combodata = combo_data.GetCurSel();
	switch (combodata)
	{
	case 0:
	{
		n = 4177;
		d = 8;
		memory.allocate(X, n + 1, d + 1);
		memory.readAbalone(X, n, d);
		break;
	}case 1:
	{
		n = 625;
		d = 4;
		memory.allocate(X, n + 1, d + 1);
		memory.readBalanceScale(X, n, d);
		break;
		
	}
	case 2:
	{
		n = 150;
		d = 4;
		memory.allocate(X, n + 1, d + 1);
		memory.readIris(X, n, d);
		break;
	}
	}

	for (int i = 0; i < d; i++) {
		listcontrol_vecto.InsertColumn(i, _T(""), LVCFMT_CENTER, 100);
		listcontrol_cluster.InsertColumn(i, _T(""), LVCFMT_CENTER, 100);
	}





	for (int i = 0; i < n; i++)
		for (int j = 0; j < d; j++) {
			CString Str = NULL;
			Str.Format(_T("%f"), X[i + 1][j + 1]);
			if ((j == 0))
				listcontrol_vecto.InsertItem(i, Str);
			else
				listcontrol_vecto.SetItemText(i, j, Str);
		}
	Str.Format(_T(" %d"), d);
	static_swc.SetWindowTextW(Str);
}


void CMFCApp1Dlg::OnBnClickedButtonCount()
{
	// TODO: Add your control notification handler code here

	//nhap so cum c
	edit_cluster.GetWindowTextW(Str);
	c = _ttoi(Str);

	//nhap epsilon
	edit_epsilon.GetWindowTextW(Str);
	epsilon = _ttoi(Str);

	// ma tran U
	memory.allocate(U, n + 1, c + 1);

	// tap cac vector cum C  
	memory.allocate(C, c + 1, d + 1);

	// khoi tao ma tran U
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= c; j++)
			U[i][j] = (float)1 / (i + j+1);

	// khoi tao cac tam C
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= d; j++)
			C[i][j] = 1;

	if (radio == 1) {
		// thuat toan fcm
		edit_m.GetWindowTextW(Str);
		m = _ttof(Str);
		float JUC = 0;
		float JUCnew = 0;
		do {
			JUC = JUCnew;
			for (int k = 1; k <= c; k++)
				calculate.update_CK(U, X, C, d, m, n, k);

			for (int i = 1; i <= n; i++)
				for (int k = 1; k <= c; k++)
					calculate.update_UIK(U, X, C, d, m, c, i, k);

			JUCnew = calculate.update_JUC(U, X, C, n, c, d, m);

		} while (abs(JUC - JUCnew) > epsilon);
	}
	
	else if (radio == 2) {
		//thuat toan MC_FCM
		
		// nhap ml
		edit_ml.GetWindowTextW(Str);
		mL = _ttof(Str);

		//nhap mu
		edit_mu.GetWindowTextW(Str);
		mU = _ttof(Str);

		//nhap alpha
		edit_alpha.GetWindowTextW(Str);
		alpha = _ttof(Str);

		// khoi tao mang delta
		float* delta;
		delta = new float[n + 1];
		for (int i = 1; i <= n; i++)
		{
			delta[i] = 0;
		}
		int n_c = n / c;

		// khoi tao mi
		float* mcfcm_m;
		mcfcm_m = new float[n + 1];
		for (int i = 1; i <= n; i++)
		{
			mcfcm_m[i] = 0;
		}

		// tinh mi
		for (int i = 1; i <= n; i++)
		{
			float* deltai;
			deltai = new float[n + 1];
			for (int j = 1; j <= n; j++)
			{
				deltai[j] = calculate.Dvector(X, C, i, j, d);
			}
			for (int x = 1; x <= n - 1; x++)
				for (int y = 1; y <= n; y++)
				{
					if (deltai[x] > deltai[y])
					{
						float temp = deltai[x];
						deltai[x] = deltai[y];
						deltai[y] = temp;
					}
				}

			for (int j = 1; j <= n_c; j++)
			{
				delta[i] += deltai[j];
			}
			delete deltai;
		}
		float deltamin = 9999;
		float deltamax = 0;
		for (int i = 1; i <= n; i++)
		{
			if (deltamin > delta[i])
				deltamin = delta[i];
			if (deltamax < delta[i])
				deltamax = delta[i];
		}
		for (int i = 1; i <= n; i++)
		{
			mcfcm_m[i] = mL + (mU - mL) * pow((delta[i] - deltamin) / (deltamax - deltamin), alpha);
		}
		float juc = 0;
		float jucnew = 0;
		do
		{
			juc = jucnew;
			for (int k = 1; k <= c; k++)
				calculate.MCFCM_update_CK(U, X, C, d, mcfcm_m, n, k);

			for (int i = 1; i <= n; i++)
				for (int k = 1; k <= c; k++)
					calculate.MCFCM_update_UIK(U, X, C, d, mcfcm_m, c, i, k);

			jucnew = calculate.MCFCM_update_JUC(U, X, C, n, c, d, mcfcm_m);

		} while (abs(juc - jucnew) > epsilon);
		delete mcfcm_m;
	}
	float delta_min = 999;
	float delta_max = 0;
	float E1 = 0, EK = 0, DK = 0;

	//ban kinh cac tam cum(thuat toan dunn)
	float* radius;
	radius = new float[c + 1];
	for (int i = 1; i <= c; i++)
		radius[i] = 0;

	//tong khoang cach cac phan tu cua cum do den cum do
	float* E;
	E = new float[c + 1];
	for (int i = 1; i <= c; i++)
		E[i] = 0;

	//tinh ban kinh cac tam cum
	for (int i = 1; i <= n; i++) {
		float clus = 0;
		int ter = 0;
		for (int j = 1; j <= c; j++) {
			if (U[i][j] > clus) {
				clus = U[i][j];
				ter = j;
			}
		}
		// thuat toan dunn
		float radius_ter = calculate.D(X, C, i, ter, d);
		if (radius_ter > radius[ter])
			radius[ter] = radius_ter;

		// thuat toan PBM
		E[ter] += radius_ter;
	}

	//tinh EK
	for (int i = 1; i <= c; i++) {
		EK += E[i];
	}

	//tinh E1
	E1 = E[1];

	//tim ban kinh lon nhat
	for (int i = 1; i <= c; i++) {
		if (delta_max < radius[i])
			delta_max = radius[i];
	}

	//tim khoang cach nho nhat giua 2 tam cum
	for (int i = 1; i < c; i++)
		for (int j = i + 1; j <= c; j++) {
			if (delta_min > calculate.Dcluster(X, C, i, j, d))
				delta_min = calculate.Dcluster(X, C, i, j, d);
			if (DK < calculate.Dcluster(X, C, i, j, d))
				DK = calculate.Dcluster(X, C, i, j, d);
		}
	float dunn = delta_min / delta_max;
	float PBM = (float)(E1 * DK) / EK;
	PBM = (float)PBM / c;
	PBM = pow((float)PBM, 2.0);


	//do do aswc
	int* belong = new int[n + 1];
	int* inclu = new int[c + 1];
	for (int i = 1; i <= c; i++)
	{
		inclu[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int thuoc = 1;
		float dothuoc = 0;
		for (int j = 1; j <= c; j++)
		{
			if (U[i][j] > dothuoc)
			{
				dothuoc = U[i][j];
				thuoc = j;
			}
		}
		belong[i] = thuoc;
		inclu[thuoc]++;
	}
	// cum i co inclu[i] phan tu
	// phan tu j thuoc cum belong[j]
	float* sx;
	sx = new float[n + 1];
	float aswc = 0;
	for (int j = 1; j <= n; j++)
	{
		// x[j] thuoc cum "thuoc"
		int thuoc = belong[j];
		if ((inclu[thuoc] == 1) || (inclu[thuoc] == 0))
			sx[j] = 0;
		float* dj = new float[n + 1];
		for (int i = 1; i <= n; i++)
		{
			dj[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			if (i == j)
				continue;
			float kc = calculate.Dvector(X, C, i, j, d);
			dj[belong[i]] += kc;
		}
		float apj = dj[thuoc] / (inclu[thuoc] - 1);
		float bpj = 9999;
		for (int i = 1; i <= c; i++)
		{
			// dj[i] = (float)dj[i] / inclu[i];
			if (bpj > dj[i])
				bpj = dj[i];
		}
		sx[j] = bpj / (apj + 0.000001);
		aswc += sx[j];
		delete dj;
	}
	aswc = aswc / n;

	// do DB
	float DB = 0;
	for (int i = 1; i <= c; i++)
	{
		float max = 0;
		for (int j = 1; j <= c; j++)
		{
			if (i == j)
				;
			else
			{
				if (max < ((E[i] + E[j]) / calculate.Dcluster(X, C, i, j, d) / n))
					max = (E[i] + E[j]) / calculate.Dcluster(X, C, i, j, d) / n;
			}
		}
		DB += max;
	}
	DB = DB / n;

	// do do SWC
	float SWC = 0;
	for (int j = 1; j <= n; j++)
	{
		int thuoc = belong[j];
		if ((inclu[thuoc] == 1) || (inclu[thuoc] == 0))
			sx[j] = 0;
		float* dj = new float[n + 1];
		for (int i = 1; i <= n; i++)
		{
			dj[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			if (i == j)
				continue;
			float kc = calculate.Dvector(X, C, i, j, d);
			dj[belong[i]] += kc;
		}
		float apj = dj[thuoc] / (inclu[thuoc] - 1);
		float bpj = 9999;
		for (int i = 1; i <= c; i++)
		{
			if (bpj > dj[i])
				bpj = dj[i];
		}
		sx[j] = (bpj - apj) / max(apj, bpj);
		SWC += sx[j];
	}
	SWC = SWC / n;

	Str.Format(_T(" %f"), dunn);
	static_dunn.SetWindowTextW(Str);
	Str.Format(_T(" %f"), PBM);
	static_pbm.SetWindowTextW(Str);
	Str.Format(_T(" %f"), aswc);
	static_aswc.SetWindowTextW(Str);
	Str.Format(_T(" %f"), DB);
	static_db.SetWindowTextW(Str);
	Str.Format(_T(" %f"), SWC);
	static_swc.SetWindowTextW(Str);

	listcontrol_cluster.DeleteAllItems();
	for (int i = 0; i < c; i++)
		for (int j = 0; j < d; j++) {
			CString Str = NULL;
			Str.Format(_T("%f"), C[i + 1][j + 1]);
			if ((j == 0))
				listcontrol_cluster.InsertItem(i, Str);
			else
				listcontrol_cluster.SetItemText(i, j, Str);
		}

	//giai phong bo nho
	delete sx;
	delete belong;
	delete inclu;
//	memory.free(X, n, d);
	memory.free(U, n, c);
	memory.free(C, c, d);
}


void CMFCApp1Dlg::OnBnClickedRadioFcm()
{
	// TODO: Add your control notification handler code here
	radio = 1;
}


void CMFCApp1Dlg::OnBnClickedRadioMcfcm()
{
	// TODO: Add your control notification handler code here
	radio = 2;
}
