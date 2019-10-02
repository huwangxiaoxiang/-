
// ��Ļʰɫ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��Ļʰɫ��.h"
#include "��Ļʰɫ��Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
C��Ļʰɫ��Dlg* dlg;
DWORD target_id;

// C��Ļʰɫ��Dlg �Ի���
BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lP)
{
	DWORD id;
	GetWindowThreadProcessId(hWnd, &id);
	if (id ==target_id&&IsWindowVisible(hWnd)) {
		//dlg->hwnd = hWnd;
		RECT rect1;
		RECT rect2;
		GetWindowRect(hWnd, &rect1);
		GetClientRect(hWnd, &rect2);
		dlg->titlteinfo.Format(L"��%d,%d,%d,%d�� %dx%d", rect1.left, rect1.top, rect1.right, rect1.bottom, rect1.right - rect1.left, rect1.bottom - rect1.top);
		dlg->ntitleinfo.Format(L"��%d,%d,%d,%d�� %dx%d", rect1.left, rect1.bottom - rect2.bottom, rect1.left + rect2.right, rect1.bottom, rect2.right, rect2.bottom);
		dlg->title_center.Format(L"(%d,%d)", (rect1.right - rect1.left) / 2 + rect1.left, (rect1.bottom - rect1.top) / 2 + rect1.top);
		dlg->ntitle_center.Format(L"(%d,%d)", rect2.right / 2 + rect1.left, rect2.bottom / 2 + rect1.bottom - rect2.bottom);
	}
	return true;
}


C��Ļʰɫ��Dlg::C��Ļʰɫ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)

	, absoluteXY(_T(""))
	, relativeXY(_T(""))
	, originXY(_T(""))
	, colorRGB(_T(""))
	, color16(_T(""))
	, OriginX(0)
	, OriginY(0)
	, processID(0)
	, titlteinfo(_T(""))
	, ntitleinfo(_T(""))
	, title_center(_T(""))
	, ntitle_center(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	dlg = this;
}

void C��Ļʰɫ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, POSXY, absoluteXY);
	DDX_Text(pDX, POSXY_, relativeXY);
	DDX_Text(pDX, ORIGINEXY, originXY);
	DDX_Text(pDX, COLORRGB, colorRGB);
	DDX_Text(pDX, COLOR16, color16);
	DDX_Text(pDX, XX, OriginX);
	DDX_Text(pDX, XY, OriginY);
	DDX_Text(pDX, ProcessID, processID);
	DDX_Text(pDX, TITLEINFO, titlteinfo);
	DDX_Text(pDX, NTITLEINFO, ntitleinfo);
	DDX_Text(pDX, TITLE_CENTER, title_center);
	DDX_Text(pDX, NTITLE_CENTER, ntitle_center);
	DDX_Control(pDX, XX, OriXEdit);
}

BEGIN_MESSAGE_MAP(C��Ļʰɫ��Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_WM_TIMER()
	
	ON_BN_CLICKED(IDC_BUTTON2, &C��Ļʰɫ��Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &C��Ļʰɫ��Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &C��Ļʰɫ��Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// C��Ļʰɫ��Dlg ��Ϣ�������

BOOL C��Ļʰɫ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &screen);
	SetTimer(1, 50, NULL);

	this->OriginX = 0;
	this->OriginY = 0;
	this->originXY = CString(L"��0,0��");
	this->relativeXY = CString(L"��0,0��");
	this->titlteinfo = CString(L"��0,0,0,0�� 0x0");
	this->ntitleinfo = CString(L"��0,0,0,0�� 0x0");
	this->title_center = CString(L"��0,0��");
	this->ntitle_center = CString(L"��0,0��");


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��Ļʰɫ��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��Ļʰɫ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C��Ļʰɫ��Dlg::MoveTo(int x, int y)
{

	mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, TransformWidth(x), TransformHeight(y), 0, 0);
}



void C��Ļʰɫ��Dlg::OnTimer(UINT_PTR nIDEvent)
{
	if (GetDlgItem(XX) == GetFocus()||GetDlgItem(XY)==GetFocus()||
		GetDlgItem(IDC_BUTTON2)==GetFocus()||
		GetDlgItem(IDC_BUTTON1)==GetFocus()||
		GetDlgItem(IDC_BUTTON4) == GetFocus() || 
		GetDlgItem(ProcessID) == GetFocus()) {}
	else {
		CPoint pos;
		GetCursorPos(&pos);
		this->absoluteXY.Format(L"(%d,%d)", pos.x, pos.y);
		this->relativeXY.Format(L"(%d,%d)", pos.x - this->orix, pos.y - this->oriy);
	
		CWindowDC dc(GetDesktopWindow());
		COLORREF color = dc.GetPixel(pos);     //��õ�point����ɫֵ
		this->colorRGB.Format(L"(%d,%d,%d)", GetRValue(color), GetGValue(color), GetBValue(color));
		this->color16.Format(L"#%s%s%s", to16(GetRValue(color)), to16(GetGValue(color)), to16(GetBValue(color)));

		
		UpdateData(false);
		CBrush brush(color);
		CClientDC dcb(this);
		dcb.FillRect(example, &brush);
	}
	
	CDialogEx::OnTimer(nIDEvent);
}



CString C��Ļʰɫ��Dlg::to16(int a)
{
	int rest;
	CString result = L"";
	rest = a % 16;
	a = a / 16;
	result = temp[rest]+result ;
	rest = a % 16;
	result = temp[rest] + result;
	return result;
}

void C��Ļʰɫ��Dlg::OnStnClickedOriginexy()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//��λ������갴ť
void C��Ļʰɫ��Dlg::OnBnClickedButton2()
{
	UpdateData(true);
	this->orix = OriginX;
	this->oriy = OriginY;
	this->originXY.Format(L"(%d,%d)", this->orix,this->oriy);
	UpdateData(false);
	GetDlgItem(TITLEINFO)->SetFocus();
}

//��ת����λ�ð�ť
void C��Ļʰɫ��Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	GetDlgItem(TITLEINFO)->SetFocus();
	MoveTo(OriginX, OriginY);

}

int C��Ļʰɫ��Dlg::TransformWidth(int old) {
	double k = 65535 / (double)screen.dmPelsWidth;
	return (int)(old * k);
}

int C��Ļʰɫ��Dlg::TransformHeight(int old) {
	double k = 65535 / (double)screen.dmPelsHeight;
	return (int)(old * k);
}


void C��Ļʰɫ��Dlg::OnBnClickedButton4()
{
	UpdateData(true);
	this->hwnd = NULL;
	target_id = this->processID;
	EnumChildWindows(NULL, EnumChildProc, 0);
	GetDlgItem(TITLEINFO)->SetFocus();
}
