int cnt = 0;
int trie[MAXLEN][26];
int fail[MAXLEN];
int rd[MAXLEN];
char c;


void insert(char* s, int i) { //trie插入
	int id = 0;
	for (; *s; ++s) {
		c = *s - 'a';
		if (!trie[id][c]) trie[id][c] = ++cnt;
		id = trie[id][c];
	}
	//一些操作(在trie上产生节点)
}

void build() { 
	queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (trie[0][i])q.push(trie[0][i]);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++i) {
			if (trie[u][i]) {
				int t = trie[u][i];
				fail[t] = trie[fail[u]][i];
				q.push(t);
				++rd[fail[t]];
			}
			else {
				trie[u][i] = trie[fail[u]][i];
			}
		}
	}
}

void query(char* s) {
	int id = 0;
	for (int i = 0; s[i]; ++i) {
		id = trie[id][s[i] - 'a'];
		//一些懒标操作
	}
}

void topo() {
	queue<int> q;
	for (int i = 1; i <= cnt; ++i)if (!rd[i])q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		//一些操作(更新当前值)
		int f = fail[u];
		--rd[f];
		//一些操作(懒标回推)
		if (!rd[f])q.push(f);
	}
}