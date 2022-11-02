#include <iostream>
#include <vector>

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
    
    int find_from_right(const char&) const; //27//
    DoubleNode* finde_substr(const String&) const; //2//
    int count_of_longest_words() const; //27//
    void print() const;
    
    void add_simbol(const char&); //27 //
    void delete_symbol(const char&); //2//
    void clear();//bolori mej //
    
    String& operator=(const String&); //bolori mej//
    String operator+(const String&) const;//2 //
    
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

int String::find_from_right(const char& c) const 
{
    DoubleNode* p = m_head;
    int k, i;
    for(i = 0; i < m_size; ++i)
    {
        if(p && p->value == c)
        {
            k = i;
        }
        p = p->next;
    }
    if(i == m_size)
    {
        return -1;
    }
    return k;
} 

DoubleNode* String::finde_substr(const String& s) const
{
    DoubleNode* p = m_head;
    DoubleNode* k;
    while(p)
    {
        k = p;
        DoubleNode* p1 = s.m_head;
        while(p1)
        {
            if(p1->value != p->value) break;
            p1 = p1->next;
            p = p->next;
        }
        p = k->next;
        if(p1 == nullptr)
        {
            return p->prev;
        }
    }
    return nullptr;
}

void String::delete_symbol(const char& c)
{
    DoubleNode* p = m_head;
    while(p)
    {
        if(p->value == c)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p = p->next;
            delete p->prev;
        }
    }
}

String& String::operator=(const String& ob)
{
    clear();
    DoubleNode* p = ob.m_head;
    while(p)
    {
        add_simbol(p->value);
        p = p->next;
    }
    return *this;
}

String String::operator+(const String& ob) const
{
    String res = *this;
    DoubleNode* p = ob.m_head;
    while(p)
    {
        res.add_simbol(p->value);
        p = p->next;
    }
    return res;
}

int String::count_of_longest_words() const
{
    DoubleNode* p = m_head;
    std::vector<int> v;
    int count;
    while(p)
    {
        count = 0;
        while(p)
        {
            if(p->value == ' ')
            {
                v.push_back(count);
                break;
            }
            else
            {
                count++;
                p = p->next;
            }
        }
        if(p) 
        {
            p = p->next;
        }
    }
    int max = v[0];
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] > max)
        {
            max = v[i];
        }
    }
    int q = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] == max)
        {
            ++q;
        }
    }
    return q;
}
