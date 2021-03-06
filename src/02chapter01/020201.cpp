/*
输入一个长度为 n 的整数序列。
接下来再输入 m 个询问，每个询问输入一对 l,r。
对于每个询问，输出原序列中从第 l 个数到第 r 个数的和。
*/

#include <stdio.h>

const int N = 100010;
int n,m;
int a[N];
int s[N];
#define get_sum(l,r) (l ? s[r] - s[l-1] : s[r])
int main() {

    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    // 前缀和初始化
    s[0] = 0;

    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];

    int l = 0, r = 0;
    while(m --){
        scanf("%d%d", &l, &r);
        printf("%d\n", get_sum(l,r));
    }
}
