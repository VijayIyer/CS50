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
void load_dict(struct node *root);
void check_dict(struct node *root);

void main()
{
int i,j,ind;
 struct node *root ;
 root= (struct node*)malloc(sizeof(struct node));


load_dict(root);
check_dict(root);
}



void check_dict(struct node *root)
{
char word[MAX];int ind=0;
while(1)
{
	printf("\nenter the word to check\t");
	scanf("%s",word);
	
	
	check(root,word,ind);
    


}

}



void load_dict(struct node *root)
{

    int i,j,ind;
 
 char word[MAX];
 int num,length,index;     
 ind=0;
  for(i=0;i<26;i++)
   {
 
   root->links[i]=NULL;
   }
    root->end=1;
  	
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
         linkup(root,word[ind],ind,word);
         }
		 
		 
		  else{
		  
		   getwhere(root->links[index],word,ind+1);
		  }

         
          
            

         }



}
int getindex(char c)
{
int index;
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
      
	  
	      struct node *temp = (struct node*)malloc(sizeof(struct node));
           temp->end=1;
            for(i=0;i<26;i++)
          {
 
            temp->links[i]=NULL;
          }
          root_temp->links[index]=temp;
         
		 
		 for(i=0;i<26;i++)
        {
 
  
        }
		 
		 
		 
		 
		 
		  root_temp->end=0;  
		
		  
		 linkup(root_temp->links[index],words[ind+1],ind+1,words);
          }

          

   
}
void print(struct node *root_print)
{

int i,j;
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






