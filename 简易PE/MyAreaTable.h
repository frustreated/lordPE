#pragma once
#include "afxcmn.h"


// MyAreaTable �Ի���

class MyAreaTable : public CDialogEx
{
	DECLARE_DYNAMIC(MyAreaTable)

public:
	MyAreaTable(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyAreaTable();

// �Ի�������
	enum { IDD = AreaTable };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_AreaTabList;
	void ShowAreaTable();
//	afx_msg void OnClose();
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
