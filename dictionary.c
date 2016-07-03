#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
struct node {
             
               int end;
            struct node* links[26];
               }; 


int getindex(char c);
   
void linkup(struct node *root_temp,char c,int ind,char words[]);
void print(struct node *root_print);	  

void getwhere(struct node *root_where,char words[],int ind);
void check(struct node *root_check,char s[],int ind) ;
void main()
{
    int i,j,ind;
 struct node *root ;
 root= (struct node*)malloc(sizeof(struct node));
 
 char word[MAX];
 int num,length,index;     
 ind=0;
  for(i=0;i<26;i++)
   {
 
   root->links[i]=NULL;
   /*  printf("%d",root->links[i]);
  */ }
    root->end=1;
   /* printf("%d",*root);
    printf("\n%d",root);
    */
	
	  printf("enter no. of words to be loaded in dictionary		");
     scanf("%d",&num);
         for(i=0;i<num;i++)
         {
 
         printf("enter word to be loaded			");
         scanf("%s",word);       
	
	 


           length=strlen(word);
     

          
         index=getindex(word[ind]);
    	 if(root->links[index]==NULL)
         {
           /*printf("%d",root);	*
		 
		 struct node *temp = (struct node*)malloc(sizeof(struct node));
          temp->end=1;
           for(j=0;j<26;j++)
          {
 
            temp->links[j]=NULL;
          }
		  root->links[index]=temp;
          root->end=0;*/
         linkup(root,word[ind],ind,word);
         }
		 
		 
		  else{
		  
		   getwhere(root->links[index],word,ind+1);
		  }

         
          
            

         }



while(1)
{
	printf("\nenter the word to check\t");
	scanf("%s",word);
	
	
	check(root,word,ind);
    


}

 





print(root);
}

int getindex(char c)
{
int index;
/* printf("\nthe char is %c",c);*/
 if(((int)c>=65&&(int)c<=90)||((int)c>=97&&(int)c<=122))
 {
 	
 	
index=(int)c;
    if(((int)c>=65&&(int)c<=90))
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









void linkup(struct node *root_temp,char c,int ind,char words[])
{


int i,index;
        
        
        
        
        
        
        if(ind<=strlen(words)-1)
      {	
	       index=getindex(c);
     /*    printf("%d",index);*/
      
	  
	      struct node *temp = (struct node*)malloc(sizeof(struct node));
           temp->end=1;
            for(i=0;i<26;i++)
          {
 
            temp->links[i]=NULL;
          }
          root_temp->links[index]=temp;
         
		 
		 for(i=0;i<26;i++)
        {
 
  
      /*   printf("\n%d",root_temp->links[i]);*/
        }
		 
		 
		 
		 
		 
		 /* printf("\n%d",root_temp->links[index]->end);*/
		  root_temp->end=0;  
          /*printf("\n%d",root_temp->links[index]->end);*/
         /*printf("%d",index);*/
		
		  
		 linkup(root_temp->links[index],words[ind+1],ind+1,words);
         /*printf("%c %d",words[ind+1],ind+1);*/
          }

          

/*printf("\n%d",root_temp->links[index]->end);*/
   
}




void print(struct node *root_print)
{

int i,j;


/*printf("\n%d",root_print->links[21]->end);
printf("\n%d",root_print->links[21]->links[8]->end);

/*
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

void getwhere(struct node *root_where,char words[],int ind)
{
int index,j;
     if(ind<=strlen(words)-1)
     {

       index=getindex(words[ind]);

           if(root_where->links[index]==NULL)
         {
		 struct node *temp = (struct node*)malloc(sizeof(struct node));
          temp->end=1;
           for(j=0;j<26;j++)
          {
 
            temp->links[j]=NULL;
          }
		  root_where->links[index]=temp;
         /*  root_where->end=0;*/
         
         linkup(root_where->links[index],words[ind+1],ind+1,words);
		
		 }

         else{
     
	         getwhere(root_where->links[index],words,ind+1);
	         }       

         
      }

    else{
       
	   root_where->end=1; 
	   
	   }


}



void check(struct node *root_check,char s[],int ind)
{
int length,index;
char c;
length=strlen(s);
c=s[ind];
index=getindex(c);


 if(root_check->links[index]==NULL)
{
	printf("word is misspelled");

}


else if(root_check->links[index]->end==0&&ind==strlen(s)-1 )
{

printf("word is  misspelled");

}









else if(root_check->links[index]!=NULL&&ind!=strlen(s)-1)
{

check(root_check->links[index],s,ind+1);
}
 

}



