#include<iostream>
using namespace std;

int main()
{
	int testcase;	cin>>testcase;
	while(testcase--){

		int n;	cin>>n;
		int p,s, arr[15];
		for(int i = 0; i < 15; ++i)	arr[i] = 0;
		for(int i = 0; i < n; ++i){
			cin>>p>>s;
			if(arr[p] < s)	arr[p] = s;
		}
		int sum = 0;
		for(int i = 1; i < 9; ++i)	sum += arr[i];

		cout<<sum<<endl;
	}
	return 0;
}
