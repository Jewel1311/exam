#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int data;
    struct node *next;
};

struct node *head=NULL, *temp,*newnode;
void insbeg(){
    int n;
    printf("Enter the data : ");
    scanf("%d",&n);
    newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = n;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }   
    else{
        newnode->next = head;
        head = newnode;
    }
}
int count(){
    int c=0;
    temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}
void insend(){
    printf("%d",count());
    int val;
    printf("enter the value: ");
    scanf("%d",&val);
    newnode= (struct node*)malloc(sizeof(struct node));
    temp=head;
    newnode->data=val;
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    
    }
     temp->next=newnode;
    

}

void inspos(){
    int val,pos;
    printf("enter the position: ");
    scanf("%d",&pos);
    if(pos==1){
        insbeg();
      }
    else if(pos>1 && pos< count()){       
        temp=head;
        int val;
        printf("enter the data: ");
        scanf("%d",&val);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->next=NULL;
        int p = 1;
        while(p<pos-1){
            temp=temp->next;
            p++;
            
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else if(pos==count()){
        insend();

    }
    else{
        printf("invalid position");
    }

}
void traversal(){
    if(head == NULL){
        printf("empty");
    }
    else{
        temp = head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}
void delbeg(){
    temp=head;
    head=head->next;
    printf("%d is deleted",temp->data);
    free(temp);

}
void delend(){
    if(head== NULL){
        printf("no elements to delete! ");
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;

    }
        printf("%d is deleted",temp->next->data);
         temp->next=NULL;
    }

}
void delpos(){
    int  pos,val;
    printf("enter the position: ");
    scanf("%d",&pos);
    int c=1;
    if(pos==c){
        delbeg();
    }
    else if (pos>c &&pos < count()){
        temp=head;
        while(c<pos-1){
        temp=temp->next;
        c++;
        }
        printf("%d is deleted",temp->next->data);
        temp->next=temp->next->next;

    }
    
}
void search(){
    int n;
    printf("Enter the data to search :");
    scanf("%d",&n);
    int f = -1;
    temp = head;
    while(temp!=NULL){
        if(temp->data == n){
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if(f == 1){
        printf("Element found");
    }
    else{
    printf("Element not found");
    }
}

void main(){
    int choice;
    while(1){
        printf("\n--------------------------------------------\n");
        printf("\n1.Insertion beg\n2.Insertion postion\n3.Insertion end\n4.Traversal\n5.Deletion beg\n6.Deletion end\n7.Deletion pos\n8.Search\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insbeg();
                    break;
            case 2: inspos();
                    break;
            case 3: insend();
                    break;
            case 4: traversal();
                    break;
            case 5: delbeg();
                    break;
            case 6: delend();
                    break;
            case 7: delpos();
                    break;
            case 8: search();
                    break;
            case 9: exit(0);
                    break;
            default: 
                    printf("Invalid Choice");
        }
    }
}