#include<bits/stdc++.h>
#include<iostream>
//#include<forward_list>
//#include<list>
using namespace std;

int main(){

    // Singly linked list
    // forward_list<int> l1 = {2,5,6,7};
    // cout<<l1.front()<<endl;
    // forward_list<int> l2;
    // l2.assign({3,4,5,6});
    // l2.push_front(4);
    // cout<< l2.size();
    // for (auto it = l1.begin(); it != l1.end(); it++)
    // {
    //     cout<<*it<<" ";
    // }

    // Doubly linked list
    list<int> l3 = {4,5,6,8};
    cout << l3.front();
    cout << l3.back();
    l3.push_front(9);
    l3.push_back(6);
    
    for(auto it=l3.begin(); it!=l3.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    l3.remove(6);

    l3.erase(l3.begin());
    cout<<"after erase"<<endl;
    for(auto i:l3){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of list "<<l3.size()<<endl;
    return 0;
}