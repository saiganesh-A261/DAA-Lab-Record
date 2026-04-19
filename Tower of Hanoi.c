#include<stdio.h>
void toh(int n,char s,char t,char d)
{
    if(n==1)
    {
        printf("Move %d disk from %c to %c \n",n,s,t,d);
        return;
    }
    toh(n-1,s,t,d);
    printf("Move %d disk from %c to %c\n",n,s,t,d);
    toh(n-1,t,d,s);
}
int main()
{
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);
    printf("\n Required moves : \n");
    toh(n,'s','t','d');
    return 0;
}

// Code By @saiganesh-A261
