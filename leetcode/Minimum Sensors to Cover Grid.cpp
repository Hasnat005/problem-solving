class Solution {
public:
    int f(int a, int b) {
        return (a + b - 1) / b;
    }
    int minSensors(int n, int m, int k) {
        int x = f(n, 2 * k + 1);
        int y = f(m, 2 * k + 1);
        return x * y;
    }
};