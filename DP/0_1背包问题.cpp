#include<iostream>
#include<vector>
#define N 4
using namespace std;

const int W = 10; // ����������� 

int v[N+1] = {0,10,40,30,50};
int wt[N+1] = {0,5,4,6,3};
int aux[N+1][W+1]; // ��̬�滮�ı���¼ 
int keep[N+1][W+1]; // ��̬�滮���ұ���Ԫ�صĸ����ռ� 


int max (int a,int b){
	return a<b?b:a;
} 

int main(){
	for(int i=1;i<=N;i++){
		for(int w=1;w<=W;w++){
			if(wt[i] <= w){ // �����ǰ��Ʒ���ԷŽ��� 
				aux[i][w] = max(aux[i-1][w], v[i] + aux[i-1][w-wt[i]]); // ǰi����Ʒ��w����������ֵ�������������max 
				if(aux[i][w] == v[i] + aux[i-1][w-wt[i]]) keep[i][w] = 1; // ��ʾ�����˵�i��Ԫ�� 
			}else {
				aux[i][w] = aux[i-1][w]; // ��ǰ��Ʒ�Ų����� 
			}
		}
	}
	
	// ��ӡ�����ռ�
	/*cout << "## memo ## " << endl; 
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			cout << aux[i][j] << " ";
		}
		cout << endl;
	}
	cout << "## keep ##" << endl;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			cout << keep[i][j] << " ";
		}
		cout << endl;
	}*/
	
	// Ѱ����������Ž�
	int weight = W;
	int index = N;
	vector<int> kpSet;
	while(weight >= 0 && index >= 1){
		if(keep[index][weight] != 0){
			kpSet.push_back(index);
			weight -= wt[index];
			index--;
		}else {
			index--;
		}
	} 
	
	cout << "����������װ: " << aux[N][W] << " ����Ԫ��Ϊ: "<< endl; 
	for(int i=0;i<kpSet.size();i++){
		cout << kpSet[i] << " " ;
	} 
}
