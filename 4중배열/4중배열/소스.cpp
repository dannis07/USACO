#include <iostream>
using namespace std;
int T;
int arr[4];
int arr1[4];
int arr2[4];
char a_b;
char b_c;
char c_a;
void check1() {
    b_c = 0;
    c_a = 0;
    int count_A = 0;
    int count_B = 0;
    int count_C = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i] > arr2[j]) {
                count_A++;
            }
            if (arr[i] < arr2[j]) {
                count_C++;
            }
        }
    }
    if (count_A > count_C) {
        c_a = 'A';
    }
    if (count_A < count_C) {
        c_a = 'C';
    }
    count_A = 0;
    count_B = 0;
    count_C = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr1[i] > arr2[j]) {
                count_B++;
            }
            if (arr1[i] < arr2[j]) {
                count_C++;
            }
        }
    }
    if (count_B > count_C) {
        b_c = 'B';
    }
    if (count_B < count_C) {
        b_c = 'C';
    }
    count_A = 0;
    count_B = 0;
    count_C = 0;
}
bool check() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int x = 1; x <= 10; x++) {
                for (int z = 1; z <= 10; z++) {
                    arr2[0] = i;
                    arr2[1] = j;
                    arr2[2] = x;
                    arr2[3] = z;
                    check1();
                    if (a_b == 'B' && b_c == 'C' && c_a == 'A') {
                        return true;
                    }
                    if (a_b == 'A' && b_c == 'B' && c_a == 'C') {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    cin >> T;
    int count_A;
    int count_B;
    for (int i = 0; i < T; i++) {
        a_b = '0'; //a_b초기화
        b_c = '0'; //b_c초기화
        c_a = '0'; //c_a 초기화
        count_A = 0; //count_A초기화 
        count_B = 0; //count_B초기화
        for (int j = 0; j < 4; j++) {
            cin >> arr[j];
        }
        for (int j = 0; j < 4; j++) {
            cin >> arr1[j];
        }
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (arr[x] > arr1[y]) {
                    count_A++;
                }
                if (arr[x] < arr1[y]) {
                    count_B++;
                }
            }
        }
        if (count_A > count_B) {
            a_b = 'A';
        }
        if (count_A < count_B) {
            a_b = 'B';
        }
        if (check() == true) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }

    }
    return 0;
}