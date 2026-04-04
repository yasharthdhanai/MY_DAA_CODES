#include<bits/stdc++.h>
using namespace std;

//  Add 2 linked list. 1->2->3 and 4->5->6 should give 5->7->9. (leetcode Q445)
// 9->9->9 and 9->9 should give 1->0->0->8. 
typedef struct node{
    int data;
    node* next;
}SN;

void createll(SN* &head){
    int n;
    cin >> n;
    SN* temp = head;
    for(int i=0 ; i<n ; i++){
        int val;
        cin >> val;
        SN* newnode = new SN();
        newnode->data = val;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

SN* add(SN* head1, SN* head2){
    SN* temp1 = head1;
    SN* temp2 = head2;
    SN* head3 = NULL;

    // FIRST REVERSE BOTH LINKED LISTS.
    SN* curr = new SN();
    SN* next = new SN();
    SN* prev = new SN();
    curr = head1;
    next = NULL;
    prev = NULL;
    while(temp1 != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        temp1 = temp1->next;
    }
    head1 = prev; 
    curr = head2;
    next = NULL;
    prev = NULL;
    while(temp2 != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        temp2 = temp2->next;
    }
    head2 = prev; 
    next = NULL;
    prev = NULL;
    // NOW ADD BOTH LINKED LISTS ARE REVERSED.
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL || carry){
        int sum = carry;
        if(temp1 != NULL){
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if(temp2 != NULL){
            sum += temp2->data;
            temp2 = temp2->next;
        }
        SN* newnode = new SN();
        newnode->data = sum % 10;
        newnode->next = head3;
        head3 = newnode;

        carry = sum / 10;
    }

    return head3;
}

int main(){
    SN* head1 = NULL;
    SN* head2 = NULL;
    SN* head3 = NULL;

    createll(head1);
    createll(head2);

    head3 = add(head1, head2);

    while(head3 != NULL){
        cout << head3->data << " ";
        head3 = head3->next;
    }
    
    return 0;
}