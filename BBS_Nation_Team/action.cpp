#include "action.h"

using namespace action;

/** \brief ���initlink.txt�ĵ��е������ļ����в�ͬ�Ĳ���
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
	//�ٴ�tableStr����ȡ������Ҫ������

	
}

void Action::Soda(const char* url)
{

}

void Action::NFT(const char* url)
{

}