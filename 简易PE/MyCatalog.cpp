// MyCatalog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����PE.h"
#include "MyCatalog.h"
#include "afxdialogex.h"
#include "MyExporTable.h"
#include "MyImport.h"
#include "MyResources.h"
#include "MyRelocation.h"
// MyCatalog �Ի���

IMPLEMENT_DYNAMIC(MyCatalog, CDialogEx)

MyCatalog::MyCatalog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyCatalog::IDD, pParent)
	, m_ExportRva(_T(""))
	, m_ExportSize(_T(""))
	, m_ImportRva(_T(""))
	, m_ImportSize(_T(""))
	, m_ResourceRva(_T(""))
	, m_ResourceSize(_T(""))
	, m_ExceptionRva(_T(""))
	,m_ExceptionSize(_T(""))
	, m_SecurityRva(_T(""))
	, m_SecuritySize(_T(""))
	, m_BaserelocRva(_T(""))
	, m_BaserelocSize(_T(""))
	, M_DebugRva(_T(""))
	, M_DebugSize(_T(""))
	, m_ArchitectureRva(_T(""))
	, m_ArchitectureSize(_T(""))
	, m_GlobalptrRva(_T(""))
	, m_GlobalptrSize(_T(""))
	, m_TlsRva(_T(""))
	, m_TlsSize(_T(""))
	, m_LoadConfigRva(_T(""))
	, m_LoadConfigSize(_T(""))
	, m_BoundImportRva(_T(""))
	, m_BoundImportSize(_T(""))
	, m_IatRva(_T(""))
	, m_IatSize(_T(""))
	, m_DelayImportRva(_T(""))
	, m_DelayImportSize(_T(""))
	, m_ComDescriptorRva(_T(""))
	, m_ComDescriptorSize(_T(""))
{

}

MyCatalog::~MyCatalog()
{
}

void MyCatalog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ExportRva);
	DDX_Text(pDX, IDC_EDIT17, m_ExportSize);
	DDX_Text(pDX, IDC_EDIT2, m_ImportRva);
	DDX_Text(pDX, IDC_EDIT18, m_ImportSize);
	DDX_Text(pDX, IDC_EDIT3, m_ResourceRva);
	DDX_Text(pDX, IDC_EDIT19, m_ResourceSize);
	DDX_Text(pDX, IDC_EDIT4, m_ExceptionRva);
	DDX_Text(pDX, IDC_EDIT20, m_ExceptionSize);
	DDX_Text(pDX, IDC_EDIT5, m_SecurityRva);
	DDX_Text(pDX, IDC_EDIT21, m_SecuritySize);
	DDX_Text(pDX, IDC_EDIT6, m_BaserelocRva);
	DDX_Text(pDX, IDC_EDIT22, m_BaserelocSize);
	DDX_Text(pDX, IDC_EDIT7, M_DebugRva);
	DDX_Text(pDX, IDC_EDIT23, M_DebugSize);
	DDX_Text(pDX, IDC_EDIT8, m_ArchitectureRva);
	DDX_Text(pDX, IDC_EDIT32, m_ArchitectureSize);
	DDX_Text(pDX, IDC_EDIT11, m_GlobalptrRva);
	DDX_Text(pDX, IDC_EDIT26, m_GlobalptrSize);
	DDX_Text(pDX, IDC_EDIT10, m_TlsRva);
	DDX_Text(pDX, IDC_EDIT25, m_TlsSize);
	DDX_Text(pDX, IDC_EDIT9, m_LoadConfigRva);
	DDX_Text(pDX, IDC_EDIT24, m_LoadConfigSize);
	DDX_Text(pDX, IDC_EDIT12, m_BoundImportRva);
	DDX_Text(pDX, IDC_EDIT27, m_BoundImportSize);
	DDX_Text(pDX, IDC_EDIT15, m_IatRva);
	DDX_Text(pDX, IDC_EDIT30, m_IatSize);
	DDX_Text(pDX, IDC_EDIT14, m_DelayImportRva);
	DDX_Text(pDX, IDC_EDIT29, m_DelayImportSize);
	DDX_Text(pDX, IDC_EDIT13, m_ComDescriptorRva);
	DDX_Text(pDX, IDC_EDIT28, m_ComDescriptorSize);
}


BEGIN_MESSAGE_MAP(MyCatalog, CDialogEx)
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_BUTTON9, &MyCatalog::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON16, &MyCatalog::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &MyCatalog::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &MyCatalog::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON21, &MyCatalog::OnBnClickedButton21)
END_MESSAGE_MAP()


// MyCatalog ��Ϣ�������


LRESULT MyCatalog::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return HTCAPTION;
}


void MyCatalog::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
}


BOOL MyCatalog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	ShowPeInfo();//��ʾ����

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

//************************************
// ������:    ShowPeInfo
// ��  ��:    MyCatalog::ShowPeInfo
// Ȩ  ��:    public 
// ����ֵ:    void
// �޶���:   
//************************************
void MyCatalog::ShowPeInfo()
{
	if (AnalPE.pNtH==NULL)
	{
		return;
	}
	
	AnalPE.OutPutPeInfo(m_ExportRva,		AnalPE.pDatD[0].VirtualAddress);
	AnalPE.OutPutPeInfo(m_ExportSize,		AnalPE.pDatD[0].Size);
	AnalPE.OutPutPeInfo(m_ImportRva,		AnalPE.pDatD[1].VirtualAddress);
	AnalPE.OutPutPeInfo(m_ImportSize,		AnalPE.pDatD[1].Size);
	AnalPE.OutPutPeInfo(m_ResourceRva,		AnalPE.pDatD[2].VirtualAddress);
	AnalPE.OutPutPeInfo(m_ResourceSize,		AnalPE.pDatD[2].Size);
	AnalPE.OutPutPeInfo(m_ExceptionRva,		AnalPE.pDatD[3].VirtualAddress);
	AnalPE.OutPutPeInfo(m_ExceptionSize,	AnalPE.pDatD[3].Size);
	AnalPE.OutPutPeInfo(m_SecurityRva,		AnalPE.pDatD[4].VirtualAddress);
	AnalPE.OutPutPeInfo(m_SecuritySize,		AnalPE.pDatD[4].Size);
	AnalPE.OutPutPeInfo(m_BaserelocRva,		AnalPE.pDatD[5].VirtualAddress);
	AnalPE.OutPutPeInfo(m_BaserelocSize,	AnalPE.pDatD[5].Size);
	AnalPE.OutPutPeInfo(M_DebugRva,			AnalPE.pDatD[6].VirtualAddress);
	AnalPE.OutPutPeInfo(M_DebugSize,		AnalPE.pDatD[6].Size);
	AnalPE.OutPutPeInfo(m_ArchitectureRva,	AnalPE.pDatD[7].VirtualAddress);
	AnalPE.OutPutPeInfo(m_ArchitectureSize,	AnalPE.pDatD[7].Size);
	AnalPE.OutPutPeInfo(m_GlobalptrRva,		AnalPE.pDatD[8].VirtualAddress);
	AnalPE.OutPutPeInfo(m_GlobalptrSize,	AnalPE.pDatD[8].Size);
	AnalPE.OutPutPeInfo(m_TlsRva,			AnalPE.pDatD[9].VirtualAddress);
	AnalPE.OutPutPeInfo(m_TlsSize,			AnalPE.pDatD[9].Size);
	AnalPE.OutPutPeInfo(m_LoadConfigRva,	AnalPE.pDatD[10].VirtualAddress);
	AnalPE.OutPutPeInfo(m_LoadConfigSize,	AnalPE.pDatD[10].Size);
	AnalPE.OutPutPeInfo(m_BoundImportRva,	AnalPE.pDatD[11].VirtualAddress);
	AnalPE.OutPutPeInfo(m_BoundImportSize,	AnalPE.pDatD[11].Size);
	AnalPE.OutPutPeInfo(m_IatRva,			AnalPE.pDatD[12].VirtualAddress);
	AnalPE.OutPutPeInfo(m_IatSize,			AnalPE.pDatD[12].Size);
	AnalPE.OutPutPeInfo(m_DelayImportRva,	AnalPE.pDatD[13].VirtualAddress);
	AnalPE.OutPutPeInfo(m_DelayImportSize,	AnalPE.pDatD[13].Size);
	AnalPE.OutPutPeInfo(m_ComDescriptorRva,	AnalPE.pDatD[14].VirtualAddress);
	AnalPE.OutPutPeInfo(m_ComDescriptorSize,AnalPE.pDatD[14].Size);
	UpdateData(FALSE);
}

//************************************
// ������:    OutPutPeInfo
// ��  ��:    MyCatalog::OutPutPeInfo
// Ȩ  ��:    public 
// ����ֵ:    void
// �޶���:   
// ��  ��:    CString & m_PeRvaInfo
// ��  ��:    CString & m_PeSizeInfo
// ��  ��:    DWORD PeRvaValue
// ��  ��:    DWORD PeSizeValue
//************************************
void MyCatalog::OutPutPeInfo(CString &m_PeRvaInfo,CString &m_PeSizeInfo,DWORD PeRvaValue,DWORD PeSizeValue)
{
	CString StrRvaValue,StrSizeValue;
	StrRvaValue.Format(L"%08X",PeRvaValue);//ת16����
	StrSizeValue.Format(L"%08X",PeSizeValue);//ת16����
	m_PeRvaInfo=StrRvaValue;
	m_PeSizeInfo=StrSizeValue;
	UpdateData(FALSE);
}

//�򿪵�����
void MyCatalog::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (AnalPE.buf==NULL)
	{
		AfxMessageBox(L"������PE�ļ�");
		return ;
	}
	if (AnalPE.pDatD->Size==0)
	{
		AfxMessageBox(L"�޵�����");
		return ;
	}
	MyExporTable dlg;
	dlg.DoModal();
}

//�����
void MyCatalog::OnBnClickedButton17()
{
	if (AnalPE.buf==NULL)
	{
		AfxMessageBox(L"������PE�ļ�");
		return ;
	}
	MyImport dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//��Դ��
void MyCatalog::OnBnClickedButton18()
{
	if (AnalPE.buf==NULL)
	{
		AfxMessageBox(L"������PE�ļ�");
		return ;
	}
	MyResources dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//�ض�λ��
void MyCatalog::OnBnClickedButton21()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (AnalPE.buf==NULL)
	{
		AfxMessageBox(L"������PE�ļ�");
		return ;
	}
	MyRelocation dlg;
	dlg.DoModal();
}
