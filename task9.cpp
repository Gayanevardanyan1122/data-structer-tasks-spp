#include <iostream>

struct DoubleNode
{
  DoubleNode(char val = 0, DoubleNode* p = nullptr, DoubleNode* n = nullptr)
    : value(val)
    , prev(p)
    , next(n)
    {}
  ~DoubleNode() {}
  
  char value;
  DoubleNode* prev;
  DoubleNode* next;
};

class String
{
public:
    String();
    String(const char*);
    String(const String&);
    ~String();
    
public:
    int find(const char&) const;
    int count_of_words() const;
    void print() const;
    
    void add_simbol(const char&);
    void clear();
    
private:
    DoubleNode* m_head;
    int m_size;
};

String::String()
    : m_head(nullptr)
    , m_size(0)
{
    std::cout << "default ctor" << std::endl;
}

String::String(const char* num)
    : m_head(new DoubleNode(*num))
    , m_size(1)
{
    std::cout << "ctor with perimetre" << std::endl;
}

String::String(const String& ob)
    : m_head(nullptr)
    , m_size(0)
{
    DoubleNode* ptr = ob.m_head;
    while(ptr)
    {
        add_simbol(ptr->value);
        ptr = ptr->next;
    }
    std::cout << "copy ctor" << std::endl;
}

String::~String()
{
    clear();
    std::cout << "dtor" << std::endl;
}

int String::find(const char& symbol) const 
{
    DoubleNode* ptr = m_head;
    for(int i = 0; i < m_size; ++i)
    {
        if(ptr->value == symbol)
        {
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}

int String::count_of_words() const
{
    DoubleNode* ptr = m_head;
    int count = 1;
    for(int i = 0; i < m_size; ++i)
    {
        if(ptr->value == ' '  &&  ptr->next != nullptr && ptr->prev != nullptr)
        {
            ++count;
        }
        ptr = ptr -> next;
    }
    return count;
} 

void String::add_simbol(const char& c)
{
    if(m_head != nullptr)
    {
        DoubleNode* ptr = m_head;
        for(int i = 0; i < m_size - 1; ++i)
        {
            ptr = ptr->next;
        }
        ptr->next = new DoubleNode(c, ptr);
    }
    else
    {
        m_head = new DoubleNode(c);
    }
    ++m_size;
}

void String::clear()
{
    for(int i = 0; i < m_size - 1; ++i)
    {
        m_head = m_head->next;
        delete m_head->prev;
    }
    delete m_head;
    m_size = 0;
    m_head = nullptr;
}

void String::print() const
{
    DoubleNode* ptr = m_head;
    while(ptr)
    {
        std::cout << ptr->value;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}




//task9.5//
#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s1, s2;
    std::stack<int> s;
    std::stack<int> s3;
    
    for(int i = 0; i < 10; ++i)
    {
        s1.push(2*i + 1);
        s2.push(2*i);
    }
    
    while(!s1.empty())
    {
        s.push(s1.top());
        s1.pop();
    }
    while(!s.empty())
    {
        s3.push(s.top());
        s.pop();
    }
    while(!s2.empty())
    {
        s3.push(s2.top());
        s2.pop();
    }
    
    while(!s3.empty())
    {
        std::cout << s3.top() << " ";
        s3.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
