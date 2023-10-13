#include <iostream>


int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        std::cin >> a >> b >> c;
        std::cout << a + b + c << " " << b + c << " " << c << std::endl;
    }
    return 0;
}
