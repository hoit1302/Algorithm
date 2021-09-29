#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a) > (b) ? (a) : (b)

long long solution(int n, long long** tri) {
    long long ans = tri[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                tri[i][j] += tri[i - 1][0];
            else if (j == i)
                tri[i][j] += tri[i - 1][j - 1];
            else
                tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);

            ans = max(ans, tri[i][j]);
        }
    }
    return ans;
}

int main() {
    int n;
    int** tri;
	scanf("%d", &n);
    tri = (int**)malloc(sizeof(int*) * n);
	 for (int i = 0; i < n; i++) {
        tri[i] = (int*)malloc(sizeof(int) * (i + 1));
        for (int j = 0; j <= i; j++)
			scanf("%d", &tri[i][j]);
    }
	printf("%lld\n", solution(n, tri));
    return 0;
}