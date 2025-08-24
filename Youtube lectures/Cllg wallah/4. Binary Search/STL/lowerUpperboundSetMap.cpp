#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    set<int> s = {1, 2, 3, 5, 7};

    auto lb_it1 = s.lower_bound(3);
    auto lb_it2 = s.lower_bound(4);
    if(lb_it1 != s.end()){
        cout<<"Element present: "<<*lb_it1<<endl;
    }
    cout << "Element not present: " << *lb_it2 << endl;

    auto ub_it1 = s.upper_bound(3);
    auto ub_it2 = s.upper_bound(4);
    if (ub_it1 != s.end())
    {
        cout << "Element present: " << *ub_it1 << endl;
    }
    cout << "Element not present: " << *ub_it2 << endl;

    map<int, int> mp;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[5] = 5;
    mp[7] = 7;

    auto lb_it_mp1 = mp.lower_bound(3);
    auto lb_it_mp2 = mp.lower_bound(4);
    if (lb_it_mp1 != mp.end())
    {
        cout << "Element present: " << lb_it_mp1->first <<": "<< lb_it_mp1->second<< endl;
    }
    cout << "Element not present: " << lb_it_mp2->first << ": " << lb_it_mp2->second << endl;

    auto ub_it_mp1 = mp.upper_bound(3);
    auto ub_it_mp2 = mp.upper_bound(4);
    if (ub_it_mp1 != mp.end())
    {
        cout << "Element present: " << ub_it_mp1->first << ": " << ub_it_mp1->second << endl;
    }
    cout << "Element not present: " << ub_it_mp2->first << ": " << ub_it_mp2->second << endl;

    return 0;
}