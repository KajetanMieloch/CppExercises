#include <iostream>

struct Link
{
    int value;
    Link* next = nullptr;
};

void reverse(Link** phead){
    Link* head = *phead;
    Link* prev = nullptr;
    Link* next = nullptr;
    while(head != nullptr){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    *phead = prev;
}

void cout(Link** phead){
    Link* head = *phead;
    while(head != nullptr){
        std::cout<<head->value<<std::endl;
        head = head->next;
    }
}

int main(){
    Link* head = new Link{9};
    Link* spam = new Link{5};
    Link* body = new Link{2};
    Link* face = new Link{1};
    Link* test = new Link{23};
    head->next = spam;
    spam->next = body;
    body->next = face;
    face->next = test;
    reverse(&head);
    cout(&head);
}