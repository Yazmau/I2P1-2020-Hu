// solution with many conditionals by Yazmau
#include<stdio.h>
#define maxn 20
void solve(int n,char (*s)[maxn]) {
    char ans = 'n';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(s[i][j] != '.') {
                if(i + 4 < n && s[i][j] == s[i + 1][j] && s[i][j] == s[i + 2][j] && s[i][j] == s[i + 3][j] && s[i][j] == s[i + 4][j])
                    ans = s[i][j];
                if(j + 4 < n && s[i][j] == s[i][j + 1] && s[i][j] == s[i][j + 2] && s[i][j] == s[i][j + 3] && s[i][j] == s[i][j + 4])
                    ans = s[i][j];
                if(i + 4 < n && j + 4 < n && s[i][j] == s[i + 1][j + 1] && s[i][j] == s[i + 2][j + 2] && s[i][j] == s[i + 3][j + 3] && s[i][j] == s[i + 4][j + 4])
                    ans = s[i][j];
                if(i + 4 < n && j - 4 >= 0 && s[i][j] == s[i + 1][j - 1] && s[i][j] == s[i + 2][j - 2] && s[i][j] == s[i + 3][j - 3] && s[i][j] == s[i + 4][j - 4])
                    ans = s[i][j];
            }
    if(ans == 'b')
        printf("black\n");
    else if(ans == 'w')
        printf("white\n");
    else
        printf("none\n");
}
int main() {
    int q;
    scanf("%d",&q);
    while(q--) {
        char s[maxn][maxn];
        int n = 15;
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        solve(n,s);
    }
    return 0;
}
