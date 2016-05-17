#include "stdafx.h"
#include "AnalyticalPE.h"


AnalyticalPE::AnalyticalPE(void)
{
}


AnalyticalPE::~AnalyticalPE(void)
{
}
void AnalyticalPE::ObtainPeInfo(TCHAR *FileName)
{
	//	TCHAR FileName[] = _T("C:\\Users\\Administrator\\Desktop\\PEText.exe");
	PeFileName=FileName;
	buf = nullptr;
	//�õ��ļ����
	hFile =CreateFile(
		FileName, GENERIC_READ|GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	//�õ��ļ���С
	DWORD dwFileSize = 
		GetFileSize(hFile, NULL);
	DWORD ReadSize = 0;
	buf = new char[dwFileSize];
	//���ļ���ȡ���ڴ�
	ReadFile(hFile, buf, dwFileSize, &
		ReadSize, NULL);
	pDosH=(PIMAGE_DOS_HEADER)buf;
	if(IMAGE_DOS_SIGNATURE!=pDosH->e_magic)
	{
		//MessageBox(L"����DOSͷ",L"s")
		AfxMessageBox(L"����DOSͷ");
		return ;
	}
	//printf_s("DOSͷ:0x%X\n",pDosH->e_magic);
	//printf_s("EXE�ļ���ƫ��ͷ:0x%X\n",pDosH->e_lfanew);
	//��ȡNTͷ
	pNtH=(PIMAGE_NT_HEADERS32)(buf+pDosH->e_lfanew);  
	//PIMAGE_NT_HEADERS32 pNtH=(PIMAGE_NT_HEADERS32)buf;  
	if (pNtH->Signature!=IMAGE_NT_SIGNATURE)
	{
	//	MessageBox(L"����NTͷ");
		AfxMessageBox(L"����NTͷ");
		return ;
	}
	//��ȡ����ͷ
	pSecH=IMAGE_FIRST_SECTION(pNtH);
	//��ȡ��ѡͷ����
	pOptH=&(pNtH->OptionalHeader);
	//��ȡ����Ŀ¼
	pDatD=&(pOptH->DataDirectory[0]);
	//��ȡ����������
	//pExpD=(PIMAGE_EXPORT_DIRECTORY)(buf+CalcOffset(pDatD->VirtualAddress));
}

void AnalyticalPE::ClosePeHandle()
{
	CloseHandle(hFile);
}

DWORD AnalyticalPE::ChangeNumber(CString NeedValue)
{
	CStringA PeValue(NeedValue);
	char *p=PeValue.GetBuffer();	//ת��Ϊchar* ����
	return strtoul(p,0,16);		//ת��Ϊʮ��������

}



void AnalyticalPE::OutPutPeInfo(CString &StrPeValue,DWORD WithPeValue)
{
	CString NewStrPeValue;
	NewStrPeValue.Format(L"%08X",WithPeValue);//ת16����
	StrPeValue=NewStrPeValue;
	
}

DWORD AnalyticalPE::CalcOffset(DWORD Rva)
{
	//ѭ���Ƚ����Ǹ�����  ����������ξͼ���ѭ��  
	//PIMAGE_NT_HEADERS32 pnt=pNtH;
	PIMAGE_SECTION_HEADER pSecHTemp=IMAGE_FIRST_SECTION(pNtH);//����ͷ
	int index=0;
	while (!(Rva>=pSecHTemp->VirtualAddress&&
		Rva<pSecHTemp->VirtualAddress+pSecHTemp->SizeOfRawData))
	{
		//�����������λ�û���ҵ�
		if (index>pNtH->FileHeader.NumberOfSections)
		{
			//	m_Section=L"����";
			////	DWORD a[5];
			//	_memccpy(&Address,pSecHTemp,6,24);
			//	//Address=(int);			

			return Rva;
		}
		++index;
		++pSecHTemp;
	}
	return Rva-pSecHTemp->VirtualAddress+pSecHTemp->PointerToRawData;;
}
