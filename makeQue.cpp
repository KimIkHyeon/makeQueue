#include <iostream>
using namespace std;

#define MAXN ((int)1e4)
int N;//��ɰ���
int cmd[MAXN + 10];
int a[MAXN + 10];

int que[MAXN + 10];
int wp, rp;
void push(int d){
	que[rp] = d;
	rp++;
}
void pop() {
	wp++;
}
int front() {
	return que[wp];
}
bool empty() {
	if (rp == wp) return 1;
	return 0;
}
int size() {
	return rp-wp;
}
void Solve(){
	wp = rp = 0;//�ʱ�ȭ
	for (int i=0; i<N; i++){
		switch(cmd[i]){
		case 0://�а� ����
			if (empty()) {
				cout << "E" << "\n";
			}
			else{
				cout << front() << "\n";
				pop();
			}
			break;
		case 1://����
			push(a[i]);
			break;
		default://2 : ���� ����
			cout << size() << "\n";
		}
	}
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> cmd[i];
		if (cmd[i] == 1){
			cin >> a[i];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	Solve();
	return 0;
}
