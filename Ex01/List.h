#pragma once

struct node
{
    int data;
    node* next;
    node* prev;
};

class List
{
private:
    node* m_Head;
    node* m_Tail;
public:
    //ctor
    List();

    //output: returns if the list is empty
    bool IsEmpty();

    //output: return the head of the list
    node* GetHead();

    //output: return the tail of the list
    node* GetTail();

    //input: data
    //output: insert the data to the head of the list
    void AddToHead(int i_DataToAdd);

    //input: data
    //output: insert the data to the tail of the list
    void AddToTail(int i_DataToAdd);

    //deletes the head of the list
    int DeleteHead();
    
    //deletes the tail of the list
    int DeleteTail();

    //input: data of the item that we want to delete
    //output: delete the item with that data from the list (if its exit)
    int DeleteItem(int i_DataToDelete);

    //input: data of the item that we want to find
    //output: returns the item with that data from the list (if its exit)
    node* SearchItem(int i_DataToSearch);

    //dtor
    ~List();
};