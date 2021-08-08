#include "List.h"

/*

List::List()
{
    m_Head = nullptr;
    m_Tail = nullptr;
}

bool List::IsEmpty()
{
    return m_Head == nullptr;
}


node* List::GetHead()const
{
    return m_Head;
}
node* List::GetTail()const
{
    return m_Tail;
}

List::~List()
{
    node* currentNode = m_Head;
    while (currentNode != nullptr)
    {
        m_Head = currentNode->next;
        delete currentNode;
        currentNode = m_Head;
    }

}

void List::AddToTail(int i_Data)
{
    node* tmp = new node;
    tmp->data = i_Data;
    tmp->next = nullptr;

    if (m_Head == nullptr)
    {
        m_Head = tmp;
        m_Tail = tmp;
    }
    else
    {
        m_Tail->next = tmp;
        m_Tail = m_Tail->next;
    }
}

void List::AddToHead(int i_Data)
{
    node* tmp = new node;
    tmp->data = i_Data;
    tmp->next = m_Head;

    if (m_Head == nullptr)
    {
        m_Tail = tmp;
    }
    m_Head = tmp;

}

void List::DeleteTail()
{

}


void List::DeleteData(int i_DataToDelete)
{
    node* currentNode = m_Head;
    node* prevNode = nullptr;

    if (m_Head->data == i_DataToDelete)
    {
        m_Head = currentNode->next;
    }
    else
    {
        while (currentNode != nullptr && currentNode->data != i_DataToDelete)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        if (m_Tail->data == i_DataToDelete)
        {
            m_Tail = prevNode;
            m_Tail->next = nullptr;
        }
        else
        {
            prevNode->next = currentNode->next;
        }
    }

    if (currentNode == nullptr)
    {
        throw "the vertex doent exist in the list";
    }
    delete currentNode;
}


*/


List::List()
{
    m_Head = nullptr;
    m_Tail = nullptr;
}

bool List::IsEmpty()
{
    return m_Head == nullptr;
}

node* List::GetHead()
{
    return m_Head;
}

node* List::GetTail()
{
    return m_Tail;
}

void List::AddToHead(int i_DataToAdd)
{
    node* newItem = new node;
    if (m_Head == nullptr)
    {
        m_Head = newItem;
        newItem->prev = nullptr;
        newItem->data = i_DataToAdd;
        newItem->next = nullptr;
        m_Tail = newItem;
    }
    else
    {
        newItem->next = m_Head;
        newItem->data = i_DataToAdd;
        newItem->prev = nullptr;
        m_Head->prev = newItem;
        m_Head = newItem;
    }
}

void List::AddToTail(int i_DataToAdd)
{
    node* newItem = new node;
    newItem->data = i_DataToAdd;
    if (m_Head == nullptr)
    {
        m_Head = newItem;
        newItem->prev = nullptr;
        newItem->next = nullptr;
        m_Tail = newItem;
    }
    else
    {
        newItem->prev = m_Tail;
        m_Tail->next = newItem;
        newItem->next = nullptr;
        m_Tail = newItem;
    }
}

int List::DeleteHead()
{
    if (m_Head == nullptr)
    {
        throw "empty list";
    }
    node* current = m_Head;
    int itemData = current->data;
    if (m_Head == m_Tail)
    {

        m_Head = nullptr;
        m_Tail = nullptr;

        delete current;
    }
    else
    {
        m_Head = m_Head->next;
        m_Head->prev = nullptr;
        delete current;
    }

    return itemData;
}

int List::DeleteTail()
{
    int itemData;
    if (m_Head == nullptr)
    {
        throw "empty list";
    }
    if (m_Head == m_Tail)
    {
        node* current = m_Head;
        itemData = current->data;
        m_Head = nullptr;
        m_Tail = nullptr;
        delete current;
    }
    else
    {
        node* current = m_Tail;
        itemData = current->data;
        m_Tail = m_Tail->prev;
        m_Tail->next = nullptr;
        delete current;
    }

    return itemData;
}
int List::DeleteItem(int i_DataToDelete)
{
    node* temp = m_Head;
    if (m_Head == m_Tail) //one item in list
    {
        if (m_Head->data != i_DataToDelete)
        {
            throw "could not find the item to delete";
        }
        m_Head = nullptr;
        m_Tail = nullptr;
        delete temp;
    }
    else if (m_Head->data == i_DataToDelete)
    {
        m_Head = m_Head->next;
        m_Head->prev = nullptr;
        delete temp;

    }
    else if (m_Tail->data == i_DataToDelete)
    {
        temp = m_Tail;
        m_Tail = m_Tail->prev;
        m_Tail->next = nullptr;
        delete temp;
    }
    else
    {
        while (temp->data != i_DataToDelete)
        {
            temp = temp->next;
            if (temp == nullptr)
            {
                throw "could not find the item to delete";
            }
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
 
    return i_DataToDelete;
}

node* List::SearchItem(int i_DataToSearch)
{
    struct node* temp;
    temp = m_Head;
    while (temp != nullptr)
    {
        if (temp->data == i_DataToSearch)
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
    return nullptr;
}

List::~List()
{
    node* currentNode = m_Head;
    while (currentNode != nullptr)
    {
        m_Head = currentNode->next;
        delete currentNode;
        currentNode = m_Head;
    }
}