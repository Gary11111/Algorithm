#include<iostream>
#define n 11

using namespace std;

int s[n+1] = {0,1,3,0,5,3,5,6,8,8,2,12}; // ��ʼʱ�� 
int f[n+1] = {0,4,5,6,7,9,9,10,11,12,14,16}; // ����ʱ�� 
int w[n+1] = {0,5,8,2,4,9,2,5,8,3,6,1}; // Ȩ�� 
int p[n+1]; // ��������� 
int opt[n+1]; // �������� 

void bubSort(){
	int tmp;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(f[i] < f[j]){
				tmp = f[i];
				f[i] = f[j];
				f[j] = tmp;
				
				tmp = w[i];
				w[i] = w[j];
				w[j] = tmp;
				
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

int binSearch(int start){ 
	for(int i=n;i>=0;i--){
		if(f[i] <= start) return i;
	}// O(n)
}

int main(){
	bubSort();
	for(int i=0;i<=n;i++) cout << s[i] << " ";
	cout << endl;
	for(int i=0;i<=n;i++) cout << f[i] << " ";
	cout << endl;
	for(int i=0;i<=n;i++) cout << w[i] << " ";
	cout << endl;
	
	// Ԥ����õ�p����
	for(int i=n;i>0;i--){
		int start = s[i];
		p[i] = binSearch(s[i]);
	} 
	for(int i=0;i<=n;i++) cout << p[i] << " " ;
	cout << endl;
	for(int i=1;i<=n;i++){
		opt[i] = max(opt[i-1],opt[i-p[i]] + w[i]);
	}
	for(int i=0;i<=n;i++) cout << opt[i] << " " ;
	
}
