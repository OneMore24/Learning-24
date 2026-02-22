#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "heap.h"
#include <iostream>

template <typename Traits>
class CQueue : public CHeap<Traits> {
private:
    using  value_type   = typename Traits::value_type;
    using  Parent       = CHeap<Traits>;

public:
    CQueue() : Parent(){}

    void enqueue(const value_type &val, ref_type ref = -1){ Parent::push(val, ref); }

    value_type dequeue(){ return Parent::pop(); }
    value_type top()    { return Parent::top(); }
    
    bool isEmpty() const { return Parent::isEmpty(); }
    size_t size () const { return Parent::size();    }
    
    friend std::ostream &operator<<(std::ostream &os, CQueue<Traits> &queue){
        os << "CQueue (Priority): size = " << queue.size() << std::endl;
        os << static_cast<Parent&>(queue) << std::endl; 
        return os;
    }
};

#endif // __QUEUE_H__