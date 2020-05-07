#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

void *aligned_malloc(size_t bytes, size_t alignment)
{
void *p1 ,*p2; // basic pointer needed for computation.

alignment = pow(2,alignment);

if((p1 =(void *) malloc(bytes + alignment + sizeof(size_t)))==NULL)
	return NULL;

printf("ADDR p1: %p  %ld\n",p1,(size_t)p1);

size_t addr=(size_t)p1+alignment+sizeof(size_t); //align and add 8 bytes of size_t maybe metadata

p2=(void *)(addr - (addr%alignment)); //modulo mostly will be 0 so p2 is pointer version of addr

*((size_t *)p2-1)=(size_t)p1;

printf("ADDR p2: %p  %p %ld\n",p2,((size_t *)p2-1),(size_t)p2);

return p2;
}

void aligned_free(void *p )
{
printf("FREE: %p \n",(void *)(*((size_t *) p-1)));
free((void *)(*((size_t *) p-1)));
}

int main()
{
	void *p = aligned_malloc(10,2);
	aligned_free(p);
	return 0;
}

-----------------*************************************----------------------
/*SIZE OF ARRAY*/
	int16_t v[] = {3200,3400,1600,500,1200};
	int16_t i[] = {12,10,-2,-4,5,3,7,2,8,-6};

	int16_t vs = sizeof(v)/sizeof(v[0]);
	int16_t is = sizeof(i)/sizeof(i[0]);

	printf("\n %d  %d \n",vs,is); //size of an array

-----------------*************************************----------------------