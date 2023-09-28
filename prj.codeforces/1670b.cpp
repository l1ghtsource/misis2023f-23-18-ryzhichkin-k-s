#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false); // спасло, без этого TL на 35-м тесте
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int k = 0;
        std::cin >> k;
        std::vector<bool> spec(30, false);
        int res = 0;
        int dr = 0;
        for (int j = 0; j < k; j++) {
            char c = ' ';
            std::cin >> c;
            spec[c - 'a'] = true;
        }
        for (int r = 0; r < n; r++) {
            if (spec[s[r] - 'a']) {
                res = std::max(res, r - dr);
                dr = r;
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}