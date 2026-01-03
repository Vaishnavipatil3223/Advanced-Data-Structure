6)#include <iostream>
#include <cstring>
using namespace std;

int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

void ways(char expr[], int l, int r, int results[], int &count) {
    for (int i = l; i <= r; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            int left[50], right[50], lc = 0, rc = 0;
            ways(expr, l, i - 1, left, lc);
            ways(expr, i + 1, r, right, rc);
            for (int x = 0; x < lc; x++)
                for (int y = 0; y < rc; y++)
                    results[count++] = calculate(left[x], right[y], expr[i]);
        }
    }
    if (count == 0) {
        int num = 0;
        for (int i = l; i <= r; i++)
            num = num * 10 + (expr[i] - '0');
        results[count++] = num;
    }
}

int main() {
    char expr[] = "2-1-1";
    int res[50], count = 0;
    ways(expr, 0, strlen(expr)-1, res, count);
    for (int i = 0; i < count; i++) cout << res[i] << " ";
    return 0;
}