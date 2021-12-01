#include <iostream>
#include "vector"
#include <algorithm>
#include <random>
#include "Heap.h"

using namespace std;

vector<int> merge(vector<int>& v1, vector<int>& v2){
    vector<int> v(v1.size() + v2.size());
    int i = 0, j = 0, k = 0;
    while(i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            v[k] = v1[i];
            k++;
            i++;
        } else {
            v[k] = v2[j];
            k++;
            j++;
        }
    }
        for(i;i < v1.size();i++){
            v[k] = v1[i];
            k++;
        }
        for(j;j < v2.size();j++){
            v[k] = v2[j];
            k++;
        }
    return v;
}

void mergesort(vector<int>& v, int ind1, int ind2){
    vector<int> v1(v.begin() + ind1, v.end() - v.size() + ind2), v2(v.begin() + ind2, v.end());
    int i1 = 0, i2 = v1.size() / 2, i3 = v2.size() / 2;
    if(v1.size() % 2 == 1) i2++;
    if(v2.size() % 2 == 1) i3++;
    if(v1.size() > 1) mergesort(v1, 0, i2);
    if(v2.size() > 1) mergesort(v2, 0, i3);
    v = merge(v1, v2);
}

int partition(vector<int>& v, int l, int r){
    int m = l;
    while (true){
        while(v[l] < v[m]) l++;
        while(v[r] > v[m]) r--;
        if(l >= r) return r;
        swap(v[l++], v[r--]);
    }
}

void quickSort(vector<int>& v, int l, int r){
    if(l < r){
        int m = partition(v, l, r);
        quickSort(v, l, m);
        quickSort(v, m + 1, r);
    }
}

void pyramidSort(vector<int>& v){
    Heap<int> heap;
    heap.Build_Heap2(v);
    v.clear();
    while (!heap.empty()){
        v.push_back(heap.extractMax());
    }
}

void bubbleSort(vector<int>& v){
    for(int i = 0;i < v.size();i++){

    }
}

int main() {
    vector<int> v(5);
    for(int i = 0; i < 5;i++) cin >> v[i];
    mergesort(v, 0, v.size() / 2);
    for(auto i : v) cout << i << " ";
    cout << endl;
    return 0;
}
