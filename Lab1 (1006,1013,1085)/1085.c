#include <stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d",&a,&b,&c);
    for (int i=a;i<=c;i=i+b)
    {
        printf("C=%d->F=%d\n",i,d=(i*1.8+32));
    }
}
