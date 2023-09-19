#include <iostream>

struct Link
{
    int value;
    Link* next = nullptr;
};

size_t size(const Link* head){
    size_t size = 0;
    while(head != nullptr){
        size++;
        head = head->next;
    }
    return size;
}

size_t sum(const Link* head){
    size_t sum = 0;
    while(head != nullptr){
        sum += head -> value;
        head = head->next;
    }
    return sum;

}

int main(){
    Link head = {5};
    Link robo = {3};
    Link obornicka = {2};
    head.next = &robo;
    robo.next = &obornicka;
    std::cout<<size(&head)<<std::endl;
    std::cout<<sum(&head)<<std::endl;
}
