#include <iostream>
#include <cstdio>
using namespace std;

int a[2000];

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; ++i){
			if(a[i] % 2){
				continue;
			}
			for(int j = i + 1; j < n; ++j){
				if(a[j] % 2){
					//位运算交换两数 
					a[i] = a[i] ^ a[j];
					a[j] = a[i] ^ a[j];
					a[i] = a[i] ^ a[j];
				}
			}
		}
		for(int i = 0; i < n; ++i){
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}
