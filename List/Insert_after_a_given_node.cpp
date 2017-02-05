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

        List* find_with_value(List* head, int data){

            if(head == NULL) return NULL;

            List*temp = head;
            while(temp!=NULL){

                if(temp->data == data){
                    return temp;
                }
                temp = temp->next;
            }

            return NULL;
        }

        void insert_after(List* head, int data, List* node){

            List* temp = find_with_value(head, data);

            if(temp == NULL){
                cout<<"Data not found in the list"<<endl;
                return;
            }

            node->next = temp->next;
            temp->next = node;

        }

        void traverse(List * head){

            List* temp = head;

            while(temp != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
            }
        }

};

/* Learning

Insertion after a given Node.
Need to find while travesing the list and return taht pointer to the node;
TC O(n)  SC O(1)

*/

int main(){

    List* head;
    List* obj1 = new List();
    head = obj1->newNode(1);
    obj1->push_back(head, obj1->newNode(2));
    obj1->push_back(head, obj1->newNode(3));

    obj1->push_front(&head, (obj1->newNode(-100)));

    obj1->insert_after(head, -100, obj1->newNode(100));
    obj1->insert_after(head, 99, obj1->newNode(100));

    cout<<"List "<<":";
    obj1->traverse(head);



}

