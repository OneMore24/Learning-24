#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <iostream>
#include <fstream>
#include <mutex>
#include "../general/types.h"
using namespace std;

template <typename T, typename _Func>
struct ListTrait{
    using value_type = T;
    using Func       = _Func;
};

template <typename T>
struct AscendingTrait   : public ListTrait<T, std::greater<T> >{};

template <typename T>
struct DescendingTrait  : public ListTrait<T, std::less<T> >{};

template <typename Traits>
class NodeLinkedList{
    using  value_type  = typename Traits::value_type;
    using  Node        = NodeLinkedList<Traits>;

private:
    value_type  m_data;
    ref_type    m_ref;
    Node       *m_pNext = nullptr;

public:
    NodeLinkedList(){}
    NodeLinkedList( value_type _value, ref_type _ref = -1, Node *_pNext = nullptr)
                : m_data(_value), m_ref(_ref), m_pNext(_pNext){   }

    value_type  GetValue    () const { return m_data;  }
    value_type &GetValueRef ()       { return m_data;  }

    ref_type    GetRef      () const { return m_ref;   }
    ref_type   &GetRefRef   ()       { return m_ref;   }

    Node      * GetNext     () const { return m_pNext; }
    Node      *&GetNextRef  ()       { return m_pNext; }

    Node &operator=(const Node &another){
        m_data  = another.GetValue();
        m_ref   = another.GetRef();
        return *this;
    }

    bool operator==(const Node &another) const  { return m_data == another.GetValue();  }
    bool operator< (const Node &another) const  { return m_data <  another.GetValue();  }
};

template <typename Container>
class LinkedListForwardIterator{
public:
    using value_type  = typename Container::value_type;
    using Node        = typename Container::Node;

private:
    Container  *m_pContainer = nullptr;
    Node       *m_pNode       = nullptr;

public:
    LinkedListForwardIterator(Container *pContainer, Node *pNode = nullptr)
                            : m_pContainer(pContainer), m_pNode(pNode){}
    LinkedListForwardIterator(LinkedListForwardIterator<Container> &another)
                            : m_pContainer(another.m_pContainer), m_pNode(another.m_pNode){}

    value_type &operator*() { return m_pNode->GetValueRef(); }

    LinkedListForwardIterator<Container> &operator++(){
        if( m_pNode )
            m_pNode = m_pNode->GetNext();
        return *this;
    }

    bool operator!=(const LinkedListForwardIterator &another) const { return m_pNode != another.m_pNode; }
    bool operator==(const LinkedListForwardIterator &another) const { return m_pNode == another.m_pNode; }
};

template <typename Traits>
class CLinkedList {
    using  value_type       = typename Traits::value_type;
    using  Node             = NodeLinkedList<Traits>;
    using  forward_iterator = LinkedListForwardIterator<CLinkedList<Traits> >;
    friend forward_iterator;

private:
    Node   *m_pRoot     = nullptr;
    Node   *m_pLast     = nullptr;
    size_t  m_nElements = 0;
    mutable std::mutex m_mutex;

public:

    CLinkedList()  : m_pRoot(nullptr), m_pLast(nullptr), m_nElements(0) {}
    CLinkedList(const CLinkedList &another);
    CLinkedList(CLinkedList &&another) noexcept;
    virtual ~CLinkedList();

    CLinkedList &operator=(const CLinkedList &another);
    CLinkedList &operator=(CLinkedList &&another) noexcept;

    value_type       &operator[](size_t index);
    const value_type &operator[](size_t index) const;

    size_t getSize() const { return m_nElements; }

    forward_iterator begin() { return forward_iterator(this, m_pRoot); }
    forward_iterator end()   { return forward_iterator(this, nullptr); }


    void push_back  (const value_type &val, ref_type ref);
    void Insert     (const value_type &val, ref_type ref);

    template <typename ObjFunc, typename ...Args>
    void Foreach    (ObjFunc of, Args... args)  { ::Foreach(*this, of, args...); }

    template <typename ObjFunc, typename ...Args>
    auto FirstThat  (ObjFunc of, Args... args)  { return ::FirstThat(*this, of, args...); }

    friend ostream &operator<<(ostream &os, const CLinkedList<Traits> &container){
        os << "CLinkedList: size = " << container.m_nElements << endl;
        os << "[";
        Node *pTemp = container.m_pRoot;
        for (size_t i = 0; i<container.getSize(); i++) {
            os << "(" << pTemp->GetValue() << ":" << pTemp->GetRef() << ")";
            pTemp = pTemp->GetNext();
            if (pTemp) os << ","; 
        } 
        os << "]" << endl;
        return os;
    } 

    friend istream &operator>>(istream &is, CLinkedList<Traits> &container);

private:
    void InternalInsert (Node *&rParent, const value_type &val, ref_type ref);
    void CopyFrom       (const CLinkedList &another);
    void Clear          ();
};

template <typename Traits>
CLinkedList<Traits>::CLinkedList(const CLinkedList &another) 
    : m_pRoot(nullptr), m_pLast(nullptr), m_nElements(0) { CopyFrom(another); }

template <typename Traits>
CLinkedList<Traits>::~CLinkedList() { Clear(); }

template <typename Traits>
CLinkedList<Traits> &CLinkedList<Traits>::operator=(const CLinkedList &another){
    if (this == &another) return *this;
    Clear();
    CopyFrom(another);
    return *this;
}

template <typename Traits>
CLinkedList<Traits> &CLinkedList<Traits>::operator=(CLinkedList &&another) noexcept {
    if (this == &another) return *this;
    Clear();

    m_pRoot             = another.m_pRoot;
    m_pLast             = another.m_pLast;
    m_nElements         = another.m_nElements;

    another.m_pRoot     = nullptr;
    another.m_pLast     = nullptr;
    another.m_nElements = 0;

    return *this;
}

template <typename Traits>
typename CLinkedList<Traits>::value_type &CLinkedList<Traits>::operator[](size_t index) {
    Node *p_temp = m_pRoot;
    for (size_t i=0; i<index; ++i)
        p_temp = p_temp->GetNext();
    return p_temp->GetValueRef();
}

template <typename Traits>
const typename CLinkedList<Traits>::value_type &CLinkedList<Traits>::operator[](size_t index) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (index >= m_nElements) {
        throw std::out_of_range("Index out of range");
    }
    
    Node *current = m_pRoot;
    for (size_t i = 0; i < index; ++i) {
        current = current->GetNext();
    }
    
    return current->GetValue();
}
#endif // __LINKEDLIST_H__