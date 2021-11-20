#include <iostream>
#include "vector"

using namespace std;

void merge(vector<int>& v, int ind1, int ind2){
    int j = 0;
    vector<int> v1(v.begin() + ind1, v.end() - ind2 - 1), v2(v.begin() + ind2, v.end());
    int size1 = ind2 - ind1, size2 = v.size() - ind2;
    for(int i = 0;i < max(size1, size2);i++){
        if(i >= size1){
            v[j] = v2[i];
            j++;
        }
        else if(i >= size2){
            v[j] = v1[i];
            j++;
        }
        else {
            if (v1[i] >= v2[i]) {
                v[j] = v2[i];
                v[j + 1] = v1[i];
            } else if (v1[i] < v2[i]) {
                v[j] = v1[i];
                v[j + 1] = v2[i];
            }
            j += 2;
        }
    }
}

void mergesort(vector<int>& v, int ind1, int ind2){
    vector<int> v1(v.begin() + ind1, v.end() - ind2 - 1), v2(v.begin() + ind2, v.end());
    cout << "ok";
    int i1 = 0, i2 = v1.size() / 2, i3 = v2.size() / 2;
    if(i1 != i2) mergesort(v1, 0, i2);
    if(i1 != i3) mergesort(v2, 0, i3);
    merge(v, ind1, ind2);
}

int main() {
    vector<int> v(5);
    for(int i = 0; i < 5;i++) cin >> v[i];
    mergesort(v, 0, v.size() / 2);
    for(auto i : v) cout << i << " ";
    cout << endl;
    return 0;
}
