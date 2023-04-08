#include <iostream>
#include <string>

struct Node
{
    std::string _value;
    Node* _next;

    Node(std::string value, Node* next);
};

class OneLinkedList
{
private:
    Node* _head;

public:
    OneLinkedList();

    OneLinkedList(std::string* content, int size);

    void add(std::string elem);

    void print();

    void reverse();
};

int main()
{
    // string* mas = new string[]{ "3", "c", "2", "b", "1", "ka" };               
    // int size = 6;

    OneLinkedList list;

    std::string input;
    std::getline(std::cin, input);

    // реверсируем строку, чтобы добавление слов шло в порядке ввода, а не в обратном
    for (int i = 0; i < input.length() / 2; i++)
    {
        char ch = input[i];
        input[i] = input[input.length() - 1 - i];
        input[input.length() - 1 - i] = ch;
    }

    // далее уже реверсированную строку разбираем на слова и добавляем слова в список 
    // добавление в односвязный список уже реверсирует порядок! 
    // Т.к. строка была реверсирована до разбора, восстанавливается порядок ввода.
    std::size_t prev = 0, pos;
    while ((pos = input.find_first_of(" ", prev)) != std::string::npos)
    {
        if (pos > prev)
            list.add(input.substr(prev, pos - prev));
        prev = pos + 1;
    }
    if (prev < input.length())
        list.add(input.substr(prev, std::string::npos));

    // вызов алгоритма реверса самого списка!
    list.reverse();

    list.print();

    system("pause");
}

Node::Node(std::string value, Node* next)
{
    _value = value;
    _next = next;
}

OneLinkedList::OneLinkedList()
{
    _head = nullptr;
}

OneLinkedList::OneLinkedList(std::string* content, int size)
    : OneLinkedList()
{
    for (int i = 0; i < size; i++)
    {
        add(content[i]);
    }
}

void OneLinkedList::add(std::string elem)
{
    Node* current = new Node(elem, _head);
    _head = current;
}

void OneLinkedList::print()
{
    Node* current = _head;
    while (current)
    {
        std::cout << current->_value << " ";
        current = current->_next;
    }
    std::cout << std::endl;
}

void OneLinkedList::reverse()
{
    Node* temp = nullptr;
    Node* prev = nullptr;
    Node* current = _head;
    while (current)
    {
        temp = current->_next;
        current->_next = prev;
        prev = current;
        current = temp;
    }
    _head = prev;
}