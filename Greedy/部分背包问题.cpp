#include<iostream>
#include<stdlib.h>
#define N 4

using namespace std;

int v[N] = {60,75,100,120};
int w[N] = {10,25,20,30};
int p[N]; // 记录性价比 
int r[N]; // 记录结果 

void bubSort(){
	int tmp;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(p[i] > p[j]){
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
				
				tmp = w[i];
				w[i] = w[j];
				w[j] = tmp;
				
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

int sum(){
	int i=0;
	int sum =0;
	while(r[i] > 0){
		sum += r[i];
		i++;
	}
	return sum;
}

int main(){
	int K;
	// cin >> K;
	K = 50;
	for(int i=0;i<N;i++){
		p[i] = v[i] / w[i];
	}
	bubSort(); // 按照性价比进行排序 
	int j=0;
	while(K>0){
		if(K>w[j]) {
			K -= w[j];
			r[j] += v[j];
			j++;
		}else {
			r[j] = K * p[j];
			K = 0;
		}
	}
	cout << "部分背包总价值" << sum() << endl;;
}
