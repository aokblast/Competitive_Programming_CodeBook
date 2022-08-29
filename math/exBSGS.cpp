// a^x 同于 b (mod p)

int a, b, p, res; 
unordered_map<int, int> mp;

bool bsgs(){
		a %= p, b %= p;
		if(b == 1 || p == 1){
			res = 0;
			return true;
		}
		ll ax =1;
		int k = 0, g;
		while((g = exgcd(a, p)) != 1){
			if(b % g)
				return false;
			++k;
			b /= g, p /= g;
			ax = ((ll)ax * (a / g)) % p;
			if(ax == b){
				res = k;
				return true;
			}
		}

		exgcd(ax , p); 
		b = ((ll)b * (((x % p) + p) % p)) % p;

		int lim = ceil(sqrt(p));

		int cur = 1;

		mp.clear();

		for(int i = 0; i < lim; ++i){
			mp[(ll)cur * b % p] = i;
			cur = (ll)cur * a % p;
		}
		a = cur, cur = 1;
		if(!a){
			if(b)
				return false;
			res = k + 1;
			return true;
		}

		for(int i = 0; i <= lim; ++i){
			if(mp.count(cur) && i * lim - mp[cur] >= 0){
				res = i * lim - mp[cur] + k;
				return true;
			}
			cur = (ll)cur * a % p;
		}
		return false;
