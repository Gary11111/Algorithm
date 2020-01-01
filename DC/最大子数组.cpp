#include<iostream>
using namespace std;
int arr[] = {6,-4,7,-4,0,1};

int max(int a,int b){
	return (a>b)?a:b;
}

int findMax(int start,int end){
	int left,right,middle;
	if(start == end){
		return arr[start];
	}
	// --------- divide ------------ 
	int mid = start+(end-start)/2;
	left = findMax(start,mid); // 左边的最大值 
		right = findMax(mid + 1,end); // 右边的最大值
	// -------- conquer ------------
	middle = arr[mid] + arr[mid + 1];
	int tmp = middle;
	for(int i = mid-1;i>=start;i--){
		tmp += arr[i];
		if(tmp > middle) middle = tmp;
	}	
	
	for(int i=mid+2;i<=end;i++){
		tmp += arr[i];
		if(tmp > middle) middle = tmp;
	}
	
	return max(max(left,right),middle); // 返回三者的最大值 
}

int main(){
	int n = 6;
	int maxSub = findMax(0,n-1);
	cout << "最大子数组的值为 " << maxSub << endl;
}
