#include <iostream>
#include <array>
class Stack
{
    private:
        int size;
        int elements[];
    public:
        Stack(int size);

        //Operations
        bool push(); // Push onto top of stack
        bool pop();  // Pop off the top of the stack
        bool isEmpty(); // Is stack empty
        int getSize(); // Return stack size
        void peek();
};

// Stack Implementation

Stack::Stack(int size)
{
    std::cout << "Make stack of size " << size << std::endl;
}

bool Stack::push(){
    std::cout << "Push\n";
    return true;
}

bool Stack::pop(){
    std::cout << "Pop\n";
    return true;
}

bool Stack::isEmpty(){
    return false;
}


int main()
{
    std::cout << "Stack Example\n";
    Stack stack(0);
    stack.push();
    stack.pop();
    return 1;
}