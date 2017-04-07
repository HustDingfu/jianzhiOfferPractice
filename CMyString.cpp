/*
题目：有如下类型的CMyString的声明 请为该类型
添加赋值运算符函数
*/
#include<cstring> // strlen and memcpy

class CMyString {
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator=(const CMyString& str);
private:
	char* m_pData;
};



CMyString& CMyString::operator=(const CMyString& str) {

	// 利用copy-swap技术
	if(&str != this) {
		CMyString tmpStr(str);
		// swap pointer of tmp.m_pData and m_pData;
		char* tmpPointer = m_pData;
		m_pData = tmpStr.m_pData;
		tmpStr.m_pData = tmpPointer;
	}
	return *this;
}

CMyString::CMyString(char* pData){
	m_pData = pData;
}

CMyString::CMyString(const CMyString& str) {
	//深拷贝
	int length = strlen(str.m_pData);
	m_pData = new char[length+1];
	memcpy(m_pData, str.m_pData, length + 1);
}

CMyString::~CMyString(){
	if(m_pData != NULL) {
		delete [] m_pData;
	}
}