//Ziyi Tang

int lookup[j];
int MaxRvalue(int j){
	if (j == 0){
		lookup[j] = 0;
		return 0;
	}
	if (lookup[j] != -1){
		return lookup[j];
	}
	else{
		int max = 0;
		for (int i = j; i >= 1; i--){
			int tmp = Sign(i, j)*Weight(i,j) + MaxRvalue(i-1);
			if (tmp > max){
				max = tmp;
			}
		}
		lookup[j] = max;
		return max;
	}
}

int main(){
	// Initialize a lookup table with -1 for all entries.
	memset(lookup, -1, sizeof(lookup)); 
	MaxRvalue(n);
}