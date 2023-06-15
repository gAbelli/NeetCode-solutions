#include <iostream>
#include <vector>

class Solution {
  public:
    std::string encode(std::vector<std::string> &strs) {
        std::string res;
        for (int i = 0; i < strs.size(); ++i) {
            std::string &s = strs[i];
            if (i != 0) {
                res += ":;";
            }
            res += s;
        }
        return res;
    }

    std::vector<std::string> decode(std::string &str) {
        std::vector<std::string> res;
        int n = str.size();
        std::string buffer;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ':') {
                if (i < n - 1 && str[i + 1] == ';') {
                    i += 2;
                    res.push_back(buffer);
                    buffer = "";
                }
            }
            buffer += str[i];
        }
        res.push_back(buffer);

        return res;
    }
};

// int main() {
//     Solution s;
//     {
//         std::vector<std::string> decoded;
//         decoded.push_back("hello");
//         decoded.push_back("world");
//         std::string encoded = s.encode(decoded);
//         std::cout << encoded << std::endl;
//     }
//     std::cout << "-----------" << std::endl;
//     {
//         std::string encoded = "hello:;world";
//         std::vector<std::string> decoded = s.decode(encoded);
//         for (const auto &s : decoded) {
//             std::cout << s << std::endl;
//         }
//     }
// }
