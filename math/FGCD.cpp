// 定理1: gcd(x, y) = gcd(y, x mod y) 辗转相除法
// 定理2: x = a * b * c, where a, b,c <= sqrt(x) or isPrime
// 定理3: gcd(x, y) = gcd(a, y) * gcd(x / a, y / gcd(a, y))


int minp[MAXN] = {0}; //最小质因数
int g[1010][1010]; //1000*1000 最大公因数表
int fac[MAXN][3]; //三个拆分的因数
bitset<MAXN> vis;

void init(){
    fac[1][0] = fac[1][1] = fac[1][2] = 1;
    for(int i = 1; i < MAXN; ++i){
        if(!vis[i]){ // Prime
            fac[i][0] = fac[i][1] = fac[i][2] = i;
            if(1ll * i * i > MAXN)
                continue;
            for(int j = i * i; j <= MAXN; j += i){
                vis[j] = 1;
                if(!minp[j])
                    minp[j] = i;
            }
        }else{
            int tmp = i / minp[i], a = minp[i] * fac[tmp][0], b = fac[tmp][1], c = fac[tmp][2];
            if(a > b)
                swap(a, b);
            if(b > c)
                swap(b, c);
            fac[i][0] = a, fac[i][1] = b, fac[i][2] = c;
        }
    }

    for(int i = 1; i <= 1000; ++i){
        g[i][0] = g[0][i] = i;
        for(int j = 1; j <= i; ++j)
            g[i][j] = g[j][i] = g[j][i % j];
    }
}

itn gcd(int x, int y){
    int tmp = g[fac[x][0]][y % fac[x][0]], res = tmp;
    y /= tmp;
    tmp = g[fac[x][1]][y % fac[x][1]], res *= tmp, y /= tmp;
    tmp = fac[x][2] > 1000 ? (y % fac[x][2] == 0 ? fac[x][2] : 1) : g[fac[x][2]][y % fac[x][2]], res *= tmp;
    return res;
}