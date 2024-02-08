#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    //1. declaration
    pair<int,string> p;
    pair<int, int> p2(5,8);

    //2. Inserting values
    p = make_pair(2,"abc");
    p = {2,"abcd"};         //value update no duplicate key values

    //3. display values
    cout<<p.first<<" : "<<p.second<<endl;

    //4. copying
    pair<int, string> &p1 = p;
    p1.first = 3;
    cout << p1.first << " : " << p1.second<<endl;

    //5. declaring pair of array
    pair<int, int> p_array[3];

    //6. initializing pair of array values
    // 1 way
    p_array[0] = {1,2};
    p_array[1] = {2,3};
    p_array[2] = {3,4};
    // 2 way
    for (int i = 0; i < 3; i++)
    {
        cin>> p_array[i].first >> p_array[i].second;
    }

    //7. Swapping 1st element with last element
    swap(p_array[0],p_array[2]);

    //8. displaying the array elements
    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " : " << p_array[i].second<<endl;
    }
    
    //9. operators- ==, !=, >=, <=


    return 0;
}