#include<iostream>
#define SIZE 20
using namespace std;

int a[] = {3,7,10,14,18,19,2,11,16,17,23,25};
int b[20]; // 辅助数组 
int revCnt; // 逆序对的个数 

void revCount(int start,int end){
	if(start == end){
		return;
	}
	// ------- divide ----------
	int mid = start + (end-start)/2;
	revCount(start,mid);
	revCount(mid+1,end);
	// ------- conquer --------
	int cnt = 0;
	int i = start, j = mid+1;
	while(i<=mid){
		if(a[i] <= a[j]){
			b[cnt++] = a[i];
		}else {
			
		}
		i++;
	}
	while(j<=end){
		b[cnt++] = a[j]; // 把剩余元素加进来 
	}
}

int main(){
	// 逆序对统计
	 
}
