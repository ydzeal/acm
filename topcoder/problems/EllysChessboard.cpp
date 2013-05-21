#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

const int inf = 100000;
int dp[15][15][15][15];
int dat[15][15];
class EllysChessboard {
public:
    int Max(int a, int b, int c) {
        return max(max(a, b), c);
    }
    void checkmin(int &x, int y) {
        if (y < x) x = y;
    }
    int gao(int ax, int ay, int bx, int by, int deep) {
        if (ax > bx || ay > by) return inf;
        if (ax==bx && ay==by) return (dp[ax][ay][bx][by] = 0);
        if (dp[ax][ay][bx][by] != -1) return dp[ax][ay][bx][by];
        dp[ax][ay][bx][by] = inf;
        int nows = gao(ax+1, ay, bx, by, deep+1);
        for (int i = ay; i <= by; ++i)
            if (dat[ax][i]) nows += Max(bx-ax, i-ay, by-i);
        checkmin(dp[ax][ay][bx][by], nows);
        nows = gao(ax, ay+1, bx, by, deep+1);
        for (int i = ax; i <= bx; ++i)
            if (dat[i][ay]) nows += Max(by-ay, i-ax, bx-i);
        checkmin(dp[ax][ay][bx][by], nows);
        nows = gao(ax, ay, bx-1, by, deep+1);
        for (int i = ay; i <= by; ++i)
            if (dat[bx][i]) nows += Max(bx-ax, i-ay, by-i);
        checkmin(dp[ax][ay][bx][by], nows);
        nows = gao(ax, ay, bx, by-1, deep+1);
        for (int i = ax; i <= bx; ++i)
            if (dat[i][by]) nows += Max(by-ay, i-ax, bx-i);
        checkmin(dp[ax][ay][bx][by], nows);
        return dp[ax][ay][bx][by];
    }
    int minCost(vector <string> board) {
        memset(dat, 0, sizeof(dat));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                dat[i+j][i-j+7] = (bool)(board[i][j]=='#');
        return gao(0, 0, 14, 14, 0);
    }
};
