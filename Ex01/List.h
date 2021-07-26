#pragma once
/*
struct node
{
    int data;
    node* next;
};

class List
{
private:
    node* m_m_Head;
    node* m_m_Tail;
public:
    List();
    bool IsEmpty();
    node* Getm_Head()const;
    node* Getm_Tail()const;
    ~List();
    void AddTom_Tail(int i_Data);
    void AddTom_Head(int i_Data);
    void Deletem_Tail();
    void DeleteData(int i_DataToDelete);
};

*/

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

    List();

    bool IsEmpty();


    node* GetHead()const;

    node* GetTail()const;

    void AddToHead(int i_DataToAdd);

    void AddToTail(int i_DataToAdd);

    //void insertAfter(int old, int i_DataToAdd);

    int DeleteHead();
    
    int DeleteTail();

    int DeleteItem(int i_DataToDelete);

    node* SearchItem(int i_DataToSearch);

    ~List();
};