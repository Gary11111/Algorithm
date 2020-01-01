#include<iostream>
#include<vector>
#define N 4
using namespace std;

const int W = 10; // 背包最大重量 

int v[N+1] = {0,10,40,30,50};
int wt[N+1] = {0,5,4,6,3};
int aux[N+1][W+1]; // 动态规划的备忘录 
int keep[N+1][W+1]; // 动态规划查找背包元素的辅助空间 


int max (int a,int b){
	return a<b?b:a;
} 

int main(){
	for(int i=1;i<=N;i++){
		for(int w=1;w<=W;w++){
			if(wt[i] <= w){ // 如果当前物品可以放进来 
				aux[i][w] = max(aux[i-1][w], v[i] + aux[i-1][w-wt[i]]); // 前i个物品，w容量的最大价值等于两种情况的max 
				if(aux[i][w] == v[i] + aux[i-1][w-wt[i]]) keep[i][w] = 1; // 表示加入了第i个元素 
			}else {
				aux[i][w] = aux[i-1][w]; // 当前物品放不进来 
			}
		}
	}
	
	// 打印辅助空间
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
	
	// 寻找问题的最优解
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
	
	cout << "背包最大可以装: " << aux[N][W] << " 背包元素为: "<< endl; 
	for(int i=0;i<kpSet.size();i++){
		cout << kpSet[i] << " " ;
	} 
}
