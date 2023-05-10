//PATTERN MATCHING BRUTE FORCE ALGORITHM//

#include<stdio.h>
#include<time.h>
#include<string.h>
int pattern(int s1,int p1,char s[100],char p[100]);
int main()
{
    int i,j;
    int n;
     FILE* fp3,*fp4;
     fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");

     char s[100];
     char p[100];
     printf("ENTER THE STRING\n");
     scanf("%s",&s);
     printf("ENTER THE PATTERN\n");
     scanf("%s",&p);

    int s1=strlen(s);
    printf("%d\n",s1);
    int p1=strlen(p);
    printf("%d\n",p1);

    int P=pattern(s1,p1,s,p);
    if(P==0)
    {
        printf("THE PATTERN IS NOT MATCHED WITH THE STRING\n");

    }
    else
    {
        printf("THE PATTERN %s MATCHED WITH STRING AT POSITION %d",p,P);
    }



    fclose(fp3);
    fclose(fp4);


}
int pattern(int s1,int p1,char s[100],char p[100])
{
    int max=s1-p1+1;
    int i,j,flag;
    for(i=1;i<=max;i++)
    {
        flag=1;
        for(j=1;j<=p1&&flag==1;j++)
        {
            if(p[j]!=s[j+i-1])
               {
                   flag=0;
               }
        }
        if(flag==1)
        {
            return i;
        }
    }
    return 0;
}
