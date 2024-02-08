// Find if second string pttrn is present in first string

// code 1: 2 unordered map + count
// code 2: unordered map + count
// code 3: 2 vector<int> - gfg
// code 4: unordered map + count + count function instead map
// code 5: 2 vector<int> ans(26,0) -gfg
// code 6: unordered map  + count   -
// code 7: unordered map with vector  + count; o/p:vector - gfg
// code 8: No sliding window approach

// code 1 :
// int search(string txt, string pat)
// {
//     unordered_map<char, int> mp;
//     for (auto it : txt)
//         mp[it]++;

//     int size = pat.length();
//     int len = mp.size();
//     int i = 0;
//     int j = 0;
//     int k = txt.length();
//     int ret_count = 0;
//     unordered_map<char, int> mp2;
//     while (j < size)
//     {
//         if (j - i + 1 < k)
//         {
//             mp2[pat[j]]++;
//             j++;
//         }
//         else if ((j - i + 1) == k)
//         {
//             mp2[pat[j]]++;
//             // match the two maps values and increment the count checks in O(1) everytime
//             {
//                 int char_count = 0;
//                 auto it = mp.begin();
//                 while (it != mp.end() && mp2[it->first] == it->second)
//                 {
//                     char_count++;
//                     it++;
//                 }
//                 if (char_count == len)
//                     ret_count++;
//             }
//             mp2[pat[i]]--;
//             i++;
//             j++;
//         }
//     }
//     return ret_count;
// }

// code 2 :
#include <bits/stdc++.h>
    using namespace std;

int countOccurance(string s, string p)
{
    unordered_map<char, int> mp;
    int ans = 0;

    // storing the occ. of string p in the map
    for (auto &x : p)
    {
        mp[x]++;
    }

    int count = mp.size();
    int k = p.size();
    int i = 0, j = 0;

    while (j < s.size())
    {
        // calculation part
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        // window length not achived yet
        if (j - i + 1 < k)
        {
            j++;
        }

        // window length achived, find ans and slide the window
        else if (j - i + 1 == k)
        {
            // finding the ans
            if (count == 0)
            {
                ans++;
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                {
                    count++;
                }
            }

            // slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string s, p;
    cin >> s;
    cin >> p;

    cout << countOccurance(s, p) << "\n";
    return 0;
}

// Aditya Kumar 1 month ago
//     we can also use vector of size 26 instead of usin g map;

// code 3 :
// int search(string pat, string txt)
// {
//     int n = txt.length(); // length of txt

//     int k = pat.length(); // window size

//     // variable to store count of the occurences of anagrams of word in the text

//     int ans = 0;

//     // storing frequency of characters in string : pat
//     vector<int> hashPat(26, 0);
//     for (int i = 0; i < k; i++)
//     {
//         hashPat[pat[i] - 'a']++;
//     }

//     // storing frequency of characters in string : txt
//     vector<int> hashTxt(26, 0);

//     int i = 0, j = 0; // start of window and end of window

//     while (j < n)
//     {

//         hashTxt[txt[j] - 'a']++;

//         if (j - i + 1 == k) // condition for attaining window size of 'k'
//         {
//             if (hashTxt == hashPat) // freq. of characters matches
//                 ans++;

//             hashTxt[txt[i] - 'a']--; // to maintain the size of window
//             i++;
//         }
//         j++;
//     }
//     return ans;
// }

// code 4 :
// int countOccurencesOfAnagrams(string str, string pattern)
// {
//     int ans = 0, k = pattern.size();
//     unordered_map<char, int> map;
//     // building the map
//     for (auto i : pattern)
//         map[i]++;
//     // storing no of distinct/unique elements in map
//     int countDistinct = map.size();
//     // sliding window
//     int ws = 0; // window start
//     for (int we = ws; we < str.size(); we++)
//     {
//         // calculations/storing area
//         if (map.count(str[we]) > 0)
//         { // IF KEY PRESENT IN MAP, then only do the operations!
//             map[str[we]]--;
//             if (map[str[we]] == 0)
//                 countDistinct--;
//         }

//         // window hit area
//         if (we >= k - 1)
//         {
//             if (countDistinct == 0)
//                 ans++; // ans
//             // adjust calculations before shifting ws
//             if (map.count(str[ws]) > 0)
//             {
//                 map[str[ws]]++;
//                 if (map[str[ws]] == 1)
//                     countDistinct++;
//             }

//             ws++; // shift
//         }
//     }
//     return ans;
// }

// code 5 :
// int search(string pat, string txt)
// {
//     vector<int> ans(26, 0);
//     vector<int> arr(26, 0);
//     for (int i = 0; i < pat.length(); i++)
//     {
//         ans[pat[i] - 'a']++;
//     }
//     int i = 0;
//     int j = 0;
//     int count = 0;
//     while (j < txt.length())
//     {
//         arr[txt[j] - 'a']++;
//         if (j - i + 1 < pat.length())
//         {
//             j++;
//         }
//         else if (j - i + 1 == pat.length())
//         {
//             if (ans == arr)
//                 count++;
//             arr[txt[i] - 'a']--;
//             i++;
//             j++;
//         }
//     }
//     return count;
// }

// code 6 :
// vector<int> findAnagrams(string s, string p)
// {
//     unordered_map<char, int> m;

//     vector<int> v;

//     for (int i = 0; i < p.size(); i++)
//         m[p[i]]++;

//     int count = m.size(), i = 0, j = 0, k = p.size();

//     while (j < s.size())
//     {
//         if (m.find(s[j]) != m.end())
//         {
//             m[s[j]]--;
//             if (m[s[j]] == 0)
//                 count--;
//         }

//         if (j - i + 1 < k)
//             j++;

//         else if (j - i + 1 == k)
//         {
//             if (count == 0)
//                 v.push_back(i);

//             if (m.find(s[i]) != m.end())
//             {
//                 m[s[i]]++;
//                 if (m[s[i]] == 1)
//                     count++;
//             }
//             i++;
//             j++;
//         }
//     }
//     return v;
// }

// code 7 :
// int search(string pat, string txt)
// {

//     unordered_map<char, int> countMap;
//     int anagramCount = 0;

//     // Stores thd distinct characters needed in total.
//     // For eg for  3
//     //        adaa 2
//     //        yumu 3
//     int targetCountOfDistinctLetters;

//     // Set the target map
//     for (auto &&i : pat)
//         countMap[i]++;

//     // How many numbers of distinct characters are there is size of map itslef.
//     targetCountOfDistinctLetters = countMap.size();

//     // Get the first window.
//     for (int i = 0; i < pat.size(); i++)
//     {
//         if (countMap.find(txt[i]) != countMap.end())
//             countMap[txt[i]]--;
//     }

//     // Set Counters
//     for (auto &&i : countMap)
//     {
//         if (i.second == 0)
//             targetCountOfDistinctLetters--;
//     }

//     if (targetCountOfDistinctLetters == 0)
//         anagramCount++;

//     // Slide thew Window
//     for (int i = pat.size(); i < txt.size(); i++)
//     {

//         if (countMap.find(txt[i]) != countMap.end())
//         {
//             countMap[txt[i]]--;

//             // Previously was 0 but now disbalanced.
//             if (countMap[txt[i]] + 1 == 0)
//                 targetCountOfDistinctLetters++;

//             // Just now reached 0.
//             if (countMap[txt[i]] == 0)
//                 targetCountOfDistinctLetters--;
//         }

//         if (countMap.find(txt[i - pat.size()]) != countMap.end())
//         {
//             countMap[txt[i - pat.size()]]++;

//             // Previously was 0 but now disbalanced.
//             if (countMap[txt[i - pat.size()]] - 1 == 0)
//                 targetCountOfDistinctLetters++;

//             // Just now reached 0.
//             if (countMap[txt[i - pat.size()]] == 0)
//                 targetCountOfDistinctLetters--;
//         }

//         // If everything is balanced means its anagram so increase its count.
//         if (targetCountOfDistinctLetters == 0)
//             anagramCount++;
//     }

//     return anagramCount;
// }
// }

// code 8 :
// // very simple cpp code
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <cstring>
// using namespace std;

// int main()
// {
//     // your code goes here

//     string str;
//     getline(cin, str);
//     int n1 = str.length();
//     string str2;
//     getline(cin, str2);
//     int n2 = str2.length(), count = 0;

//     sort(str2.begin(), str2.end());

//     string temp;

//     for (int i = 0; i < n1 - 3; i++)
//     {
//         temp.insert(temp.end(), {str[i], str[i + 1], str[i + 2], str[i + 3]});
//         sort(temp.begin(), temp.end());

//         if (temp.compare(str2) == 0)
//             count++;

//         temp.clear();
//     }

//     cout << count;

//     return 0;
// }

// CODING SITE
// METHOD 1
// int search(string pat, string txt)
// {
//     vector<int> ans(26, 0);
//     vector<int> arr(26, 0);
//     for (int i = 0; i < pat.length(); i++)
//     {
//         ans[pat[i] - 'a']++;
//     }
//     int i = 0;
//     int j = 0;
//     int count = 0;
//     while (j < txt.length())
//     {
//         arr[txt[j] - 'a']++;
//         if (j - i + 1 < pat.length())
//         {
//             j++;
//         }
//         else if (j - i + 1 == pat.length())
//         {
//             if (ans == arr)
//                 count++;
//             arr[txt[i] - 'a']--;
//             i++;
//             j++;
//         }
//     }
//     return count;
// }

// // METHOD 2
// unordered_map<char, int> mp;
// for (char a : pat)
//     mp[a]++;
// int count = mp.size();
// int i = 0, j = 0;
// int n = txt.size();
// int k = pat.size();
// int ans = 0;
// while (j < n)
// {
//     // calculation
//     if (mp.find(txt[j]) != mp.end())
//     {
//         mp[txt[j]]--;
//         if (mp[txt[j]] == 0)
//             count--;
//     }
//     if (j - i + 1 < k)
//         j++;
//     else if (j - i + 1 == k)
//     {
//         // ans calculation
//         if (count == 0)
//             ans++;
//         // check before incrementing i
//         if (mp.find(txt[i]) != mp.end())
//         {
//             mp[txt[i]]++;
//             if (mp[txt[i]] == 1)
//                 count++;
//         }
//         i++;
//         j++;
//     }
// }
// return ans;

// // METHOD 3
// int search(string k, string s)
// {
//     int i = 0;
//     int j = 0;
//     int l = k.size();
//     map<char, int> m;
//     for (int i = 0; i < k.size(); i++)
//     {
//         m[k[i]]++;
//     }
//     int ans = 0;
//     int count = m.size();
//     while (j < s.size())
//     {
//         if ((j - i + 1) < l)
//         {
//             m[s[j]]--;
//             if (m[s[j]] == 0)
//             {
//                 count--;
//             }
//             j++;
//         }
//         else if ((j - i + 1) == l)
//         {
//              EXTRA
//             m[s[j]]--;
//             if (m[s[j]] == 0)
//             {
//                 count--;
//             }
//              NORMAL
//             if (count == 0)
//             {
//                 ans++;
//             }
//             m[s[i]]++;
//             if (m[s[i]] == 1)
//             {
//                 count++;
//             }
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }

// // METHOD 4
// int ans = 0;
// int i = 0, j = 0, k = pat.length();
// int cnt = 0;
// unordered_map<char, int> mp;
// for (auto ch : pat)
// {
//     mp[ch]++;
// }
// cnt = mp.size();
// while (j < txt.size())
// {
//     if (mp.find(txt[j]) != mp.end())
//     {
//         mp[txt[j]]--;
//         if (mp[txt[j]] == 0)
//             cnt--;
//     }
//     if (j - i + 1 < k)
//         j++;
//     else if (j - i + 1 == k)
//     {
//         if (cnt == 0)
//             ans++;
//         if (mp.find(txt[i]) != mp.end())
//         {
//      Koi character h map m jiski frequency '0' h
//             if (mp[txt[i]] == 0)
//                 cnt++;
//             mp[txt[i]]++;
//             // if(mp[txt[i]]==1) count++;
//         }
//         i++;
//         j++;
//     }
// }
// return ans;
// }
// ;