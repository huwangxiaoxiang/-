
// ��Ļʰɫ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��Ļʰɫ��App: 
// �йش����ʵ�֣������ ��Ļʰɫ��.cpp
//

class C��Ļʰɫ��App : public CWinApp
{
public:
	C��Ļʰɫ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��Ļʰɫ��App theApp;
