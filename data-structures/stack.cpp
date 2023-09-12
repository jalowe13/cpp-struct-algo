#include <iostream>
#include <array>
class Stack
{
    private:
        int size;
        int *elements;
        int top = -1; // Top of the stack
    public:
        Stack(int size);

        //Operations
        bool push(int n); // Push onto top of stack
        bool pop();  // Pop off the top of the stack
        bool isFull(); // Is stack full
        bool isEmpty(); // Is stack empty
        int getSize(); // Return stack size
        void peek(); // Peek at the top of the stack
};

// Stack Implementation

Stack::Stack(int size)
{
    std::cout << "Make stack of size " << size << std::endl;
    this->size = size;
    int new_stack[size];
    this->elements = new int[size];
}

bool Stack::push(int n){
    std::cout << "Push\n";
    this->top++;
    if (!isFull())
    {
        elements[top] = n;
        std::cout << elements[top] << std::endl;
        return true;
    }
    return false;
}

bool Stack::pop(){
    std::cout << "Pop\n";
    if (!isEmpty())
    {
        top--;
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if (top == -1)
    {
        return true;
    }
    return false;
}
bool Stack::isFull(){
    if (top+1 == size)
    {
        return true;
    }
    return false;
}

void Stack::peek(){
    std::cout << "Top element is " << elements[top] << std::endl;
}


int main()
{
    std::cout << "Stack Example\n";
    Stack stack(3);
    stack.push(15);
    stack.peek();
    stack.pop();
    stack.peek();
    return 1;
}