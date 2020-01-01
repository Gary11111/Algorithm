#include<iostream>
#include<vector>
#define X 7
#define Y 6

using namespace std;
char x[X+1] = {0,'A','B','C','B','D','A','B'};
char y[Y+1] = {0,'B','D','C','A','B','A'};

int d[X+1][Y+1];

int p[X+1][Y+1]; // 0:down, 1:right, 2:DR

int main(){
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			if(x[i] == y[j]){
				d[i][j] = d[i-1][j-1] + 1;
				p[i][j] = 2;
			}else {
				d[i][j] = max(d[i-1][j],d[i][j-1]);
				p[i][j] = d[i-1][j] > d[i][j-1] ? 0 : 1;
			}
		}
	}
	
	cout << "最长公共子序列为: " << d[X][Y] << endl;
	vector<char> res;
	int i=X,j=Y;
	while(i!=1 && j!=1){
		if(p[i][j] == 0){
			i--;
		}else if(p[i][j] == 1){
			j--;
		}else {
			res.push_back(y[j]);
			i--;
			j--;
		}
	}
	
	for(int k=0;k<res.size();k++) cout << res[k] << " ";
	
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}
