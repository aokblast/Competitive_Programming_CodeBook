bool gauss() {
	for(int i = 0; i < n; ++i){
		int r = i;
		for(int j = i + 1; j < n; ++j)
			if(arr[r][i] < arr[j][i])
				r = j;
		if(r != i)
			swap(arr[r], arr[i]);
		
		if(!arr[i][i])
			return false;
		
		int rev = (exgcd(arr[i][i], MOD), (x % MOD + MOD) % MOD);
		
		for(int k = 0; k < n; ++k){
			if(k == i)
				continue;
			int times = arr[k][i] * rev % MOD;
			for(int j = i; j < (n << 1); ++j)
				arr[k][j] = ((arr[k][j] - times * arr[i][j]) % MOD + MOD) % MOD;
			
		}
		
		for(int j = i; j < (n << 1); ++j)
			arr[i][j] = arr[i][j] * rev % MOD;
	}
	return true;
}