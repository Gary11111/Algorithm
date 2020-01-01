#include<iostream>
#define n 7
using namespace std;
int a[n] = {6,-8,7,7,-4,0,1};

int max(int a,int b,int c){
	return max(a,max(b,c));
}

int main(){
	int low,high,maxSum; // actually need
	int ilow,ihigh,imaxSum; // auxilary space
	low = 0;
	high = 0;
	maxSum = 0;
	ilow = 0;
	ihigh = 0;
	imaxSum = 0;
	
	for(int i=0;i<n;i++){
		ihigh = i;
		if(imaxSum > 0){
			imaxSum += a[i];
		}else{
			ilow = i;
			imaxSum = a[i];
		}
		
		if(imaxSum > maxSum){
			maxSum = imaxSum;
			low = ilow;
			high = ihigh;
		}
	}
	cout << maxSum << endl;
	cout << low << " " << high << endl;
}
