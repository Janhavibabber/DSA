// Counting possible decoding of a given digit sequence
// Here we will discuss how to count all the possible decodings of a given digit sequence. Before counting the number of decodings first let’s see how the numbers are assumed to be coded.

// 1 = A, 2 = B, 3 = C, . . . . , 26 = Z.

// Now let’s take an example for reference,

// Sequence = 131

// Possible decoding (1, 3, 1,)    = ACA
// Possible decoding (13, 1)   = MA
// So, the total possible decodings of sequence 131 is 2.

#include<iostream>
#include<cstring>
using namespace std;

int countDecoding(char *digit, int n)
{
    int *decodings[n+1];
    decodings[0] = 1;
    decodings[1] = 1;

    for (int i = 0; i < n; i++)
    {
        int p = digit[i] - 48;
        int q = digit[i-1] - 48;
        if(p>=0 && q<=26)
            decodings[i+1] = decodings[i];
        if((p + q*10)>0 && (p + q*10)<=26) 
            decodings[i+1] += decoding[i-1];
    }
    return decodings[n];
}

int main()
{
    char digit[20];
    gets(digit);
    int n = strlen(digit);
    cout<<countDecoding(digit,n);
    return 0;
}