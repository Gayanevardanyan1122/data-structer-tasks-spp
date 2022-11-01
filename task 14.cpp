#include <iostream>

struct Node 
{
    Node(int v = 0, Node* n = nullptr)
        : value(v)
        , next(n)
    {}
    ~Node() {}
    
    int value;
    Node* next;
};

class Set 
{
public:
    Set();
    Set(const Set&);
    ~Set();
    
public:
    bool is_contain(int) const;
    bool is_subset(const Set&) const;
    void print() const;
    
    void add_elem(int);
    void remove_elem(int);
    Set& operator=(const Set&);
    void clear();

private:
    Node* m_head;
};

Set::Set()
    : m_head(nullptr)
{
    std::cout << "default ctor" << std::endl;
}

Set::Set(const Set& ob)
    : m_head(nullptr)
{
    Node* ptr = ob.m_head;
    while(ptr)
    {
        add_elem(ptr->value);
        ptr = ptr->next;
    }
    std::cout << "copy ctor" << std::endl;
}

Set::~Set()
{
    clear();
    std::cout << "dtor" << std::endl;
}

bool Set::is_contain(int el) const
{
    Node* ptr = m_head;
    while(ptr)
    {
        if(ptr->value == el)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

bool Set::is_subset(const Set& s) const
{
    Node* ptr = s.m_head;
    while(ptr)
    {
        if(!is_contain(ptr->value))
        {
            return false;
        }
        ptr = ptr->next;
    }
    return true;
}

void Set::add_elem(int k)
{
    Node* ptr = m_head;
    Node* prev = nullptr;
    while(ptr && k > ptr->value)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if(prev == nullptr)
    {
        m_head = new Node(k, m_head);
    }
    else
    {
        prev->next = new Node(k, ptr);
    }
    
}

void Set::remove_elem(int e)
{
    if(m_head == nullptr)
    {
        throw "Set is empty";
    }
    else
    {
        Node* ptr = m_head;
        Node* p = nullptr;
        while(ptr && ptr->value < e)
        {
            p = ptr;
            ptr = ptr->next;
        }
        if(p == nullptr && ptr->value == e)
        {
            m_head = m_head->next;
            delete ptr;
            ptr = nullptr;
        }
        else if(ptr->value == e)
        {
            ptr = ptr->next;
            delete p->next;
            p->next = ptr;
        }
        else
        {
            throw "this element is not contained in set";
        }
    }
}

Set& Set::operator=(const Set& ob)
{
    clear();
    Node* p = ob.m_head;
    while(p)
    {
        add_elem(p->value);
        p = p->next;
    }
    return *this;
}

void Set::clear()
{ 
    Node* p = m_head;
    while(m_head)
    {
        m_head = m_head->next;
        delete p;
        p = m_head;
    }
}

void Set::print() const
{
    Node* p = m_head;
    while(p)
    {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << std::endl;
}


// task14.5//

#include <iostream>
#include <queue>


int main()
{
    std::queue<int> Q1, Q2;
    for(int i = 10; i > 0; --i)
    {
        Q1.push(i);
    }
    
    int* a = new int [Q1.size()];
    int i = 0, k = Q1.size();
    while(!Q1.empty())
    {
        a[i] = Q1.front();
        Q1.pop();
        ++i;
    }
    
    for(int i = 0; i < k; ++i)
    {
        for(int j = i + 1; j < k; ++j)
        {
            if(a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for(int i = 0; i < k; ++i)
    {
        Q2.push(a[i]);
    }
    
    while(!Q2.empty())
    {
        std::cout << Q2.front() << " ";
        Q2.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
