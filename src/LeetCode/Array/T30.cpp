#include "iostream"

using namespace std;

/**
示例 1：
输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。

示例 2：
输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。

示例 3：
输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
 * @param s
 * @param words
 * @return
 */
vector<int> findSubstring(string s, vector<string> &words) {
    int wordsLen = words.size();
    int wordLen = words[0].size();
    int winLen = wordsLen * wordLen;
    vector<int> ans;
    if (winLen > s.size()) return ans;
    unordered_map<string, int> wordMap_tar;
    for (auto &item: words) {
        wordMap_tar[item]++;
    }
    int overload;
    for (int i = 0; i < wordLen; i++) {
        unordered_map<string, int> wordMap;
        overload = 0;
        int right = i;
        while (right <= s.size() - wordLen && (right + wordLen <= s.size())) {
            string str = s.substr(right, wordLen);
            right += wordLen;
            if (wordMap[str]++ == wordMap_tar[str]) overload++;
            int left = right - winLen;
            if (left < 0) continue;
            if (overload == 0) ans.push_back(left);
            str = s.substr(left, wordLen);
            if (--wordMap[str] == wordMap_tar[str]) overload--;
        }
    }
    return ans;
}


vector<int> findSubstring_1(string s, vector<string> &words) {
    int wordsLen = words.size();
    int wordLen = words[0].size();
    int winLen = wordsLen * wordLen;
    vector<int> ans;
    if (winLen > s.size()) return ans;
    unordered_map<string, int> wordMap_tar;

    for (auto &item: words) {
        wordMap_tar[item]++;
    }
    int num = wordMap_tar.size();//字符串种类个数（重复的字符串算一个种类）
    int winLeft, winRight, includedNum;
    for (int i = 0; i < wordLen; ++i) {
        unordered_map<string, int> wordMap;
        winLeft = i;
        winRight = i;
        includedNum = num;
        while (winRight + wordLen <= s.size()) {
            string str = s.substr(winRight, wordLen);
            winRight += wordLen;//右窗口移动
            if (++wordMap[str] == wordMap_tar[str]) includedNum--;//该种类字符串已全部包含
            if ((winRight - winLeft) < winLen) continue;//滑动窗口长度没达到
            if (includedNum == 0) ans.push_back(winLeft);
            str = s.substr(winLeft, wordLen);//左窗口收缩
            if (wordMap[str]-- == wordMap_tar[str]) includedNum++;//窗口收缩后某个字符串个数没到到目标个数
            winLeft += wordLen;
        }
    }
    return ans;
}

int main() {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word", "good", "best", "good"};
//    string s = "barfoofoobarthefoobarman";
//    vector<string> words = {"bar", "foo", "the"};
    vector<int> ans = findSubstring_1(s, words);
    for_each(ans.begin(), ans.end(), [](int x) { cout << x << endl; });
    return 0;
}