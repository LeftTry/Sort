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
    int m = (l + r) / 2;
    while (true){
        while(v[l] < v[m]) l++;
        while(v[r] > v[m]) r--;
        if(l >= r) return r;
        swap(v[l++], v[r--]);
    }
}

int partition1(vector<int>& v, int l, int r){
    int left = l;
    int mid = (l + r) / 2;
    int right = r;
    int mediana;
    if(left > mid){
        if(left < right){
            mediana = left;
        }else mediana = right;
    }else if(mid > right){
        mediana = right;
    }else mediana = mid;
    while (true){
        while(v[l] < v[mediana]) l++;
        while(v[r] > v[mediana]) r--;
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

void quickSortMed(vector<int>& v, int l, int r){
    if(l < r){
        int m = partition1(v, l, r);
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

void test (void (*sort_function)(vector<int>&, int, int), int n, vector<int>& v, int l, int r){
    double ticksStart = clock();
    sort_function(v, l, r);
    double timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    sort_function(v, l, r);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v.begin(), v.end());
    ticksStart = clock();
    sort_function(v, l, r);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(v.begin(), v.end() - v.size() + v.size() / 10, g);
    ticksStart = clock();
    sort_function(v, l, r);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
}

int main() {
    int n = 1e3;
    cout << "Size: " << n << endl;
    vector<int> v(n), vbackup(n);
    for(int i = 0;i < v.size();i++) v[i] = rand();
    vbackup = v;
    cout << "BubbleSort:" << endl;
    test(bubbleSort, n, v);
    v = vbackup;
    cout << "BubbleSortExt:" << endl;
    test(bubbleSortExt, n, v);
    v = vbackup;
    cout << "selectSort:" << endl;
    test(selectSort, n, v);
    v = vbackup;
    cout << "putSort:" << endl;
    test(putSort, n, v);
    n = 1e4;
    cout << "Size: " << n << endl;
    vector<int> v1(n);
    for(int i = 0;i < v1.size();i++) v1[i] = rand();
    vbackup = v1;
    cout << "BubbleSort:" << endl;
    test(bubbleSort, n, v1);
    v1 = vbackup;
    cout << "BubbleSortExt:" << endl;
    test(bubbleSortExt, n, v1);
    v1 = vbackup;
    cout << "selectSort:" << endl;
    test(selectSort, n, v1);
    v1 = vbackup;
    cout << "putSort:" << endl;
    test(putSort, n, v1);
    n = 1e5;
    cout << "Size: " << n << endl;
    vector<int> v2(n);
    for(int i = 0;i < v2.size();i++) v2[i] = rand();
    vbackup = v2;
    cout << "BubbleSort:" << endl;
    test(bubbleSort, n, v2);
    v2 = vbackup;
    cout << "BubbleSortExt:" << endl;
    test(bubbleSortExt, n, v2);
    v2 = vbackup;
    cout << "selectSort:" << endl;
    test(selectSort, n, v2);
    v2 = vbackup;
    cout << "putSort:" << endl;
    test(putSort, n, v2);
    n = 1e5;
    cout << "Size: " << n << endl;
    for(int i = 0;i < v.size();i++) v[i] = rand();
    vbackup = v;
    cout << "PyramidSort:" << endl;
    test(pyramidSort, n, v);
    v = vbackup;
    cout << "MergeSort:" << endl;
    int o = v.size() / 2;
    if(v.size() % 2 == 1) o++;
    test(mergesort, n, v, 0, o);
    v = vbackup;
    cout << "QuickSort:" << endl;
    test(quickSort, n, v, 0, v.size() - 1);
    v = vbackup;
    cout << "QuickSortMed:" << endl;
    test(quickSortMed, n, v, 0, v.size() - 1);
    v = vbackup;
    cout << "QuickSortNonStable:" << endl;
    double ticksStart = clock();
    sort(v.begin(), v.end());
    double timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v.begin(), v.end());
    ticksStart = clock();
    sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(v.begin(), v.end() - v.size() + v.size() / 10, g);
    ticksStart = clock();
    sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
    v = vbackup;
    cout << "QuickSortStable:" << endl;
    ticksStart = clock();
    stable_sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    stable_sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v.begin(), v.end());
    ticksStart = clock();
    stable_sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    shuffle(v.begin(), v.end() - v.size() + v.size() / 10, g);
    ticksStart = clock();
    stable_sort(v.begin(), v.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
    n = 1e6;
    cout << "Size: " << n << endl;
    for(int i = 0;i < v1.size();i++) v1[i] = rand();
    vbackup = v1;
    cout << "PyramidSort:" << endl;
    test(pyramidSort, n, v1);
    v1 = vbackup;
    cout << "MergeSort:" << endl;
    o = v1.size() / 2;
    if(v1.size() % 2 == 1) o++;
    test(mergesort, n, v1, 0, o);
    v1 = vbackup;
    cout << "QuickSort:" << endl;
    test(quickSort, n, v1, 0, v1.size() - 1);
    v1 = vbackup;
    cout << "QuickSortMed:" << endl;
    test(quickSortMed, n, v1, 0, v1.size() - 1);
    v1 = vbackup;
    cout << "QuickSortNonStable:" << endl;
    ticksStart = clock();
    sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v1.begin(), v1.end());
    ticksStart = clock();
    sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    shuffle(v1.begin(), v1.end() - v1.size() + v1.size() / 10, g);
    ticksStart = clock();
    sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
    v1 = vbackup;
    cout << "QuickSortStable:" << endl;
    ticksStart = clock();
    stable_sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    stable_sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v1.begin(), v1.end());
    ticksStart = clock();
    stable_sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    shuffle(v1.begin(), v1.end() - v1.size() + v1.size() / 10, g);
    ticksStart = clock();
    stable_sort(v1.begin(), v1.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
    n = 1e7;
    cout << "Size: " << n << endl;
    for(int i = 0;i < v2.size();i++) v2[i] = rand();
    vbackup = v2;
    cout << "PyramidSort:" << endl;
    test(pyramidSort, n, v2);
    v2 = vbackup;
    cout << "MergeSort:" << endl;
    o = v2.size() / 2;
    if(v2.size() % 2 == 1) o++;
    test(mergesort, n, v2, 0, o);
    v2 = vbackup;
    cout << "QuickSort:" << endl;
    test(quickSort, n, v2, 0, v2.size() - 1);
    v2 = vbackup;
    cout << "QuickSortMed:" << endl;
    test(quickSortMed, n, v2, 0, v2.size() - 1);
    v2 = vbackup;
    cout << "QuickSortNonStable:" << endl;
    ticksStart = clock();
    sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v2.begin(), v2.end());
    ticksStart = clock();
    sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    shuffle(v2.begin(), v2.end() - v2.size() + v2.size() / 10, g);
    ticksStart = clock();
    sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
    v2 = vbackup;
    cout << "QuickSortStable:" << endl;
    ticksStart = clock();
    stable_sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "non_sorted: " << endl;
    cout << timeUsed << endl;
    ticksStart = clock();
    stable_sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted: " << endl;
    cout << timeUsed << endl;
    reverse(v2.begin(), v2.end());
    ticksStart = clock();
    stable_sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sorted, reversed: " << endl;
    cout << timeUsed << endl;
    shuffle(v2.begin(), v2.end() - v2.size() + v2.size() / 10, g);
    ticksStart = clock();
    stable_sort(v2.begin(), v2.end());
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "90% sorted" << endl;
    cout << timeUsed << endl;
    return 0;
}
