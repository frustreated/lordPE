#pragma once
#include "afxcmn.h"


// MyRelocation �Ի���

class MyRelocation : public CDialogEx
{
	DECLARE_DYNAMIC(MyRelocation)

public:
	MyRelocation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyRelocation();

// �Ի�������
	enum { IDD = Relocation };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void ShowRelocation();
	CListCtrl m_FirstReloc;
	CListCtrl m_SecondReloc;
	virtual BOOL OnInitDialog();
	void OnNMClickList(NMHDR *pNMHDR,LRESULT *pResult);
};
