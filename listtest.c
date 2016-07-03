#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
             
               int end;
            struct node* links[26];
               }; 

void print(struct node *root_print);
void main()
{
	int i;
struct node *root = (struct node*)malloc(sizeof(struct node));
 for(i=0;i<26;i++)
   {
 
   root->links[i]=NULL;
   }
    root->end=1;
struct node *temp ;
temp= (struct node*)malloc(sizeof(struct node));
temp->end=1;
root->links[0]=temp;
/*printf("%d",root->links[0]->end);*/

print(root);
}



void print(struct node *root_print)
{

int i,j;

printf("\n%d",root_print->links[0]->end);
/*printf("%d",root_print->links[0]->end);
/*printf("%d",root_print->links[0]->links[0]->end);
*//*

 for(i=0;i<26;i++)
 {

    

    if(root_print->links[i]!=NULL)
   {  
    
	printf("%c",i+97);
    print(root_print->links[i]);
    }
   
   
  }
  if(root_print->end==1)
  {
  
  printf("\n");
  } 
*/
}


