#include <iostream>

#include <iostream>
#include <string>

template<typename T>
class DynamicArray
{
private:
    T* mas_;
    int size_;
    int capacity_;

public:
    DynamicArray();

    ~DynamicArray();

    void push(T elem);

    T pop();

    T at(int i);

    void resize(int size);

    int size();

    int capacity();

    void clear();

    void exit();
};

int main() {
    DynamicArray<int> arr;

    std::string command;
    int num;
    while (true) {
        std::cin >> command;
        if (command == "push") {
            std::cin >> num;
            arr.push(num);
        }
        else if (command == "at") {
            std::cin >> num;
            arr.at(num);
        }
        else if (command == "capacity") {
            arr.capacity();
        }
        else if (command == "pop") {
            arr.pop();
        }
        else if (command == "size") {
            arr.size();
        }
        else if (command == "resize") {
            std::cin >> num;
            arr.resize(num);
        }
        else if (command == "clear") {
            arr.clear();
        }
        else if (command == "exit") {
            arr.exit();
            break;
        }
    }
}
template<typename T>
DynamicArray<T>::DynamicArray() {
    mas_ = new T[1];
    size_ = 0;
    capacity_ = 1;
}
template<typename T>
void DynamicArray<T>::push(T elem) {
    if (size_ >= capacity_) {
        capacity_ *= 2;
        T* tmp = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            tmp[i] = mas_[i];
        }
        if (mas_) {
            delete[] mas_;
        }
        mas_ = tmp;
    }
    mas_[size_] = elem;
    size_++;
    std::cout << "ok" << "\n";
}
template<typename T>
T DynamicArray<T>::pop() {
    if (size_ == 0) {
        std::cout << "error" << "\n";
        ;
        return 0;
    }
    T elem = mas_[size_ - 1];
    size_--;
    capacity_ = size_;
    T* tmp = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        tmp[i] = mas_[i];
    }
    if (mas_) {
        delete[] mas_;
    }
    mas_ = tmp;
    std::cout << elem << "\n";
    return elem;
}
template<typename T>
T DynamicArray<T>::at(int i) {
    if (i < 0 || i >= size_) {
        std::cout << "error" << "\n";
        return 0;
    }
    std::cout << mas_[i] << "\n";
    return mas_[i];
}
template<typename T>
void DynamicArray<T>::resize(int size) {
    if (size < 0) {
        std::cout << "error" << "\n";
        return;
    }
    T* tmp = new T[size];
    int new_size = (size_ < size ? size_ : size);
    for (int i = 0; i < new_size; i++) {
        tmp[i] = mas_[i];
    }
    if (mas_) {
        delete[] mas_;
    }
    mas_ = tmp;
    size_ = new_size;
    capacity_ = size;
    std::cout << "ok" << "\n";
}
template<typename T>
int DynamicArray<T>::size() {
    std::cout << size_ << "\n";
    return size_;
}
template<typename T>
int DynamicArray<T>::capacity() {
    std::cout << capacity_ << "\n";
    return capacity_;
}
template<typename T>
void DynamicArray<T>::clear() {
    if (mas_) {
        delete[] mas_;
    }
    mas_ = new T[1];
    capacity_ = 1;
    size_ = 0;
    std::cout << "ok" << "\n";
}
template<typename T>
DynamicArray<T>::~DynamicArray() {
    if (mas_) {
        delete[] mas_;
    }
    capacity_ = 0;
    size_ = 0;
}
template<typename T>
void DynamicArray<T>::exit() {
    std::cout << "bye" << "\n";
}
