// r互素

int a[MAXN], r[MAXN];
int n = 1, ans = 0;


for(int i = 0; i < k; ++i)
	n *= r[i];

for(int i = 0; i < k; ++i){
	ll m = n / r[i];
	exgcd(m, r[i]);
	ans = (ans + ((((lll)a[i] * m) % n) * x % n)) % n;
}


// r非互素

ll	M = r[0],  ans = a[0];

for(int i = 1; i < k; ++i){
	ll da = (((a[i] - ans) % r[i]) + r[i]) % r[i];
	ll g = exgcd(M, r[i]);
	if(da % g)
		return -1;
	auto tmp = (lll)M * x * (da / g);
	M = M * (r[i] / g);
	ans = (((ans + tmp) % M) + M) % M;
}
