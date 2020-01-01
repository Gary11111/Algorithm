#include<iostream>
#define N 10


using namespace std;

int p[N+1] = {0,1,5,8,9,10,17,17,20,24,26};
int r[N+1] = {0}; // 记录钢条长度对应的切割最大价值 
int cut[N+1] = {0}; // 记录切的位置 


int main(){
	for(int i=1;i<=N;i++){
		int max = 0;
		int index = 0;
		for(int j=1;j<=i;j++){
			if(p[j] + r[i-j] > max){
				max = p[j] + r[i-j];
				index = j;
			}
		}
		r[i] = max;
		cut[i] = index;
	}
	for(int i=0;i<=N;i++) cout << r[i] << " ";
	cout << endl;
	for(int i=0;i<=N;i++) cout << cut[i] << " ";
	cout << endl;
	cout << "钢条切割的最大价值为: " << r[N] << endl; 
	cout << "切法如下：" << endl;
	int index = N;
	while(index > 0){
		cout << "长度为： " << index << "在" << cut[index] << "切" << endl;
		index -= cut[index];
	}
}
