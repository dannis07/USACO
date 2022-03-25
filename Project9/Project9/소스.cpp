#include <iostream>
using namespace std;
int T;
int arrA[4];
int arrB[4];
int arrC[4];

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		int countA=0;
		int countB = 0;
		int countC = 0;
		int ab = 0;
		int bc = 0;
		int ac = 0;
		int correct = 0;
		for (int i = 0; i < 4; i++) {
			cin >> arrA[i];
		}
		for (int i = 0; i < 4; i++) {
			cin >> arrB[i];
		}
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				for (int x = 1; x <= 10; x++) {
					for (int y = 1; y <= 10; y++) {
						arrC[0] = i;
						arrC[1] = j;
						arrC[2] = x;
						arrC[3] = y;
						for (int a = 0; a < 4; a++) {
							for (int b = 0; b < 4; b++) {
								if (arrA[a] > arrB[b]) {
									countA++;
								}
								if (arrB[b] > arrA[a]) {
									countB++;
								}
							}
							if (countA > countB) {
								ab = 1;
							}
							else if (countB > countA) {
								ab = 2;
							}
						}
						countA = 0;
						countB = 0;
						countC = 0;
						for (int a = 0; a < 4; a++) {
							for (int b = 0; b < 4; b++) {
								if (arrB[a] > arrC[b]) {
									countB++;
								}
								if (arrC[b] > arrB[a]) {
									countC++;
								}
							}
							if (countC > countB) {
								bc = 3;
							}
							else if (countB > countC) {
								bc = 2;
							}
						}
						countA = 0;
						countB = 0;
						countC = 0;
						for (int a = 0; a < 4; a++) {
							for (int b = 0; b < 4; b++) {
								if (arrA[a] > arrC[b]) {
									countA++;
								}
								if (arrC[b] > arrA[a]) {
									countC++;
								}
							}
							if (countC > countA) {
								ac = 3;
							}
							else if (countB > countA) {
								ac = 1;
							}
						}
						countA = 0;
						countB = 0;
						countC = 0;
						if (ab == 1 && bc == 2 && ac == 3 || ab == 2 && bc == 3 && ac == 1) {
							correct = 1;
						}
					}
				}
			}
		}
		if (correct == 1) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}

	}
}