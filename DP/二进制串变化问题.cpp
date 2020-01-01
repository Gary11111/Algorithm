#include<iostream>
#define n 3

using namespace std;
int a[] = {-1,1,0,1};
int b[] = {-1,0,1,0};
int c[n+1];

int main(){
	for(int i=1;i<=n;i++){
		if(a[i] == b[i]) c[i] = c[i-1];
		else if(a[i]!=b[i]){
			if(a[i-1]!=b[i-1] && a[i] != a[i-1] && i > 1){
				c[i] = c[i-2] + 1;
			}else {
				c[i] = c[i-1] + 1;
			}
		}
	}
	cout << "cost for transfer a to b is: " << c[n] << endl;
}
