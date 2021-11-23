#include<stdio.h>

int main(){
	char a[39];
	scanf("%s",a);
	int i,j,maxlen=0,maxi=0,flag=0,cnt=0;
	for(i=0;i<8;i++){
		flag=0;
		for(j=0;j<4;j++){
			if(a[i*5+j]!='0'){
				flag=1;
				break;	
			}
		}
		if(flag==0){
			cnt++;
			if(cnt>maxlen){
				maxlen=cnt;
				maxi=i+1-cnt;
			}
		}else cnt=0;
	}
	for(i=0;i<8;i++){
		if(i==maxi&&maxlen!=1&&maxlen!=0){
			printf(":");
			if(i==0)printf(":");
			i+=maxlen;
			if(i>7)break; 
			}
		j=0;
		while(a[i*5+j]=='0'&&j<3)j++;
		for(;j<4;j++)printf("%c",a[i*5+j]);
		if(j==4&&i!=7)printf(":");
	}
	
	return 0;
}
