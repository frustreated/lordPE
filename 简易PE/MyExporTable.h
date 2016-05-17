#pragma once
#include "afxcmn.h"


// MyExporTable �Ի���

class MyExporTable : public CDialogEx
{
	DECLARE_DYNAMIC(MyExporTable)

public:
	MyExporTable(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyExporTable();

// �Ի�������
	enum { IDD = ExporTable };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnCbnSelchangeCombo2();
	void ShowExportInfo();		//��ʾ�������Ϣ	
	void ShowExportList();		//��ʾ�������Ϣ	
	virtual BOOL OnInitDialog();	 
	CString m_ExportOffest;			 //�����ƫ��
	CString m_Characteristic;		 //����ֵ
	CString m_Plot;					 //��ַ
	CString m_Name;					 //����
	CString m_NameString;			 //�����ַ���
	CString m_FunctionNumber;		 //��������
	CString m_FunctionNameNumber;	 //����������
	CString m_FunctionAddr;			 //������ַ
	CString m_FunctionNameAddr;		 //�������Ƶ�ַ
	CString m_FunSerialNumberAddr;	 //��������ŵ�ַ
	CListCtrl m_ExportList;
};
