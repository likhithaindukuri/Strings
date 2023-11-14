class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right && s[left] == ' ')
        {
            left++;
        } 
        while (left <= right && s[right] == ' ')
        {
            right--;
        }
        vector<string> words;
        string word;
        for (int i = left; i <= right; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (i > 0 && s[i - 1] != ' ') {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for (const string& w : words) {
            result += w + ' ';
        }
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};