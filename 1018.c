#include <stdio.h>
int main(void) {
    int N, M, min = 64, count;
    char chess[50][51];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", chess[i]);
    }
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            count = 0;
            char start = chess[i][j];
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    char expected;
                    if ((x + y) % 2 == 0)
                        expected = start;
                    else
                        expected = (start == 'B') ? 'W' : 'B';

                    if (chess[i + x][j + y] != expected)
                        count++;
                }
            }
            if (count > 32) count = 64 - count;
            if (min > count) min = count;
        }
    }
    printf("%d\n", min);
    return 0;
}
