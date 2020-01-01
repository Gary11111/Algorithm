#include<iostream>
#define SIZE 8
using namespace std;
int a[] = {2,8,7,1,3,5,6,4};

void swap(int i,int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void quickSort(int left,int right){
	cout << "left : " << left << endl;
	cout << "right: " << right << endl;
	if(left >= right) return ; // 这个条件特别重要 
	int i = left-1;
	int j = left;
	while(j!=right){
		if(a[j] < a[right]){
			i++;
			swap(i,j);
		}
		j++;
	}
	swap(i+1,right);
	quickSort(0,i); // sort left
	quickSort(i+2,right); // sort right
}

int main(){
	quickSort(0,7);
	for(int i=0;i<8;i++) cout << a[i] << " ";
}
