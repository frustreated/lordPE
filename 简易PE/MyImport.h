#pragma once
#include "afxcmn.h"


// MyImport �Ի���

class MyImport : public CDialogEx
{
	DECLARE_DYNAMIC(MyImport)

public:
	MyImport(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyImport();

// �Ի�������
	enum { IDD = Import };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void ShowImportList();		//��ʾ�������Ϣ
	CListCtrl m_UpImport;
	CListCtrl m_DownImport;
	virtual BOOL OnInitDialog();
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult);
};
