#include <delay.h>


void delayms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<600;j++);
	}
}