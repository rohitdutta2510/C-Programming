#include<stdio.h>
#include<malloc.h>

struct node{
    int coeff,exp;
    struct node *next;
};
typedef struct node N;
N *start1=NULL, *start2=NULL, *start3=NULL, *ptr, *tail3=NULL;

void addpoly();
N* createpoly(N*);
void display(N*);

int main(){
	int choice;
	do{
		printf("\n 1. Enter the first polynomial\n 2. Enter the second polynomial\n 3. Display the polynomials\n 4. Add & Display\n 5. EXIT\n");
		scanf("%d", &choice);

		switch(choice){
			case 1: start1 = createpoly(start1);
					break;

			case 2: start2 = createpoly(start2);
					break;

			case 3: printf("\n First plynomial: ");
					display(start1);
					printf("\n Second plynomial: ");
					display(start2);
					break;

			case 4: addpoly();
					display(start3);
					break;
		}
	}while(choice!=5);
	return 0;
}

void addpoly(){
    N *temp1, *temp2, *temp3;
    temp1=start1;
    temp2=start2;
    while(temp1!=NULL||temp2!=NULL){
        ptr=(N*)malloc(sizeof(N));
        if(temp1->exp>temp2->exp||temp2==NULL){
        	ptr->coeff = temp1->coeff;
        	ptr->exp=temp1->exp;
        	temp1=temp1->next;
        }
        else if(temp2->exp>temp1->exp||temp1==NULL){
        	ptr->coeff = temp2->coeff;
        	ptr->exp=temp2->exp;
        	temp2=temp2->next;
        }
        else{
        	ptr->coeff = temp1->coeff+temp2->coeff;
        	ptr->exp=temp1->exp;
        	temp1=temp1->next;
        	temp2=temp2->next;
        }
        if(start3==NULL)
        	start3 = tail3 = ptr;
        else{
        	tail3->next=ptr;
        	tail3=ptr;
        }
    }
    tail3->next=NULL;
}


N* createpoly(N* start){
	int exp, coeff, i;
	N* temp = NULL;
	do{
		printf("\nEnter the coefficient: ");
		scanf("%d", &coeff);
		printf("\nEnter the exponent: ");
		scanf("%d", &exp);
		ptr=(N*)malloc(sizeof(N));

		ptr->exp = exp;
		ptr->coeff = coeff;

		if(start==NULL)
			{start = ptr;}
		else{
			temp = start;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=ptr;
		}
		ptr->next = NULL;
		printf("\n Press 1 to continue & 0 to EXIT: ");
		scanf("%d", &i);
	}while(i==1);

	return start;
}

void display(N* start){
	N* temp;
	if(start==NULL)
		printf(" Empty Polynomial \n\n");
	temp=start;
	while(temp!=NULL){
		printf("%d(x^%d)", temp->coeff, temp->exp);
		if(temp->next!=NULL)
			printf(" + ");
		temp=temp->next;
	}
}




















