#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int size = -1;

// ---------- BASIC INDEX FUNCTIONS ----------
int parent(int i){
    return (i - 1) / 2;
}

int leftChild(int i){
    return (2 * i) + 1;
}

int rightChild(int i){
    return (2 * i) + 2;
}

// ---------- SHIFT UP ----------
void shiftup(int i){
    while(i > 0 && H[parent(i)] < H[i]){
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// ---------- SHIFT DOWN ----------
void shiftdown(int i){

    int maxindex = i;

    int l = leftChild(i);
    if(l <= size && H[l] > H[maxindex]){
        maxindex = l;
    }

    int r = rightChild(i);
    if(r <= size && H[r] > H[maxindex]){
        maxindex = r;
    }

    if(i != maxindex){
        swap(H[i], H[maxindex]);
        shiftdown(maxindex);
    }
}

// ---------- INSERT ----------
void insert(int value){
    size++;
    H[size] = value;
    shiftup(size);
}

// ---------- EXTRACT MAX ----------
int extractmax(){
    if(size < 0){
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int result = H[0];
    H[0] = H[size];
    size--;

    shiftdown(0);
    return result;
}

// ---------- DISPLAY HEAP ----------
void display(){
    for(int i = 0; i <= size; i++){
        cout << H[i] << " ";
    }
    cout << endl;
}

// ---------- MAIN ----------
int main(){

    insert(10);
    insert(50);
    insert(30);
    insert(20);
    insert(40);

    cout << "Heap: ";
    display();

    cout << "Extract Max: " << extractmax() << endl;

    cout << "Heap after extraction: ";
    display();

    return 0;
}
