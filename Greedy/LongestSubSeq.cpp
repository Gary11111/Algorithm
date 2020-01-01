#include<iostream>
#define n 6
using namespace std;

int a[n+1] = {0,5,24,6,17,12,45};
int t[n+1];

int main(){
	for(int i=1;i<=n;i++){
		int max = 1;
		for(int j=1;j<=i;j++){
			if(a[j] < a[i] && t[j]+1 > max){
				max  = t[j] + 1;
			}
		}
		t[i] = max;
	}
	for(int i=0;i<=n;i++) cout << t[i] << " ";
	cout << endl;
	cout << "longest Seq length = " << t[n] << endl;
}
