#include<iostream>
#define n 7

using namespace std;
int a[n] = {1,1,2,3,4,4,5};
int t[n];

int main(){
	int k; // 每组至少包含k个数 
	int d; // 每组直径不能超过d
	cin >> k >> d;
	int i;
	t[0] = 1; // 第一个元素默认为可以分组 
	t[k-1] = (i>=(k-1))?0:1; // 初始化第一个可以分组的元素
	for(i=k-1;i<n;i++){
		bool flag = false;
		for(int j=0;j<=(i-(k-1));j++){
			if(t[j] == 1 && a[i] - a[j+1] <= d){
				flag = true;
			}
		}
		if(flag) t[i] = 1;
	} 
	for(i=0;i<n;i++) cout << t[i] << " " ;
}
