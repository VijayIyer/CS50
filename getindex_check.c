#include<stdio.h>

int getindex(char c);

void main()
{
char c;int index;
printf("enter char\t");
scanf("%c",&c);
index=getindex(c);
printf("\n%d",index);

}






int getindex(char c)
{
int index;
/* printf("\nthe char is %c",c);*/
 if(((int)c>65&&(int)c<90)||((int)c>97&&(int)c<122))
 {
index=(int)c;
    if(((int)c>65&&(int)c<90))
   {
   index=index-65;
   }
    else
   {

    index=index-97;

   }

  }
return(index);

}




