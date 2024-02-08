// Approach:
// 1.	Keep on building the substring from j=0 [increasing the window size] and log occurance of each character in a Map.
// 2.	If map size (Unique Characters in Map) becomes greater than k, keep on reducing window size (increase i pointer) and decrease the occurance of character from Map till map size becomes <=k. 
// 3.	If map size becomes equal to k, compute the Candidate answer.
// 4.	Increase j pointer and perform steps 1-3 until j<array size [while loop condition] .

// code 1: use vector
// code 2: use unordered map
// code 3: use map
// code 4: use unordered map
// code 5: use unordered map
// code 6: use unordered map

// code 1
// // For C++, we can use a vector instead of a map;
// // 0th index of the vector will keep the count of 'a' and 26th will store the count of 'z'.Suppose we have characters 'a' and 'b' in our window.then the vector will have 24 zeroes; vector = {1,1,0,0,0,0....,0,0}. Then for each iteration will calculate 26-(count of zeroes in the vector) compare that to K.

// // Code below:

// int longestKSubstr(string s, int k)
// {

//     vector<int> cnt(26, 0);
//     int ans = 0, i = 0, j = 0;

//     while (j < s.size())
//     {
//         cnt[s[j] - 'a']++;
//         int zeroes = count(cnt.begin(), cnt.end(), 0);

//         if (26 - zeroes < k)
//             j++;

//         else if (26 - zeroes == k)
//         {
//             ans = max(ans, j - i + 1);
//             j++;
//         }

//         else if (26 - zeroes > k)
//         {
//             cnt[s[i] - 'a'] - -;
//             i++;
//             j++;
//         }
//     }

//     if (ans == 0)
//         return -1;

//     else
//         return ans;
// }

// code 2
// // Longest Substring k unique character
// /*
// Given a string you need to print the size of the longest possible substring that has exactly
// k unique characters.
// Example:
// Input:
// 2
// aabacbebebe
// 3
// aaaa
// 1
// Output:
// 7
// 4 . */
// #include <bits/stdc++.h>
// using namespace std;
// int longest(string str, int k)
// {
//     int i = 0, j = 0;
//     int maxi = INT_MIN;
//     int count = 0;
//     unordered_map<char, int> map;
//     map.clear();
//     while (j < str.size())
//     {
//         map[str[j]]++;
//         if (map.size() < k)
//         {
//             j++;
//         }
//         else if (map.size() == k)
//         {
//             maxi = max(maxi, j - i + 1);
//             j++;
//         }
//         else if (map.size() > k)
//         {
//             while (map.size() > k)
//             {
//                 map[str[i]]--;
//                 if (map[str[i]] == 0)
//                 {
//                     map.erase(str[i]);
//                 }
//                 i++;
//             }
//             j++;
//         }
//     }
//     return maxi;
// }
// int main()
// {
//     string str;
//     cin >> str;
//     int k;
//     cin >> k;
//     cout << longest(str, k);
// }

// code 3
// // a bit extended shorter version, but understanding of the exhaustive version is must
// map<char, int>mp;
// int cnt = 0;
// int start = 0, end = 0;
// int ans = -1;
// while (end < s.size())
// {

//     mp[s[end]]++;
//     // distinct count check after add
//     if (mp[s[end]] == 1)
//     {
//         cnt++;
//     }
//     while (cnt > k)
//     {
//         mp[s[start]]--;
//         // distinct count count after remove
//         if (mp[s[start]] == 0)
//         {
//             cnt--;
//         }
//         start++;
//     }
//     if (cnt == k)
//     {
//         ans = max(ans, end - start + 1);
//     }
//     end++;
// }
// return ans;

// code 4
// int longestKSubstr(string s, int k)
// {
//     unordered_map<char, int> mp;
//     int i = 0;
//     int j = 0;
//     int ans = -1;

//     while (j < s.length())
//     {
//         mp[s[j]]++;

//         while (mp.size() > k)
//         {
//             mp[s[i]]--;
//             if (mp[s[i]] == 0)
//                 mp.erase(s[i]);
//             ++i;
//         }

//         if (mp.size() == k)
//         {
//             ans = max(ans, (j - i) + 1);
//         }
//         j++;
//     }

//     return ans;
// }

// code 5
// int longestKSubstr(string s, int k)
// {

//     int ans = -1;
//     int i = 0, j = 0;
//     int temp = 0;
//     unordered_map<char, int> mp;
//     while (j < s.length())
//     {
//         mp[s[j]]++;
//         j++;
//         temp++;

//         if (mp.size() > k)
//         {

//             while (mp.size() > k)
//             {
//                 mp[s[i]]--;
//                 temp--;
//                 if (mp[s[i]] == 0)
//                     mp.erase(s[i]);
//                 i++;
//             }
//         }

//         if (mp.size() == k)
//             ans = max(ans, temp);
//     }
//     return ans;
//     // your code here
// }

// code 6
// / given string ko traverse aur map mein store krte chlenge jabtak size of map k nhi ban jaata

//         // We'll traverse the string and will keep on adding elements in the map with their respective frequency

//         // map bnao
//         unordered_map<char, int>
//             mp;

// // SIZE OF MAP WILL SHOW THE NUMBER OF THE CHARACTERS

// int ans = -1;
// // windows ki shruwat zero se krenge
// int i = 0;
// int j = 0;

// // purri string ka safar krenge

// // TRAVERSE THE STRING
// while (j < s.length())
// {
//     // saath saath elements ko store krte chlenge aur saath mein frequency ko bhi bdayenge

//     // INCREMENTING THE FREQUENCY OF CHARACTERS
//     mp[s[j]]++;

//     // 3 alag alag case ho skte hai
//     // THERE WILL BE THREE DIFFERENT CASES

//     // FIRST WOULD BE IF OUR MAP SIZE IS LESS THAN K
//     // IT MENAS WE HAVEN'T REACHED THE K NUMBER OF CHARACTERS YET

//     // map ka size will show the number of characters

//     // 1--> jab hmari substring mein k se kam characters honge  if(mp.size() < k) = khidki bdao
//     // ye case automatically handle ho jayega j++;

//     // 2--> jab hmari subtring mein k characters honge mp.size() == k
//     //  THIS COULD BE OUR POSSIBLE CANDIDATE
//     if (mp.size() == k)

//         // iss wqt humein answer mil gya hai
//         // WILL CALCULATE THE ANSWER
//         ans = max(ans, (j - i) + 1);

//     // ans milne ke baad j++ ho jayega LINE 66

//     // 3--> jab hmari subring mein k se jyada characters honge mp.size() > k

//     // jab tk element ko map se remove kro tabtk map ka size k se bda hai

//     // NUMBER OF CHARACTERS BECAME GREATER THAN K
//     while (mp.size() > k)
//     {
//         // WILL DECREAMENT THE COUNT OF CHARACTERS FROM THE FRONT OF THE WINDOW
//         mp[s[i]]--;
//         // agar kisi element ka count zero ho gya it means ki uss element ko remove krenge toh
//         // mp.size aur k match kar jayega
//         // CHARACTER COUNT == 0??? ERASE THE ELEMENT FROM MAP
//         if (mp[s[i]] == 0)
//         {
//             mp.erase(s[i]);
//         }
//         i++;
//     }

//     j++; // aage bdte chlo
// }

// return ans;