#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int calcRedundantBits(int m) {
    for (int i = 0; ; i++) {
        if (pow(2, i) >= m + i + 1) {
            return i;
        }
    }
}

string posRedundantBits(string data, int r) {
    int j = 0;//j is an index for tracking the position of the redundant bits to be added.
    int k = 1;//k is an index for accessing the original data bits.
    int m = data.length();//m is the length of the original data.
    string res = "";
    for (int i = 1; i <= m + r; i++) {
        if (i == pow(2, j)) {
            res += '0';
            j++;
        }
        else {
            res += data[data.length() - k];
            k++;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

string calcParityBits(string arr, int r) {
    int n = arr.length();
    for (int i = 0; i < r; i++) {
        int val = 0;
        for (int j = 1; j <= n; j++) {
            if (j & (1 << i)) {
                val ^= (arr[n - j] - '0');
            }
        }
        arr = arr.substr(0, n - (1 << i)) + to_string(val) + arr.substr(n - (1 << i) + 1);
    }
    return arr;
}

int detectError(string arr, int nr) {
    int n = arr.length();
    int res = 0;
    for (int i = 0; i < nr; i++) {
        int val = 0;
        for (int j = 1; j <= n; j++) {
            if (j & (1 << i)) {
                val ^= (arr[n - j] - '0');
            }
        }
        res += val * pow(2, i);
    }
    return res;
}

int main() {
    string data;
    cout << "Enter the data bits: ";
    cin >> data;
    int m = data.length();
    int r = calcRedundantBits(m);
    string arr = posRedundantBits(data, r);
    arr = calcParityBits(arr, r);
    cout << "Data transferred is " << arr << endl;

    string data_rec;
    cout << "Enter the received codeword: ";
    cin >> data_rec;
    cout << "Error Data is " << data_rec << endl;
    int correction = detectError(data_rec, r);
    cout << "The position of error is " << correction << endl;

    return 0;
}

