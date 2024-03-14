#include <iostream>
#include <vector>
#include <string>
#include <cstring>

// Implementing stack with linked list

typedef struct Stack{

    char value;
    Stack *next;

    // constructor
    Stack(char x) {
        value = x;
        next = NULL;
    }

} Stack;

bool isEmpty(Stack *top) {
    if(top == NULL)
        return true;
    else
        return false;
}

void insert_top(Stack **top, int x){

    if(isEmpty(*top)) {
        *top = new Stack(x);
        return;
    }
        
    Stack *new_stack = new Stack(x);
    new_stack->next = *top;
    *top = new_stack;

}

char gettop(Stack *top) {

    if(isEmpty(top))
        return -1;
    
    return top->value;

}

void pop(Stack **top) {

    if(isEmpty(*top))
        return;
    
    Stack *tmp = *top;
    *top = tmp->next;
    delete tmp;

}

void print_stack(Stack *top) {

    if(isEmpty(top)) {
        std::cout << "NULL" << std::endl;
        return;
    }

    Stack *tmp = top;
    while(tmp != NULL) {
        std::cout << tmp->value << std::endl;
        tmp = tmp->next;
    }

}


// reversing a string with stack
std::string reverse_string_stack(Stack *top) {

    std::string output;
    while(!isEmpty(top)) {
        output.push_back(gettop(top));
        pop(&top);
    }

    return output;
} 

int main(void) {

    Stack *top = NULL;
    char input[100];
    std::cin.getline(input,100);

    int size = strlen(input);
    for(int i = 0; i < size; ++i)
        insert_top(&top,input[i]);
    
    std::string inv = reverse_string_stack(top);
    std::cout << inv << std::endl;



    // if want to test with integers, just change the return of
    // stack functions
    
    /*
    int elements;
    std::cout << "\nHow many elements to add to stack? ";

    std::cin >> elements;

    for(int i = 0; i < elements; ++i) {
        int aux;
        std::cout << "\nAdd to stack : ";
        std::cin >> aux;
        insert_top(&top,aux);
    }

    
    print_stack(top);
    pop(&top);
    print_stack(top);
    std::cout << gettop(top) << std::endl;
    */


}


