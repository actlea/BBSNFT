/************************************************************************/
/* author:�ż���
/* version:1.0
/* info: action.h ���ļ���������ȡ������Ҷӵ���Ҫ����
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
		void InitLink(); //��ʼ������
		void WiKi(const char*);//��ȡwiki��ҳ�й�����Ϣ�ı��
		void Soda(const char*);//��ȡsoda��ҳ�н�����Ϣ�ı��
		void NFT(const char*);//��ȡnaiton-football-team��վ�е�country��player����
		
	private:
		map<string,string>m_country_ch_e_name; //���ҵ���Ӣ����
		set<string>m_coachname; //����������
		
	};

}
