#include<c++/v1/bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node *create(Node **head, int data){
    Node *node = new Node();
    
    node->data = data;
    node->next = *head;
    *head = node;
    
    return node;
}

void print(Node *head){
    
    int count = 0;
    while(head!=NULL)
    {
        count++;
        cout<<head->data<<"x^"<<count<<" + ";
        head = head->next;
    }
    cout<<endl;
}

void reverseLL(Node** head)
{
    stack<Node*> s;
    Node* temp = *head;
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty()) {

        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int count(Node *head){
    int count = 0;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    
    return count;
}

void addkro(Node *head1, Node *head2, Node **head3){
    
    Node *temp1=head1;
    Node *temp2=head2;

    int c1 = count(head1);
    int c2 = count(head2);

    while(temp1!=NULL || temp2!=NULL){
        if(c1>c2){
            Node *node = new Node();
            
            node->data = temp1->data;
            node->next = *head3;
            *head3 = node;
            
            temp1=temp1->next;
            --c1;
        }
        else if(c1==c2){
            --c1;--c2;
            int value = temp1->data + temp2->data;
            Node *node = new Node();
            
            node->data = value;
            node->next = *head3;
            *head3 = node;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
    }
}


int main(){
    
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    
    head1 = create(&head1,2);
    head1 = create(&head1,5);
    head1 = create(&head1,3);
    head1 = create(&head1,4);
    head1 = create(&head1,1);
    
    head2 = create(&head2,6);
    head2 = create(&head2,5);
    head2 = create(&head2,4);
    head2 = create(&head2,3);
    

    print(head1);
    cout<<"\n\n\n";
    print(head2);
    addkro(head1,head2,&head3);
    
    cout<<"\n\n\n";
    reverseLL(&head3);
    print(head3);
    return 0;
}

