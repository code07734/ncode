//#include <intrin.h>
//#include <immintrin.h>
void mod(uint32_t *x, uint32_t div){
	uint32_t bita,n=*x,c=1,mask,mod,num,coeff;
	_BitScanReverse(&bita,div);
	//printf("n=%d\n div=%d\n bita=%d\n", n,div,bita);
	if(n<=div){c=0;}
	while(c>0){
		mask=(1<<(bita+1))-1;
		mod=n&mask;
		if(mod==div){mod=0;}
		num=n>>(bita+1);
		coeff=(1<<(bita+1))-div;
		n=(coeff*num)+mod;
		//printf("mask=%d\n mod=%d\n num=%d\n coeff=%d\n n=%d\n\n", mask,mod,num,coeff,n);
		printf("%d\n", n);
		if(n<=2*div && n>div){c=0;n-=div;}
	}
	if(n==div){n=0;}


	*x=n;
}
