#include <iostream>
#include <conio.h>

using namespace std;

#define max 100

class Sort {
public:
  virtual void sorting (int* arr) = 0;
};

class Merge : public Sort {
public:
    void sorting(int* arr,int l, int r) override;
};

void Merge::sorting(int* arr, int l, int r) {
    if (r == l)
        return;
    if (r - l == 1) {
        if (arr[r] < arr[l])
            swap(arr[r], arr[l]);
        return;
    }
    int m = (r + l) / 2;
    sorting(arr,l, m);
    sorting(arr,m + 1, r);
    int buf[max];
    int xl = l;
    int xr = m + 1;
    int cur = 0;
    while (r - l + 1 != cur) {
        if (xl > m)
            buf[cur++] = arr[xr++];
        else if (xr > r)
            buf[cur++] = arr[xl++];
        else if (arr[xl] > arr[xr])
            buf[cur++] = arr[xr++];
        else buf[cur++] = arr[xl++];

    }
    for (int i = 0; i < cur; i++)
        arr[i + l] = buf[i];
};

int main() {
    Merge merge1;
    unsigned int n;
    cin >> n;
    int* arr;
    for (int i = 0; i < n; i++) {
        cout << "Array[" << i << "] - ";
        cin >> arr[i];
    }
    merge1.sorting(arr,0,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
