int f[MAXLEN]; // failure Function 1-index

void kmp(char s[], char p[]){
	int i = 0, j = -1;
	int n = strlen(s), m = strlen(p);f[0]=-1;
	while(i < m){
		if(j == -1 || p[i] == p[j]){
			f[++i] = ++j;
		}else{
			j = f[j];
		}
	}
	i = 0; j = 0;
	while(i <= n){
		if(j == -1 || s[i] == p[j]){
			++j, ++i;
			if(j == m){
				//一些操作
			}

		}else{
			j = f[j];
		}
	}
}
