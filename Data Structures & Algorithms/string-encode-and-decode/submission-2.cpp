class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        string res = "";

        for(int i = 0; i < n; i++) {
            res += strs[i];
            res += "_sp*";
        }

        cout << res << endl;

        return res;


    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        int n = s.size();
        vector<string> res;
        string currentWord = "";

        for(int i = 0; i < n; i++) {
            if(s[i] == '_' && s[i+1] == 's' && s[i+2] == 'p' && s[i+3] == '*') {
                res.push_back(currentWord);
                cout << currentWord << endl;
                currentWord = "";
                i += 3;
                continue;
            }
            currentWord += s[i];
        }

        return res;

    }
};
