class CMyString {
public:
    CMyString(char *pData = NULL);
	  CMyString(const CMyString& str);
	  ~CMyString(void) { delete []m_pData; }

private:
    char* m_pData;
}

CMyString::CMyString(const CMyString& str) {
    *this = str;
}

CMyString& CMyString::operator =(const CMyString& str) {
	  if (this == &str) {
			   return *this;
		}
		
		// if (m_pData != NULL) {
		//      delete []m_pData;
		// 		 m_pData = NULL;
		// }
		//
		// m_pData = new char[strlen(str.m_pData) + 1];
		// strcpy(m_pData, str.m_pData);
		
		// 考虑异常安全性
		char *newData = new char[strlen(str.m_pData) + 1];
		strcpy(newData, str.m_pData);
		if (m_pData != NULL) {
			  delete []m_pData;
			  m_pData = newData;
		}
		
		return *this;
}