#include<stdio.h>
#include<stdlib.h>

//Reverse Linked List Elements

struct node{
	int data;
	struct node* next;
};

struct node* q=NULL;
struct node* start=NULL;
struct node* temp=NULL;

void reverse(){
	
	struct node* temp;
	struct node* prev=NULL;
	
	q=start;
	while(q!=NULL){
		
		temp=q->next;
		q->next=prev;
		prev=q;
		q=temp;
		
	}
	
	
	start=prev;
	
	
	
}
void deleteEnd(){
	
	
	q=start;
	
	while(q->next->next!=NULL){
		q=q->next;
	}
	
	free(q->next);
	q->next=NULL;
	
	
	
	
	
}
void addStart(int data){
	
	struct node* addednode=(struct node*)malloc(sizeof(struct node));
	addednode->data=data;
	addednode->next=start;
	start=addednode;
	
	
	
}
void addedNode(int data,int f_data){
	
	struct node* addednode=(struct node*)malloc(sizeof(struct node));
	addednode->data=data;
	
	q=start;
	
	while(q->next->data!=f_data){
		q=q->next;
	}
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=q->next;
	q->next=addednode;
	addednode->next=temp;
	

}

void printNode(){
	
	
	q=start;

	while(q->next!=NULL){
		printf("%d=>",q->data);
		q=q->next;
	}
	
	printf("%d",q->data);
	
	
}

void startupDelete(){
	
	struct node* secondnode=NULL;
	secondnode=start->next;
	free(start);
	start=secondnode;
	
	
}
void deleteBetween(int data){
	
	q=start;
	if(start->data==data){
		startupDelete();
	}
	while(q->next->data!=data){
		q=q->next;
	}
	
	if(q->next==NULL){
		deleteEnd();
	}
	//Since I will assign other nodes to these nodes, the field will already be created. 
	//I don't need to create a node with malloc.
	struct node* prev=NULL;
	struct node* next=NULL;
	
	prev=q;
	next=q->next->next;
	free(q->next);
	prev->next=next;
	
	
}

int main(){
	
	int addedData;
	int f_data;
	int n;
	int _data;
	
	
	

	while(1){
		
		printf("\n1-Add an element to the beginning\n2-Add an element before another element\n3-Deletes the last element\n4-Deleted startup\n5-Delete element between two elements in linked lists\n6-Reverse Linked List Elements:\n");
	    scanf("%d",&n);
		switch(n){
			case 1:
				printf("\nEnter the value to be added at the start:");
	            scanf("%d",&addedData);
	            addStart(addedData);
	            printNode();
	            break;
	            
	            
	            
	         case 2:
			    printf("\nEnter the value to be added:");
	        	scanf("%d",&addedData);
	        	printf("Which number should be added before:");
	        	scanf("%d",&f_data);
	        	addedNode(addedData,f_data);
		        printNode();  
		        break;
		        
		     case 3:
		     	
			    deleteEnd();
				printNode();  
		        break;  
			
			case 4:
			    
				startupDelete();
				printNode();
				break;	
			
			case 5:
			    
			    
			    printf("\nEnter the data of the node to be deleted:");
			    scanf("%d",&_data);
				deleteBetween(_data);
				printNode();
				break;	
			
			case 6:
			    reverse();
				printNode();
				break;	 
		}
		
		
	}
	
	return 0;
}
