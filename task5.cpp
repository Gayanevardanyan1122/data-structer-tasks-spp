#include <iostream>

struct Node
{
    Node(double c, int d, Node* n = nullptr)
        : coefficient(c)
        , degree(d)
        , next(n)
    {}
    ~Node() {}
  
    double coefficient;
    int degree;
    Node* next;
};

class Polinom
{
public:
    Polinom();
    Polinom(const Polinom&);
    ~Polinom();
    
public:
    Polinom derivative() const;
    void insert(double, int);
    Polinom& operator=(const Polinom&);
    bool operator==(const Polinom&) const;
    void clear();
    void print() const;
    
private:
    Node* m_head;
};

Polinom::Polinom()
    : m_head(nullptr)
{
    std::cout << "default ctor" << std::endl;
}
    
Polinom::Polinom(const Polinom& ob)
    : m_head(nullptr)
{
    Node* ptr = ob.m_head;
    while(ptr)
    {
        insert(ptr->coefficient, ptr->degree);
        ptr = ptr->next;
    }
    std::cout << "copy ctor" << std::endl;
}

Polinom::~Polinom()
{
    clear();
    std::cout << "dtor" << std::endl;
}

Polinom Polinom::derivative() const
{
    if(m_head == nullptr)
    {
        throw "yor Polinom is null";
    }
    Polinom res;
    Node* ptr = m_head;
    double c;
    int d;
    while(ptr)
    {
        c = ptr->coefficient;
        d = ptr->degree;
        res.insert(c*d, d - 1);
        ptr = ptr->next;
    }
    return res;
}

void Polinom::insert(double c, int k)
{
    Node* ptr = m_head;
    Node* prev = nullptr;
    while(ptr && ptr->degree > k)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if(prev == nullptr)
    {
        m_head = new Node(c, k, m_head);
    }
    else
    {
        prev->next = new Node(c, k, ptr);
    }
}

Polinom& Polinom::operator=(const Polinom& ob)
{
    clear();
    Node* ptr = ob.m_head;
    while(ptr)
    {
        insert(ptr->coefficient, ptr->degree);
        ptr = ptr->next;
    }
    return *this;
}

bool Polinom::operator==(const Polinom& ob) const
{
    Node* ptr1 = m_head;
    Node* ptr2 = ob.m_head;
    while(ptr1 && ptr2)
    {
        if(ptr1->coefficient != ptr2->coefficient || ptr1->degree != ptr2->degree)
        {
            return false;
        }
    }
    if(ptr1 || ptr2)
    {
        return false;
    }
    return true;
}

void Polinom::clear() 
{
    Node* ptr = m_head;
    while(m_head)
    {
        m_head = m_head->next;
        delete ptr;
        ptr = m_head;
    }
}

void Polinom::print() const
{
    Node* ptr = m_head;
    while(ptr)
    {
        std::cout << "coefficient is " << ptr->coefficient << " " << "degree is " << ptr->degree << std::endl;
        ptr = ptr->next;
    }
}
//task5.5 //
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
