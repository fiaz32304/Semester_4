#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapsize = -1;

int parent(int i){
    return (i - 1) / 2;
}

void shiftup(int i){
    while(i > 0 && H[parent(i)] < H[i]){
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void insert(int p){
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftup(heapsize);
}

int main() {
    insert(10);
    insert(50);
    insert(30);
    insert(40);

    for(int i = 0; i <= heapsize; i++){
        cout << H[i] << " ";
    }

    return 0;
}
