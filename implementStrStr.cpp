int strstr(string s, string x)
{
     int sLen = s.length();
    int xLen = x.length();

    for (int i = 0; i <= sLen - xLen; i++) {
        int j;
        for (j = 0; j < xLen; j++) {
            if (s[i + j] != x[j]) {
                break;
            }
        }
        if (j == xLen) {
            return i;
        }
    }

    return -1;
}