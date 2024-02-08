#include<iostream>
#include<set>
using namespace std;

int main(){
    //1.Declare
    set<string> s;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        //2. Insert or emplace
        s.insert(str);
        //s.emplace(str)
    }

    //3. Print
    for(auto &val : s){
        cout<<val<<endl;
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout<<(*it)<<endl;
    }
    
    //4. Access
    auto it = s.find("abc");
    //find with 2 values
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);
    //OR
    st.erase(st.find(2), st.find(4));

    //5. erase using iterator
    if (it!=s.end())
    {
        s.erase(it);
    }
    //5. erase using value
    s.erase("bcd");

    //6. count - count the no. of occurences
    int cnt = st.count(1);

    
    return 0;
}