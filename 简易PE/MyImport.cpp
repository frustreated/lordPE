// MyImport.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����PE.h"
#include "MyImport.h"
#include "afxdialogex.h"
#include "vector"
using namespace std;


vector<PIMAGE_IMPORT_DESCRIPTOR> m_VecImport;
// MyImport �Ի���

IMPLEMENT_DYNAMIC(MyImport, CDialogEx)

MyImport::MyImport(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyImport::IDD, pParent)
{

}

MyImport::~MyImport()
{
}

void MyImport::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_UpImport);
	DDX_Control(pDX, IDC_LIST2, m_DownImport);
}


BEGIN_MESSAGE_MAP(MyImport, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &MyImport::OnNMClickList)
//	ON_WM_CHAR()
END_MESSAGE_MAP()


// MyImport ��Ϣ�������


BOOL MyImport::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str[]={L"DLL����",L"OriginalFirstThunk",L"����ʱ���־",L"ForwarderChain",L"����",L"FirstThunk"};
	CString str1[]={L"ThunkRVA",L"Thunkƫ��",L"Thunkֵ",L"��ʾ",L"API����"};
	m_UpImport.SetExtendedStyle(m_UpImport.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//��ѡ�з��
	m_DownImport.SetExtendedStyle(m_DownImport.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	for (int i=0;i<sizeof(str)/sizeof(str[0]);i++)
	{
		m_UpImport.InsertColumn(i,str[i],LVCFMT_LEFT,67);
	}
	for (int i=0;i<sizeof(str1)/sizeof(str1[0]);i++)
	{
		m_DownImport.InsertColumn(i,str1[i],LVCFMT_LEFT,67);
	}
	ShowImportList();
	return TRUE;  // return TRUE unless you set the focus to a control

	// �쳣: OCX ����ҳӦ���� FALSE
}



void MyImport::ShowImportList()
{
	//��ȡ�����
	PIMAGE_IMPORT_DESCRIPTOR  pImpD;
	AnalPE.pDatD=&(	AnalPE.pOptH->DataDirectory[1]);
	pImpD=(PIMAGE_IMPORT_DESCRIPTOR)((long)AnalPE.buf+AnalPE.CalcOffset(AnalPE.pDatD->VirtualAddress));
	//��һ��ѭ�� ÿ�������DLL���ν���
	int i=0;
	CString str;
	while(pImpD->Name)
	{
		//DLL�������
		//printf_s("DLL���ƣ�%s  ",(AnalPE.buf+AnalPE.CalcOffset(pImpD->Name)));
		CString str((AnalPE.buf+AnalPE.CalcOffset(pImpD->Name)));
		//m_UpImport.InsertItem(i,L"(AnalPE.buf+AnalPE.CalcOffset(pImpD->Name))");
		m_UpImport.InsertItem(i,str);
		
		//printf_s("INT(�������Ʊ�)��%08X  ",pImpD->OriginalFirstThunk);
		str.Format(L"%08X",pImpD->OriginalFirstThunk);
		m_UpImport.SetItemText(i,1,str);
		//printf_s("����ʱ���־��%08X  ",pImpD->TimeDateStamp);
		str.Format(L"%08X",pImpD->TimeDateStamp);
		m_UpImport.SetItemText(i,2,str);
	//	printf_s("ForwarderChain��%08X  ",pImpD->ForwarderChain);
		str.Format(L"%08X",pImpD->ForwarderChain);
		m_UpImport.SetItemText(i,3,str);
	//	printf_s("���ƣ�%08X  ",pImpD->Name);
		str.Format(L"%08X",pImpD->Name);
		m_UpImport.SetItemText(i,4,str);
	//	printf_s("FirstThunk��%08X\n",pImpD->FirstThunk);
		str.Format(L"%08X",pImpD->FirstThunk);
		m_UpImport.SetItemText(i,5,str);
		m_VecImport.push_back(pImpD);
		i++;
		
		//system("pause");
		pImpD++;
	}
}


//void MyImport::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}

void MyImport::OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	POSITION pos = m_UpImport.GetFirstSelectedItemPosition();
	int nIndex=(int)pos;
	if (pos == NULL)//�ж��Ƿ�Ϊ��
	{
		return;
	}
	//while(m_DownImport.DeleteColumn(0));
	m_DownImport.DeleteAllItems();
	//�ӻ�ȡ��DLL���뺯����ַ�� IAT ����ƫ��
	PIMAGE_THUNK_DATA32 pInt=(PIMAGE_THUNK_DATA32)(AnalPE.buf+AnalPE.CalcOffset(m_VecImport[nIndex-1]->FirstThunk));
	
	//ѭ�����������ַ��IAT
	int i=0;
	CString str;
	while(pInt->u1.Function)
	{

		DWORD ThunkOffest=AnalPE.CalcOffset(m_VecImport[nIndex-1]->OriginalFirstThunk);
		//�ж����λ�Ƿ�Ϊ1 ��Ϊ1�����Ƶ���
		if (!IMAGE_SNAP_BY_ORDINAL32(pInt->u1.Ordinal))
		{
			//�ҵ������������ַ ������ȡ��  
			//printf_s("ThunkRVA��%08X  ",m_VecImport[nIndex]->OriginalFirstThunk);
			str.Format(L"%08X",m_VecImport[nIndex-1]->OriginalFirstThunk);
			m_DownImport.InsertItem(i,str);
			//printf_s("Thunkƫ�ƣ�%08X  ",ThunkOffest);
			str.Format(L"%08X",ThunkOffest);
			m_DownImport.SetItemText(i,1,str);
		//	printf_s("Thunkֵ��%08X  ",pInt->u1.AddressOfData);
			str.Format(L"%08X",pInt->u1.AddressOfData);
			m_DownImport.SetItemText(i,2,str);
			PIMAGE_IMPORT_BY_NAME pFunName=(PIMAGE_IMPORT_BY_NAME)(AnalPE.buf+AnalPE.CalcOffset(pInt->u1.AddressOfData));
		//	printf_s("��ʾ��%04X  ",pFunName->Hint);
			str.Format(L"%04X",pFunName->Hint);
			m_DownImport.SetItemText(i,3,str);
		//	printf_s("API���ƣ�%s\n",pFunName->Name);
			CString str(pFunName->Name);
			//str.Format(L"%s",pFunName->Name);
			m_DownImport.SetItemText(i,4,str);
			//ÿ��ƫ���ĸ��ֽ�
			m_VecImport[nIndex-1]->OriginalFirstThunk+=4;
			ThunkOffest+=4;
		}
		else
		{
			//m_DownImport.DeleteColumn(0);
			
			////�ҵ������������ַ ������ȡ��  
			////	PIMAGE_IMPORT_BY_NAME pFunName=(PIMAGE_IMPORT_BY_NAME)(buf+CalcOffset(pInt->u1.AddressOfData,pNtH));
			////printf_s("ThunkRVA��%08X  ",m_VecImport[nIndex]->OriginalFirstThunk);
			str.Format(L"%08X",m_VecImport[nIndex-1]->OriginalFirstThunk);
			m_DownImport.InsertItem(i,str);
		//	printf_s("Thunkƫ�ƣ�%08X  ",ThunkOffest);
			str.Format(L"%08X",ThunkOffest);
			m_DownImport.SetItemText(i,1,str);
		//	printf_s("Thunkֵ��%08X  ",pInt->u1.AddressOfData);
			str.Format(L"%08X",pInt->u1.AddressOfData);
			m_DownImport.SetItemText(i,2,str);
			//printf_s("��ʾ��-  ");
			m_DownImport.SetItemText(i,3,L"-");
		//	printf_s("��ţ�%4xH  %4dD\n",pInt->u1.Ordinal&0x7fffffff,pInt->u1.Ordinal&0x7fffffff);
			CString str2;
			str2.Format(L"%4xH",pInt->u1.Ordinal&0x7fffffff);
			str.Format(L"%4dD",pInt->u1.Ordinal&0x7fffffff);
			m_DownImport.SetItemText(i,4,str2+L" "+str);
		}
		i++;
		pInt++;
	}
}
