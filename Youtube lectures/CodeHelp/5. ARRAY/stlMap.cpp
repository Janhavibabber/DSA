#include<bits/stdc++.h>
using namespace std;

int main()
{
    //1. Declare
    map<int,string> m;
    map<int, pair<int,int>> mp;
    map<pair<int,int>, int> mpp;

    //2. inserting values
    m[3] = 8;
    m[1] = "abc";
    m.emplace({2,9});
    m.insert({4,"xyz"});
    m.insert(make_pair(2,"pqr"));
    mpp.({2,3}) = 10;

    //3. Print
    //using iterators
    map<int,string> :: iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout<<(*it).first<<":"<<(*it).second<<endl;
    }
    // using range loop
    for(auto &pr: m)
        cout<<pr.first<<":"<<pr.second;

    //4. other functions
    cout<<"Size of map"<<m.size()<<endl;
    auto it = m.find(3);
    if(it == m.end()){
        cout<<"no value";
    }
    else{
        cout<<(*it).first<<":"<<(*it).second;
    }

    //5. Deleting
    //by giving key as input
    m.erase(3);
    //print m;

    //by passing iterator as I/p
    m.erase(it);
    //print m

    m.clear();


    return 0;
}