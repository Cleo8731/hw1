#include "split.h"
#include <iostream>

using namespace std;

void print(Node*& in)
{
    Node* temp = in;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void deleteList(Node*& in)
{
    Node* temp;
    while (in != nullptr)
    {
        temp = in;
        in = in->next;
        delete temp;
    }
}

int main()
{
    // initialization of in with int array
    int size = 10;
    int list[] = {3, 4, 7, 8, 1, 2, 18, 172, 32, 31};
    Node* in = new Node(list[size - 1], nullptr);
    for (int i = size - 2; i >= 0; i--)
    {
        in = new Node(list[i], in);
    }

    cout << "list1: ";
    print (in);

    Node* odds = NULL;
    Node* evens = NULL;
    split(in, odds, evens);
    
    cout << "Odds: ";
    print(odds);

    cout << "Evens: ";
    print(evens);

    cout << "list1: ";
    print (in);

    deleteList(odds);
    deleteList(evens);

    return 0;
}