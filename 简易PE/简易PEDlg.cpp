
// ����PEDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����PE.h"
#include "����PEDlg.h"
#include "afxdialogex.h"
#include "MyCatalog.h"
#include "MyAreaTable.h"
#include "MyFileLocation.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C����PEDlg �Ի���



C����PEDlg::C����PEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����PEDlg::IDD, pParent)
	
	, m_EntryPoint(_T(""))
	, m_ImageBase(_T(""))
	, m_SizeOfImage(_T(""))
	, m_BaseOfCode(_T(""))
	, m_BaseOfData(_T(""))
	, m_SectionAlignment(_T(""))
	, m_FileAlignment(_T(""))
	, m_Magic(_T(""))
	, m_Subsystem(_T(""))
	, m_NumberOfSections(_T(""))
	, m_TimeDateStamp(_T(""))
	, m_SizeOfHeaders(_T(""))
	, m_Characteristics(_T(""))
	, m_CheckSum(_T(""))
	, m_SizeOfOptionalHeader(_T(""))
	, m_NumberOfRvaAndSizes(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����PEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_EntryPoint);
	DDX_Text(pDX, IDC_EDIT1, m_EntryPoint);
	DDX_Text(pDX, IDC_EDIT2, m_ImageBase);
	DDX_Text(pDX, IDC_EDIT3, m_SizeOfImage);
	DDX_Text(pDX, IDC_EDIT4, m_BaseOfCode);
	DDX_Text(pDX, IDC_EDIT5, m_BaseOfData);
	DDX_Text(pDX, IDC_EDIT6, m_SectionAlignment);
	DDX_Text(pDX, IDC_EDIT7, m_FileAlignment);
	DDX_Text(pDX, IDC_EDIT8, m_Magic);
	DDX_Text(pDX, IDC_EDIT9, m_Subsystem);
	DDX_Text(pDX, IDC_EDIT10, m_NumberOfSections);
	DDX_Text(pDX, IDC_EDIT11, m_TimeDateStamp);
	DDX_Text(pDX, IDC_EDIT12, m_SizeOfHeaders);
	DDX_Text(pDX, IDC_EDIT13, m_Characteristics);
	DDX_Text(pDX, IDC_EDIT14, m_CheckSum);
	DDX_Text(pDX, IDC_EDIT15, m_SizeOfOptionalHeader);
	DDX_Text(pDX, IDC_EDIT16, m_NumberOfRvaAndSizes);
}

BEGIN_MESSAGE_MAP(C����PEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &C����PEDlg::OnEnChangeEdit1)
	ON_WM_DROPFILES()
	ON_EN_CHANGE(IDC_EDIT2, &C����PEDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON12, &C����PEDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON3, &C����PEDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON13, &C����PEDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON10, &C����PEDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &C����PEDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// C����PEDlg ��Ϣ�������

BOOL C����PEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����PEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����PEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����PEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//ʵ���ļ���ק
void C����PEDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT movecount=DragQueryFile(hDropInfo,-1,NULL,0);
	TCHAR movefile[MAX_PATH]={0};
	for (UINT i=0;i<movecount;i++)
	{

		DragQueryFile(hDropInfo,i,movefile,MAX_PATH);
		SetWindowText(movefile);
		//	UpdateData(FALSE);
	}
	DragFinish(hDropInfo);
	AnalPE.ObtainPeInfo(movefile);
	ShowPeInfo();
	CDialogEx::OnDropFiles(hDropInfo);
}
//������ʾPE�����Ϣ
void C����PEDlg::ShowPeInfo()
{
	//BaseOfCode;
	if (AnalPE.buf==NULL)
	{
		AfxMessageBox(L"������PE�ļ�");
		return ;
	}
	AnalPE.OutPutPeInfo(m_EntryPoint,AnalPE.pOptH->AddressOfEntryPoint);		//��ڵ�
	AnalPE.OutPutPeInfo(m_ImageBase,AnalPE.pOptH->ImageBase);					//�����ַ
	AnalPE.OutPutPeInfo(m_SizeOfImage,AnalPE.pOptH->SizeOfImage);				//�����С
	AnalPE.OutPutPeInfo(m_BaseOfCode,AnalPE.pOptH->BaseOfCode);					//�����ַ
	AnalPE.OutPutPeInfo(m_BaseOfData,AnalPE.pOptH->BaseOfData);					//���ݻ�ַ
	AnalPE.OutPutPeInfo(m_SectionAlignment,AnalPE.pOptH->SectionAlignment);		//�����
	AnalPE.OutPutPeInfo(m_FileAlignment,AnalPE.pOptH->FileAlignment);			//�ļ������
	AnalPE.OutPutPeInfo(m_Magic,AnalPE.pOptH->Magic);							//��־��
	//�ڶ���
	AnalPE.OutPutPeInfo(m_Subsystem,AnalPE.pOptH->Subsystem);					//��ϵͳ
	AnalPE.OutPutPeInfo(m_NumberOfSections,AnalPE.pNtH->FileHeader.NumberOfSections);			//������Ŀ
	AnalPE.OutPutPeInfo(m_TimeDateStamp,AnalPE.pNtH->FileHeader.TimeDateStamp);				//����ʱ���־
	AnalPE.OutPutPeInfo(m_SizeOfHeaders,AnalPE.pOptH->SizeOfHeaders);			//���״�С
	AnalPE.OutPutPeInfo(m_Characteristics,AnalPE.pNtH->FileHeader.Characteristics);			//����ֵ
	AnalPE.OutPutPeInfo(m_CheckSum,AnalPE.pOptH->CheckSum);						//У���
	AnalPE.OutPutPeInfo(m_SizeOfOptionalHeader,AnalPE.pNtH->FileHeader.SizeOfOptionalHeader);	//��ѡͷ����С
	AnalPE.OutPutPeInfo(m_NumberOfRvaAndSizes,AnalPE.pOptH->NumberOfRvaAndSizes);//RVA������С
	UpdateData(FALSE);
}
//
//
void C����PEDlg::OutPutPeInfo(CString &m_PeInfo,DWORD PeValue)
{
	CString str;
	str.Format(L"%08X",PeValue);//ת16����
	m_PeInfo=str;
	UpdateData(FALSE);
}

//��ڵ�
void C����PEDlg::OnEnChangeEdit1()
{
	UpdateData(TRUE);
}




//�����ַ
void C����PEDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�


	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//Ŀ¼
void C����PEDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyCatalog dialog;
	dialog.DoModal();
}

//���״�С +
void C����PEDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CStringA PeValue(m_SizeOfHeaders);
	char *p=PeValue.GetBuffer();	//ת��Ϊchar* ����
	AnalPE.pOptH->SizeOfHeaders=strtoul(p,0,16)+512;;		//ת��Ϊ10����DWORD  512Ϊ16����200
	OutPutPeInfo(m_SizeOfHeaders,AnalPE.pOptH->SizeOfHeaders);			//���״�С
//	WriteFile(AnalPE.hFile,cs,strlen(cs),&dwsize,NULL);	
	AnalPE.ClosePeHandle();
}

//���α�
void C����PEDlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (AnalPE.buf==NULL)
	{
		AfxMessageBox(L"������PE�ļ�");
		return ;
	}
	MyAreaTable dlg;
	dlg.DoModal();
}

//λ�ü�����
void C����PEDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyFileLocation dlg;
	dlg.DoModal();
}


void C����PEDlg::OnBnClickedButton9()
{
	EndDialog(0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
