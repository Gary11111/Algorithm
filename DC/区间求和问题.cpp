#include<iostream>
#define SIZE 10
using namespace std;
// 区间求和问题

// int a[] = {2,8,7,1,3,5,6,4};
int a[] = {4,1,3,2,16,9,10,14,8,7};
int sum[SIZE];

int X,Y; // 用户输入 

int rec(int start,int end){
	if(start == end) return 0;
	int mid = start + (end-start)/2;
	int count=0;
	count += rec(start,mid); // 加上左边满足条件的 
	count += rec(mid+1,end); // 加上右边满足条件的  
	int i=start,j=mid;
	while(i<=mid && j<=end){ // 加上合并之后满足条件的 
		if(sum[j] - sum[i] <= X) {
			j++;
		}else if(sum[j] - sum[i] >= Y){
			i++;
		}else {
			count ++;
			i++;
		}
	}
	return count;
}



int main(){
	sum[0] = a[0];
	for(int i=1;i<SIZE;i++) sum[i] = sum[i-1] + a[i]; // 初始化前缀和数组
	cin >> X >> Y;
	cout << "满足条件的子数组有： " << rec(0,SIZE-1) << endl;; 
} 
