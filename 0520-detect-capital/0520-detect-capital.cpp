class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upper = true;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] < 'A' || word[i] > 'Z') {
                upper = false;
                break;
            }
        }

        if (upper) {
            return true;
        }

        bool lower = true;
        for (int i = 0; i < word.length(); i++) {

            if (word[i] < 'a' || word[i] > 'z') {
                lower = false;
                break;
            }
        }
        if (lower) {
            return true;
        }

        for (int i = 1; i < word.length(); i++) {
            if (word[i] < 'a' || word[i] > 'z') {
                return false;
            }
        }
        return true;
    }
};