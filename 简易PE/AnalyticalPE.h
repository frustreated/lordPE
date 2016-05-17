#pragma once
class AnalyticalPE
{
public:
	AnalyticalPE(void);
	~AnalyticalPE(void);
public:
	CString PeFileName;
	char* buf ;
	PIMAGE_DOS_HEADER pDosH;	//DOSͷ
	PIMAGE_NT_HEADERS32 pNtH;	//NTͷ
	PIMAGE_OPTIONAL_HEADER32 pOptH;//��ѡͷ
	PIMAGE_SECTION_HEADER pSecH;//����ͷ
	PIMAGE_DATA_DIRECTORY pDatD;//����Ŀ¼
	PIMAGE_EXPORT_DIRECTORY pExpD;// ����������
	void ObtainPeInfo(TCHAR *FileName);					//��ȡPE��Ϣ
	void ClosePeHandle();
	HANDLE hFile ;
	DWORD ChangeNumber(CString NeedValue);			//����ת��
	void OutPutPeInfo(CString &StrPeValue,DWORD WithPeValue);
	DWORD CalcOffset(DWORD Rva);		//����λ��
};

