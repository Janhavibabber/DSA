#include<iostream>
using namespace std;

// remove case sensitive restriction for pallindrome
char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' +'a';
        return temp; 
    }
}

// check Pallin without case sensitive-
// App 1 - org string - get reverse string - compare org and reverse string - if same then pallindrome - drawback: using extra space
// App 2 - take 2 pointing variable start and end - compare characters from start and end - if equal then pallindrome
bool checkPallin(char a[], int n){
    int s = 0, e = n - 1;
    while(s<=e){
        if(toLowerCase(a[s])!=toLowerCase(a[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

// reverse string
void reverse(char name[], int n){
    int s=0, e=n-1;
    while(s<e){
        swap(name[s++], name[e--]);
    }
}

// length of the string
int getLength(char name[]){
    int c =0;
    for(int i=0; name[i] != '\0'; i++){
        c++;
    }
    return c;
}

int main()
{
    char name[20];

    cout<<"enter your name:";
    cin>>name;

    cout<<"Your name is:";
    cout<<name<<endl;

    // length of the string
    int len = getLength(name);
    cout<<"Length: "<<len<<endl;

    // reverse string
    reverse(name, len);
    cout << "Reverse: " << name << endl;

    // check Pallindrome
    cout<<"Pallindrome or not: "<< checkPallin(name, len)<<endl;

    cout<<"Character is"<<toLowerCase('b')<<endl;
    cout<<"Character is"<<toLowerCase('C')<<endl;
    
    


    return 0;
}