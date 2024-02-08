#include <iostream>  
#include<vector> 
#include<list> 
#include<deque>

#include<bits/stdc++.h>
using namespace std;  
int main()  
{  
    //initialise vector ---------------------
    vector<string> v={"mango","apple","banana"};  
    //initialise iterator
    vector<string>::iterator i1;  
    //print elements
    cout<<"Vector elements:\n";
    for(i1=v.begin();i1!=v.end();i1++) 
    {    
        cout<<*i1<<" ";  
    }
    cout<<endl;
    
    
    //initialize list -----------------
    list<int> l = {1,2,3,4};
    //initialise iterator
    list<int>::iterator i2;  
    //print elements
    cout<<"List elements:\n";
    for(i2=l.begin();i2!=l.end();i2++) 
    {    
        cout<<*i2<<" ";  
    } 
    cout<<endl;

    //initialize dequeue -----------------------
    deque<char> d = {'a','b','c','d'};
    //initialize iterator
    deque<char>::iterator i3;
    //print elements
    cout<<"Deque elements:"<<endl;
    for(i3=d.begin();i3!=d.end();i3++)
    {
        cout<<*i3<<" ";

    }
    cout<<endl;

    //initialize set ------------------------
    set < int > s = {4,7,2,9,0,1,6};
     //initialize iterator
    set<int>::iterator i4;
    //print elements
    cout<<"Set elements:"<<endl;
    for(i4=s.begin();i4!=s.end();i4++)
    {
        cout<<*i4<<" ";

    }
    cout<<endl;

    //Store elements in decreasing order in sets -----------
    set < int , greater <int> > s2 = {4,7,2,9,0,1,6};
    set<int>::iterator i5;
    cout<<"Set elements in decreasing order:"<<endl;
    for(i5=s2.begin();i5!=s2.end();i5++)
    {
        cout<<*i5<<" ";

    }
    cout<<endl;

    //Store elements in multiset ------------------------
    multiset <int> ms = {1,1,1,10} ;
    
    multiset <int>::iterator i6;
    cout<<"Set elements in multiset:"<<endl;
    for(i6=ms.begin();i6!=ms.end();i6++)
    {
        cout<<*i6<<" ";

    }
    cout<<endl;


    //MAPS -----------
    map<int, string> m;//{ {1,"rahul"}, {2,"Vijay"}, {3,"gaurav"}  }
    m[10]="Rahul";
    m[20]="vijay";
    m[30]="gaurav";
    cout<<"Print Map using keys:\n";
    cout<<m[10]<<" "<<m[20]<<" "<<m[30]<<endl;
    cout<<"print map using iterator:\n";
    map<int, string>:: iterator i7;
    for(i7=m.begin();i7!=m.end();i7++)
    {
        cout<<(*i7).first<<":"<<(*i7).second<<" ";

    }
    cout<<endl;


    //Multimap -------------------
    multimap<string, string> mm = {  
            {"India","New Delhi"},  
            {"India", "Hyderabad"},  
            {"United Kingdom", "London"},  
            {"United States", "Washington D.C"}  
    };  
    cout<<"\nprint Multi-Map using iterator:\n";
    multimap<string, string>:: iterator i8;
    for(i8=mm.begin();i8!=mm.end();i8++)
    {
        cout<<(*i8).first<<":"<<(*i8).second<<" ";

    }
    cout<<endl;

   
    //Stacks-------------
    //Add elements to stack
    stack <int> newst;  
    newst.push(55);  
    newst.push(44);  
    newst.push(33);  
    newst.push(22);  
    newst.push(11);  
    // elemenst in stack are : 11,22,33,44,55 from top to bottom
    //pop 2 elements from stack;
    cout<<endl<<"printing elements in the stack:\n";
    while (!newst.empty () )  
    {  
            cout<< " " << newst.top ();  
            newst.pop();  
    }  
    cout<<endl;

    //Queues   ------------------------
    queue <int> q;  
    q.push(10);  
    q.push(20);  
    q.push(30); 
    //elements in q are 10,20 , 30 from front to back

     q.pop();  
     //now elements are 20,30
     //print elements in queue :
     cout<<"\n printing elements in queue:\n";
     while (!q.empty())  
    {  
        cout << " " << q.front();  
        q.pop();
   }  
   cout<<endl;
   






    return 0;  
}  