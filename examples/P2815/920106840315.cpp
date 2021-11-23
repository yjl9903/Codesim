//IPv6 地址压缩
#include<bits/stdc++.h>
using namespace std;
char ch[39];//input 39 long char  ch的有效域为整个函数 
int maxl=-1;//max left
int maxr=1;//max right
void findmaxzero(){//find the max zero
	bool ifzero;
	int i,j,sum;//用于记录 外循环 内循环  0000的个数 
	for(i=0,sum=0;i<8;i++){
		ifzero=true;
		for(j=0;j<4;j++){
			if(ch[i*5+j]!='0'){
				ifzero=false;
				break;
			}
		}
		if(ifzero){
			sum++;
			if(sum>maxr){
				maxr=sum;
				maxl=i;
			}
		}else{
			sum=0;
		}
	}
	if(maxr==1)maxl=-1;
	maxl=maxl-maxr+1;
}
int main(){
	cin>>ch;
	findmaxzero();
	int i1,i2;
	for(i1=0;i1<8;i1++){
		if(maxl==i1){
			cout<<":";
			if(i1==0)cout<<":";
			i1=i1+maxr;
			if(i1>7)break;
		}
		i2=0;
		while(ch[i1*5+i2]=='0'&&i2<3)i2++;
		for(;i2<4;i2++){
			cout<<ch[i1*5+i2];
		}
		if(i2==4&&i1!=7)cout<<":";
	}
	return 0;
}
