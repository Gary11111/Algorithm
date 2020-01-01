#include<iostream>
#define SIZE 10
using namespace std;
// �����������

// int a[] = {2,8,7,1,3,5,6,4};
int a[] = {4,1,3,2,16,9,10,14,8,7};
int sum[SIZE];

int X,Y; // �û����� 

int rec(int start,int end){
	if(start == end) return 0;
	int mid = start + (end-start)/2;
	int count=0;
	count += rec(start,mid); // ����������������� 
	count += rec(mid+1,end); // �����ұ�����������  
	int i=start,j=mid;
	while(i<=mid && j<=end){ // ���Ϻϲ�֮������������ 
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
	for(int i=1;i<SIZE;i++) sum[i] = sum[i-1] + a[i]; // ��ʼ��ǰ׺������
	cin >> X >> Y;
	cout << "�����������������У� " << rec(0,SIZE-1) << endl;; 
} 
