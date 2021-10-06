int Log2[MAXLEN]; //预处理log2
int st[MAXLEN][20]; //稀疏表
int n, m; //n个节点 m个query

void pre() {
	Log2[1] = 0, Log2[2] = 1;
	for (int i = 3; i <= MAXLEN; ++i) {
		Log2[i] = Log2[i >> 1] + 1;
	}
}

void build() {
	for (int j = 1; j <= 20; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

inline int query(int l, int r) {
	int lo = Log2[r - l + 1];
	return min(st[l][lo], st[r - (1 << lo) + 1][lo]);
}