/************************************************************************/
/* author:张佳敏
/* version:1.0
/* info: file.h 针对文件的一些操作
/* time:  [4/2/2014 actlea]
/************************************************************************/

#ifndef _FILE_H
#define _FILE_H

/** \brief  打开文件*path
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
	//从本地文件中读取数据存入pageSrc，如果成功返回true
	//声明为static和声明为extern有点类似，此函数因此具有了全局的使用范围
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
	//提取表格数据
	//从下载好的网页中提取表格存入string中
	static string ExtractDataToStr(string& str)
	{
		std::string originalPageString = str;
		std::string tabStr;
		std::string tempStr;
		std::string sResult;

		while (FindTableInHtmlString(originalPageString, tempStr) == 0)
		{	

			tabStr += tempStr;
			//从表格中提取数据
			sResult+=ExtractTableDataEx2(tabStr);

		}/*end while*/
		return sResult;
	}
	//static string ExtractTableDataEx2(string& str)
	//{
	//	string strResult;
	//	//去除表格中的空格
	//	DeleteSpaces(table);
	//	eraseTag(table,'\n');//去除原始table中所有的换行符

	//	//去掉表头<thead
	//	if(table.find("tbody")!=string::npos)
	//		table = table.substr(table.find("<tbody"),table.find("</tbody")-table.find("<tbody"));
	//	//统计表格行数
	//	int rowNum = SubStrCount(table, "<tr");


	//	//以表格各行的最大列数作为表格的列数
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


	//	//初始化包含所有表格数据的二维vector
	//	vector< vector<string> > tabVec(rowNum);
	//	vector< vector<string> >::iterator rIter = tabVec.begin();
	//	for (; rIter != tabVec.end(); ++rIter)
	//	{
	//		(*rIter).resize(colNum);
	//	}

	//	//按行遍历表格
	//	rpos = 0;
	//	for (int i = 0; i < rowNum; i++)
	//	{
	//		rpos = FindStr2Str(table, rpos, "<tr", "</tr>", rowStr);
	//		//计算这一行的列数
	//		int crrntColNum = SubStrCount(rowStr, "<td") + SubStrCount(rowStr, "<th");

	//		//对每一个td进行处理
	//		string tdStr, dataStr, tmpStr;
	//		int cpos = 0;
	//		for (int j = 0; j < crrntColNum; j++)
	//		{
	//			if (rowStr.find("<th") != string::npos)
	//				cpos = FindStr2Str(rowStr, cpos, "<th", "</th>", tdStr);
	//			else
	//				cpos = FindStr2Str(rowStr, cpos, "<td", "</td>", tdStr);

	//			//确定该单元格横跨的行数
	//			int spanNum;
	//			if (tdStr.find("rowspan") != string::npos)
	//			{
	//				string spanNumStr;
	//				FindStr2StrEx(tdStr, 0, "rowspan=\"", "\"", spanNumStr);
	//				spanNum = atoi(spanNumStr.c_str());
	//			}
	//			else
	//				spanNum = 1;
	//			//为了防止网页本身rowspan错误导致tabVec数组越界，将spanNum修改为正确值
	//			//该情况出现在http://sports.sina.com.cn/z/wvbach11/schedule/index.shtml 第9比赛日9.23(周五)这个字段上面
	//			if (i + spanNum - 1 > rowNum - 1)
	//				spanNum = rowNum - i;
	//			//提取单元格的数据
	//			ExtractDataFromTd(tdStr, dataStr);


	//			//在第i行的vector中找到第一个为空的位置
	//			int emptyPos = 0;
	//			while (tabVec[i][emptyPos] != "")
	//				emptyPos++;
	//			//对spanNum行写入单元格数据dataStr
	//			for (int k = i; k - i < spanNum; k++)
	//			{

	//				tabVec[k][emptyPos] = dataStr;
	//			}
	//		}
	//	}
	//	//将二维vector写入string
	//	rIter = tabVec.begin();
	//	for (; rIter != tabVec.end(); ++rIter)
	//	{
	//		vector<string>::iterator cIter = (*rIter).begin();
	//		for (; cIter <= (*rIter).end() - 1; ++cIter)
	//		{
	//			//不是最后一项，且下一项不为空
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