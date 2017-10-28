#define PRINT1(a) (printf("The value of a is: %.1f\n",a))
#define PRINT2(a,b)(printf("The value of a is: %.1f\nThe value of b is: %.1f\n",a,b))
#define MAX2(a,b) (a>b?a:b)
#define MAX3(a,b,c) (MAX2(MAX2(a,b),c))