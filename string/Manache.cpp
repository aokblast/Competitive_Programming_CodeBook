char s[MAXLEN]; //字串 记得填充$#^(aaa-> $#a#a#a#^)
int p[MAXLEN]; //回文长度

int len = 0 //s的长度

void manache(){
	int i_r = 0, c = 0, r = 0; //i_r 反射点, c 中心点 r 右端点
	for(int i = 1; i < len; ++i){
		i_r = 2 * c - i;
		if(r > i) p[i] = min(r - i, p[i_r]);
		else p[i] = 0;
		while(s[i + 1 + p[i]] == s[i - 1 - p[i]]) ++p[i];
		if(i + p[i] > r) c = i, r = i + p[i];
	}
	int m = 0; // 长度
	c = 0; //中央
	for(int i = 0; i < len - 1; ++i){
		if(p[i] > m) c = i, m = p[i];
	}	
	printf("%d\n", m);
}
