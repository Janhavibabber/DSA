#include<bits/stdc++.h>
using namespace std;

int main(){

    //1. min and max element
    int arr[]={1,16,8,3,42,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* maxele = max_element(arr, arr+n);
    cout<<*maxele;
    int* minele = min_element(arr, arr+n);
    cout<<*minele;

    //2. accumulate - sum
    int sum = accumulate(arr, arr+n, 0);
    cout<<sum;

    //3. count
    // int freq = count(arr, arr+n,8);
    map<int,int> m;
    m[1] = 3;
    m[4] = 8;
    int freq = m.count(4);
    cout<< freq;

    // 3. Find
    int ele = find(arr, arr+n,8);
    map<int, int> m;
    m[1] = 3;
    m[4] = 8;
    int ele = m.count(4);
    cout << ele;

    // 4. Reverse
    cout << reverse(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    

    h/w - vectors pe implement krna

    // 5. lambda function
    declaration
    [](int x){return x+2;};

    //call
    cout<<[](int x){return x+2;}(2)<<endl;
    cout<<[](int x, int y){return x+y;}(2,5)<<endl;
    
    //reusing
    auto sum = [](int x, int y){ return x + y; }
    cout<<sum(2,3)<<endl;

    //6. all_of
    vector<int> v ={2,3,5};
    cout<<all_of(v.begin(), v.end(), [](int x){return x>0;});

    //7. any_of
    vector<int> v = {2, 3, 5};
    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x > 0; });

    return 0;
}