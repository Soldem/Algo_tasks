#include <iostream>
#include <string>

struct Node {
    char value_;
    Node* next_;

    Node(char value, Node* next);
};

class LinkedList {
private:
    Node* head_;

public:
    LinkedList(std::string input);

    ~LinkedList();

    void add(char elem);

    void print();

    void reverse();
};

int main() {

    std::string input;
    std::getline(std::cin, input);

    LinkedList list(input);

    // вызов алгоритма реверса самого списка
    list.reverse();

    list.print();
}

Node::Node(char value, Node* next) {
    value_ = value;
    next_ = next;
}

LinkedList::LinkedList(std::string input) {
    for (int i = input.length() - 1; i >= 0; i--) {
        add(input[i]);
    }
}

LinkedList::~LinkedList()
{
    Node* current = head_;
    while (current)
    {
        head_ = head_->next_;
        delete current;
        current = head_;
    }
}

void LinkedList::add(char elem) {
    Node* current = new Node(elem, head_);
    head_ = current;
}

void LinkedList::print() {
    Node* current = head_;
    while (current) {
        std::cout << current->value_;
        current = current->next_;
    }
    std::cout << std::endl;
}

void LinkedList::reverse() {
    Node* temp = nullptr;
    Node* prev = nullptr;
    Node* current = head_;
    while (current) {
        temp = current->next_;
        current->next_ = prev;
        prev = current;
        current = temp;
    }
    head_ = prev;
}
