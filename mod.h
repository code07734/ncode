//#include <intrin.h>
//#include <immintrin.h>
void mod(uint64_t *x, uint64_t div){
	uint64_t hbit,xbit,n=*x,c=1,mask,rem,num,coeff;
	_BitScanReverse(&hbit,div);
	hbit+=1;
	mask=(1<<hbit)-1;
	coeff=mask+1-div;
	if(n<(2*div)){c=0;}
	while(c!=0){
		//_BitScanReverse(&xbit,n);
		//n-=(div<<(xbit-hbit));
		rem=n&mask;
		num=n>>hbit;
		n=(coeff*num)+rem;
		if(2*div<n && n<(3*div)){c=0;n-=div;}
		if(n<(2*div)){c=0;}
		printf("%lld\n", n);
	}
	if(n>div){n-=div;}
	if(n==div){n=0;}
	
	*x=n;
}

void qmod(uint64_t *x, uint64_t div){
	uint64_t hbit,n=*x,c=1,mask,rem,num,coeff;
	_BitScanReverse(&hbit,div);
	hbit+=1;
	mask=(1<<hbit)-1;
	rem=n&mask;
	num=(1<<hbit)-div;
	n>>=hbit;
	while(c!=0){
		rem+=num&(0-(n&1));
		n>>=1;
		num<<=1;
		if(num>=div){num-=div;}
		if(n==0 && rem>=div){n=rem;rem=n&mask;n>>=hbit;num=(1<<hbit)-div;}
		if(n==0){c=0;}
		//printf("%lld %lld\n", n, rem);
	}
	if(rem>=div){rem-=div;}
	*x=rem;
}
