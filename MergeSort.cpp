#include <iostream>
#include <conio.h>

using namespace std;

#define max 100

class Sort {
public:
    virtual void sorting (int* arr, int size) = 0;
};

class Merge : public Sort {
    int left, right;
public:
    void sorting(int* arr,int size) override;
    void init(int size);
};

void Merge::sorting(int* arr, int size) {
    if (right == left)
        return;
    if (right - left == 1) {
        if (arr[right] < arr[left])
            swap(arr[right], arr[left]);
        return;
    }
    int m = (right + left) / 2;
    left = 0;
    right = m;
    sorting(arr,size);
    left = m +1;
    if (size%2 == 1){
        right = m*2+1;
    }
    else{
        right = m*2;
    }
    sorting(arr,size);
    int buf[max];
    int xl = left;
    int xr = m + 1;
    int cur = 0;
    while (right - left + 1 != cur) {
        if (xl > m)
            buf[cur++] = arr[xr++];
        else if (xr > right)
            buf[cur++] = arr[xl++];
        else if (arr[xl] > arr[xr])
            buf[cur++] = arr[xr++];
        else buf[cur++] = arr[xl++];

    }
    for (int i = 0; i < cur; i++)
        arr[i + left] = buf[i];
};

void Merge::init(int size){
    left = 0;
    right = size;
}

int main() {
    Merge merge1;
    unsigned int n;
    cin >> n;
    int* arr;
    for (int i = 0; i < n; i++) {
        cout << "Array[" << i << "] - ";
        cin >> arr[i];
    }
    merge1.init(n);
    merge1.sorting(arr,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}