#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 30
int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
int c6=0;
int c7=0;
int c8=0;
int c9=0;
int c10=0;
int c11=0;
int c12=0;

typedef struct reserve{
    char name[20];
    int c_no;
    int time;
    int date;
    int num_g;
    struct reserve* llink;
    struct reserve* rlink;
    // struct menuitem* order;
} Reserve;
typedef struct DLIST{
    Reserve * head;
    int no_Reserves;
}DLIST;
DLIST* init()
{
    DLIST* temp=malloc(sizeof(DLIST));
    temp->head=NULL;
    temp->no_Reserves=0;
    return temp;
    
}
typedef struct menuitem{
 int data;
 float price;
 int quan;
 char fname[200];
 struct menuitem* next;

}menuitem;
typedef struct llist
{
    menuitem* head;
}LLIST;
void init_sll(LLIST* ptr)
{
    ptr->head=NULL;
}
void insert(LLIST*ptr)
{
    menuitem* temp=malloc(sizeof(menuitem));
    if(temp!=NULL)
    {
        printf("Enter corresponding food code:\n");
        scanf("%d",&temp->data);
        if(temp->data==1)
        {
            strcpy(temp->fname,"Truffle Infused Mushroom Crostini");
        }
        else if(temp->data==2)
        {
            strcpy(temp->fname,"Crispy Calamari with Lemon Aioli");
        }
        else if(temp->data==3)
        {
            strcpy(temp->fname,"Spinach and Artichoke Stuffed Phyllo Cups");
        }
        else if(temp->data==4)
        {
            strcpy(temp->fname,"Grilled Salmon with Mango Salsa");
        }
        else if(temp->data==5)
        {
            strcpy(temp->fname,"Filet Mignon with Red Wine Reduction");
        }
        else if(temp->data==6)
        {
            strcpy(temp->fname,"Vegetarian Risotto with Truffle Oil");
        }
        else if(temp->data==7)
        {
            strcpy(temp->fname,"Chocolate Lava Cake with Raspberry Coulis");
        }
        else if(temp->data==8)
        {
            strcpy(temp->fname,"Tiramisu with Espresso Drizzle");
        }
        else if(temp->data==9)
        {
            strcpy(temp->fname,"Mango Panna Cotta with Fresh Berries");
        }
        else{
            printf("Invalid food code\n");
        }
        temp->next=NULL;
        printf("Enter the quantitiy\n");
        scanf("%d",&temp->quan);
        if(temp->data==1)
        {
            temp->price=350;
        }
        else if(temp->data==2)
        {
            temp->price=420;
        }
        else if(temp->data==3)
        {
            temp->price=380;
        }
        else if(temp->data==4)
        {
            temp->price=650;
        }
        else if(temp->data==5)
        {
            temp->price=850;
        }
        else if(temp->data==6)
        {
            temp->price=480;
        }
        else if(temp->data==7)
        {
            temp->price=320;
        }
        else if(temp->data==8)
        {
            temp->price=380;
        }
        else if(temp->data==9)
        {
            temp->price=200;
        }
        else{
            printf("Invalid food code\n");
        }
    }
    temp->next=ptr->head;
    ptr->head=temp;
    
}

void display_fooditem(LLIST*ptr)
{
if(ptr->head==NULL)
    {
        printf("No ordering done\n");
    }
    else{
        menuitem* curr=ptr->head;
        while(curr!=NULL)
        {
            printf("%d. ",curr->data);
            printf("%s\t",curr->fname);
            printf("Quantity:%d\t",curr->quan);
            printf("Rs.%.2f",curr->price);
            printf("\n");
            curr=curr->next;
        }
    }
    printf("*********************************\n");
}
typedef struct queue{
    int q[MAX];
    int front;
    int rear;
}QUEUE;
void initQueue(QUEUE*pq)
{
    pq->front=0;
    pq->rear=-1;
}
int isEmpty(QUEUE*pq)
{
   return (pq->front>pq->rear);
}
int isFull(QUEUE*pq)
{
    return (pq->rear==MAX-1);
}
void enqueue(QUEUE* pq, int ele)
{
    if (!isFull(pq))
    {
        pq->rear++;
        pq->q[pq->rear] = ele;
    }
    else
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
}

int dequeue(QUEUE*pq)
{
   int e=pq->q[pq->front];
   pq->front++;
   return e;
   //return pq->q[pq->front++];
}
void find(QUEUE*pq)
{

    int total=0;
    int t=0;
        while(!isEmpty(pq))
        {
            // printf("%d\t",pq->q[i]);
            total+=dequeue(pq);
        }
    printf("Your total bill is Rs. %d\n",total);
}
void find_total(LLIST* ptr, QUEUE* pq)
{
    if (ptr->head == NULL)
    {
        printf("No preordering done\n");
    }
    else
    {
        menuitem* curr = ptr->head;
        while (curr != NULL)
        {
            int c = curr->price * curr->quan;
            enqueue(pq, c);
            curr = curr->next;
        }
        find(pq);
    }
}
void modify_fooditem(LLIST*ptr)
{
    display_fooditem(ptr);
    printf("\nEnter the food code of the item you want to modify\n");
    int x;
    scanf("%d",&x);
    int y;
    printf("Enter the new quantity\n");
    scanf("%d",&y);
    menuitem*curr=ptr->head;
    while(curr!=NULL)
    if(curr->data==x){
        curr->quan=y;
        printf("Successfully modified\n");
        break;
    }
    else{
        curr=curr->next;
    }
    printf("*********************************\n");
}
void delete_fooditem(LLIST* ptr)
{
    display_fooditem(ptr);
    int d;
    printf("\nEnter the food code of the itme that you want to delete\n");
    scanf("%d",&d);
    menuitem*curr=ptr->head;
    menuitem*prev=NULL;
    if(curr->data==d){
        ptr->head=curr->next;
        free(curr);
    }
    else{
    while(curr!=NULL)
    if(curr->data==d){
        prev->next=curr->next;
        free(curr);
        break;
    }
    else{
        prev=curr;
        curr=curr->next;
    }
    }
    printf("*********************************\n");
}
menuitem* prebook(LLIST*ptr){
    //menuitem* result = NULL;
    int quit=1;
    while(quit){
    printf("Appetizers:\n");
    printf("1. Truffle Infused Mushroom Crostini\t\t\t350Rs \n");
    printf("2. Crispy Calamari with Lemon Aioli\t\t\t420Rs\n");
    printf("3. Spinach and Artichoke Stuffed Phyllo Cups\t\t380Rs\n\n");
    printf("Main Courses:\n");
    printf("4. Grilled Salmon with Mango Salsa\t\t\t650Rs\n");
    printf("5. Filet Mignon with Red Wine Reduction\t\t\t850Rs\n");
    printf("6. Vegetarian Risotto with Truffle Oil\t\t\t480Rs\n\n");
    printf("Desserts:\n");
    printf("7. Chocolate Lava Cake with Raspberry Coulis\t\t320Rs\n");
    printf("8. Tiramisu with Espresso Drizzle\t\t\t380Rs\n");
    printf("9. Mango Panna Cotta with Fresh Berries\t\t\t300Rs\n");
    printf("\n");
    printf("1. Insert item\n");
    printf("2. Modify quantity\n");
    printf("3. Delete item\n");
    printf("4. Display\n");
    printf("5.Exit\n");
    int ch;
    printf("Enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: insert(ptr);
        break;
        case 2: modify_fooditem(ptr);
        break;
        case 3: delete_fooditem(ptr);
        break;
        case 4:display_fooditem(ptr);
        break;
        case 5:
                printf("Exiting menu\n");
                quit=0;
                break;
        default: printf("Enter valid input\n");
    }
}
}
int make_reservation(DLIST *ptr) 
{
    Reserve* temp = malloc(sizeof(Reserve));

    if (temp != NULL) {
        printf("Enter name:\n");
        scanf("%s", temp->name);
        printf("Enter Contact Number:\n");
        scanf("%d", &temp->c_no);
        printf("Choose a date:\n");
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("1. Today: %d-%02d-%02d\n",  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("2. Tomorrow: %d-%02d-%02d\n",  tm.tm_mday+1, tm.tm_mon + 1, tm.tm_year + 1900);
        // printf("1. Today\n");
        // printf("2. Tomorrow\n");
        scanf("%d", &temp->date);
        printf("Choose a time:\n");
        printf("1. 12PM - 2PM\n");
        printf("2. 2PM - 4PM\n");
        printf("3. 4PM - 6PM\n");
        printf("4. 6PM - 8PM\n");
        printf("5. 8PM - 10PM\n");
        printf("6. 10PM - 12AM\n");
        scanf("%d", &temp->time);
        printf("Enter the number of guests\n");
        scanf("%d", &temp->num_g);

        // Check if the chosen time slot is available
        int* current_slot;
        if (temp->date == 1) {
            current_slot = (temp->time == 1) ? &c1 : 
                           (temp->time == 2) ? &c2 : 
                           (temp->time == 3) ? &c3 : 
                           (temp->time == 4) ? &c4 : 
                           (temp->time == 5) ? &c5 : 
                           (temp->time == 6) ? &c6 : NULL;
        } else if (temp->date == 2) {
            current_slot = (temp->time == 1) ? &c7 : 
                           (temp->time == 2) ? &c8 : 
                           (temp->time == 3) ? &c9 : 
                           (temp->time == 4) ? &c10 : 
                           (temp->time == 5) ? &c11 : 
                           (temp->time == 6) ? &c12 : NULL;
        } else {
            printf("Invalid date\n");
            free(temp);
            return 0;
        }

        if (current_slot == NULL || (*current_slot + temp->num_g) > 10) {
            printf("Sorry!! We are full..\n");
            printf("Next User\n");
            free(temp);
            return 0;
        }

        // Update the slot count
        *current_slot += temp->num_g;

        temp->rlink = temp->llink = NULL;

        if (ptr->head == NULL) {
            ptr->head = temp;
        } else {
            Reserve* first = ptr->head;
            temp->rlink = first;
            first->llink = temp;
            ptr->head = temp;
        }

        ptr->no_Reserves++;
        return 1;

    }

    return 0;
}
void display(DLIST *ptr)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
        
        
    if(ptr->head==NULL)
    {
        printf("No reservation made\n");
    }
    else{
        Reserve*curr=ptr->head;
        while(curr->rlink!=NULL)
        {
            curr=curr->rlink;
        }
    
            printf("Name:%s\n",curr->name);
            printf("Contact number:%d\n",curr->c_no);
            printf("Time:");
            int tr=curr->time;
            if(tr==1)
            {
                printf("12PM-2PM\n");
            }
            else if(tr==2)
            {
                printf("2PM-4PM\n");
            }
            else if(tr==3)
            {
                printf("4PM-6PM\n");
            }
            else if(tr==4)
            {
                printf("6PM-8PM\n");
            }
            else if(tr==5)
            {
                printf("8PM-10PM\n");
            }
            else{
                printf("10PM-12AM\n");
            }
            if(curr->date==1)
            {
            printf("Date: %d-%02d-%02d\n",  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        
            }
            else{
                printf("Date: %d-%02d-%02d\n",  tm.tm_mday+1, tm.tm_mon + 1, tm.tm_year + 1900);
            }
            printf("Number of guests:%d\n",curr->num_g);
        
    }
    printf("\n");
}


void modify(DLIST* ptr)
{
    Reserve*temp=ptr->head;
    int ch=1;
    while(temp->rlink!=NULL  && temp!=NULL)
    {
        temp=temp->rlink;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
        
        
    while(ch)
    {
    printf("1. Name\n2. Contact number\n3. Time\n4. Date\n5. Number of guests\n");
    int y=0;
    scanf("%d",&y);
    
    switch(y)
    {
        case 1: 
        printf("Enter name:\n");
        scanf("%s",temp->name);
        break;
        case 2:
        printf("Enter Contact Number:\n");
        scanf("%d",&temp->c_no);
        break;
        case 3:
        printf("Choose a time:\n");
        printf("1. 12PM - 2PM\n");
        printf("2. 2PM - 4PM\n");
        printf("3. 4PM - 6PM\n");
        printf("4. 6PM - 8PM\n");
        printf("5. 8PM - 10PM\n");
        printf("6. 10PM - 12AM\n");
        scanf("%d",&temp->time);
        break;
        case 4:
        printf("1. Today: %d-%02d-%02d\n",  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("2. Tomorrow: %d-%02d-%02d\n",  tm.tm_mday+1, tm.tm_mon + 1, tm.tm_year + 1900);
        scanf("%d",&temp->date);
        break;
        case 5:
        printf("Enter the number of guests\n");
        int u=temp->num_g;
        scanf("%d",&temp->num_g);
        if(temp->num_g>10)
        {
            printf("Sorry!! We are full..\n");
            printf("Next User\n");
            temp->num_g=u;
        }
        else
        {
        int x=temp->date;
        int y=temp->time;
        int* current;
        if (x == 1) {
            current = (y == 1) ? &c1 : 
                           (y == 2) ? &c2 : 
                           (y == 3) ? &c3 : 
                           (y == 4) ? &c4 : 
                           (y == 5) ? &c5 : 
                           (y == 6) ? &c6 : NULL;
        } else if (x == 2) {
            current = (y == 1) ? &c7 : 
                           (y == 2) ? &c8 : 
                           (y == 3) ? &c9 : 
                           (y == 4) ? &c10 : 
                           (y == 5) ? &c11 : 
                           (y == 6) ? &c12 : NULL;
        }
        *current-=u;
        *current+=temp->num_g;
        if (current == NULL || (*current > 10)) {
            printf("Sorry!! We are full..\n");
            printf("Next User\n");
            free(temp);
           continue;
        }
        }
        break;
        default:printf("Enter valid input\n");
    }    
    display(ptr);
    printf("Do you want to do another modification(Enter 1 if yes and 0 if no)\n");
    while(1)
    {
        scanf("%d",&ch);
        if(ch==0 || ch==1)
        {
            break;
        }
        else{
            printf("Invalid input.Try again\n");
        }
    }
    }
}
    

void delete(DLIST*ptr)
{
    Reserve* first=ptr->head;

    while(first->rlink!=NULL)
    {
        first=first->rlink;
    }
    int x=first->date;
    int y=first->time;
    int* current;
        if (x == 1) {
            current = (y == 1) ? &c1 : 
                           (y == 2) ? &c2 : 
                           (y == 3) ? &c3 : 
                           (y == 4) ? &c4 : 
                           (y == 5) ? &c5 : 
                           (y == 6) ? &c6 : NULL;
        } else if (x == 2) {
            current = (y == 1) ? &c7 : 
                           (y == 2) ? &c8 : 
                           (y == 3) ? &c9 : 
                           (y == 4) ? &c10 : 
                           (y == 5) ? &c11 : 
                           (y == 6) ? &c12 : NULL;
        }
        *current-= first->num_g;

        free(first);
        ptr->head=NULL;
        ptr->no_Reserves--;  
    printf("Your reservation has been successfully deleted\n");
}
int main()
{
    
    int del=0;
    int ch=1;
    
    while(ch){
        DLIST *ptr=init();
     LLIST mtr;
    init_sll(&mtr);
    printf("--------------------------------------------------------\n");
    printf("           WELCOME TO RESTAURANT \n");
    printf("--------------------------------------------------------\n\n");
    printf("Appetizers:\n");
    printf("1. Truffle Infused Mushroom Crostini\t\t\t350Rs \n");
    printf("2. Crispy Calamari with Lemon Aioli\t\t\t420Rs\n");
    printf("3. Spinach and Artichoke Stuffed Phyllo Cups\t\t380Rs\n\n");
    printf("Main Courses:\n");
    printf("4. Grilled Salmon with Mango Salsa\t\t\t650Rs\n");
    printf("5. Filet Mignon with Red Wine Reduction\t\t\t850Rs\n");
    printf("6. Vegetarian Risotto with Truffle Oil\t\t\t480Rs\n\n");
    printf("Desserts:\n");
    printf("7. Chocolate Lava Cake with Raspberry Coulis\t\t320Rs\n");
    printf("8. Tiramisu with Espresso Drizzle\t\t\t380Rs\n");
    printf("9. Mango Panna Cotta with Fresh Berries\t\t\t300Rs\n");
    
        printf("Do you want to reserve a table(Enter 1 if yes and 0 if no)\n");
        int x;
        scanf("%d",&x);
        if(x==1){
            if(!make_reservation(ptr))
            {continue;}
            else{
            printf("Do you want to modify your table reservation(Enter 1 if yes and 0 if no)\n");
            while(1){
                int z;
                scanf("%d",&z);
                if(z==1)
                {
                    modify(ptr);
                    break;
                }
                else if(z==0)
                {
                    printf("Alright!! Continue your booking\n");
                    break;
                }
                else{
                    printf("Invalid input\n");
                }
            }
            printf("Do you want to prebook your food(Enter 1 if yes and 0 if no)\n");
            while(1){
                int z;
                scanf("%d",&z);
                if(z==1)
                {
                    
                    Reserve*temp=ptr->head;
                    while(temp!=NULL)
                    {
                        temp=temp->rlink;
                    }
                    prebook(&mtr);
                    break;
                }
                else if(z==0)
                {
                
                    printf("Alright!! Continue your booking\n");
                    break;
                }
                else{
                    printf("Invalid input\n");
                }
            }
            printf("Do you want to delete your reservation(Enter 1 if you want to delete and 0 if not)\n");
            while(1){
                int z;
                scanf("%d",&z);
                if(z==1)
                {
                    delete(ptr);
                    del=1;
                    break;
                }
                else if(z==0)
                {
                    //printf("Thankyou \n");
                    break;
                }
                else{
                    printf("Invalid input\n");
                }
            }
        }
        }
        else if(x==0){
            printf("Thank you\n");
            printf("Next user\n");
            continue;
        }
        else{
            printf("Invalid input\n");
        }
    printf("\n");
    if(del==1)
    {
        printf("Come again!!\n");
    }
    else{
        printf("Your reservation details\n");
        display(ptr);
        printf("Your order details\n");
        display_fooditem(&mtr);
        QUEUE qobj;
        initQueue(&qobj);
        find_total(&mtr,&qobj); 
    }
    
    printf("****************************************************************\n");
    printf("\n");
    printf("Next user\n");
    printf("Do you want to make a reservation\n");
    scanf("%d",&ch);
    }
    }