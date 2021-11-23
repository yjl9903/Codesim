#include<bits/stdc++.h>
using namespace std;
int main(){
	char ch[50]={0};
	char a[50]={0};
	char b[50]={0};
	cin>>ch;
	int f=1;
	int k=0;
	for(int i=0;i<strlen(ch);i++){
		
		if(f==0){
			if(ch[i]==':'){
	 	    a[k++]=':';
			f=1;
			continue;	
		    }
			a[k++]=ch[i];
			continue;
		}
		if(f==1){
			if(ch[i]!='0'&&ch[i]!=':')
			{
			  a[k++]=ch[i];
			  f=0;
			  continue;	
			}
			if(ch[i]==':'){
				a[k++]='0';
				a[k++]=':';
				continue;
			}
		    if(ch[i]=='0'&&i==strlen(ch)-1){
		      a[k++]='0';	
			}	
		}	
	}
	
	int kk=1;
	int s[9]={0};

	for(int i=0;i<strlen(a);i++){
		if(a[i]==':'){
           kk++;
		}
		if(i==0&&a[i]=='0'&&a[i+1]==':')
		s[kk]++;
		if(a[i]=='0'&&a[i-1]==':'&&a[i+1]==':')
		s[kk]++;
		if(a[i]=='0'&&a[i-1]==':'&&i==strlen(a)-1)
		s[kk]++;
	}
	int lenmax=-1;int index=-1;
	for(int i=1;i<=8;i++){
		if(s[i]==0)continue;
		if(s[i]==1)
		{   int len=0;
		    int j;
		    
			for( j=i;j<=8;j++){
				if(s[j]==1)len++;
				else break;
			}
			
			if(len>lenmax){
				lenmax=len;
				index=i;
			}
			
			i=j;
		}
	}
	
	
	kk=1;
	int kkk=0;
	int ff=0;
	
	
	for(int i=0;i<strlen(a);i++){
		if(kk==index){
			if(kk==1){
				b[kkk++]=':';
			}
			
			for(int j=i;j<strlen(a);j++)
			{   
			     
				if(a[j]==':'||j==strlen(a)-1){
				         lenmax--;
				         if(a[j]==':')kk++;
				}
				
				if(lenmax==0){
					i=j;
					if(j==strlen(a)-1)ff=1;
					break;
				}
				
			}
			
		}
		if(a[i]==':'){
		  kk++;
		  b[kkk++]=a[i];
		  continue;	
		}
		if(i==strlen(a)-1&&ff==1){
			b[kkk++]=':';
			continue;
		}
		b[kkk++]=a[i];
	}
	cout<<b<<endl;
	return 0;
} 
