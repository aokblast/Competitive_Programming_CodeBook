// ax+by=gcd(a, b) if gcd(a, b) == 1
// ax同余c(mod b) <=> ax + by = c
// c 同余 a / b (mod M) = bx 同余 a (mod M)

ll Exgcd(ll a, ll b, ll &x, ll &y){
    if(!b)
        return x = 1, y = 0, a;
    ll d = Exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

//线性

void inv(){
    inv[1] = 1;
    for(int i = 2; i <= n; ++i)
	    inv[i] = (ll)(p - p / i) * inv[p % i] % p;
}


//随机线性

int arr[n + 1], ji[n + 1], rev[n + 1], inv[n + 1]; // 数组，前缀积，前缀积逆元

ji[0] = 1;

for(int i = 1; i <= n; ++i)
    ji[i] = ji[i - 1] * arr[i] % p;

rev[n] = (exgcd(ji[n], p), x);

for(int i = n; i >= 1; --i)
    rev[i - 1] = (ll)rev[i] * arr[i] % p;

for(int i = 1; i <= n; ++i)
    inv[i] = (ll)rev[i] * ji[i - 1] % p;
