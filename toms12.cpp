#include <iostream>

struct Node 
{
    Node(int val = 0, Node* n = nullptr)
        : value(val)
        , next(n)
        {}
    ~Node() {}
    
    int value;
    Node* next;
};

class MultySet
{
public:
    MultySet();
    MultySet(const MultySet&);
    ~MultySet();
    
public:
    double mid() const;
    MultySet intersection(const MultySet&) const;
    bool is_contain(int) const;
    void print() const;
    
    void Remove_elements(int);
    void add_elem(int);
    MultySet& operator=(const MultySet&);
    void clear(); 
    
private:
    Node* m_head;
    int m_size;
};

MultySet::MultySet()
    : m_head(nullptr)
    , m_size(0)
{
    std::cout << "default ctor" << std::endl;
}

MultySet::MultySet(const MultySet& ob)
    : m_head(nullptr)
    , m_size(0)
{
    Node* ptr = ob.m_head;
    while(ptr)
    {
        add_elem(ptr->value);
        ptr = ptr->next;
    }
    std::cout << "copy ctor" << std::endl;
}

MultySet::~MultySet()
{
    clear();
    std::cout << "dtor" << std::endl;
}

double MultySet::mid() const
{
    Node* ptr = m_head;
    int sum = 0;
    while(ptr)
    {
        sum += ptr->value;
        ptr = ptr->next;
    }
    
    return ((double)sum / m_size);
}

MultySet MultySet:: intersection(const MultySet& ob) const
{
    MultySet res;
    Node* ptr = ob.m_head;
    while(ptr)
    {
        if(is_contain(ptr->value) && !res.is_contain(ptr->value))
        {
            res.add_elem(ptr->value);
        }
        ptr = ptr->next;
    }
    return res;
}

bool MultySet::is_contain(int el) const
{
    if(m_head == nullptr)
    {
        return false;
    }
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

void MultySet::Remove_elements(int el)
{
    if(m_head != nullptr)
    {
        int c = m_size;
        Node* ptr = m_head;
        Node* prev = nullptr;
        while(ptr && ptr->value < el)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        while(ptr && ptr->value == el)
        {
            if(prev == nullptr)
            {
                m_head = m_head->next;
                delete ptr;
                ptr = m_head;
            }
            else
            {
                ptr = ptr->next;
                delete prev->next;
                prev->next = ptr;
            }
            --m_size;
        }
        if(m_size == c)
        {
            throw "in your MultySet not that element";
        }
    }
    else
    {
        throw "your MultySet is empty";
    }
}

void MultySet::add_elem(int el)
{
    if(m_head == nullptr)
    {
        m_head = new Node(el);
    }
    else
    {
        Node* ptr = m_head;
        Node* p = nullptr;
        while(ptr && ptr->value < el)
        {
            p = ptr;
            ptr = ptr->next;
        }
        if(p == nullptr)
        {
            m_head = new Node(el, m_head);
        }
        else
        {
            p->next = new Node(el, ptr);
        }
    }
    ++m_size;
}

MultySet& MultySet::operator=(const MultySet& ob)
{
    clear();
    Node* ptr = ob.m_head;
    while(ptr)
    {
        add_elem(ptr->value);
        ptr = ptr->next;
    }
    return *this;
}

void MultySet::clear()
{
    while(m_head)
    {
        Remove_elements(m_head->value);
    }
}

void MultySet::print() const
{
    Node* ptr = m_head;
    while(ptr)
    {
        std::cout << ptr->value << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}



// harc 5

#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<char> s;
    std::stack<char> res;
    
    std::string tox;
    std::cin >> tox;
    
    for(int i = 0; i < tox.size(); ++i)
    {
        s.push(tox[i]);
        res.push(tox[tox.size() - i - 1]);
    }
    
    if(res == s)
    {
        std::cout << "tox is polindrome" << std::endl;
    }
    else
    {
        std::cout << "tox is not polindrome" << std::endl;
    }
    
    return 0;
}

