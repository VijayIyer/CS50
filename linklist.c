#include<stdio.h>

void main()
{
struct node {
    int val;
    struct node *next[2];
};


struct node *root = (struct node*)malloc(sizeof(struct node));
root->val = 20;
root->next[1] = NULL;

printf("%d",root->val);
struct node *root1 = (struct node*)malloc(sizeof(struct node));
struct node *root2 = (struct node*)malloc(sizeof(struct node));
root1->val=50;
root2->val=100;
root->next[1]=root1;
root->next[2]=root2;
printf("\n%d",root->next[1]);

printf("\n%d",root1);
printf("\n%d",root->next[2]->val);
printf("\n%d",root2->val);

root1->next[1]=NULL;

}
