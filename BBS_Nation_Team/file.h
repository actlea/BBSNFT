/************************************************************************/
/* author:�ż���
/* version:1.0
/* info: file.h ����ļ���һЩ����
/* time:  [4/2/2014 actlea]
/************************************************************************/

#ifndef _FILE_H
#define _FILE_H

/** \brief  ���ļ�*path
 *
 * \param 
 * \param 
 * \return 
 *
 */  

#include "header.h"
#include <fstream>
using namespace std;

namespace action{
	//�ӱ����ļ��ж�ȡ���ݴ���pageSrc������ɹ�����true
	//����Ϊstatic������Ϊextern�е����ƣ��˺�����˾�����ȫ�ֵ�ʹ�÷�Χ
	static void readFromFile(string filePath,string& pageSrc)
	{

		string tmpStr;
		ifstream in;

		in.open(filePath);

		try
		{
			if(in.fail())
				throw filePath;
		}
		catch (string str)
		{
			cout << "file " << str << " open error!" << endl;
			abort();
		}

		while(getline(in,tmpStr))
		{
			pageSrc+=tmpStr;
			tmpStr.clear();
		}
		in.close();

	}

	static void writeToFile(string filePath,string& pageSrc)
	{
		string tmpStr;
		ofstream out;

		out.open(filePath);

		try
		{
			if(out.fail())
				throw filePath;
		}
		catch (string str)
		{
			cout << "file " << str << " open error!" << endl;
			abort();
		}
		out<<pageSrc;
		out .close();

	}
	//��ȡ�������
	//�����غõ���ҳ����ȡ������string��
	static string ExtractDataToStr(string& str)
	{
		std::string originalPageString = str;
		std::string tabStr;
		std::string tempStr;
		std::string sResult;

		while (FindTableInHtmlString(originalPageString, tempStr) == 0)
		{	

			tabStr += tempStr;
			//�ӱ������ȡ����
			sResult+=ExtractTableDataEx2(tabStr);

		}/*end while*/
		return sResult;
	}
	//static string ExtractTableDataEx2(string& str)
	//{
	//	string strResult;
	//	//ȥ������еĿո�
	//	DeleteSpaces(table);
	//	eraseTag(table,'\n');//ȥ��ԭʼtable�����еĻ��з�

	//	//ȥ����ͷ<thead
	//	if(table.find("tbody")!=string::npos)
	//		table = table.substr(table.find("<tbody"),table.find("</tbody")-table.find("<tbody"));
	//	//ͳ�Ʊ������
	//	int rowNum = SubStrCount(table, "<tr");


	//	//�Ա����е����������Ϊ��������
	//	int colNum = 0;
	//	size_t rpos = 0;
	//	string rowStr;
	//	for (int i = 0; i < rowNum; i++)
	//	{
	//		rpos = FindStr2Str(table, rpos, "<tr", "</tr>", rowStr);
	//		int n = SubStrCount(rowStr, "<td");
	//		if (n > colNum)
	//			colNum = n;
	//	}


	//	//��ʼ���������б�����ݵĶ�άvector
	//	vector< vector<string> > tabVec(rowNum);
	//	vector< vector<string> >::iterator rIter = tabVec.begin();
	//	for (; rIter != tabVec.end(); ++rIter)
	//	{
	//		(*rIter).resize(colNum);
	//	}

	//	//���б������
	//	rpos = 0;
	//	for (int i = 0; i < rowNum; i++)
	//	{
	//		rpos = FindStr2Str(table, rpos, "<tr", "</tr>", rowStr);
	//		//������һ�е�����
	//		int crrntColNum = SubStrCount(rowStr, "<td") + SubStrCount(rowStr, "<th");

	//		//��ÿһ��td���д���
	//		string tdStr, dataStr, tmpStr;
	//		int cpos = 0;
	//		for (int j = 0; j < crrntColNum; j++)
	//		{
	//			if (rowStr.find("<th") != string::npos)
	//				cpos = FindStr2Str(rowStr, cpos, "<th", "</th>", tdStr);
	//			else
	//				cpos = FindStr2Str(rowStr, cpos, "<td", "</td>", tdStr);

	//			//ȷ���õ�Ԫ���������
	//			int spanNum;
	//			if (tdStr.find("rowspan") != string::npos)
	//			{
	//				string spanNumStr;
	//				FindStr2StrEx(tdStr, 0, "rowspan=\"", "\"", spanNumStr);
	//				spanNum = atoi(spanNumStr.c_str());
	//			}
	//			else
	//				spanNum = 1;
	//			//Ϊ�˷�ֹ��ҳ����rowspan������tabVec����Խ�磬��spanNum�޸�Ϊ��ȷֵ
	//			//�����������http://sports.sina.com.cn/z/wvbach11/schedule/index.shtml ��9������9.23(����)����ֶ�����
	//			if (i + spanNum - 1 > rowNum - 1)
	//				spanNum = rowNum - i;
	//			//��ȡ��Ԫ�������
	//			ExtractDataFromTd(tdStr, dataStr);


	//			//�ڵ�i�е�vector���ҵ���һ��Ϊ�յ�λ��
	//			int emptyPos = 0;
	//			while (tabVec[i][emptyPos] != "")
	//				emptyPos++;
	//			//��spanNum��д�뵥Ԫ������dataStr
	//			for (int k = i; k - i < spanNum; k++)
	//			{

	//				tabVec[k][emptyPos] = dataStr;
	//			}
	//		}
	//	}
	//	//����άvectorд��string
	//	rIter = tabVec.begin();
	//	for (; rIter != tabVec.end(); ++rIter)
	//	{
	//		vector<string>::iterator cIter = (*rIter).begin();
	//		for (; cIter <= (*rIter).end() - 1; ++cIter)
	//		{
	//			//�������һ�����һ�Ϊ��
	//			if (cIter != (*rIter).end() - 1 && *cIter != "" && *(cIter+1) != "")
	//				strResult += (*cIter) + ',';
	//			else
	//			{
	//				strResult += (*cIter);
	//				break;
	//			}
	//		}
	//		strResult += '\n';
	//	}
	//	return strResult;
	//}
}


#endif // _FILE_H