#include<stdio.h>
int main(){
	int t,n,a[2006];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			if(a[i]%2==0)
			printf("%d ",a[i]);
		}
		for(i=0;i<n;i++){
			if(a[i]%2!=0)
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}
