#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char c;
    int numofchar;
    struct node *next;
} node;

node *createnode(char c){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->c = c;
    newnode->numofchar = 1;
    newnode->next = NULL;
    return newnode;
}
int tabcount = 0;
node *findninsert(char c, node *head){

    if(head == NULL){
        return createnode(c);
    }else{
        node *temp = head;
        node *prev = NULL;
        while(temp != NULL){
            
            if(temp->c == c){
                temp->numofchar++;
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = createnode(c);
        return head;
    }
}

void printll(node *head) {
    for (node *temp = head; temp != NULL ; temp = temp->next) {
        if(temp->c == '\n'){
            printf("\\n : %d\n", temp->numofchar);
        }else if(temp->c == ' ') {
            printf("' ' : %d\n", temp->numofchar);
        }else if(temp->c == '\t') {
            printf("\\t : %d\n", temp->numofchar);
        }else{
            printf("%c  : %d\n", temp->c, temp->numofchar);
        }
    }
}

int main() {
    FILE *file = fopen("main.c", "r"); 

    if (file == NULL) {
        perror("File opening failed");
        return 1;
    }
    
    node *head = NULL;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        head = findninsert((char)ch, head);
    }
    
    fclose(file);
    
    printll(head);
    
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}
