#ifndef SORT_HEAP_H
#define SORT_HEAP_H

#include <iostream>
#include "vector"

using namespace std;

template <typename T>
class Heap{
    vector<T> heap;
public:
    Heap();
    Heap(vector<T>&);
    vector<T> get_vec();
    void Shift_up(int);
    void Shift_up1(int);
    void Shift_down(int);
    void Shift_down1(int);
    void increaseEl(int, T);
    void decreaseEl(int, T);
    T extractMax();
    void insert(T);
    void Delete(int);
    template<class Type> friend std::ostream & operator<<(std::ostream&, Heap<Type>);

    void Build_Heap1(vector<int> &v);
    void Build_Heap2(vector<int> &v);
    bool empty();
};

template<typename T>
Heap<T>::Heap(vector<T>& h) {
    heap = h;
}

template<typename T>
void Heap<T>::Shift_up(int index) {
    int i = index;
    if(heap.empty()){
        cout << 0 << " ";
        return;
    }
    while(i > 0){
        int o = i / 2;
        if(i % 2 == 0) o--;
        if(heap[i] > heap[o]){
            T s = heap[o];
            heap[o] = heap[i];
            heap[i] = s;
            i = o;
        }
        else break;
        //cout << "ok";
    }
    cout << i + 1 << endl;
}

template<typename T>
void Heap<T>::Shift_up1(int index) {
    int i = index;
    if(heap.empty()){
        cout << 0 << " ";
        return;
    }
    while(i > 0){
        int o = i / 2;
        if(i % 2 == 0) o--;
        if(heap[i] > heap[o]){
            T s = heap[o];
            heap[o] = heap[i];
            heap[i] = s;
            i = o;
        }
        else break;
        //cout << "ok";
    }
}

template<typename T>
void Heap<T>::increaseEl(int index, T val) {
    heap[index] += val;
}

template<class Type>
std::ostream &operator<<(ostream & out, Heap<Type> h) {
    vector<Type> vec = h.get_vec();
    for(int i = 0;i < vec.size();i++)
        out << vec[i] << " ";
    out << endl;
    return out;
}

template<typename T>
vector<T> Heap<T>::get_vec() {
    return heap;
}

template<typename T>
void Heap<T>::Shift_down(int ind) {
    int i = ind;
    if(heap.empty()){
        cout << 0 << endl;
        return;
    }
    while(i <= int(heap.size())){
        int o1 = 2 * i + 1;
        int o2 = 2 * i + 2;
        if(o1 >= int(heap.size())) o1 = -1;
        if(o2 >= int(heap.size())) o2 = -1;
        if(o1 == -1 && o2 == -1) break;
        int maxind = -1;
        if(o1 == -1 || o2 == -1) maxind = max(o1, o2);
        else{
            if(heap[o1] >= heap[o2]) maxind = o1;
            else maxind = o2;
        }
        if(heap[i] < heap[maxind]){
            T s = heap[maxind];
            heap[maxind] = heap[i];
            heap[i] = s;
            i = maxind;
        }
        else break;
    }
    cout << i + 1 << " ";
}

template<typename T>
void Heap<T>::Shift_down1(int ind) {
    int i = ind;
    if(heap.empty()){
        //cout << 0 << endl;
        return;
    }
    while(i <= int(heap.size())){
        int o1 = 2 * i + 1;
        int o2 = 2 * i + 2;
        if(o1 >= int(heap.size())) o1 = -1;
        if(o2 >= int(heap.size())) o2 = -1;
        if(o1 == -1 && o2 == -1) break;
        int maxind = -1;
        if(o1 == -1 || o2 == -1) maxind = max(o1, o2);
        else{
            if(heap[o1] >= heap[o2]) maxind = o1;
            else maxind = o2;
        }
        if(heap[i] < heap[maxind]){
            T s = heap[maxind];
            heap[maxind] = heap[i];
            heap[i] = s;
            i = maxind;
        }
        else break;
    }
}

template<typename T>
void Heap<T>::decreaseEl(int ind, T val) {
    heap[ind] -= val;
}

template<typename T>
T Heap<T>::extractMax() {
    T extracted = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    this->Shift_down1(0);
    //cout << extracted << endl;
    return extracted;
}

template<typename T>
void Heap<T>::insert(T val) {
    heap.push_back(val);
    this->Shift_up(heap.size() - 1);
}

template<typename T>
void Heap<T>::Delete(int ind) {
    T deleted = heap[ind];
    heap[ind] = heap.back();
    heap.pop_back();
    this->Shift_up1(ind);
    this->Shift_down1(ind);
    cout << deleted << endl;
}

template<typename T>
Heap<T>::Heap() {
}
template<typename T>
void Heap<T>::Build_Heap1(vector<int>& v){
    heap.push_back(v[0]);
    for(int i = 1;i < v.size();i++){
        heap.push_back(v[i]);
        this->Shift_up(heap.size() - 1);
    }
}

template<typename T>
void Heap<T>::Build_Heap2(vector<int>& v){
    heap = v;
    for(int i = heap.size() - 1;i >= 0;i--){
        this->Shift_down1(i);
    }
}

template<typename T>
bool Heap<T>::empty() {
    if(heap.empty() == true) return true;
    else return false;
}

#endif //SORT_HEAP_H
