#pragma once


// MyFileLocation �Ի���

class MyFileLocation : public CDialogEx
{
	DECLARE_DYNAMIC(MyFileLocation)

public:
	MyFileLocation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyFileLocation();

// �Ի�������
	enum { IDD = FileLocation };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	void  LockEdit(int EditId);					//����ָ���༭��
	void  OutPutPeInfo();
	DWORD ExclusiveCalcOffset(DWORD Rva);
	afx_msg void OnBnClickedButton10();
	//afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton9();
	CString m_Va;
	CString m_Rva;
	CString m_Offset;
	afx_msg void OnEnChangeEdit1();
	
	CString m_Section;
	CString m_Byte;
	CString m_StrPDosAddr;
};
