#include <vector>
#include <map>
#include "iostream"

using namespace std;

/**
 * KMP字符串匹配算法
 * @param haystack
 * @param needle
 * @return
 */
void calcNext(vector<int> &next, string s) {//计算前缀与后缀相同的索引
    int left = 0;
    next[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (left > 0 && s[left] != s[i]) {
            left = next[left - 1];
        }
        if (s[i] == s[left]) {
            left++;
        }
        next[i] = left;
    }
    for (auto &item: next) {
        cout << item << '\t';
    }
    cout << endl;
}

int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    vector<int> next;
    next.resize(needle.size(), -1);
    calcNext(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == needle.size()) {
            return i - needle.size() + 1;
        }
    }
    return -1;

}



/**
 * HorsPool字符串匹配算法
 * @param s
 * @return
 */
map<char, int> shiftTable(string s) {
    map<char, int> table;
    int len = s.size();
    for (int i = 0; i < len - 1; ++i) {
        table[s[i]] = len - i - 1;
    }
    return table;
}


int strStr2(string haystack, string needle) {
    map<char, int> table = shiftTable(needle);
    int size = needle.size();
    int m = haystack.size() - 1;
    int n = needle.size() - 1;
    while (n <= m) {
        int match_count = 0;
        while (match_count < size && needle[size - match_count - 1] == haystack[n - match_count]) {
            match_count++;
        }
        if (match_count == size) {
            return n - match_count + 1;
        } else {
            if (table.count(haystack[n])) {
                n += table[haystack[n]];
            } else {
                n += size;
            }
        }
    }
    return -1;
}

int main() {
    string haystack = "abcaaabcabf";
    string needle = "abcac";
    cout << strStr(haystack, needle);
};