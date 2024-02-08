// Find maximum occuring characters

// class Solution
// {
// public:
//     // Function to find the maximum occurring character in a string.
//     char getMaxOccuringChar(string str)
//     {
//         // METHOD 1 - using frequency array
//         // calculate the frequency of string by traversing string
//         int arr[26] = {0};
//         for (int i = 0; i < str.length(); i++)
//         {
//             int num = str[i] - 'a';
//             arr[num]++;
//         }
//         // sort(str.begin(), str.end());
//         // unordered_map<char,int> mp;
//         // for(auto i: str){
//         //     mp[i]++;
//         // }

//         // find the maximum no. and character
//         int maxi = INT_MIN;
//         int res = 0;
//         for (int i = 0; i < 26; i++)
//         {
//             if (arr[i] > maxi)
//             {
//                 maxi = arr[i];
//                 res = i;
//             }
//             // maxi = max(maxi, arr[i]);
//             // res = (char)(i+'a');
//         }

//         // Print the character or type cast it to char
//         return res + 'a';

//         // METHOD 2 - using unordered map
//         // calculate the frequency of string by traversing string
//         // sort(str.begin(), str.end());
//         // unordered_map<char,int> mp;
//         // int maxi = INT_MIN;
//         // char res;

//         // for(int i=0; i<str.length(); i++){
//         //     mp[str[i]]++;
//         //     // find the maximum no. and character
//         //     if(mp[str[i]] > maxi){
//         //         maxi = mp[str[i]];
//         //         res = str[i];
//         //     }
//         // }

//         // // Print the character or type cast it to char
//         // return res;

//         //METHOD 3 - using map
//         map<char, int> mp;
//         int m = INT_MIN;
//         for (auto const &x : str)
//             m = max(m, ++mp[x]);
//         for (auto const &x : mp)
//             if (x.second == m)
//                 return x.first;

//         //
//         map<char, int> mp;
//         for (auto i : str)
//         {
//             mp[i]++;
//         }
//         int m = INT_MIN;
//         for (auto i : mp)
//         {
//             m = max(m, i.second);
//         }
//         for (auto i : mp)
//         {
//             if (i.second == m)
//             {
//                 return i.first;
//             }
//         }

//         //
//         map<char, int> freq;
//         for (int i = 0; i < str.length(); i++)
//         {
//             freq[str[i]]++;
//         }
//         char ans = freq.begin()->first;
//         int maxx = freq.begin()->second;

//         for (auto it : freq)
//         {
//             if (it.second > maxx)
//             {
//                 maxx = it.second;
//                 ans = it.first;
//             }
//         }
//         return ans;
//     }
// int l = str.length();
// string rep = "@40";
// for (int i = 0; i < l; i++)
// {
//     if (str[i] == ' ')
//     {
//         str.replace(i, 1, rep);
//     }
// }
// return str;
// }
// };