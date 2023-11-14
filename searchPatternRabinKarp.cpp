class Solution
{
    public:
        vector<int> computeLPS(string pat) {
        int m = pat.length();
        vector<int> lps(m, 0);
        int len = 0; 

        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> search(string pat, string txt) {
        int n = txt.length();
        int m = pat.length();

        vector<int> lps = computeLPS(pat);
        vector<int> indices;

        int i = 0; 
        int j = 0; 

        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                // Pattern found
                indices.push_back(i - j + 1);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        if (indices.empty()) {
            indices.push_back(-1);
        }

        return indices;
    }
     
};