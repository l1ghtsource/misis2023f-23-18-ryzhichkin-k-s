#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        int k = 0;
        std::string s;
        std::cin >> n >> k >> s;
        bool flag = true;
        for (int i = 0; i < k; i++) {
            char temp = s[i];
            int j = i + k;
            while (j < n) {
                if (temp == '1' and s[j] == '0') {
                    std::cout << "NO" << std::endl;
                    flag = false;
                    break;
                }
                else if (temp == '0' and s[j] == '1') {
                    std::cout << "NO" << std::endl;
                    flag = false;
                    break;
                }
                else if (temp == '?' and s[j] != '?') {
                    temp = s[j];
                }
                j += k;
            }
            s[i] = temp;
        }
        if (flag) {
            int zero_counter = 0;
            int uno_counter = 0;
            for (int i = 0; i < k; i++) {
                if (s[i] == '0') {
                    uno_counter++;
                }
                else if (s[i] == '1') {
                    zero_counter++;
                }
            }
            if (zero_counter > k / 2 || uno_counter > k / 2) {
                std::cout << "NO" << std::endl;
            }
            else {
                std::cout << "YES" << std::endl;
            }
        }

    }
    return 0;
}