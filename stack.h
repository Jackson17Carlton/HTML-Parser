//
//  stack.hpp
//  HTMLparser
//
//  Created by Jackson Carlton on 3/25/19.
//  Copyright © 2019 Jackson Carlton. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
struct StackNode
{
    string Text;
    StackNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface
//-----------------------------------------------------------
class Stack
{
public:
    // Constructors
    Stack();
    Stack(const Stack & stack);
    ~Stack();
    
    // Methods
    bool IsFull();
    bool IsEmpty();
    void Push(string Text);
    void Pop(string &Text);
    void Top(string &Text);
    int GetLength();
    void Print();
    
private:
    StackNode *Head;
    int Length;
};
#endif /* stack_hpp */
