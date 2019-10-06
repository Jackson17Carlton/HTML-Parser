//
//  main.cpp
//  HTMLparser
//
//  Created by Jackson Carlton on 3/29/19.
//  Copyright © 2019 Jackson Carlton. All rights reserved.
//

#include "stack.h"

int main()
{
    //Variable declartion
    string filename;
    char ch; //Used to construct HTML string tags
    string HTML; //Built when the file is scanned through character by character
    string top; //Stores the top string in the stack
    Stack steck; //Stack as a linked list
    int size = 15; //Size of array of tags that don't require closing tags
    string Tegs[] = {"bd", "wbr", "hr", "br", "img", "input", "link", "meta", "base", "embed", "source", "area", "keygen", "param", "track"}; //Array of unclosed tags
    
     //File handling
    cout << "Enter an HTML filename: ";
    getline(cin, filename);
    cout << filename << endl;
    ifstream din;
    din.open(filename);
    if (din.fail())
    {
        cout << "File cannot be located, check the name!" << endl;
        return 0;
    }
    
    //Reading through file character by character until reaching eof (end of file)
    while (!din.eof())
    {
        din.get(ch);
        if (ch == '<')
        {
            din.get(ch);
            while (ch != '>' && ch != ' ')
            {
                HTML = HTML + ch; //Adds each character to a string of characters terminated by '>' or ' '
                din.get(ch);
            }
            cout << "-----------------------------------" << endl;
            cout << "New Tag Found: " << HTML << endl;
            steck.Top(top);
            if (('/' + top) == HTML)
            {
                cout << "Found a matching Tag for: " << HTML << endl;
                steck.Pop(top);
                cout << top << " was removed from the Stack" << endl;
                steck.Print();
                HTML = "";
            }
            else
            {
                steck.Push(HTML);
                for (int i = 0; i < size; i++) //This loop immediately pops the top element if it matches one of the tags of the array
                {
                    if (Tegs[i] == HTML)
                    {
                        cout << HTML << " doesn't require and end tag. It will not be pushed onto Stack..." << endl;
                        steck.Pop(top);
                    }
                }
                steck.Top(top);
                cout << "Top Tag: " << top << endl;
                steck.Print();
                HTML = "";
            }
        }
    }
    if (steck.IsEmpty())
    {
        cout << "-----------------------------------" << endl;
        cout << "The HTML Tags are balanced!" << endl;
    }
    else
    {
        cout << "-----------------------------------" << endl;
        cout << "The HTML Tags are not balanced!" << endl;
    }
    din.close();
    return 0;
}

