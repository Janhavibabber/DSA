// Method 1: normal
// Method 2: swap
// Method 3: constant space
// Method 4, Method 9, Method 10, Method 11: different
// Method 5, Method 6, Method 7, Method 8: string stream

// Method 1:
//  C++ program to reverse a string
// #include <bits/stdc++.h>
// using namespace std;

// // Function to reverse words*/
// void reverseWords(string s)
// {

//     // temporary vector to store all words
//     vector<string> tmp;
//     string str = "";
//     for (int i = 0; i < s.length(); i++)
//     {

//         // Check if we encounter space
//         // push word(str) to vector
//         // and make str NULL
//         if (s[i] == ' ')
//         {
//             tmp.push_back(str);
//             str = "";
//         }

//         // Else add character to
//         // str to form current word
//         else
//             str += s[i];
//     }

//     // Last word remaining,add it to vector
//     tmp.push_back(str);

//     // Now print from last to first in vector
//     int i;
//     for (i = tmp.size() - 1; i > 0; i--)
//         cout << tmp[i] << " ";
//     // Last word remaining,print it
//     cout << tmp[0] << endl;
// }

// // Driver Code
// int main()
// {
//     string s = "i like this program very much";
//     reverseWords(s);
//     return 0;
// }
// Learn Data Structures &Algorithms with GeeksforGeeks
//     Output
//         much very program this like i

// // Time complexity : O(N)
// // Auxiliary Space : O(N)

// // Note : The above code doesn’t handle the cases when the string starts with space.



// // //Method 2: Reverse words in a given string using the swap operation:
// // The above task can also be accomplished by splitting the words separately and directly swapping the string starting from the middle.

// // Follow the below steps to solve the problem:

// // Store the string in the form of words
// // Swap the words with each other starting from the middle
// // Print the string
// // Below is the implementation of the above approach:


// // C++ code to reverse a string
 
// #include <bits/stdc++.h>
// using namespace std;
 
// // Reverse the string
// string RevString(string s[], int l)
// {
 
//     // Check if number of words is even
//     if (l % 2 == 0) {
 
//         // Find the middle word
//         int j = l / 2;
 
//         // Starting from the middle
//         // start swapping words at
//         // jth position and l-1-j position
//         while (j <= l - 1) {
//             string temp;
//             temp = s[l - j - 1];
//             s[l - j - 1] = s[j];
//             s[j] = temp;
//             j += 1;
//         }
//     }
 
//     // Check if number of words is odd
//     else {
 
//         // Find the middle word
//         int j = (l / 2) + 1;
 
//         // Starting from the middle start
//         // swapping the words at jth
//         // position and l-1-j position
//         while (j <= l - 1) {
//             string temp;
//             temp = s[l - j - 1];
//             s[l - j - 1] = s[j];
//             s[j] = temp;
//             j += 1;
//         }
//     }
 
//     string S = s[0];
 
//     // Return the reversed sentence
//     for (int i = 1; i < 6; i++) {
//         S = S + " " + s[i];
//     }
//     return S;
// }
 
// // Driver code
// int main()
// {
//     string s = "i like this program very much";
 
//     string words[]
//         = { "i", "like", "this", "program", "very", "much" };
 
//     cout << RevString(words, 6) << endl;
 
//     return 0;
// }
// // Learn Data Structures & Algorithms with GeeksforGeeks
// // Output
// // much very program this like i

// // Time complexity: O(N)
// // Auxiliary Space: O(N)

// //Method 3:
// // Reverse words in a given string using constant space : Follow the below steps to solve the problem :

// // Go through the string and mirror each word in the string,
// // Then,
// // in the end,
// // mirror the whole string.Below is the implementation of the above approach :

// // C++ code for the above approach

// #include <bits/stdc++.h>
//     using namespace std;

// string reverse_words(string s)
// {
//     int left = 0, i = 0, n = s.size();

    // if string start with a space
//     while (s[i] == ' ')
//         i++;

//     left = i;

//     while (i < n)
//     {
            // in case end of the string or space in a string
//         if (i + 1 == n || s[i] == ' ')
//         {
                //updating j with prev value
//             int j = i - 1;
                // for last word
//             if (i + 1 == n)
//                 j++;

                // traversed the whole word and storing in reverse order
//             while (left < j)
//                 swap(s[left++], s[j--]);

                // updating left for next value
//             left = i + 1;
//         }
//         if (i > left && s[left] == ' ')
//             left = i;

//         i++;
//     }
//     reverse(s.begin(), s.end());
//     return s;
// }

// // Driver code
// int main()
// {

//     string str = "i like this program very much";

//     str = reverse_words(str);

//     cout << str;

//     return 0;
// }
// //  Learn Data Structures &Algorithms with GeeksforGeeks
// //  Output
// //  much very program this like i

// // Time complexity : O(N)
// // Auxiliary Space : O(1)

// // Method 4
// string reverseString(string &str)
// {
//     // Write your code here.
//     string ans;

//     int i = str.size() - 1;
//     while (i >= 0)
//     {

//         while (str[i] == ' ' && i >= 0)
//         {
//             i--;
//         }

//         int j = i;
//         while (str[i] != ' ' && i >= 0)
//         {
//             i--;
//         }

//         if (ans.empty())
//         {
//             for (int k = i + 1; k < j + 1; k++)
//             {
//                 ans.push_back(str[k]);
//             }
//         }
//         else
//         {
//             ans.push_back(' ');
//             for (int k = i + 1; k < j + 1; k++)
//             {
//                 ans.push_back(str[k]);
//             }
//         }
//     }

//     return ans;
// }

// // Method 5
// // Fastest C++ Solution in T.C : -O(n) S.C : -O(n)
// #include <bits/stdc++.h>

// string reverseString(string &str)
// {

//     vector<string> words;

//     stringstream ss(str);

//     string s;

//     while (ss >> s)
//     {

//         words.push_back(s);
//     }

//     string ans;

//     for (int i = words.size() - 1; i >= 0; i--)
//     {

//         if (i != words.size() - 1)
//         {

//             ans += ' ';
//         }

//         ans += words[i];
//     }

//     return ans;
// }

// // Method 6:
// #include <sstream>
// #include <bits/stdc++.h>
// string reverseString(string str)
// {

//     stringstream s(str);
//     string words;
//     vector<string> v;
//     string ans = "";
//     while (s >> words)
//     {
//         v.push_back(words);
//     }
//     for (int i = v.size() - 1; i >= 0; i--)
//     {
//         ans = ans + v[i];
//         if (i != 0)
//         {
//             ans = ans + " ";
//         }
//     }
//     return ans;
// }

// // Method 7
// #include <bits/stdc++.h> string reverseString(string str) { // Write your code here.   
// str+=' ';  
// vector<string>v;   
// string temp="";   
// for(int i=0;i<str.size();i++){       
//     if(str[i]==' ') {           
//         if(temp.length())           
//             v.push_back(temp);           
//             temp="";         
//         }       
//         else            
//             temp+=str[i];          
//     }   
//     reverse(v.begin(),v.end());   
//     string ans="";   
//     for(int i=0;i<v.size();i++){       
//         ans+=v[i];       
//         ans+=' ';   
//     }   
//     ans.pop_back();   
//     return ans;    
// }

// // Method 7:
// //  Intuition
// //  We can solve this question using Multiple Approaches.(Here I have explained all the possible solutions of this problem)
// //              .

// // Solved using String
// // + Two Pointers.In - place.Solved using String with extra space.Approach We can easily understand the all the approaches by seeing the code which is easy to understand with comments.

// // Complexity Time complexity : Time complexity is given in code comment.

// // Space complexity : Space complexity is given in code comment.

// // Code
// /*

// Time Complexity : O(N), where n is the total number of characters in the given string.

// Space Complexity : O(1), Constant space. In-place solution.

// Solved using String + Two Pointers.
// /*
// /***************************************** Approach 1 *****************************************/
// class Solution
// {
// private:
//     void reverse(string &s, int i, int j)
//     {
//         while (i < j)
//         {
//             char temp = s[i];
//             s[i++] = s[j];
//             s[j--] = temp;
//         }
//     }

// public:
//     string reverseWords(string &s)
//     {
//         int i = 0, j = 0;
//         int l = 0;
//         int len = s.length();
//         int wordcount = 0;
//         while (true)
//         {
//             while (i < len && s[i] == ' ')
//                 i++;
//             if (i == len)
//                 break;
//             if (wordcount)
//                 s[j++] = ' ';
//             l = j;
//             while (i < len && s[i] != ' ')
//             {
//                 s[j] = s[i];
//                 j++;
//                 i++;
//             }
//             reverse(s, l, j - 1);
//             wordcount++;
//         }
//         s.resize(j);
//         reverse(s, 0, j - 1);
//         return s;
//     }
// };

// /*

//     Time Complexity : O(N), where n is the total number of characters in the given string.

//     Space Complexity : O(1), Constant space. Extra space is only allocated for the String(ans), however the
//     output does not count towards the space complexity.

//     Solved using String.

// /*


// /***************************************** Approach 2 *****************************************/

// class Solution
// {
// public:
//     string reverseWords(string &s)
//     {
//         stringstream ss(s);
//         string word, ans;
//         while (ss >> word)
//         {
//             ans = word + " " + ans;
//         }
//         return ans.substr(0, ans.size() - 1);
//         ;
//     }
// };

// // Method 8
// //  Approach
// //  (Also explained in the code)

// // The code starts by trimming the input string s to remove any leading and trailing spaces.

// // It then splits the trimmed string into words based on spaces using a stringstream. The words are stored in the words vector.

// // Next, it initializes an output string out.

// // The code iterates through the words in reverse order (from the last word to the second word) and appends each word followed by a space to the output string.

// // Finally, it appends the first word to the output string without a trailing space.

// // Complexity
// // Time complexity:
// // O(n)O(n)O(n)

// // Space complexity:
// // O(m)O(m)O(m) ( where M is the total number of words in the input string. The space is primarily used for storing the words in the words vector.)

// // Code
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         // Trim the input string to remove leading and trailing spaces
//         int i = 0, j = s.size() - 1;
//         while (i <= j && s[i] == ' ')
//             i++; // Find the first non-space character
//         while (j >= i && s[j] == ' ')
//             j--;                    // Find the last non-space character
//         s = s.substr(i, j - i + 1); // Extract the trimmed substring

//         // Split the trimmed string into words based on spaces
//         vector<string> words; // Create a vector to store words
//         stringstream ss(s);   // Create a stringstream with the trimmed string
//         string word;
//         while (ss >> word)
//         {                          // Tokenize the string into words
//             words.push_back(word); // Store each word in the vector
//         }

//         // Initialize the output string
//         string out = "";

//         // Iterate through the words in reverse order
//         for (int i = words.size() - 1; i > 0; i--)
//         {
//             // Append the current word and a space to the output
//             out += words[i] + " ";
//         }

//         // Append the first word to the output (without trailing space)
//         return out + words[0]; // Concatenate the reversed words
//     }
// };

// // Method 9
// //  Intuition
// //  Approach
// //  Complexity
// //  Time complexity : Space complexity : Code
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         string str = "";
//         int e = 0;
//         int f = s.size() - 1;
//         if (e == f)
//             return s;
//         while (e < f && s[e] == ' ')
//         {
//             e++;
//         }
//         while (f > e && s[f] == ' ')
//             f--;
//         if (e == f)
//             return str = s[e];
//         int j = f;
//         int k;
//         while (f > e)
//         {
//             j = f;
//             while (j > e && s[j] == ' ')
//                 j--;
//             f = j;
//             while (j > e && s[j] != ' ')
//                 j--;
//             if (j == e)
//             {
//                 while (j <= f)
//                 {
//                     str += s[j];
//                     j++;
//                 }
//                 break;
//             }
//             else
//             {
//                 k = j;
//                 j++;
//                 while (j <= f)
//                 {
//                     str += s[j];
//                     j++;
//                 }
//                 str += ' ';
//                 f = k;
//             }
//         }
//         return str;
//     }
// };

// // Method 10
// //  Intuition
// //  Approach
// //  Complexity
// //  Time complexity : O(n)
// //  Space complexity : O(n)
// //  Code
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         int len = s.size() - 1;
//         string temp = "";
//         string ans = "";
//         for (int i = len; i >= 0; i--)
//         {
//             if (s[i] == ' ' && temp != "")
//             {
//                 reverse(temp.begin(), temp.end());
//                 ans += temp + ' ';
//                 temp = "";
//             }
//             else
//             {
//                 if (s[i] == ' ')
//                     continue;
//                 temp += s[i];
//             }
//         }
//         reverse(temp.begin(), temp.end());
//         ans += temp;
//         if (ans[ans.size() - 1] == ' ')
//             // ans=ans.erase(ans.size()-1);
//             ans.pop_back();
//         return ans;
//     }
// };

// // Method 11
// //  Intuition
// //  Approach
// //  Complexity
// //  Time complexity : Space complexity : Code
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {

//         int cnt = 0, cntb = 0;
//         string res = "";
//         string w = " ";
//         reverse(s.begin(), s.end());
//         s += w;
//         reverse(s.begin(), s.end());
//         w = "";
//         for (int i = s.size() - 1; i >= 0; i--)
//         {
//             if (cnt == 0 && s[i] == ' ')
//             {
//             }
//             else if (cnt == 0 && s[i] != ' ')
//             {
//                 cnt = 1;
//                 w += s[i];
//                 cntb = 0;
//             }
//             else if (cnt == 1 && s[i] != ' ')
//             {
//                 if (cntb == 1)
//                 {
//                     w = " ";
//                     res += w;
//                     w = "";
//                 }
//                 w += s[i];
//                 cntb = 0;
//             }
//             else if (cnt == 1 && s[i] == ' ')
//             {
//                 reverse(w.begin(), w.end());
//                 res += w;
//                 w = "";
//                 cntb = 1;
//             }
//             /* else{
//                  reverse(w.begin(),w.end());
//                  res+=w;
//              }
//             /* else if(cnt==1 && cntb==1 && s[i]!=' '){
//                  w=" ";
//                  res+=w;
//              }*/
//         }
//         return res;
//     }
// };