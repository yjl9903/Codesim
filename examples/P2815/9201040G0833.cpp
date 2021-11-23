#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int a[8];

struct Zero{
	int idx;
	int len;
}b[8];

int s = 0;

int main(void){
	scanf("%x:%x:%x:%x:%x:%x:%x:%x", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);
	for(int i = 0; i < 8; ++i){
		if(a[i] == 0){
			b[s].idx = i;
			b[s].len = 0;
			for(int j = i; j < 8; ++j){
				if(a[j] == 0){
					++b[s].len;
				}
				else{
					i += b[s].len - 1;
					break;
				}
			}
			++s;
		}
		
	}
	bool flag = false;
	for(int i = 0; i < s; ++i){
		if(b[i].len != 1){
			flag = true;
		}
	}
	if(s == 0 || !flag){
		printf("%x:%x:%x:%x:%x:%x:%x:%x\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
		return 0;
	}
	int max_idx = 0;
	int max_len = b[max_idx].len;
	for(int i = 0; i < s; ++i){
		if(b[i].len > max_len){
			max_len = b[i].len;
			max_idx = i; 
		}
	}
	if(b[max_idx].idx == 0){
		printf("::");
		for(int i = b[max_idx].len; i < 7; ++i){
			printf("%x:", a[i]);
		}
		if(a[7] == 0){
			return 0;
		}
		printf("%x\n", a[7]);
		return 0;
	}
	if(b[max_idx].idx + b[max_idx].len == 8){
		for(int i = 0; i < b[max_idx].idx; ++i){
			printf("%x:", a[i]);
		}
		printf(":\n");
		return 0;
	}
	for(int i = 0; i < b[max_idx].idx; ++i){
		printf("%x:", a[i]);
	}
	printf(":");
	for(int i = b[max_idx].idx + b[max_idx].len; i < 7; ++i){
		printf("%x:", a[i]);
	}
	printf("%x\n", a[7]);
	return 0;
}
