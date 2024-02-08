#include <iostream>  
#include<bits/stdc++.h>
using namespace std;  
void print1(vector<int> v)
{
    cout<<"Vector elements are:\n";
    vector<int>::iterator i;
    for(i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
} 

int main()  
{  
    //some other iterators ....
    //1- normal iterator 
    //moves forward, can modify elements.
    
    //2- reverse iterator. If you increment it, moves in 
    //reverse direction
    

    vector<int> v = {1,2,3,4,5};
    vector<int>::reverse_iterator rit;
    cout<<"print elements in reverse: "<<endl;  
    //for each iterator begin() funcrtion changes.
    //begin(), rbegin(), cbegin() etc...
    for (rit=v.rbegin(); rit!=v.rend(); ++rit)  
    cout << *rit<< '\n';  

    //3- constant iterator
    //can access element, delete element, but can't change it
   
   //change element using it
    vector<int>::iterator it;
    it=v.begin()+1;
    *it=5;
    print1(v);
    
    //change element using cit
    vector<int>::const_iterator cit;
    cit=v.cbegin()+1;
    //*cit=2;
    //print element using cit
    cout<<*cit<<endl;

    //delete element using cit
    // it=v.end()-1;
    // v.erase(it);
    // print1(v);
    cit=v.cend()-1;
    v.erase(cit);
    print1(v);

    //4- reverse const iterator.
    //moves in reverse dir, can't modify
    
    //begin(), rbegin(), cbegin(), crbegin()
    //end(), rend(), cend(), crend();

    //-------------------------------
    //functions related to size
    //1- empty() 
    //check if container is full or empty.
    //return 0 or 1.
    cout<<"Is vector empty\n";
    cout<<v.empty()<<endl;
    
    //2- find number of elements in vector.
    //size();
    cout<<"Size of vector\n";
    cout<<v.size()<<endl;

    // //3- at function
    //begin()+
    // cout<<v.at(1)<<endl;

    //------------- ALGOS -------
    //1- find algo
    //find(begin, end, element)
    cout<<"search for element\n";
    it=find(v.begin(),v.end(),4);
    if(it!=v.end())
        cout<<"element found\n";
    else
        cout<<"element not found\n";

    //2- sort algo
    //combination of QS, HS, IS
    //first QS, then HS , then samll array IS
    //can use parallel processing/ multi threading

    //sort(begin, end) // must provide range
    v={4,2,6,8,3,8,1};
    cout<<"sort only first three elements\n";
    sort(v.begin(),v.begin()+2);
    print1(v);

    cout<<"sort all elements\n";
     sort(v.begin(),v.end());
    print1(v);

    //3- is_sorted()
    //check if already sorted (inc order default)
    cout<<"check if sorted in increasing order:\n";
    cout<<is_sorted(v.begin(),v.end())<<endl;
    cout<<"check if sorted in decreasing order:\n";
    cout<<is_sorted(v.begin(),v.end(),greater<int>())<<endl;

    //4- partial sort()
    //to find partial elements in sorted array
    //v(first, middle, last) - middle is not included
    v={4,7,1,0,3,9,2};
    //sorted v={0,1,2,3,4,7,9};
    partial_sort(v.begin(),v.begin()+3, v.end());
    cout<<"partial sort first three elements\n";
    print1(v);
    //order of remaining elements is not specific.

    //4- nth element
    //find nth element in sorted container
    //rearranges the container.
    v={7,5,7,2,0,2,3};
    //sorted {0,2,2,3,5,7,7};
    cout<<"Nth element is:\n";
    nth_element(v.begin(),v.begin()+3,v.end());
    print1(v);

    //5- iota // insert elements in inc order
    //used to fill the elements in container
    iota(v.begin(),v.end(),9);
    cout<<"vector elements after iota\n";
    print1(v);

    //6- copy 
    //copy from v to another vector
    //to vector should be equal or greater. not smaller
    //elements in to_vector are replaced by new elements
    vector<int> from_vector = {11,22,33,44,55};
    vector<int> to_vector1 = {1,1,1,1,1,2,2};
   
    copy(from_vector.begin(),from_vector.end(),to_vector1.begin());
    cout<<"print elements of to_vector1\n";
    print1(to_vector1);

    //to copy at end of to_vector ;
    vector<int> to_vector2 = {1,1};
    cout<<"print elements of to_vector2\n";
    copy(from_vector.begin(),from_vector.end(),back_inserter(to_vector2));
    print1(to_vector2);
    //v1=v2;
    //difference between v2= v1 and copy() algo.
    //we can copy only selected elements to to_vector










    
















}