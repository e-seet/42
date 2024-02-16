
#include "utils.h"

void insertSort()
{
	printf("insert sort\n");
	
	// 

}

void mergeSort2()
{
	printf("merge sort\n");
}


// algo to calculate the miin run
int calculate_minrun(int n)
{
    int r = 0;
	// int iter = 0;

    while (n >= 64)
	{
		// printf("iter: %d\n", iter);
        // printf("n value:%d \n", n);
		r = r | (n & 1);
		// printf("r value:%d\n", r);
        n >>= 1;
        // printf("n value:%d \n\n", n);
		// iter ++;
    }
	// printf("final n:%d, final r: %d\n\n", n, r );
    return n + r;
}
