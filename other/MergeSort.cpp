int arr[MAXLEN]; // 数组
int tmp[MAXLEN]; // 暂存
int ans  = 0; // 逆序对

void mergeSort(int left, int right){
	if(left >= right) return;
	int mid = left + ((right - left) >> 1);
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	int l = left;
	int r = mid + 1;
	int idx = 0;	
	while(l <= mid && r <= right){		
		tmp[idx++] = arr[l] <= arr[r] ? arr[l++] 
		: ((ans += mid - l + 1 /* 逆序对 */ ), arr[r++]);
	}
	while(l <= mid){
		tmp[idx++] = arr[l++];
	}
	while(r <= right){
		tmp[idx++] = arr[r++];
	}
	for(int i = 0; i < idx; ++i){
		arr[left + i] = tmp[i];
	}
}