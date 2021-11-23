//1.四个数字，第一位开始的零可以缩掉
//2.一串零可以缩成：：
//3.最长的零串，前面的零串，只能缩一次
#include <bits/stdc++.h>
using namespace std;
//先找到最长的零串，变成：：
char a[39];
char b[39];
signed choose(char a[39]){
	int sum_1=0;
	int sum_2=0; 
	int num=39;
	int n_1=0;//起始位置 
	int n_2=0;//终止位置 
	for(int i=0;i<39;i++){
		if(a[i]=='0'){
			sum_2++;
		}
		else{
			if(sum_2>sum_1)
			sum_1=sum_2;
			n_2=i;//终止时的位置 = n_2
			sum_2=0;
		}
	}
	n_1=39-sum_1/4-sum_1;
	for(int i=0;i<n_1;i++){
		int j=0;
		b[j]=a[i];
		j++;
	} 
	b[n_1]=':';
	b[n_1+1]=':';
	for(int i=n_2;i<39;i++){
		int k=n_1+2;
		b[k]=a[i];
		k++; 
	}
	num=num-n_2-n_1;
	return b[];
	return num;
}
int main(){
	for(int i=0;i<39;i++){
		cin>>a[i];
	}
	int temp=0;
	choose(a[39]);
	for(int i=0;i<num;i++){
		if(b[0]=='0'){
			if(b[1]=='0'){
				if(b[2]=='0'){
					if(b[3]=='0'){
						b[0]=b[1]=b[2]=b[3]="";
					}
					else{
						b[0]=b[1]=b[2]="";
					}
					
				}
				else{
						b[0]=b[1]="";
					}
			}
			else{
						b[0]="";
					}
		}
	}
}
