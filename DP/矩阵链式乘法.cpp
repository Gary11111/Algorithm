#include<iostream>
#define N 4
using namespace std;

int p[N+1] = {5,4,6,2,7};
int m[N+1][N+1] = {0};

int main(){
	for(int length = 1;length < N;length++){
		for(int i=0;i<N-length;i++){
			int j = i+length;
			int min = 21479800;
			for(int k=i;k<j;k++){
				if(m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1] < min){
					min = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				}
			}
			m[i][j] = min;
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "矩阵相乘的结果为: " << m[0][N-1] << endl;
}
