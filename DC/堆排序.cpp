#include<iostream>
#define SIZE 10 // ����Ԫ�صĸ��� 
using namespace std;
// heapSort

int prioQue[SIZE]; // ���ȶ��� = ��
int tail;
//int input[] = {2,8,7,1,3,5,6,4};
int input[] = {4,1,3,2,16,9,10,14,8,7} ;

void swap(int a,int b){
	int tmp = prioQue[b];
	prioQue[b] = prioQue[a];
	prioQue[a] = tmp;
}

void insert(int ele){
	// ����м���һ��Ԫ�� :
	// �ȼӵ���β��Ȼ������븸�ڵ���бȽ� 
	prioQue[tail] = ele; // ��βָ������ƶ�
	int tmp = tail++;
	if(tail == 1) return ; // ֻ��һ��Ԫ�ز��Ƚ� 
	while(tmp > 0 && prioQue[tmp] < prioQue[(tmp+1)/2 - 1]){
		swap(tmp,(tmp+1)/2 - 1);
		tmp = (tmp+1)/2 - 1;
	}
} 

int extractMin(){
	// �Ӷ���ȡ������Ԫ�ز����� 
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
		// ���Ⱥ������ӽڵ��еĽ�С�߽��н��� 
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
	tail = 0; // ��ʼ����β 
	// cout << "build heap" << endl;
	buildHeap(); // ����ʹ��inesrt���� 
	tail --; // ʹָ��ָ���βԪ�� 
	// for(int i=0;i<SIZE;i++) cout << prioQue[i] << " " ;
	cout << "heap sort " << endl;
	heapSort();  // ����ʹ��Extract-minȡ���Ѷ�Ԫ�� 
	for(int i=0;i<SIZE;i++) cout << input[i] << " " ; 
}
