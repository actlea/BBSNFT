#include "action.h"

using namespace action;

/** \brief 针对initlink.txt文档中的三个文件进行不同的操作
 *
 * \param 
 * \param 
 * \return null
 *
 */  
void Action::InitLink()
{
	int mark = 0;
	string pageSrc;

	readFromFile(LINKFILE,pageSrc);

	const char *ptr = pageSrc.c_str();
	string url;

	while(*ptr)
	{
		if(*ptr != '@')
		{
			url += *ptr;
		}
		else
		{
			if(mark==0)
			{
				WiKi(url);
			}
			else if(mark==1)
			{
				NFT(url);
			}
			else
			{
				Soda(url);
			}
				mark++;
			url.clear();
		}
		ptr ++;
	}

}


void Action::WiKi(const char* url)
{
	string page;
	string tableStr;
	try
	{
		page = DownLoadPage(url);
		if(_strcmpi(page,"error") )
		{
			throw url;
		}
	}
	catch (const char* e)
	{
		cout << url <<" download failed!"
			abort();
	}
	tableStr = ExtractDataToStr(page)
	//再从tableStr中提取我们需要的数据

	
}

void Action::Soda(const char* url)
{

}

void Action::NFT(const char* url)
{

}