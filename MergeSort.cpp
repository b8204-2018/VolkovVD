#include <iostream>
#include <conio.h>

using namespace std;

#define max 100

class Sort {
public:
    virtual void sorting(int* arr, int size) = 0;
};

class Merge : public Sort {
public:
    void sorting(int* arr,int size) override;
    void merging(int left, int right);
};

void Merge::sorting(int *arr, int size){
    merging(0,size-1)
};

void Merge::merging(int left, int right){
    if (right == left)
        return;
    if (right - left == 1) {
        if (arr[right] < arr[left])
            swap(arr[right], arr[left]);
        return;
    }
    int m = (right + left) / 2;
    sorting(left,m);
    sorting(m+1,right);
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
}

int main() {
    Sort *sort = new Merge;
    unsigned int n;
    cin >> n;
    int* arr;
    for (int i = 0; i < n; i++) {
        cout << "Array[" << i << "] - ";
        cin >> arr[i];
    }
    sort->sorting(arr,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}