int djs[MAXLEN]; 
//init for(int i = 0; i < size; ++i)djs[i] = i;

int find(int id){
	return djs[id] == id ? id : djs[id] = find(djs[id]);
}
bool uSet(int a, int b){
	int pa = find(a), pb = find(b);
	return pa == pb ? true : (djs[pa] = pb, false);	
}