#include <iostream>
#include <cstring>
using namespace std; 
/*思路： 
用numT,numM分别表示 T,M 的个数。 
先从前往后遍历：
若在某一时刻 T的个数小于 M的个数，则完不成匹配，bool值b=0。
再从后往前遍历：
若在某一时刻 T的个数小于 M的个数，则完不成匹配，bool值b=0。
最后判断 f是否为0（是否能完成匹配），且T的个数是否是M的2倍。
输出YES或NO即可。
*/
int main() 
{
	int ALLMODEL=0;
	cin>>ALLMODEL;
	
	while(ALLMODEL--)
	{
		int length=0;
		cin>>length;
		string s;
		cin>>s;
		int numT=0,numM=0; bool b=1;
		for(int i=0; i<length; i++)
		{
			if(s[i]=='T') numT++;
			if(s[i]=='M') numM++;
			if(numT<numM) {b=0; break;}
		} 
		numT=0; numM=0;
		for(int i=0; i<length; i++)
		{
			if(s[length-i-1]=='T') numT++;
			if(s[length-i-1]=='M') numM++;
			if(numT<numM) {b=0; break;}
		} 
		if( b && (numT==2*numM) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

