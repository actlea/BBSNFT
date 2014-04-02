/************************************************************************/
/* author:张佳敏
/* version:1.0
/* info: action.h 该文件集中了提取足球国家队的主要操作
/* time:  [4/2/2014 actlea]
/************************************************************************/
#pragma once
#include "header.h"

namespace action
{
	class Action
	{
	public:
		Action(){};
		~Action(){};
		void InitLink(); //初始化链接
		void WiKi(const char*);//提取wiki网页中国家信息的表格
		void Soda(const char*);//提取soda网页中教练信息的表格
		void NFT(const char*);//提取naiton-football-team网站中的country，player链接
		
	private:
		map<string,string>m_country_ch_e_name; //国家的中英文名
		set<string>m_coachname; //教练的名称
		
	};

}
