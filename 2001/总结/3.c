

int n = 2;

int f2(int a, int b) {
    static int m;
    extern int j;
    n = n * j + 1;
    j = j + m + 1;
    m = n + j + a + b;
    return m;
}