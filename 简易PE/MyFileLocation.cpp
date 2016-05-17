// MyFileLocation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����PE.h"
#include "MyFileLocation.h"
#include "afxdialogex.h"
#include "AnalyticalPE.h"

// MyFileLocation �Ի���

IMPLEMENT_DYNAMIC(MyFileLocation, CDialogEx)

MyFileLocation::MyFileLocation(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyFileLocation::IDD, pParent)
	//, m_Va(0)
	, m_Rva(_T(""))
	, m_Offset(_T(""))
, m_Va(_T(""))
, m_Section(_T(""))
, m_Byte(_T(""))
{

}

MyFileLocation::~MyFileLocation()
{
}

void MyFileLocation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_Va);
	DDX_Text(pDX, IDC_EDIT2, m_Rva);
	DDX_Text(pDX, IDC_EDIT3, m_Offset);
	DDX_Text(pDX, IDC_EDIT1, m_Va);
	DDX_Text(pDX, IDC_EDIT4, m_Section);
	DDX_Text(pDX, IDC_EDIT5, m_Byte);
}


BEGIN_MESSAGE_MAP(MyFileLocation, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON10, &MyFileLocation::OnBnClickedButton10)
//	ON_EN_CHANGE(IDC_EDIT4, &MyFileLocation::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON11, &MyFileLocation::OnBnClickedButton11)
	ON_EN_CHANGE(IDC_EDIT2, &MyFileLocation::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON12, &MyFileLocation::OnBnClickedButton12)
	ON_EN_CHANGE(IDC_EDIT3, &MyFileLocation::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON9, &MyFileLocation::OnBnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT1, &MyFileLocation::OnEnChangeEdit1)
END_MESSAGE_MAP()




// MyFileLocation ��Ϣ�������


//VA�༭��
void MyFileLocation::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	UpdateData(TRUE);

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//����VA�༭��
void MyFileLocation::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LockEdit(IDC_EDIT1);
}

//RVA�༭��
void MyFileLocation::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	UpdateData(TRUE);

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
//����RVA�༭��
void MyFileLocation::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LockEdit(IDC_EDIT2);
}

//ƫ�����༭��
void MyFileLocation::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	UpdateData(TRUE);

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//����ƫ�����༭��
void MyFileLocation::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LockEdit(IDC_EDIT3);
}

void MyFileLocation::LockEdit(int EditId)
{
	CEdit *p1 = (CEdit *)GetDlgItem(IDC_EDIT1);
	CEdit *p2 = (CEdit *)GetDlgItem(IDC_EDIT2);
	CEdit *p3 = (CEdit *)GetDlgItem(IDC_EDIT3);
	CEdit *p4 = (CEdit *)GetDlgItem(IDC_EDIT4);
	CEdit *p5 = (CEdit *)GetDlgItem(IDC_EDIT5);
	p1->SetReadOnly(TRUE);
	p2->SetReadOnly(TRUE);
	p3->SetReadOnly(TRUE);
	p4->SetReadOnly(TRUE);
	p5->SetReadOnly(TRUE);
	switch (EditId)
	{
	case IDC_EDIT1:
		p1->SetReadOnly(FALSE);
		break;
	case IDC_EDIT2:
		p2->SetReadOnly(FALSE);
		break;
	case IDC_EDIT3:
		p3->SetReadOnly(FALSE);
		break;
	default:
		break;
	}	
	p1->SetWindowText(_T(""));
	p2->SetWindowText(_T(""));
	p3->SetWindowText(_T(""));
}


//ִ�а�ť
void MyFileLocation::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DWORD Value;
	if (m_Va==L""&&m_Rva==L""&&m_Offset==L"")
	{
		return;
	}
	if (m_Va!=L"")
	{
		Value=AnalPE.ChangeNumber(m_Va);
	}
	if (m_Rva!=L"")
	{
		Value=AnalPE.ChangeNumber(m_Rva);
	}
	if (m_Offset!=L"")
	{
		Value=AnalPE.ChangeNumber(m_Rva);
	}
	DWORD ShowValue=ExclusiveCalcOffset(Value);
	AnalPE.OutPutPeInfo(m_Va,Value+AnalPE.pOptH->ImageBase);//���VA
	//AnalPE.OutPutPeInfo(m_Va,Value+AnalPE.pNtH->OptionalHeader.ImageBase);//���VA
	AnalPE.OutPutPeInfo(m_Rva,Value);		//���RVA
	AnalPE.OutPutPeInfo(m_Offset,ShowValue);//���ƫ��
	//ExclusiveCalcOffset()
	UpdateData(FALSE);
}


DWORD MyFileLocation::ExclusiveCalcOffset(DWORD Rva)
{
	//ѭ���Ƚ����Ǹ�����  ����������ξͼ���ѭ��  
	//PIMAGE_NT_HEADERS32 pnt=pNtH;
	PIMAGE_SECTION_HEADER pSecHTemp=IMAGE_FIRST_SECTION(AnalPE.pNtH);//����ͷ
	int index=0;
	while (!(Rva>=pSecHTemp->VirtualAddress&&
		Rva<pSecHTemp->VirtualAddress+pSecHTemp->SizeOfRawData))
	{
		//�����������λ�û���ҵ�
		if (index>AnalPE.pNtH->FileHeader.NumberOfSections)
		{
				m_Section=L"����";
			////	DWORD a[5];
			//	_memccpy(&Address,pSecHTemp,6,24);
			//	//Address=(int);			

			return Rva;
		}
		++index;
		++pSecHTemp;
	}
	PBYTE iiii=(PBYTE)(Rva-pSecHTemp->VirtualAddress+pSecHTemp->PointerToRawData+(long)AnalPE.buf);
	//CString aa;
	//ʮ�����Ʊ༭��Ҳ��������������
	for (int i=0;i<10;i++)
	{
		CString jj;
		jj.Format(L"%02x ",*(iiii++));
		m_Byte+=jj;
	}
	m_Section=pSecHTemp->Name;
	return Rva-pSecHTemp->VirtualAddress+pSecHTemp->PointerToRawData;;
}




