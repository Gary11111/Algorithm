#include<iostream>
#define SIZE 10 // 数组元素的个数 
using namespace std;
// heapSort

int prioQue[SIZE]; // 优先队列 = 堆
int tail;
//int input[] = {2,8,7,1,3,5,6,4};
int input[] = {4,1,3,2,16,9,10,14,8,7} ;

void swap(int a,int b){
	int tmp = prioQue[b];
	prioQue[b] = prioQue[a];
	prioQue[a] = tmp;
}

void insert(int ele){
	// 向堆中加入一个元素 :
	// 先加到队尾，然后逐层与父节点进行比较 
	prioQue[tail] = ele; // 队尾指针向后移动
	int tmp = tail++;
	if(tail == 1) return ; // 只有一个元素不比较 
	while(tmp > 0 && prioQue[tmp] < prioQue[(tmp+1)/2 - 1]){
		swap(tmp,(tmp+1)/2 - 1);
		tmp = (tmp+1)/2 - 1;
	}
} 

int extractMin(){
	// 从堆中取出顶端元素并返回 
	int ret = prioQue[0];
	// cout << ret <<  " " ; 
	if(tail == 0) return ret;
	prioQue[0] = prioQue[tail];
	int tmp = 0;
	while(1){
		int cnt = 0; 
		int leftchild = 2*(tmp+1) - 1;
		int rightchild = 2*(tmp+1);
		if(leftchild >= tail) break;
		
		int left = prioQue[leftchild];
		int right = prioQue[rightchild];
		// 优先和左右子节点中的较小者进行交换 
		if(left <= right){
			if(prioQue[tmp] > left) {
				cnt ++;
				swap(tmp,leftchild);
				tmp = leftchild;
			}
			else if(prioQue[tmp] > right){
				cnt++;
				swap(tmp,rightchild);
				tmp = rightchild;
			} 
		}else {
			if(prioQue[tmp] > right) {
				cnt ++;
				swap(tmp,rightchild);
				tmp = rightchild;
			}
			else if(prioQue[tmp] > left){
				cnt++;
				swap(tmp,leftchild);
				tmp = leftchild;
			} 
		}
		
		if(cnt == 0) break;
	}
	tail--;
	return ret;
}

void buildHeap(){
	for(int i=0;i<SIZE;i++) insert(input[i]);
}

void heapSort(){
	for(int i=0;i<SIZE;i++) input[i] = extractMin();
}

int main(){
	// leftchild = 2(i+1) - 1;
	// rightchild = 2(i+1)
	// parent = (i+1)/2 -1
	tail = 0; // 初始化队尾 
	// cout << "build heap" << endl;
	buildHeap(); // 不断使用inesrt建堆 
	tail --; // 使指针指向队尾元素 
	// for(int i=0;i<SIZE;i++) cout << prioQue[i] << " " ;
	cout << "heap sort " << endl;
	heapSort();  // 不断使用Extract-min取出堆顶元素 
	for(int i=0;i<SIZE;i++) cout << input[i] << " " ; 
}
