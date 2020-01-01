#include<iostream>
#define n 7
using namespace std;
int a[n] = {-6,-4,7,7,-4,0,1};
int s[n];

int _max(int a,int b){
	return (a>b)?a:b;
}

int main(){
	int maxSum = -1;
	for(int i=0;i<n;i++){
		if(i == 0) s[i] = a[0];
		else {
			s[i] = s[i-1] + a[i];
		}
		if(s[i] > maxSum) maxSum = s[i];
	}
	for(int i=0;i<n;i++) cout << s[i] << " ";
	cout << endl << maxSum << endl;
	
	int min = 99999;
	int max = -21792974;
	for(int i=0;i<n;i++){
		if(s[i]<min) min = s[i];
		if(s[i] > max) max = s[i];
	}
	cout << max - min << endl;
	cout << _max(max-min,maxSum) << endl;
}
