#include<iostream>
using namespace std;
int main(void){
    int t;
    cin>>t;
    for(int m=0;m<t;m++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c1=0,c2=0;
        for(int i=0;i<n;i++)              // 先遍历一遍 T是M的两倍 
            if(s[i]=='M')
                c1++;                         
            else
                c2++;
        if(c1*2!=c2)
            cout<<"NO"<<endl;
        else{
            int c=0;
            int flag=1;                       
            for(int i=0; i<n;i++)
            {
                if(s[i]=='M')
                    c--;                     
                else
                    c++;
                if(c<0||(c2/2)<c)  
                {
                    cout<<"NO"<<endl;
                    flag=0;                   
                    break;
                }
            }
            if(flag)
                cout<<"YES"<<endl;
        }
    }
}



