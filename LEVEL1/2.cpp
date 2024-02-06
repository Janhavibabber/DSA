#include <iostream>
using namespace std;
 
int main() {
    char c;
    cout << "Enter a character\n";
    cin >> c;
  
    if((c >= 'a'&& c <= 'z') || (c >= 'A' && c <= 'Z')) {
        cout << c << " is an Alphabet.";
    } else {
        cout << c << " is not an Alphabet.";
    }
  
    return 0;
}