// code 1: unordered map - similar format but not exact - code2
// code 2: unordered map - similar format but not exact - code1
// code 3: unordered map - totally different
// code 4: unordered map - Aditya's format
// code 5: unordered map - code8
// code 6: unordered map - code9
// code 7: vector - totally different
// code 8: unordered map - code5
// code 9: unordered map - code6
// code 10: frequency array - totally different

// code 1
// string minWindow(string s, string t)
// {
//     int i = 0, j = 0, MinL = INT_MAX, start = 0;
//     unordered_map<char, int> mp;
//     for (auto it : t)
//         mp[it]++;
//     int count = mp.size();

//     if (mp.find(s[j]) != mp.end())
//     {
//         mp[s[j]]--;
//         if (mp[s[j]] == 0)
//             count--;
//     }

//     while (j < s.length())
//     {
//         if (count > 0)
//         {
//             j++;
//             if (mp.find(s[j]) != mp.end())
//             {
//                 mp[s[j]]--;
//                 if (mp[s[j]] == 0)
//                     count--;
//             }
//         }
//         else if (count == 0)
//         {
//             // MinL=min(MinL,j-i+1);
//             if (MinL > j - i + 1)
//             {
//                 MinL = j - i + 1;
//                 start = i;
//             }
//             while (count == 0)
//             {
//                 if (mp.find(s[i]) != mp.end())
//                 {
//                     mp[s[i]]++;
//                     if (mp[s[i]] == 1)
//                     {
//                         count++;
//                         // MinL=min(MinL,j-i+1);
//                         if (MinL > j - i + 1)
//                         {
//                             MinL = j - i + 1;
//                             start = i;
//                         }
//                     }
//                     i++;
//                 }
//                 else
//                     i++;
//             }
//         }
//     }
//     string str = "";
//     if (MinL != INT_MAX)
//         return str.append(s.substr(start, MinL));
//     else
//         return str;
// }

// // code 2
// string minWindow(string s, string t)
// {
//     unordered_map<char, int> mp;
//     int minlen = INT_MAX, start = 0;
//     for (auto ch : t)
//     {
//         mp[ch]++;
//     }
//     int i = 0, j = 0, count = mp.size();
//     while (j < s.length())
//     {
//         if (mp.find(s[j]) != mp.end())
//         {
//             mp[s[j]]--;
//             if (mp[s[j]] == 0)
//                 count--;
//         }
//         if (count == 0)
//         {
//             while (count == 0)
//             {
//                 if (mp.find(s[i]) != mp.end())
//                 {
//                     mp[s[i]]++;
//                     if (mp[s[i]] == 1)
//                     {
//                         count++;
//                         if (j - i + 1 < minlen)
//                         {
//                             minlen = j - i + 1;
//                             start = i;
//                         }
//                     }
//                 }
//                 i++;
//             }
//         }
//         j++;
//     }
//     if (minlen == INT_MAX)
//         return "";
//     return s.substr(start, minlen);
// }
// B) Also if yout want to get the string for leetcode 76. Minimum Window Substring
// line 1) replace by return("");
// line 2) replace by return s.substring(start,start+min)

// // code 3
// If you want to find the smallest string:
// string minWindow(string s, string t)
// {
//     int starti = 0;
//     int endi = -1;
//     int slen = s.length();
//     int tlen = t.length();
//     unordered_map<char, int> mp;
//     for (int i = 0; i < tlen; i++)
//         mp[t[i]]++;

//     int count = mp.size();

//     string res = "";

//     if (slen < tlen)
//         return res;
//     if (s == t)
//         return s;
//     int ans = INT_MAX;
//     int ans_i = 0;
//     while (endi < slen)
//     {
//         if (count != 0)
//         {
//             endi++;
//             if (mp.find(s[endi]) != mp.end())
//             {
//                 mp[s[endi]]--;
//                 if (mp[s[endi]] == 0)
//                     count--;
//             }
//         }
//         while (count == 0 && starti < slen)
//         {
//             if (ans > (endi - starti) + 1)
//             {
//                 ans = (endi - starti) + 1;
//                 ans_i = starti;
//             }
//             if (mp.find(s[starti]) != mp.end())
//             {
//                 mp[s[starti]]++;
//                 if (mp[s[starti]] > 0)
//                     count++;
//             }
//             starti++;
//         }
//     }

//     if (ans == INT_MAX)
//         return "";
//     return s.substr(ans_i, ans);
// }

// // code 4
// working code in C++ According to Aditya Bhai's Explanation  Hope this help !!!!

// #include <bits/stdc++.h>
//     using namespace std;
// int main()
// {
//     string s = "totmtaptat";
//     string s1 = "tta";
//     // Making the Map

//     unordered_map<char, int> mp;
//     for (int i = 0; i < s1.length())
//         mp[s1[i]]++;

//     // Creating Variables

//     int ans = INT_MAX;
//     int i = 0, j = 0;
//     int count = mp.size();

//     // starting to  solve

//     while (j < s.length())
//     {
//         // CALCULATION STEP ( As Aditya's general format)

//         if (mp.find(s[j]) != mp.end())
//         {
//             mp[s[j]]--;
//             if (mp[s[j]] == 0)
//                 count--;
//         }

//         // step to slide " j "

//         if (count > 0)
//             j++;

//         // step where we will find a candidate for answer

//         else if (count == 0)
//         {
//             ans = min(ans, j - i + 1); // A candidate for our Answer

//             // trying to minimize the window size after getting a candidate for answer

//             while (count == 0)
//             {
//                 if (mp.find(s[i]) == mp.end())
//                 {
//                     i++;
//                     ans = min(ans, j - i + 1); // updating the answer
//                 }
//                 else
//                 {
//                     mp[s[i]]++;
//                     if (mp[s[i]] > 0)
//                     {
//                         i++;
//                         count++;
//                     }
//                     else
//                     {
//                         i++;
//                         ans = min(ans, j - i + 1); // updating the answer
//                     }
//                 }
//             }
//             j++;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// // code 5
// I think this code works in case when length of the minimum substring is to be returned:
// -
//     int
//     Solution(string s, string p)
// {
//     int n = s.length();
//     int m = p.length();
//     int i = 0, j = 0;
//     int Count = INT_MAX;
//     int l = INT_MAX;
//     unordered_map<char, int> freq;

//     for (int i = 0; i < m; i++)
//         freq[p[i]]++;
//     Count = freq.size();

//     if (m < n)
//     {
//         while (j < n)
//         {
//             if (freq.find(s[j]) != freq.end())
//             {
//                 freq[s[j]]--;
//                 if (freq[s[j]] == 0)
//                     Count--;
//             }

//             if (Count > 0)
//                 j++;

//             if (Count == 0)
//             {
//                 l = min(l, j - i + 1);
//                 while (Count == 0 && i <= j)
//                 {
//                     if (freq.find(s[i]) != freq.end())
//                     {
//                         freq[s[i]]++;
//                         if (freq[s[i]] == 1)
//                         {
//                             l = min(l, j - i + 1);
//                             Count++;
//                         }
//                     }
//                     i++;
//                 }
//                 j++;
//             }
//         }

//         return l;
//     }

//     else
//         return -1;
// }

// // code 6
// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {

//         // Some initial Variables for running the loop ans answer;
//         int i = 0, j = 0, ans = INT_MAX;
//         int idx = -1;
//         // Create a map to store the frequency of characters
//         unordered_map<char, int> mp;
//         // Fill the map with character frequency
//         for (auto x : t)
//             mp[x]++;

//         int count = mp.size();
//         // Start the sliding
//         while (j < s.length())
//         {

//             if (mp.find(s[j]) != mp.end())
//             {
//                 mp[s[j]]--;
//                 if (mp[s[j]] == 0)
//                     count--;
//             }

//             while (count == 0)
//             {
//                 // ans = min(ans, j - i + 1);
//                 if (ans > j - i + 1)
//                 {
//                     ans = j - i + 1;
//                     idx = i;
//                 }

//                 if (mp.find(s[i]) != mp.end())
//                 {

//                     if (mp[s[i]] == 0)
//                     {
//                         count++;
//                     }
//                     mp[s[i]]++;
//                 }
//                 i++;
//             }

//             j++;
//         }

//         return (idx == -1) ? "" : s.substr(idx, ans);
//     }
// };

// // code 7-leetcode
// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         vector<int> map(128, 0);
//         for (char c : t)
//         {
//             map[c]++;
//         }

//         int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
//         while (end < s.size())
//         {
//             if (map[s[end++]]-- > 0)
//             {
//                 counter--;
//             }
//             while (counter == 0)
//             {
//                 if (end - begin < d)
//                 {
//                     head = begin;
//                     d = end - head;
//                 }
//                 if (map[s[begin++]]++ == 0)
//                 {
//                     counter++;
//                 }
//             }
//         }
//         return d == INT_MAX ? "" : s.substr(head, d);
//     }
// };

// // code 8
// Intuition : The problem asks to find the minimum window in s that contains all the characters of t.One way to approach this problem is to use a sliding window technique.We can maintain a window that starts from the beginning of s and moves forward until it contains all the characters of t.Once we have such a window, we can try to shrink it by moving the window's start pointer forward while still keeping all the characters of t in the window. This will give us the minimum window.

// #Approach:

//                                                                                                                                                                                                                                                                                                                               Check if s is shorter than t.If it is,
//     there is no possible solution, and we return an empty string.Create a frequency map of characters in t.Initialize count, start, min_length, and min_start to 0. Traverse the string s using the end pointer.If the current character in s is present in the frequency map, increment the count.Decrement the frequency of the current character in the frequency map.If the count equals the length of t, it means we have found a window that contains all characters of t.Now we try to shrink the window by moving the start pointer forward until the window still contains all the characters of t.If the length of the current window is smaller than the minimum length so far, update the minimum length and the minimum start.Increment the frequency of the character at the start pointer and decrement the count.Return the minimum window or an empty string if no window exists.Complexity : Time complexity : O(N), where N is the length of the string s.We traverse the string s once.Space complexity : O(M), where M is the length of the string t.We create a frequency map of characters in t.Code class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         if (s.size() < t.size())
//         {
//             return "";
//         }
//         unordered_map<char, int> map;
//         for (int i = 0; i < t.size(); i++)
//         {
//             map[t[i]]++;
//         }
//         int count = 0, start = 0, min_length = INT_MAX, min_start = 0;
//         for (int end = 0; end < s.size(); end++)
//         {
//             if (map[s[end]] > 0)
//             {
//                 count++;
//             }
//             map[s[end]]--;
//             if (count == t.length())
//             {
//                 while (start < end && map[s[start]] < 0)
//                 {
//                     map[s[start]]++, start++;
//                 }
//                 if (min_length > end - start)
//                 {
//                     min_length = end - (min_start = start) + 1;
//                 }
//                 map[s[start++]]++;
//                 count--;
//             }
//         }
//         return min_length == INT_MAX ? "" : s.substr(min_start, min_length);
//     }
// };

// // code 9
// Intuition
//     In this problem,
//     we need to find the minimum window substring of string s that contains all characters from string t.We can use a sliding window approach to find the minimum window substring efficiently.

//     Approach 01 Create an unordered_map mp to store the count of characters in string t.Initialize variables ans,
//     start, and count.Use pointers i and j to iterate through string s.Decrement count of the current character in the map;
// if it
//     becomes 0, decrement the count variable.Move pointer i to check if it is possible to remove more characters and get smaller substrings.Store the smaller length in ans and update the start variable.Add the current element to the map and increment the count if it becomes greater than 0. If ans has a length other than INT_MAX, return the substring from the start index to the length of ans; otherwise, return an empty string.
// Complexity
// Time complexity: The time complexity of this solution is O(m), where 'm' is the length of string 's'. The algorithm iterates through the string once, and each iteration involves constant time operations.

// Space complexity: The space complexity is O(n), where 'n' is the length of string 't'. We use additional space for the unordered_map to store characters from 't'.

// Code
// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         int m = s.size(), n = t.size();
//         unordered_map<char, int> mp;

//         int ans = INT_MAX;
//         int start = 0;

//         for (auto x : t)
//             mp[x]++;

//         int count = mp.size();

//         int i = 0, j = 0;

//         while (j < s.length())
//         {
//             mp[s[j]]--;
//             if (mp[s[j]] == 0)
//                 count--;

//             if (count == 0)
//             {
//                 while (count == 0)
//                 {
//                     if (ans > j - i + 1)
//                     {
//                         ans = j - i + 1;
//                         start = i;
//                     }
//                     mp[s[i]]++;
//                     if (mp[s[i]] > 0)
//                         count++;

//                     i++;
//                 }
//             }
//             j++;
//         }
//         if (ans != INT_MAX)
//             return s.substr(start, ans);
//         else
//             return "";
//     }
// };

// // code 10
// Intuition
//     The problem
//     requires finding
// the minimum window in string s that contains all characters from string t.To solve this, we can use a sliding window approach.We will maintain two pointers, i and j, which represent the left and right boundaries of the current window.We will also maintain two arrays, map and window, to track the frequency of characters in string t and the current window, respectively.Additionally, we will use a variable count to keep track of how many distinct characters from t are currently present in the window.

//                                                                                                                                                                                                                                                                                                                                                                                                 Approach Create an array map of size 256 to store the frequency of characters in string t.Traverse through string t and update the map array with the frequency of each character.Initialize variables count,
//     i, start, end, and ans.count will keep track of the number of distinct characters in the current window.i will represent the left boundary of the window.start and end will store the indices of the minimum window found, and ans will store the length of the minimum window.Iterate through string s using pointer j from 0 to m - 1, where m is the size of string s.a.Update the window array with the frequency of the character at index j.b.If the frequency of the character at index j is less than or equal to its frequency in map, increment the count.c.If count equals the size of string t, it means all characters from t are present in the current window.Now, we need to shrink the window from the left side until we no longer have all characters from t in the window while maintaining the minimum window size.- Increment i and decrease the frequency of the character at index i in the window array.- Continue incrementing i until the frequency of the character at index i in the window array becomes less than its frequency in the map array.- Update the ans, start, and end variables with the current window size and indices if the current window size is smaller than the previous minimum.- Decrement the count since we removed a character from the window.After the loop, if start is still - 1, it means no valid window was found, so return an empty string.Otherwise, extract the substring from s using the indices start and end to obtain the minimum window.Return the minimum window substring.Complexity Time complexity : O(m + n) O(m + n) O(m + n), where m is the size of string s and n is the size of string t.The loop through string s takes O(m) time, and the loop through string t takes O(n) time.Space complexity : O(1) O(1) O(1), since the map and window arrays have a constant size of 256 characters, and the additional variables used are constant.Code class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         int m = s.size();
//         int n = t.size();
//         if (n > m)
//             return ""; // Handle the case where t is longer than s

//         int map[256] = {0}; // Create an array to store the frequency of characters in string t
//         for (char c : t)
//         {
//             map[c]++;
//         }
//         int count = 0; // Count of distinct characters in the current window

//         int window[256] = {0};                          // Create an array to track the frequency of characters in the current window
//         int i = 0, start = -1, end = -1, ans = INT_MAX; // Initialize pointers and variables

//         for (int j = 0; j < m; j++)
//         {
//             window[s[j]]++; // Expand the window by adding character at index j
//             if (window[s[j]] <= map[s[j]])
//             {
//                 count++; // Increment count if the character is present in t
//             }
//             if (count == n)
//             { // If all characters of t are present in the window
//                 while (map[s[i]] == 0 || window[s[i]] > map[s[i]])
//                 {
//                     window[s[i]]--;
//                     i++; // Contract the window from the left side
//                 }
//                 if ((j - i + 1) < ans)
//                 {
//                     ans = j - i + 1;
//                     start = i;
//                     end = j; // Update the minimum window indices
//                 }
//                 window[s[i]]--;
//                 i++;
//                 count--;
//             }
//         }
//         if (start == -1)
//             return ""; // No valid window found
//         string final = "";
//         for (int x = start; x <= end; x++)
//         {
//             final += s[x]; // Extract the minimum window substring
//         }
//         return final;
//     }
// };