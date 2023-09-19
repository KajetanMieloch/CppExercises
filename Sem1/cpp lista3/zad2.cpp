#include <iostream>

struct Link
{
    int value;
    Link* next = nullptr;
};

void release(Link** phead){
    Link* head = *phead;
    while (head!=nullptr)
    {
        Link* tmp=head;
        std::cout<<head->value<<std::endl;
        head=head->next; 
        delete tmp;
    }
    *phead=nullptr;
}

void relaseRecursively(Link** phead){
    Link* head = *phead;
    if(head!=nullptr){
        std::cout<<head->value<<std::endl;
        relaseRecursively(&head->next);
        delete head;
    }
    *phead=nullptr;
}

int main(){
    std::cout << "relase with while" << std::endl;
    Link* head = new Link{5};
    Link* spam = new Link{3};
    Link* body = new Link{2};
    head->next = spam;
    spam->next = body;
    release(&head);

    
    std::cout << "relase via recursion" << std::endl;
    Link* meat = new Link{5};
    Link* neet = new Link{3};
    Link* good = new Link{2};
    meat->next = neet;
    neet->next = good;
    relaseRecursively(&meat);
}