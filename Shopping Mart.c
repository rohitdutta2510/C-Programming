#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	int price, index;
	char name[30];
	struct Node* next;
};
typedef struct Node node;
node* top;

void push(char[], int);
void pop();
void del_sel(int);
void display();

int main(){
    int choice, price, select;
    char name[30];
    do{
        printf("\n ******** Welcome to the Shopping Mart ********\n");
        printf("    1. Add Products to Cart\n");
        printf("    2. Check Out Last added item from the Cart\n");
        printf("    3. Show the last added\n");
        printf("    4. Show the Cart\n");
        printf("    5. Select Product for Check out\n");
        printf("    6. EXIT\n");
        printf("\n   Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("\n Enter item name: ");
                    scanf("%s", name);
                    printf(" Enter price: ");
                    scanf("%d", &price);
                    push(name, price);
                    break;

            case 2: pop();
                    break;

            case 3: printf("\n Last added ---> %s  Rs.%d\n", top->name, top->price);
                    break;

            case 4: display();
                    break;

            case 5: display();
                    printf("\n Enter the index no. to check out :");
                    scanf("%d", &select);
                    del_sel(select);
                    display();
                    break;

            case 6: break;
        }
    }while(choice!=6);
}

void push(char name[30], int price){
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->name,name);
	temp->price = price;
    temp->next = top;
	top = temp;
}

void pop(){
	node* temp;

	if (top == NULL) {
		printf("\n Empty Cart --- No item to check out\n");
	}
	else {
		temp = top;
		top = top->next;
		temp->next = NULL;
        printf("\n Item checked out ---> %s ---- Rs.%d\ns", temp->name, temp->price);
		free(temp);
	}
}

void del_sel(int ch){
    node *temp, *preptr=NULL;
    temp = top;
    int n=1;
    while (temp != NULL) {
        if(ch==1)
            pop();
        else if(n==ch){
            preptr->next = temp->next;
            free(temp);
            break;
        }
        n+=1;
        preptr=temp;
        temp = temp->next;
        }
}

void display(){
	node* temp;
	if (top == NULL) {
		printf("\n Empty Cart\n");
		exit(1);
	}
	else {
		temp = top;
		int n=1;
		printf("\n -------- Your Cart --------\n");
		while (temp != NULL) {
			printf(" %d. %s     Rs. %d\n", n,temp->name,temp->price);
			n+=1;
			temp = temp->next;
		}
		printf(" -----------------------------\n");
	}
}
