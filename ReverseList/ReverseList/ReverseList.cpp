#include <iostream>
#include <string>

struct Node {
    std::string value_;
    Node* next_;

    Node(std::string value, Node* next);
};

class LinkedList {
private:
    Node* head_;

public:
    LinkedList(std::string input);

    ~LinkedList();

    void add(std::string elem);

    void print();

    void reverse();
};

int main() {
    // string* mas = new string[]{ "3", "c", "2", "b", "1", "ka" };               
    // int size = 6;

   // LinkedList list;

    std::string input;
    std::getline(std::cin, input);

    LinkedList list(input);

    // вызов алгоритма реверса самого списка
    list.reverse();

    list.print();

    system("pause");
}

Node::Node(std::string value, Node* next) {
    value_ = value;
    next_ = next;
}

LinkedList::LinkedList(std::string input) {
    // реверсируем строку, чтобы добавление слов шло в порядке ввода, а не в обратном
    for (int i = 0; i < input.length() / 2; i++) {
        char ch = input[i];
        input[i] = input[input.length() - 1 - i];
        input[input.length() - 1 - i] = ch;
    }

    // далее уже реверсированную строку разбираем на слова и добавляем слова в список 
    // добавление в односвязный список уже реверсирует порядок
    // Т.к. строка была реверсирована до разбора, восстанавливается порядок ввода.
    std::size_t prev = 0, pos;
    while ((pos = input.find_first_of(" ", prev)) != std::string::npos) {
        if (pos > prev)
            add(input.substr(prev, pos - prev));
        prev = pos + 1;
    }
    if (prev < input.length())
        add(input.substr(prev, std::string::npos));
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

void LinkedList::add(std::string elem) {
    Node* current = new Node(elem, head_);
    head_ = current;
}

void LinkedList::print() {
    Node* current = head_;
    while (current) {
        std::cout << current->value_ << " ";
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
