#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int N = 1e6 + 5;
 
int t, n;
string s;
int T_num, M_num, len;
 
bool judge(){
	T_num = M_num = 0;
	for(int i = 0; i < len; i++){
		if(s[i] == 'T'){
			T_num++;
		}
		if(s[i] == 'M'){
			M_num++;
		}
		if(T_num < M_num){
			return false;
		}
	}
	if(T_num != 2 * M_num){
		return false;
	}
	T_num = 0;
	M_num = 0;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == 'T'){
			T_num++;
		}
		if(s[i] == 'M'){
			M_num++;
		}
		if(T_num < M_num){
			return false;
		}
	}
	return true;
}
 
int main(void){
	scanf("%d", &t);
	while(t--){
		cin >> n >> s;
		len = s.length();
		if(judge()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
