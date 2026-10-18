class Solution {
public:
    string reverseWords(string s) {
        int write = 0;
        int n = static_cast<int>(s.size());
        for (int read = 0; read < n; read++) {
            if (s[read] == ' ') {
                continue;
            }

            if (write > 0) {
                s[write++] = ' ';
            }

            while (read < n && s[read] != ' ') {
                s[write++] = s[read++];
            }
        }

        s.resize(write);
        reverse(s.begin(), s.end());

        int start = 0;
        for (int end = 0; end <= write; end++) {
            if (end == write || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};