//TMT问题即是把TMT消去，最后如果能将整个数列全部消去，则符合条件
//因此：1：从左往右数，T的数量时刻大于等于M
//2：从右往左数，T的数量时刻大于等于M
//3：整个数列中T是M的两倍 
#include<bits/stdc++.h>
using namespace std;
	int t;//用于记录用例数
	int n;//用于记录用例元素个数
	int NumT,NumM=0;
	int judge=1;
	string ac;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>ac;
		ac=" "+ac;//重置首字符 
		for(int i=1;i<=n;i++){
			if(ac[i]=='T')NumT++;
			if(ac[i]=='M')NumM++;
			if(NumT<NumM){
				judge=0;
				break;
			}
		}NumT=0;NumM=0;
		for(int i=n;i>=1;i--){
			if(ac[i]=='T')NumT++;
			if(ac[i]=='M')NumM++;
			if(NumT<NumM){
				judge=0;
				break;
			}
		}
		if(judge==0||NumT!=NumM*2)cout<<"NO";
		else cout<<"YES";
		cout<<endl;
		NumT=0;NumM=0;judge=1;//为了下一次循环作准备 
	}
	return 0;	 
}
 
