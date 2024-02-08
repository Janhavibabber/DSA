#include <iostream>  
#include<bits/stdc++.h>
using namespace std; 
void print1(vector<string> v)
{
    cout<<"Vector elements are:\n";
    vector<string>::iterator i;
    for(i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
} 
int main()  
{  
    //vector<string> v{"apple","banana","orange"};  
    //ways to insert ------
    //1- insert();
    //insert at begin
    vector<string> v;
    vector<string>::iterator i1; 
    i1=v.begin();
    v.insert(i1,"apple"); 
    cout<<"vector elements are:\n";
    for(i1=v.begin();i1!=v.end();i1++) 
    {    
        cout<<*i1<<" ";  
    }
    cout<<endl; 
    

    //again insert at begin again
    v.insert(v.begin(),"mango");  
    print1(v);
    

    //insert at 4th position = error, insert at third position
    v.insert(v.begin()+2,"banana");  
    print1(v);

    //insert at end - 3times
    v.insert(v.end(),3,"kiwi");
    print1(v);

    //copy form another vector
    vector<string> v1={"violet","indigo", "blue"};
    v.insert(v.end(),v1.begin(),v1.end());
    print1(v);

    //same for list and deque
    //same for set - if already present then it is not inserted.
    //example
     set<string> s;
     s.insert("apple");
     s.insert("apple");
     s.insert("banana");

     //same for map and multimap
     map<char, int> m;
     m.insert({'d',1});  
     m.insert({'e',2});
     m.insert({'f',5}); 

     //but stack and queues have insertion rules.
     //not available for stacks and queues.
     //You can only push to the end of queue and top of stack
    stack<int> newstack;  
    newstack.push(69);  
    newstack.push(79);  
    newstack.push(80); 


    //2- push_back() ------
    v.push_back("c++");  
    v.push_back("java");  
    v.push_back("python");  
    v.push_back("c");  
    //same for deque , list;
    //Not for set - because it inserts in sorted order
    //not for map- because it inserts according to key
    //not for stack- stack inserts at the top
    //not for queue- becaue it inserts at end

    //3- emplace()---
    v.emplace(v.begin(),"string1");
    v.emplace(v.begin()+1,"string2");
    v.emplace(v.begin()+2,"string3");
    //same for dequeue, list, 

    //for set, and map location is not specified
    //s.emplace(1);
    //s.empalce(2);
    //s.emplace(3);
    //s.empalce(4);

    //for map 
//    m.emplace('a', 1);  
//    m.emplace('b', 2);  
//    m.emplace('c', 3);  
//    m.emplace('d', 4);  
//    m.emplace('e', 5);

    //not available for stack, queue

    //-----------------------------------------
    //Deletion from containers
    //1- erase
    //deletion from vector
    // v.erase(v.begin()+5);  
    // v.erase(v.begin(), v.begin()+5);  
    //same for list and dequeue;

    //to erase from set, use key, or position
    //s.erase(10);
    //s.erase(s.begin());

    //to erase from map , use key or position
    //mymap.erase(10);
    //mymap.erase(mymap.begin()+1);

    //stack and queue only allows pop
    //mystack.pop()
    //myqueue.pop()

    //2- pop_back()
    //simply delete the last element
    //myvector.pop_back()
    //mylist.pop_back()
    //mydeque.pop_back()

    //not available in set, map, stack , queue

    //3- clear()
    //clear all elements at a time.
    //myvector.clear()
    //mylist.clear()
    //mydeque.clear()
    
    //myset.clear()
    //mymap.clea()

    //not available for stack, queue

 

}