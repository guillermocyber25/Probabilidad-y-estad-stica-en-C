double poisson(long x, double k){
	
	if(x == 0)
	   return pow(e, - k);
	
	return ((double)(k / x) * poisson(x - 1, k));
}
