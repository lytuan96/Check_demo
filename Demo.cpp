//Code install led 
#include <iostream>
using namespace std;
int Matrix[200][25];
int HoanVi[6][3]= {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
int Answer;
int main() {
//	freopen("input.txt","r",stdin);
	int T, N, M;
	cin >>T;
	for (int testCase =1; testCase <= T; testCase++) {
		cin >> N >> M;
		// Nhap input vao mang
		for (int i=0; i< N; i++) {
			for (int j=0; j< M; j++) {
				cin >> Matrix[i][j];
			}
		}

		// reset Answer
		Answer = -1;
		
		// Kiem tra 6 hoan vi
		for (int i=0; i < 6; i++){
			int count =0;
			for (int cot = 0; cot < M; cot++) {
				// phan 1 : 0 -> N/3
				for (int hang = 0; hang < N/3; hang++) {
					if (Matrix[hang][cot] != HoanVi[i][0]) {
						count++;
					}
				}
				// phan 2 : N/3 -> 2*N/3
				for (int hang = N/3; hang < 2*N/3; hang++) {
					if (Matrix[hang][cot] != HoanVi[i][1]) {
						count++;
					}
				}
				// phan 3: 2*N/3 -> N
				for (int hang = 2*N/3 ; hang < N; hang++) {
					if (Matrix[hang][cot] != HoanVi[i][2]) {
						count++;
					}
				}
			}
			// so sanh voi Answer
			if( Answer == -1 || Answer > count) {
				Answer = count;
			}
		}
		// in het qua
		cout <<"#"<<testCase <<" "<<Answer<<endl;
	}
	return 0;
}