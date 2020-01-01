#include<iostream>
#define k 3
#define n 9

using namespace std;

int coin[k] = {1,4,5};
int t[n+1];

int main(){
	for(int i=1;i<=n;i++){ // O(n)
		int min = t[i-1] + 1;
		for(int j=0;j<k;j++){ // O(k)
			if(i<coin[j]) {
				break;
			}
			if(t[i-coin[j]] + 1 < min){
				min = t[i-coin[j]] + 1;
			}
		}
		t[i] = min;
	}
	for(int i=0;i<=n;i++) cout << t[i] << " ";
	cout << t[n] << endl;
}
