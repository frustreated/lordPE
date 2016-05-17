// MyAreaTable.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����PE.h"
#include "MyAreaTable.h"
#include "afxdialogex.h"
#include "AnalyticalPE.h"

// MyAreaTable �Ի���

IMPLEMENT_DYNAMIC(MyAreaTable, CDialogEx)

MyAreaTable::MyAreaTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyAreaTable::IDD, pParent)
{

}

MyAreaTable::~MyAreaTable()
{
}

void MyAreaTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_AreaTabList);
}


BEGIN_MESSAGE_MAP(MyAreaTable, CDialogEx)
//	ON_WM_CLOSE()
//	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// MyAreaTable ��Ϣ�������


BOOL MyAreaTable::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str[]={L"����",L"VOffset",L"VSize",L"ROffset",L"Rsize",L"��־"};
	for (int i=0;i<sizeof(str)/sizeof(str[0]);i++)
	{
		m_AreaTabList.InsertColumn(i,str[i],LVCFMT_LEFT,67);
	}
	ShowAreaTable();
	return TRUE;  // return TRUE unless you set the focus to a control
}

void MyAreaTable::ShowAreaTable()
{
	if (AnalPE.pSecH==NULL)
	{
		return;
	}
	PIMAGE_SECTION_HEADER pSecHTemp=AnalPE.pSecH;;//����ͷ
	int i=0;
	CString str;
	while (i<AnalPE.pNtH->FileHeader.NumberOfSections)	//������Ŀ
	{
		str=pSecHTemp->Name;
		m_AreaTabList.InsertItem(i,str);
		str.Format(L"%08X",pSecHTemp->VirtualAddress);
		m_AreaTabList.SetItemText(i,1,str);
		str.Format(L"%08X",pSecHTemp->Misc.VirtualSize);
		m_AreaTabList.SetItemText(i,2,str);
		str.Format(L"%08X",pSecHTemp->PointerToRawData);
		m_AreaTabList.SetItemText(i,3,str);
		str.Format(L"%08X",pSecHTemp->SizeOfRawData);
		m_AreaTabList.SetItemText(i,4,str);
		str.Format(L"%08X",pSecHTemp->Characteristics);
		m_AreaTabList.SetItemText(i,5,str);
		++pSecHTemp;
		i++;
	}
}


//void MyAreaTable::OnClose()
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	int i=0;
//	//m_AreaTabList.DeleteAllItems();
//	CDialogEx::OnClose();
//}


//void MyAreaTable::OnShowWindow(BOOL bShow, UINT nStatus)
//{
//	CDialogEx::OnShowWindow(bShow, nStatus);
//	int i=0;
//	
//	// TODO: �ڴ˴������Ϣ����������
//}
