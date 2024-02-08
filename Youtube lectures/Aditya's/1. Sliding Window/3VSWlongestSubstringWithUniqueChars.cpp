
// code 1: unordered set
// code 2: unordered set
// code 3: set
// code 4: unordered map
// code 5: unordered map
// code 6: unordered map
// code 7: vector
// code 8: vector
// code 9: Array
// Article with Mistakes using map


// Intuition
//     The intuition behind the 3 solutions is to iteratively find the longest substring without repeating characters by maintaining a sliding window approach.We use two
//     pointers(left and right) to represent the boundaries of the current substring.As we iterate through the string,
//     we update the pointers and adjust the window to accommodate new unique characters and eliminate repeating characters.

//         Approach 1 -
//         Set
//         We use a set(charSet)
// to keep track of unique characters in the current substring.We maintain two pointers, left and right, to represent the boundaries of the current substring.The maxLength variable keeps track of the length of the longest substring encountered so far.We iterate through the string using the right pointer.If the current character is not in the set(charSet), it means we have a new unique character.We insert the character into the set and update the maxLength if necessary.If the character is already present in the set, it indicates a repeating character within the current substring.In this case, we move the left pointer forward, removing characters from the set until the repeating character is no longer present.We insert the current character into the set and continue the iteration.Finally, we return the maxLength as the length of the longest substring without repeating characters.Code class Solution{
//     public:

// code 1
// int lengthOfLongestSubstring(string s)
// {
//     int n = s.length();
//     int maxLength = 0;
//     unordered_set<char> charSet;
//     int left = 0;

//     for (int right = 0; right < n; right++)
//     {
//         if (charSet.count(s[right]) == 0)
//         {
//             charSet.insert(s[right]);
//             maxLength = max(maxLength, right - left + 1);
//         }
//         else
//         {
//             while (charSet.count(s[right]))
//             {
//                 charSet.erase(s[left]);
//                 left++;
//             }
//             charSet.insert(s[right]);
//         }
//     }

//     return maxLength;
// }
// }
// ;

// CPP Solution for beginners | O(n) time | Longest Substring without repeating characters
// A solution for beginners, which is straightforward, easy to understand, without too many complications and room to optimize once you understand the basic premise of the question. Hope this helps!

// Time Complexity: O(n)
// Space Complexity: O(min of a,b) for the unordered set. a, is the upper bound of the space complexity.
// Where a: Size of the string
// b: Size of the number of characters in the character-set

// code 2
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_set<char> set;

//         int i = 0, j = 0, n = s.size(), ans = 0;

//         while (i < n && j < n)
//         {
//             if (set.find(s[j]) == set.end()) // If the character does not in the set
//             {
//                 set.insert(s[j++]);    // Insert the character in set and update the j counter
//                 ans = max(ans, j - i); // Check if the new distance is longer than the current answer
//             }
//             else
//             {
//                 set.erase(s[i++]);
//                 /*If character does exist in the set, ie. it is a repeated character,
//                 we update the left side counter i, and continue with the checking for substring. */
//             }
//         }

//         return ans;
//     }
// };

// code 3
// C++ Solution using Set
//     sheldonbang 205 12234 Apr 13,
//     2020 C++ C
//         Ordered Set int
//         lengthOfLongestSubstring(string s)
//  {
//     int n = s.length();
//     if (n == 0)
//         return 0;
//     set<char> st;
//     int maxsize = 0;
//     int i = 0, j = 0;
//     while (j < n)
//     {
//         if (st.count(s[j]) == 0)
//         {
//             st.insert(s[j]);
//             maxsize = max(maxsize, (int)st.size());
//             j++;
//         }
//         else
//         {
//             st.erase(s[i]);
//             i++;
//         }
//     }
//     return maxsize;
// }

// Approach 2 - Unordered Map
//                  We improve upon the first solution by using an unordered
//                  map(charMap)
// instead of a set.The map stores characters as keys and their indices as values.We still maintain the left and right pointers and the maxLength variable.We iterate through the string using the right pointer.If the current character is not in the map or its index is less than left, it means it is a new unique character.6 We update the charMap with the character's index and update the maxLength if necessary. If the character is repeating within the current substring, we move the left pointer to the next position after the last occurrence of the character.We update the index of the current character in the charMap and continue the iteration.At the end, we return the maxLength as the length of the longest substring without repeating characters.Code class Solution
// {
// public:

// code 4
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = s.length();
//         int maxLength = 0;
//         unordered_map<char, int> charMap;
//         int left = 0;

//         for (int right = 0; right < n; right++)
//         {
//             if (charMap.count(s[right]) == 0 || charMap[s[right]] < left)
//             {
//                 charMap[s[right]] = right;
//                 maxLength = max(maxLength, right - left + 1);
//             }
//             else
//             {
//                 left = charMap[s[right]] + 1;
//                 charMap[s[right]] = right;
//             }
//         }

//         return maxLength;
//     }
// };

// code 5
// C++ Code class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         if (s.length() == 0)
//             return 0;               // if string of length zero comes simply return 0
//         unordered_map<char, int> m; // create map to store frequency,(get to know all unique characters
//         int i = 0, j = 0, ans = INT_MIN;
//         while (j < s.length())
//         {
//             m[s[j]]++;                 // increase the frequency of the element as you traverse the string
//             if (m.size() == j - i + 1) // whem map size is equal to the window size means suppose window size is 3 and map size is also three that means in map all unique characters are their
//             {
//                 ans = max(ans, j - i + 1); // compare the length of the maximum window size
//             }
//             else if (m.size() < j - i + 1) // if the map size is less than the window size means there is some duplicate present like window size = 3 and map size = 2 means there is a duplicates
//             {
//                 while (m.size() < j - i + 1) // so till the duplicates are removed completely
//                 {
//                     m[s[i]]--;        // remove the duplicates
//                     if (m[s[i]] == 0) // if the frequency becomes zero
//                     {
//                         m.erase(s[i]); // delete it completely
//                     }
//                     i++; // go for next element
//                 }
//             }
//             j++; // go for the next element
//         }
//         return ans;
//     }
// };

// code 6
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {

//         unordered_map<char, int> index;
//         int start = 0, res = 0;
//         for (int i = 0; i < s.length(); i++)
//         {

//             if (index.find(s[i]) != index.end() && index[s[i]] >= start)
//                 start = index[s[i]] + 1;

//             index[s[i]] = i;
//             res = max(res, i - start + 1);
//         }

//         return res;
//     }
// };

// Approach 3 - Integer Array
// This solution uses an integer array charIndex to store the indices of characters.
// We eliminate the need for an unordered map by utilizing the array.
// The maxLength, left, and right pointers are still present.
// We iterate through the string using the right pointer.
// We check if the current character has occurred within the current substring by comparing its index in charIndex with left.
// If the character has occurred, we move the left pointer to the next position after the last occurrence of the character.
// We update the index of the current character in charIndex.
// At each step, we update the maxLength by calculating the length of the current substring.
// We continue the iteration until reaching the end of the string.
// Finally, we return the maxLength as the length of the longest substring without repeating characters.

// code 7
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = s.length();
//         int maxLength = 0;
//         vector<int> charIndex(128, -1);
//         int left = 0;

//         for (int right = 0; right < n; right++)
//         {
//             if (charIndex[s[right]] >= left)
//             {
//                 left = charIndex[s[right]] + 1;
//             }
//             charIndex[s[right]] = right;
//             maxLength = max(maxLength, right - left + 1);
//         }

//         return maxLength;
//     }
// };

// code 8
// int lengthOfLongestSubstring(string s)
// {
//     vector<int> dict(256, -1);
//     int maxLen = 0, start = -1;
//     for (int i = 0; i != s.length(); i++)
//     {
//         if (dict[s[i]] > start)
//             start = dict[s[i]];
//         dict[s[i]] = i;
//         maxLen = max(maxLen, i - start);
//     }
//     return maxLen;
// }

// SLIDING WINDOW || O(n) || Faster than 90 % and Memory usage less than 100 % kush980 Annual Badge 2022 510 26449 Jan 13, 2021 C++ C
//     Sliding Window
//     class Solution
// code 9
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {

//         // SLIDING WINDOW  - TIME COMPLEXITY O(2n)
//         //                   SPACE COMPLEXITY O(m)   //size of array

//         int store[256] = {0}; // array to store the occurences of all the characters
//         int l = 0;            // left pointer
//         int r = 0;            // right pointer
//         int ans = 0;          // initializing the required length as 0

//         while (r < s.length()) // iterate over the string till the right pointer reaches the end of the string
//         {
//             store[s[r]]++; // increment the count of the character present in the right pointer

//             while (store[s[r]] > 1) // if the occurence become more than 1 means the char is repeated
//             {
//                 store[s[l]]--; // reduce the occurence of temp as it might be present ahead also in the string
//                 l++;           // contraction of the present window till the occurence of the 't' char becomes 1
//             }

//             ans = max(ans, r - l + 1); // As the index starts from 0 , ans will be (right pointer-left pointer + 1)
//             r++;                       // now will increment the right pointer
//         }
//         return ans;
//     }
// };



// // Article with Mistakes
// // Dear All,

// // I solved this issue with different approaches and happy to share with you. Probably looking to all of them and comparing you will understand which one is better and why. All solutions containes comments for your better understanding of algorithm. Hope you will enjoy =)

// // Please find below my last and best solution with Sliding Window approach. Here we have O(n) time complexity(where n is a length of string) and O(k) space complexity(where k is unique characters from the string). You can notice that find() takes additional affort and Time Complexity won't be equal to O(n). I will try to explain: In general Time Complexity of searching elements in map is O(log n) in worst case. But exactly in our case it's very close to O(1) because we add only unique characters and range of possible characters is very small compared to string length. Let's imagine that our string contains 1 000 000 characters. But in Hash Table will be maximum 128 characters(in real life even less because some specific characters won't not used). Method find() in our case will be O(log 128) = 7 - very close to constant time. So, on each step logic will do maximum 7 additional steps. That's why it's very close to O(n). We can say that TC is O(n * log m), where n - length of string, m - number of unique characters from string. But since we know that m not more than 128, and log m not more than 7 - is very close to constant and we can ignore it.
// // We can try to use unordered_map that TC of find is O(1). The reason why I use map instead - unordered_map is not stable. In worst case TC will be O(n), not O(1). It happens when hash function will generate same hash index that calls collisions. Also unordered_map required for extra space for Hash Table. map - always O(log n). Since we know that log n = 7 in worse case - make sense use map.

// // class Solution {
// // public:
// // int lengthOfLongestSubstring(string s)
// // {
// //     // Return 0 if string is empty
// //     if (s == "")
// //     {
// //         return 0;
// //     }

// //     // Hash table for storing characters and indexes
// //     map<char, int> characters;

// //     // Longest sequence that will be returned in the end: for sure will be > 1 because 0 result was checked in the beginning
// //     int longest = 1;
// //     int j = 0;

// //     // Each character from string add to HashTable with his index. If we reach same character again - update index
// //     for (int i = 0; i < s.length(); ++i)
// //     {
// //         // If current character already exist in the HashTable
// //         if (characters.find(s[i]) != characters.end())
// //         {
// //             // Take larger index for future calculation between old and current+1 in HashTable
// //             j = j >= characters.find(s[i])->second + 1 ? j : characters.find(s[i])->second + 1;
// //         }
// //         // Add character with current index to HashTable
// //         characters[s[i]] = i;
// //         // longest will be chosen between larger value: old longest OR current sequance between i and j indexes + 1
// //         longest = longest >= i - j + 1 ? longest : i - j + 1;
// //     }

// //     return longest;
// // }
// // }
// // ;
// // Next will be my first try with brute force solution that has O(n^3) complexity. This approach will work here in LeetCode for small strings, but for big you will receive status 'Time Limit Exceeded'. In your IDE it will work even for big strings but very slowly. Iterator used just for practice. New method was created in private section for checking dublicates in substring - bool dublicatesInSubstring(string& s, const int substringBegin, const int substringEnd).

// class Solution
// {
// private:
//     // Method for dublicates check in substring
//     bool dublicatesInSubstring(string &s, const int substringBegin, const int substringEnd)
//     {
//         std::map<char, int> charactersOfSubstr;
//         std::map<char, int>::iterator it;

//         // Check substring for dublicates
//         for (int i = substringBegin; i <= substringEnd; ++i)
//         {
//             // Add character to HashTable
//             it = charactersOfSubstr.find(s[i]);
//             if (it != charactersOfSubstr.end())
//             {
//                 it->second++;
//             }
//             else
//             {
//                 charactersOfSubstr.insert(std::pair<char, int>(s[i], 0));
//             }
//             // In case HashTable has more that one such character - return true that means dublicates exist in substring
//             if (it->second > 0)
//             {
//                 return true;
//             }
//         }

//         return false;
//     }

// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         // Return 0 if string is empty
//         if (s == "")
//         {
//             return 0;
//         }

//         // Longest sequence that will be returned in the end
//         int longest = 0;

//         // For each character from string - ckech longest sequence untin end of the string
//         for (int i = 0; i < s.length(); ++i)
//         {
//             for (int j = i; j < s.length(); ++j)
//             {
//                 // In case no dublicates - function return false and longest substring should be calculated
//                 if (!dublicatesInSubstring(s, i, j))
//                 {
//                     longest = longest >= j - i + 1 ? longest : j - i + 1;
//                 }
//             }
//         }

//         return longest;
//     }
// };
// My next try was approach with O(n^2) complexity that much faster than previous and LeetCode finished all test cases without 'Time Limit Exceeded' status. Iterator also used only for practice.

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         // Return 0 if string is empty
//         if (s == "")
//         {
//             return 0;
//         }

//         std::map<char, int> charactersOfSubstr;
//         std::map<char, int>::iterator it;

//         // Longest sequence that will be returned in the end
//         int longest = 0;

//         // For each character from string - check longest sequence until encountered dublicate
//         for (int i = 0; i < s.length(); ++i)
//         {
//             // HashTable should be cleared before starting with new substring analyzing
//             charactersOfSubstr.clear();
//             for (int j = i; j < s.length(); ++j)
//             {
//                 // Try to find character in the HashTable
//                 it = charactersOfSubstr.find(s[j]);

//                 // If current character already exist in the HashTable - quit from j-loop to get next character for analyze
//                 if (it != charactersOfSubstr.end())
//                 {
//                     break;
//                 }
//                 // If character doesn't exist in HashTable - add it and recount unique sequence lenght
//                 else
//                 {
//                     charactersOfSubstr.insert(pair<char, int>(s[j], 1));

//                     // longest will be choseт between larger value: old longest OR current sequance (j - i + 1)
//                     longest = longest >= j - i + 1 ? longest : j - i + 1;
//                 }
//             }
//         }

//         return longest;
//     }
// };
// Next try was very close to O(n)
// but still loop inside loop used.After this approach I thought that it's possible to get rid of nested loop.

//     class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         // Return 0 if string is empty
//         if (s == "")
//         {
//             return 0;
//         }

//         // Hash table for storing characters and count dublicates
//         std::map<char, int> charactersOfSubstr;

//         // Longest sequence that will be returned in the end
//         int longest = 0;
//         int j = 0;

//         // Each character from string add to HashTable: for dublicates increase value that used in result calculation
//         for (int i = 0; i < s.length(); ++i)
//         {
//             // Try to find character in the HashTable
//             // If current character already exist in the HashTable - increment value
//             if (charactersOfSubstr.find(s[i]) != charactersOfSubstr.end())
//             {
//                 charactersOfSubstr.find(s[i])->second++;
//             }
//             // Othervise add it to HashTable
//             else
//             {
//                 charactersOfSubstr.insert(pair<char, int>(s[i], 1));
//             }

//             // ONLY if in HashTable exist several same characters:
//             // decrease ALL characters between j and i in HashTable AND increase j for calculation while s[i] value in Hash table > 1
//             while (charactersOfSubstr.find(s[i])->second > 1)
//             {
//                 // Descrease value of existing character
//                 charactersOfSubstr.find(s[j])->second--;
//                 // Increase j for future calculation
//                 ++j;
//             }

//             // longest will be chosen between larger value: old longest OR current sequance (i - j + 1)
//             longest = longest >= i - j + 1 ? longest : i - j + 1;
//         }

//         return longest;
//     }
// };