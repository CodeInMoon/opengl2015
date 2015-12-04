#pragma once
#include <stdio.h>
#include <time.h>

namespace apanoo {

	struct Time
	{
		int year;
		int month;
		int day;

		int hour;
		int min;
		int sec;
	};

	class System
	{
	private:
		System() {};
		static System *m_Instance;  // ����

		class CGarbo  // ���ڲ����������ע��system����
		{
		public:
			~CGarbo() {
				if (System::m_Instance)
				{
					delete System::m_Instance;
				}
			}
		};
		static CGarbo Garbo;

	public:
		static System * GetInstance();  // Instance

		Time* SystemTime();
	};
}