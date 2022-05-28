#include "MyList.h"
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;

//CONSTRUCTORS AND DESTRUCTORS

//default constructor
MyList::MyList() { head = NULL; }

//copy constructor
MyList::MyList(const MyList &str)
{
    head = nullptr;
    Node *temp = str.head;
    while (temp != nullptr)
    {
        push_back(temp->value);
        temp = temp->next;
    }
}

//constructor with string object parameter
MyList::MyList(const string &str)
{
    this->head = nullptr;
    for (unsigned i = 0; i < str.size(); i++)
    {
        push_back(str[i]);
    }
}

//constructor with string literal parameter
MyList::MyList(const char *str)
{
    this->head = nullptr;
    for (unsigned i = 0; i < strlen(str); i++)
    {
        push_back(str[i]);
    }
}

//destructor
MyList::~MyList()
{
    while (head)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }
}

//MUTATORS

//insert value at front of list
void MyList::push_front(char value)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = this->head;
    head = temp;
}

//insert value at back of list
void MyList::push_back(char value)
{
    Node *temp = new Node;
    temp->value = value;
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        for (Node *i = head; i != nullptr; i = i->next)
        {
            if (i->next == nullptr)
            {
                i->next = temp;
                temp->next = nullptr;
            }
        }
    }
}

//remove first item from the list. no action on empty list
void MyList::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        Node *temp = head;
        temp = head->next;
        delete head;
        head = temp;
    }
}

//removes last item from the list. no action on empty list
void MyList::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        for (Node *i = head; i != nullptr; i = i->next)
        {
            if (i->next == nullptr)
            {
                head = nullptr;
                return;
            }
            if (i->next->next == nullptr)
            {
                Node *temp = i->next;
                i->next = nullptr;
                delete temp;
                return;
            }
        }
    }
}

//swaps value of nodes at positions i and j. no action if i or j is out of bounds
void MyList::swap(int i, int j)
{
    int sz = size();

    if (i < 0 || i >= sz)
    {
        return;
    }
    if (j < 0 || j >= sz)
    {
        return;
    }
    if (i == j)
    {
        return;
    }
    else
    {
        int posi = 0;
        int posj = 0;
        for (Node *temp = head; temp != nullptr; temp = temp->next)
        {
            if (i == posi)
            {
                Node *swappy = temp;
                for (Node *temp2 = head; temp2 != nullptr; temp2 = temp2->next)
                {
                    if (j == posj)
                    {
                        char tempval;
                        tempval = swappy->value;
                        swappy->value = temp2->value;
                        temp2->value = tempval;
                        return;
                    }
                    posj++;
                }
            }
            posi++;
        }
    }
}

//Inserts a node with value at position i in the list.
//abort via an assert statement if i is out-of-bounds
void MyList::insert_at_pos(int i, char value)
{
    assert(i >= 0 && i <= size()); //abort via assert if i is out-of-bounds
    if (head == nullptr)
    {
        return;
    }
    if (i == 0)
    {
        push_front(value);
    }
    else if (i == size())
    {
        push_back(value);
    }
    else
    {
        int pos = 1;
        Node *prev = head;
        for (Node *temp = head->next; temp != nullptr; temp = temp->next)
        {
            if (i == pos)
            {
                Node *val = new Node;
                val->value = value;
                prev->next = val;
                val->next = temp;
                return;
            }
            prev = temp;
            pos++;
        }
    }
}

//reverse items in list
void MyList::reverse()
{
    if (head == nullptr)
    {
        return;
    }
    for (int i = 0; i < size() / 2; i++)
    {
        swap(i, size() - i - 1);
    }
}

//ACCESSORS

//returns number of nodes in list
int MyList::size() const
{
    int size = 0;
    for (Node *i = head; i != nullptr; i = i->next)
    {
        size++;
    }
    return size;
}

//prints contents of list
void MyList::print() const
{
    for (Node *i = head; i != nullptr; i = i->next)
    {
        cout << i->value;
        if (i->next != nullptr)
        {
            cout << " ";
        }
    }
    cout << endl;
}

//finds position of first occurence of a character value in list and return that position. if not in
//list, function returns -1
int MyList::find(char value) const
{
    if (head == nullptr)
    {
        return -1;
    }
    int pos = 0;
    for (Node *i = head; i != nullptr; i = i->next)
    {
        if (i->value == value)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

//find position of first occurence of MyList query_str in list and return that position.
//if query_str is not in list, return -1
int MyList::find(MyList &query_str) const
{
    if (head == nullptr || query_str.head == nullptr)
    {
        return -1;
    }
    if (query_str.size() > size())
    {
        return -1;
    }
    int pos = 0;
    Node *query = query_str.head;
    Node *thisy = head;
    for (int i = 0; i < size(); i++)
    {
        if (query->value == thisy->value)
        {
            query = query->next;
            pos++;
            if (pos == query_str.size())
            {
                return i + 1 - query_str.size();
            }
        }
        else
        {
            pos = 0;                //reset position
            query = query_str.head; //reset head again
        }
        if (i < size() && i != size())
        {
            thisy = thisy->next;
        }
        else
        {
            return -1;
        }
    }

    return -1;
}

//OPERATOR OVERLOADERS

//overloaded assignment operator
MyList &MyList::operator=(const MyList &str)
{
    if (str.head != nullptr)
    {
        if (this == &str)
        {
        }
        else
        {
            while (head != nullptr)
            {
                Node *temp = head->next;
                delete head;
                head = temp;
            }
            head = nullptr;
            for (Node *temp = str.head; temp != nullptr; temp = temp->next)
            {
                push_back(temp->value);
            }
        }
    }
    else
    {
        head = nullptr;
    }
    return *this;
}

//overloaded [] operator returns writable reference to memory location for list l1 at l1[i]
char &MyList::operator[](const int i)
{
    assert(i >= 0 && i <= size());
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        exit(1);
    }
    int pos = 0;
    Node *temp = head;
    for (temp = head; temp != nullptr; temp = temp->next)
    {
        if (i == pos)
        {
            return temp->value;
        }
        pos++;
    }
    return temp->value;
}

//concatenates two lists together
MyList MyList::operator+(const MyList &str)
{
    if (head == nullptr && str.head == nullptr)
    {
        exit(1);
    }
    MyList list;
    if (head == nullptr)
    {
        for (Node *temp = str.head; temp != nullptr; temp = temp->next)
        {
            list.push_back(temp->value);
        }
        return list;
    }
    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        list.push_back(temp->value);
    }
    if (str.head == nullptr)
    {
        return list;
    }
    else
    {
        for (Node *temp2 = str.head; temp2 != nullptr; temp2 = temp2->next)
        {
            list.push_back(temp2->value);
        }
        return list;
    }
}

//CHALLENGE

//check whether list object contains palindrome
bool MyList::is_palindrome() const
{
    if (head == nullptr)
    {
        return false;
    }
    MyList palin;
    MyList compare;
    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        palin.push_back(temp->value);
        compare.push_back(temp->value);
    }
    palin.reverse();
    int sz = size();
    int count = 0;
    Node *i = palin.head;
    for (Node *temp2 = compare.head; temp2 != nullptr; temp2 = temp2->next)
    {
        if (i->value == temp2->value)
        {
            count++;
        }
        i = i->next;
    }
    if (count == sz)
    {
        return true;
    }

    return false;
}

//merge two sorted list into implicit list object
void MyList::merge_list(MyList A, MyList B)
{
    if (A.head == nullptr && B.head == nullptr)
    {
        return;
    }
    while (size() > 0)
    {
        pop_front();
    }
    if (A.head == nullptr)
    {
        for (Node *temp = B.head; temp != nullptr; temp = temp->next)
        {
            push_back(temp->value);
            return;
        }
    }
    if (B.head == nullptr)
    {
        for (Node *temp2 = A.head; temp2 != nullptr; temp2 = temp2->next)
        {
            push_back(temp2->value);
            return;
        }
    }
    else
    {
        Node *aa = A.head;
        Node *bb = B.head;
        while (aa != nullptr && bb != nullptr)
        {
            if (aa->value <= bb->value)
            { //check to see which ones smaller, and merge in smaller value
                push_back(aa->value);
                aa = aa->next;
            }
            else
            { //else merge in other value
                push_back(bb->value);
                bb = bb->next;
            }
        }
        if (aa == nullptr)
        {
            for (Node *temp3 = bb; temp3 != nullptr; temp3 = temp3->next)
            {
                push_back(temp3->value);
            }
        }
        if (bb == nullptr)
        {
            for (Node *temp4 = aa; temp4 != nullptr; temp4 = temp4->next)
            {
                push_back(temp4->value);
            }
        }
    }
}

//remove all instances of char c from implicit list object
bool MyList::remove_char(char c)
{
    if (head == nullptr)
    {
        return false;
    }
    if (find(c) == -1)
    {
        return false;
    }
    if (head->value == c)
    {
        head = head->next;
    }
    Node *i = new Node;
    for (Node *temp = head; temp != nullptr; temp = temp)
    {
        if (temp->value != c)
        {
            i = temp;
            temp = temp->next;
        }
        else if (head->value == c)
        {
            i = temp->next;
            head = i;
            delete temp;
            temp = i->next;
        }
        else
        {
            i->next = temp->next;
            delete temp;
            temp = i->next;
        }
    }

    return true;
}

//returns first node's value
char MyList::front() const
{
    if (head == nullptr)
    {
        exit(1);
    }
    return head->value;
}
