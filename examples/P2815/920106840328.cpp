#include <iostream>

using namespace std;
struct people{
int starttime;
int endtime;
int sumtime;
int guodutime=0;
};
int main()
{
   int n;
   cin>>n;
   people a[50];
   int m_max1=0;
   int m_max2=0;
   for(int i=0;i<n;i++)
   {
       cin>>a[i].starttime;
       cin>>a[i].endtime;
   }
    for(int i=0;i<n-1;i++)
   {
       for(int j=i;j<n-i;j++)
       {
           if(a[j+1].starttime<a[i].endtime&&a[j+1].endtime>a[i].endtime)
           {
               a[i].endtime=a[j+1].endtime;
           }
       }
   }
   for(int i=0;i<n;i++)
   {
       a[i].sumtime=a[i].endtime-a[i].starttime;
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(a[j+1].endtime<a[i].starttime)
           {
              a[i].guodutime=a[i].starttime-a[j+1].endtime;
           }
       }
   }
    for(int i=0;i<n;i++)
   {
       if(m_max1<a[i].sumtime)
       {
           m_max1=a[i].sumtime;
       }
       if(m_max2<a[i].guodutime)
       {
           m_max2=a[i].guodutime;
       }
   }
   cout<<m_max1<<' '<<m_max2;
    return 0;
}
