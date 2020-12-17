#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long k = 10000000, i, count = 0;
    double z, pi, x, y;
    int it=1;
	printf("The execution time are\nSize\t\t\t\t1\t\t\t2\t\t\t\t4\t\t\t\t8\n");
	while(it<=4){
		int n = 10000000*it, i, j, sum =0, k;
        srand(omp_get_wtime());
        printf("%d\t\t",n);
        for(int p=1;p<=8;p=p*2)
		{
            double starttime = omp_get_wtime();
            count=0;
            #pragma omp for parallel private(x,y,z) num_threads(p)
            //#pragma omp parallel for
            for (i = 0; i < n; i++)
            {
                x = (double)rand() / RAND_MAX;
                y = (double)rand() / RAND_MAX;
                z = x * x + y * y;
                if (z <= 1)
                    count++;
            }

            pi = (double)count / n * 4;
            double finishtime = omp_get_wtime();

            //printf("# of trials= %d , estimate of pi is %g \n", n, pi);
            printf("%lf \t\t",(double)(finishtime - starttime));
            //printf("\n# of trials= %d , estimate of pi is %g \n", n, pi);
        }
        //printf("\n# of trials= %d , estimate of pi is %g \n", n, pi);
        printf(" estimate of pi is %g",pi);
        printf("\n");
        it++;
    }
    return 0;
}
