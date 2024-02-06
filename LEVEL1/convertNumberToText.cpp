#include<iostream>
#include<string.h>
 using namespace std;
    //main Program
    void numToWords(string num)
    {
        int length_of_string = strlen(num);
        if (length_of_string == 0){
             cout<<"String is Empty"; 
             return;
        }
        
        if (length_of_string > 4){
            cout<<"Please enter the string with supported length"; 
            return;  
        }
        string ones_digits = {"“zero”", "“one”", "“two”", "“three”", "“four”", "“five”", "“six”", "“seven”", "“eight”", "“nine”"}; 
        string tens_digits = {"", "“ten”", "“eleven”", "“twelve”", "“thirteen”", "“fourteen”", "“fifteen”", "“sixteen”", "“seventeen”", "“eighteen”","“nineteen”"}; 
        string multiple_of_ten = {"", "", "“twenty”", "“thirty”", "“forty”", "“fifty”", "“sixty”", "“seventy”", "“eighty”", "“ninety”"}; 
        string power_of_ten = {"“hundred”", "“thousand”"};
        cout<<num<<":\n";
        if (length_of_string == 1){  
        cout<<ones_digits[num[0] – '0']; 
        return;
        }
        int x=0;
        while (x < strlen(num)){
            if(length_of_string >= 3){
                if (num[x] – 48 != 0){
                    cout<<ones_digits[num[x] – 48]<<"\n";
                    cout<<power_of_ten[length_of_string – 3]<<"\n";
                    length_of_string–;
                }
            }
            else{
                if (num[x] – 48 == 1){
                    sum = (num[x] – 48 + num[x] – 48); 
                    cout<<tens_digits[sum]); 
                    return;
                }
                else if(num[x] – 48 == 2 and num[x + 1] – 48 == 0){
                    cout<<"twenty"; 
                    return;
                }
                else{
                    int i = num[x] – 48; 
                    if(i > 0){
                        cout<<multiple_of_ten[i]<<end = " "; 
                    }
                    else{ 
                        cout<<""<<end = ""; 
                    }
                    x += 1; 
                    if(num[x] – 48 != 0){
                        cout<<ones_digits[num[x] – 48];
                    }
                    }
            }
            x++;
        }
    }
    int main()
    {
        numToWords("1121");
        return 0;
    }
