#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 50
struct node {
             
               int end;
            struct node* links[26];
               }; 


int getindex(char c);
void linkup(struct node *root_temp,char c,int ind,char words[]);
void print(struct node *root_print);
void main()
{


struct node *root = (struct node*)malloc(sizeof(struct node));
 int i,j,ind;
 char word[MAX];
 int num,length,index;     
 ind=0;
  for(i=0;i<26;i++)
   {
 
   root->links[i]=NULL;
   }
    root->end=1;

printf("%d",root->end);







        printf("enter no. of words to be loaded in dictionary		");
     scanf("%d",&num);
     for(i=0;i<num;i++)
     {
 
        printf("enter word to be loaded			");
        scanf("%s",word);       
	
	 


           length=strlen(word);
     

          
         index=getindex(word[ind]);
           printf("index is %d",index);
      
     
	    if(root->links[index]==NULL)
         {
		 
		 
		 struct node *temp = (struct node*)malloc(sizeof(struct node));
          temp->end=1;
           for(j=0;j<26;j++)
          {
 
            temp->links[j]=NULL;
          }
		  root->links[index]=temp;
          root->end=0;
         linkup(root,word[ind],ind,word);
         }
		 
	 
	 }





print(root);





}















void linkup(struct node *root_temp,char c,int ind,char words[])
{


int index,i;
            
    /*printf("\n%d",root_temp->end);*/
	  if(ind<=strlen(words)-1)
      {
	   
	     
	     index=getindex(c);
        
		 struct node *temp = (struct node*)malloc(sizeof(struct node));
           temp->end=1;
            for(i=0;i<26;i++)
          {
 
            temp->links[index]=NULL;
          }

		  root_temp->links[index]=temp;
       /*  printf("\n%d",root_temp->links[index]->end);
		 /*printf("\n%d",root_temp->links[index]->end);  */
          root_temp->end=0;  
          
         linkup(root_temp->links[index],words[ind+1],ind+1,words);
        /* printf("%c %d",words[ind+1],ind+1);*/
          }

   
         


}




void print(struct node *root_print)
{

int i,j;
printf("printed is\n");
printf("%d",root_print->end);
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

