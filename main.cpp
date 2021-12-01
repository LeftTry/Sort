#include <iostream>
#include "vector"
#include <algorithm>
#include <random>
#include "Heap.h"
#include "ctime"
#include <random>
#include "iterator"

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
    for(int i = 0;i < v.size() - 1;i++){
        for(int j = 0;j < v.size() - i - 1;j++){
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}

void bubbleSortExt(vector<int>& v){
    for(int i = 0;i < v.size() - 1;i++){
        int q = 0;
        for(int j = 0;j < v.size() - i - 1;j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                q++;
            }
        }
        if(q == 0) break;
    }
}

void putSort(vector<int>& v){
    for(int i = 1;i < v.size();i++){
        for(int j = i;j > 0 && v[j - 1] > v[j];j--){
            swap(v[j], v[j - 1]);
        }
    }
}

void selectSort(vector<int>& v){
    for(int i = 0;i < v.size() - 1;i++){
        for(int j = i + 1;j < v.size();j++){
            if(v[j] < v[i]) swap(v[i], v[j]);
        }
    }
}

void test (void (*sort_function)(vector<int>&), int n, vector<int>& v){
    double ticksStart = clock();
    sort_function(v);
    double timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    sort_function(v);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v.begin(), v.end());
    ticksStart = clock();
    sort_function(v);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(v.begin(), v.end() - v.size() + v.size() / 10, g);
    ticksStart = clock();
    sort_function(v);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
}

int main() {
    int n = 1e3;
    cout << "Size: " << n << endl;
    vector<int> v(n);
    for(int i = 0;i < v.size();i++) v[i] = rand();
    cout << "BubbleSort:" << endl;
    test(bubbleSort, n, v);
    cout << "BubbleSortExt:" << endl;
    test(bubbleSortExt, n, v);
    cout << "selectSort:" << endl;
    test(selectSort, n, v);
    cout << "putSort:" << endl;
    test(putSort, n, v);
    n = 1e4;
    cout << "Size: " << n << endl;
    vector<int> v1(n);
    for(int i = 0;i < v1.size();i++) v1[i] = rand();
    cout << "BubbleSort:" << endl;
    test(bubbleSort, n, v1);
    cout << "BubbleSortExt:" << endl;
    test(bubbleSortExt, n, v1);
    cout << "selectSort:" << endl;
    test(selectSort, n, v1);
    cout << "putSort:" << endl;
    test(putSort, n, v1);
    n = 1e5;
    cout << "Size: " << n << endl;
    vector<int> v2(n);
    for(int i = 0;i < v2.size();i++) v2[i] = rand();
    cout << "BubbleSort:" << endl;
    test(bubbleSort, n, v2);
    cout << "BubbleSortExt:" << endl;
    test(bubbleSortExt, n, v2);
    cout << "selectSort:" << endl;
    test(selectSort, n, v2);
    cout << "putSort:" << endl;
    test(putSort, n, v2);
    return 0;
}
