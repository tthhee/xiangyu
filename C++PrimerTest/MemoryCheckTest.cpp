#include <iostream>

using namespace std;
int main()
{

SYSTEM_INFO sysInfo;

            GetSystemInfo(&sysInfo);

            cout<<"机器属性："<<endl;

            cout<<"页大小="<<sysInfo.dwPageSize<<endl;

            cout<<"分配粒度="<<sysInfo.dwAllocationGranularity<<endl;

            cout<<"用户区最小值="<<sysInfo.lpMinimumApplicationAddress<<endl;

   cout<<"用户区最大值="

<<sysInfo.lpMaximumApplicationAddress<<endl<<endl; 
return 0;
}