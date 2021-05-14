#include<iostream>
#include <ctime>

using namespace std;

class Myfloat
{
public:
    float number;
    Myfloat* next;
    Myfloat(float data)
    {
        number = data;
    }
};

void add(Myfloat* &head, float number)
{
    if (head == nullptr)
    {
        head = new Myfloat(number);
        head->next = nullptr;
        return;
    }

    Myfloat* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Myfloat(number);
}

void addAfter(Myfloat* &head,float addNumber, float beforeNumber)
{
    if (head == nullptr) return;

    Myfloat* temp = head;
    while (temp->next != nullptr && temp->number !=beforeNumber)
    {
        temp = temp->next;
    }

    if (temp->number == beforeNumber)
    {
        Myfloat* data = new Myfloat(addNumber);
        data->next = temp->next;
        temp->next = data;
    }
}

void deleteN(Myfloat* &head, float number)
{
    if (head == nullptr) return;

    if (head->number == number)
    {
        Myfloat* copyHead = head;
        head = head->next;
        delete copyHead;
        return ;
    }

    Myfloat* temp = head;

    while (temp->next != nullptr && temp->next->number != number)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr) return;

    Myfloat* copyT = temp->next;
    temp->next = temp->next->next;
    delete copyT;

}

void outPut(Myfloat* head)
{
    if (head == nullptr) return;

    Myfloat* temp = head;

    while (temp != nullptr)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    srand(time(0));

    Myfloat* head = nullptr;

    float c = 5.0;

    for (int i = 0; i < 10; i++)
    {
        add(head, (rand() % 5) / c);
    }
    outPut(head);

    add(head, 4);
    outPut(head);

    addAfter(head, 1.3, head->number);
    outPut(head);

    addAfter(head, 4.3, 4);
    outPut(head);

    deleteN(head, 4.3);
    outPut(head);

    deleteN(head, head->number);
    outPut(head);

    return 0;
}