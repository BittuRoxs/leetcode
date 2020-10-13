// Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest substring without repeating
// characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring. Example 4:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int find_in_vector(vector<string> s, char element) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i][0] == element) {
        return i;
      }
    }
    return -1;
  }

  int lengthOfLongestSubstring(string s) {
    if (s == " ") return 1;
    int current_winner = 0;
    vector<string> current_substring = {};
    for (int i = 0; i < s.size(); i++) {
      int index;

      index = find_in_vector(current_substring, s[i]);

      // if element not inside the current vector
      if (index == -1) {
        string temp;
        temp.push_back(s[i]);
        current_substring.push_back(temp);

      }
      // if element is already inside it
      else {
        if (current_winner < current_substring.size()) {
          current_winner = current_substring.size();
        }
        // empty current_substring until no double element is contained
        vector<string> temp_substring(current_substring.begin() + index + 1,
                                      current_substring.end());
        current_substring = temp_substring;
        string temp;
        temp.push_back(s[i]);
        current_substring.push_back(temp);
      }
    }
    if (current_winner < current_substring.size()) {
      return current_substring.size();
    }

    return current_winner;
  }
};
