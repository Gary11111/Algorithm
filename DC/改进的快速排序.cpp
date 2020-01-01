#include<iostream>
#include<stdlib.h>
#include<time.h> 
#define SIZE 10
using namespace std;
// int a[] = {2,8,7,1,3,5,6,4};
int a[] = {4,1,3,2,16,9,10,14,8,7} ;

void swap(int i,int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int random(int lo=0, int hi=8){
	// srand(time(NULL)); :: Ϊ��ÿ�β�����ͬ���������������������� 
	return rand()%(hi-lo);
}

void quickSort(int left,int right){
	if(left >= right) return ; // ��������ر���Ҫ 
	int i = left-1;
	int j = left;
	int pix = left + random(left,right+1); // ȡ����Ԫ��
	swap(right,pix); // ������Ԫ�غ����һ��Ԫ�ص�λ�� 
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
	quickSort(0,SIZE-1);
	for(int i=0;i<SIZE;i++) cout << a[i] << " ";
}
