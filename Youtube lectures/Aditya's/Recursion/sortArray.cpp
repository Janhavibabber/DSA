//sort an array using recursion base of sorting a stack using recursion. As for array we can use any sorting algorithm
// sort array in descending order
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp){
    if(v.size() == 0 || v[v.size()-1]>=temp){
        v.push_back(temp);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return;
}

void Sort(vector<int> &v){
    if(v.size()==1){
        return;
    }
    // separating last element for sorting
    int temp = v[v.size() -1];
    v.pop_back();
    // hypothesis
    Sort(v);
    //induction step
    insert(v, temp);
}

int main()
{
    vector<int> v  ={9,0,1,4,90,67,2,120};
    Sort(v);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}