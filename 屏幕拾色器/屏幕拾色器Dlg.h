
// ��Ļʰɫ��Dlg.h : ͷ�ļ�
//

#pragma once


// C��Ļʰɫ��Dlg �Ի���
class C��Ļʰɫ��Dlg : public CDialogEx
{
// ����
public:
	C��Ļʰɫ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	HWND hwnd;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DEVMODE screen;//��Ļ�ֱ�����Ϣ
	CRect *example=new CRect(CPoint(272,89), CPoint(356,119));

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CString temp[16] = { L"0",L"1",L"2",L"3", L"4",L"5", L"6",L"7", L"8",L"9", L"A",L"B", L"C",L"D", L"E",L"F" };
	void MoveTo(int x, int y);
	int TransformWidth(int);
	int TransformHeight(int);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	// ����������
	CString absoluteXY;
	// ����������
	CString relativeXY;
	// �������
	CString originXY;
	// ��λ��RGB��ɫֵ
	CString colorRGB;
	// 16������ɫֵ
	CString color16;
	// ��λ�������x
	int OriginX;
	// ��λ�������Yֵ
	int OriginY;
	// ����ID
	DWORD processID;


	CString to16(int a);

public:
	afx_msg void OnStnClickedOriginexy();
	afx_msg void OnBnClickedButton2();
protected:
	CEdit OriXEdit;
	int orix=0;
	int oriy = 0;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	// ��������������Ϣ
	CString titlteinfo;
	// ����������������Ϣ
	CString ntitleinfo;
	// ����������������
	CString title_center;
	// ������������������
	CString ntitle_center;
};
