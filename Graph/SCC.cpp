#include<iostream>
#include<vector>
#define n 12
using namespace std;
int graph[n+1][n+1];
int revGraph[n+1][n+1];
/*
	color :
	0 = White
	1 = Grey
	2 = Black
*/
int color1[n]; // for origin graph
int color2[n]; // for reverse graph
vector<int> vetR; // 逆向图中的结点变黑序列 
vector<int> vetL; // vetR 取逆 

void initGraph(){
	graph[1][3] = 1;
	graph[3][2] = 1;
	graph[2][1] = 1;
	graph[4][1] = 1;
	graph[1][6] = 1;
	graph[4][7] = 1;
	graph[7][6] = 1;
	graph[6][4] = 1;
	
	graph[10][12] = 1;
	graph[12][11] = 1;
	graph[11][10] = 1;
	graph[4][10] = 1;
	graph[6][11] = 1;
	
	graph[5][5]  = 1;
	graph[5][4] = 1;
	graph[5][9] = 1;
	graph[5][7] = 1;
	
	graph[8][9] = 1;
	graph[9][8] = 1;
	graph[8][7] = 1;
}

void reverse(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(graph[i][j] == 1){
				revGraph[j][i] == 1;
			}
		}
	}
}

void dfs2(int i){
	if(color2[i] == 0) color2[i] = 1;
	for(int j = 1; j<=n;j++){
		if(revGraph[i][j] == 1 && color2[j] == 0){
			dfs2(j);
		}
	}
	color2[i] = 2;
	vetR.push_back(i);
}

int main(){
	initGraph();
	reverse();
	for(int i=1;i<=n;i++){
		if(color2[i] == 0){
			dfs2(i);
		}
	}
	for(int i=0;i<vetR.size();i++) cout << vetR[i] << " ";
}
