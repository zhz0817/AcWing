#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;
int n, m;
int f[N], g[N], q[N];
//拷贝数组，因为这里不能使用一维优化，因为如果倒叙枚举，你就不能用滑动窗口了。
// q存储容量为k时对应的价值
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        int v, w, s;
        cin >> v >> w >> s;//体积 价值 数量
        memcpy(g, f, sizeof f);
        for (int j = 0; j < v; j ++ ) {
            // j 代表背包容量 k 对 v 取模后的余数，也就是 k % v 的结果。通过枚举不同的 j 值，
            // 程序可以分组处理背包容量 k，以便利用单调队列优化动态规划的状态转移
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v) {
                while (hh <= tt && q[hh] < k - s * v) hh ++ ; //剔除超出长度元素
                if (hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w); //更新当前答案
                while (hh <= tt && g[q[tt]] <= g[k] - (k - q[tt]) / v * w) tt -- ; //维护单调性
                // 这段代码的目的是确保单调队列中的元素 q[] 满足单调性：队头元素对应的状态价值 g[q[hh]] 
                // 要小于等于当前状态 k 对应的状态价值 g[k] - (k - q[tt]) / v * w。这样就可以保证队列中的元素是按照状态价值的非递增顺序排列的。
                q[++tt] = k;//用更大的值去覆盖更小的值
            } 
        }
    }
    cout << f[m] << endl;
    return 0;
}