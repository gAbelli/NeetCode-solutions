import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return new ArrayList<>();
        }

        char[][] letters = new char[8][];
        letters['2' - '2'] = new char[] {'a', 'b', 'c'};
        letters['3' - '2'] = new char[] {'d', 'e', 'f'};
        letters['4' - '2'] = new char[] {'g', 'h', 'i'};
        letters['5' - '2'] = new char[] {'j', 'k', 'l'};
        letters['6' - '2'] = new char[] {'m', 'n', 'o'};
        letters['7' - '2'] = new char[] {'p', 'q', 'r', 's'};
        letters['8' - '2'] = new char[] {'t', 'u', 'v'};
        letters['9' - '2'] = new char[] {'w', 'x', 'y', 'z'};

        List<String> res = new ArrayList<>();
        char[] cur = new char[digits.length()];
        dfs(digits, letters, res, cur, 0);

        return res;
    }

    void dfs(String digits, char[][] letters, List<String> res, char[] cur,
             int index) {
        if (index == digits.length()) {
            res.add(new String(cur));
            return;
        }

        for (char c : letters[digits.charAt(index) - '2']) {
            cur[index] = c;
            dfs(digits, letters, res, cur, index + 1);
        }
    }
}
