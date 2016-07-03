#include<stdio.h>


int MAX=4;

void initialize(int *a,int MAX)
{

int i,j,temp,l,k;




for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
		
		
		
		if(i==0&&j==0)
		{
			printf("enter input(zero for vacant position) at %d,%d\t\t",i,j);
		    scanf("%d",&temp);		
	     
		}
		else
		{
	
		again :	printf("enter input(zero for vacant position) at %d,%d\t\t",i,j);
	    scanf("%d",&temp);		
	     
	       for(l=0;l<MAX;l++)
	       {
		     for(k=0;k<MAX;k++)
	   
         
		      {
		        if((*(a+l*MAX+k))==temp)
		        {
		          printf("%d      %d\n",*(a+l*MAX+k),temp);
		          printf("wrong value entered\n");
		          goto  again;
		        }
		       }		   
		    }
		}
	*(a+i*MAX+j)=temp;
    }
	

}

}

void draw(int *a,int MAX)
{
int i,j;


for(i=0;i<MAX;i++)
{
printf("\n");
for(j=0;j<MAX;j++)
{
			if(*(a+i*MAX+j)==0)
			
			{
			printf("-\t");
			}
			else
			{
			printf("%d\t",*(a+i*MAX+j));
             }


}
}









}





void move(int *a,int MAX)

{

int i,j,row_vac,col_vac,temp,row,col;
int valid;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
	       if((*(a+i*MAX+j))==0)
	        {
	        row_vac=i;col_vac=j;
	        }
	    }
	}
	
	
	
	
again2 :	printf("swap vacant position with ?:		");
	scanf("%d",&temp);
	/*     get position of number to be swapped with         */
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
		if((temp==*(a+i*MAX+j)))
		{
		
		row=i;col=j;
		break;
	     }
		}
		
	}
	
	

/*check if move is valid*/
	if(((row==row_vac && col==col_vac+1)||(row==row_vac && col==col_vac-1)||(row==row_vac-1 && col==col_vac)||(row==row_vac+1 && col==col_vac)))
   { 
         valid=1;
    }
	else
 {
 
        valid=0;
	
	}
	
	
	/*printf("%d",valid);*/
		
	if(valid==1)
	{
	
	temp=*(a+row_vac*MAX+col_vac);
	
	*(a+row_vac*MAX+col_vac)=*(a+row*MAX+col);
	*(a+row*MAX+col)=temp;
    row_vac=row;
    col_vac=col;

   }
	else
  {

	printf("move not valid");
   goto again2;
    }
	


	
	
	
	
	
}


int check_won(int *a,int MAX,int won)
{

int i,j,flag=0;

for(i=0;i<MAX;i++)
{

 for(j=0;j<MAX;j++)

   {
	
     if(i==MAX-1&&j==MAX-1)
     {
	    if(*(a+i*MAX+j)==0)
	     {
		 break;
	     }
     }  



        if(*(a+i*MAX+j)==i*(MAX)+(j+1))
        {
         flag=1;
         }

         else
        {


          flag=0;
          break;
        }






   }  


}





        if(flag==1)

         {
          won=1;
          }




/* print that game is won and exit*/
          if(won==1)
          {
           printf("won");

          }

return(won);
}



int main()
{
	int i,j,won=0;
	
	int mat[MAX][MAX];
	

	for(i=0;i<MAX;i++)
    {
       for(j=0;j<MAX;j++)
     {   
  
        mat[i][j]=-1;
     }
    }
  
  
  initialize(&mat[0][0],MAX);


while(won==0)
{

  draw(&mat[0][0],MAX);
  move(&mat[0][0],MAX);
  draw(&mat[0][0],MAX);
  won=check_won(&mat[0][0],MAX,won);
printf("\n%d",won);
}






return 0;

}







