#include<bits/stdc++.h>
using namespace std;

class List{

    int data;
    class List *next;

    public:

        List* newNode(int data){
            List *temp = new List;
            temp->data = data;
            temp->next = NULL;
            return temp;
        }

        void push_front(List** head, List *node){

            if(*head == NULL){
                *head = node;
                return;
            }

            (node)->next = *head;
            *head = node;
        }

        void push_back(List *head, List *node){

            if(head == NULL){
                head = node;
                return;
            }

            List* temp = head;

            while(temp->next !=NULL){
                temp = temp->next;
            }

            temp->next = node;

        }

        void traverse(List * head){

            List* temp = head;

            while(temp != NULL){
                    cout<<temp->data<<endl;
                    temp = temp->next;
            }
        }

};

/* Learning

Insertion at end of LL
Insertion at beginning of LL
We Always need double pointer if we need to change head of a linked list.

*/

int main(){

    List* head;
    List* obj1 = new List();
    head = obj1->newNode(1);
    obj1->push_back(head, obj1->newNode(2));
    obj1->push_back(head, obj1->newNode(3));

    obj1->push_front(&head, (obj1->newNode(-100)));

    obj1->traverse(head);



}
