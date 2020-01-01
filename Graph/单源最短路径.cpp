#include<iostream>
#include<set>
#define n 5
#define inf 214798098
#define null -1
using namespace std;
int a[n][n]; // 有权图 
int color[n]; // 用来表示结点的访问情况 
int d[n]; // 用来表示s到每个结点的距离
int pred[n]; // 用来表示每个结点的前驱结点 

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = inf;
		}
	}
	a[0][1] = 2;
	a[0][2] = 7;
	a[1][2] = 3;
	a[2][1] = 2;
	a[2][3] = 1;
	a[1][3] = 8;
	a[1][4] = 5;
	a[3][4] = 4;
	a[4][3] = 5;
	for(int i=0;i<n;i++){
		d[i] = inf;
		color[i] = 0;
		pred[n] = null;
	}
}

void relax(int u,int v,int w){
	if(d[v] > d[u] + w){
		d[v] = d[u] + w;
	}
} 

void bellMan(int s){
	d[s] = 0;
	int m = n-1;
	while(m--){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j] < inf){
					relax(i,j,a[i][j]);
				}
			}
		}
	}
}

int main(){
	init();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	bellMan(0);
	for(int i=0;i<n;i++) cout << d[i] << " " ;
}
