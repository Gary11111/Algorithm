#include<iostream>
#define n 7

using namespace std;
int a[n] = {1,1,2,3,4,4,5};
int t[n];

int main(){
	int k; // ÿ�����ٰ���k���� 
	int d; // ÿ��ֱ�����ܳ���d
	cin >> k >> d;
	int i;
	t[0] = 1; // ��һ��Ԫ��Ĭ��Ϊ���Է��� 
	t[k-1] = (i>=(k-1))?0:1; // ��ʼ����һ�����Է����Ԫ��
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
