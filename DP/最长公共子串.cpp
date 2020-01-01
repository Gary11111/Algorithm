#include<iostream>
#define X 7
#define Y 6

using namespace std;

int x[X+1] = {0,'D','E','A','D','B','E','E'};
int y[Y+1] = {0,'E','A','T','B','E','E'};

int d[X+1][Y+1];

int main(){
	int max = 0;
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			if(x[i] == y[j]){
				d[i][j] = d[i-1][j-1] + 1;
				if(d[i][j] > max) max = d[i][j];
			}
		}
	}
	cout << "最长公共子串为: " << max << endl;
}
