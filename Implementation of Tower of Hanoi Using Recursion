#include<stdio.h>
void emp(int n,char S, char D, char A)
{
 if(n==1)
 {
  printf("\nMove %d From %c to %c",n,S,D);
  return;
 }
 emp(n-1,S,A,D);
 printf("\nMove %d From %c to %c",n,S,D);
 emp(n-1,A,D,S);
}
int main()
{
 int n;
 char S,D,A;
 printf("Enter the No.of Disks:");
 scanf("%d",&n);
 printf("\n Required moves : \n");
 emp(n,'S','D','A');
 return 0;
}
