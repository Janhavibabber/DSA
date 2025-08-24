#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 5, 7};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Element present: "<<*lower_bound(arr, arr+n, 3)<<endl;
    cout << "Element not present: " << *lower_bound(arr, arr + n, 4) << endl;
    
    cout << "Element present: " << *upper_bound(arr, arr + n, 3) << endl;
    cout << "Element not present: " << *upper_bound(arr, arr + n, 4) << endl;
    cout << "Element not present: " << upper_bound(arr, arr + n, 4) << endl;

    vector<int> v = {1, 2, 3, 3, 3, 5, 7};

    // For element present in vector - upper bound is more accurate
    auto it1 = lower_bound(v.begin(), v.end(), 3);
    cout<<"no. of smaller elements/ first occurence of key using lower bound: "<< (it1 - v.begin()) <<endl;
    cout << "no. of larger elements using lower bound: " << (v.end() - it1) << endl;

    auto it3 = upper_bound(v.begin(), v.end(), 3);
    cout << "no. of smaller elements using upper bound: " << (it3 - v.begin()) << endl;
    cout << "no. of larger elements/ first occurence of key using upper bound: " << (v.end() - it3) << endl;

    // last occurence not working for unsorted array
    auto it5 = lower_bound(v.begin(), v.end(), 3+1);
    cout << "last Occurence using lower bound: " << (it3 - v.begin()) - 1 << endl;
    auto it6 = upper_bound(v.begin(), v.end(), 3+1);
    cout << "last Occurence using upper bound: " << (it6 - v.begin()) - 1 << endl;

    // For element not present in vector
    auto it2 = lower_bound(v.begin(), v.end(), 4);
    cout << "no. of smaller elements using lower bound: " << (it2 - v.begin()) << endl;
    cout << "no. of larger elements using lower bound: " << (v.end() - it2) << endl;

    auto it4 = upper_bound(v.begin(), v.end(), 4);
    cout << "no. of smaller elements using upper bound: " << (it4 - v.begin()) << endl;
    cout << "no. of larger elements using upper bound: " << (v.end() - it4) << endl;

    return 0;
}