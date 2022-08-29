ll lucas(ll n, ll m, ll p){
	if(m == 0)
		return 1ll;
	else
		return C(n % p, m % p, p) * lucas(n / p, m / p) % p;
}