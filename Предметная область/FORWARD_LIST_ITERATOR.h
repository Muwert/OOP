#ifndef FORWARD_LIST_CONTAINER_FORWARD_LIST_ITERATOR_H
#define FORWARD_LIST_CONTAINER_FORWARD_LIST_ITERATOR_H

#include <iterator>
#include <cassert>
#include "FORWARD_LIST_NODE.h"
#pragma warning(disable : 4996)

namespace Container {
    template<typename T>
    class forward_list_iterator : public std::iterator<std::forward_iterator_tag, T, T*, T&> 
    {
        friend class forward_list<T>;

    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const reference;
        using _forward_list_node = typename Container::forward_list_node<T>;
        using _node_pointer = typename Container::forward_list_node<T>*;
        using iterator = typename Container::forward_list_iterator<T>;
        using const_iterator = const iterator;

        reference operator* () const {
            return _pointee->_value;
        }

        iterator& operator++() {
            _pointee = _pointee->_next;
            return *this;
        }

        iterator operator++(int) {
            iterator retval(_pointee);
            ++(*this);
            return retval;
        }

        bool operator == (iterator other) const {
            return _pointee == other._pointee;
        }

        bool operator!= (iterator other) const {
            return _pointee != other._pointee;
        }

        friend std::ostream& operator<<(std::ostream& os, const forward_list<T>& obj);

    private:
        _node_pointer _pointee;
        explicit forward_list_iterator(_node_pointer pointee) :_pointee(pointee) {};
    };
}

#endif 
