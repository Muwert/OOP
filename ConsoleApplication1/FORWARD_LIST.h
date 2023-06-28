#ifndef FORWARD_LIST_CONTAINER_FORWARD_LIST_H
#define FORWARD_LIST_CONTAINER_FORWARD_LIST_H

#include "FORWARD_LIST_ITERATOR.h"
#include <memory.h>
#include <iostream>

namespace Container
{
    template<typename T>
    class forward_list 
    {
    private:
        using _forward_list_node = typename Container::forward_list_node<T>;
        using _node_pointer = typename Container::forward_list_node<T>*;
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const reference;
        using iterator = typename Container::forward_list_iterator<T>;
        using const_iterator = const iterator;

        explicit forward_list() : _head(make_node(value_type{}, nullptr)), _tail(_head) { };

        forward_list(forward_list&& other) noexcept
            :_head{ std::move(other._head) }, _tail{ std::move(other._tail) }
        {
            other._head = nullptr;
            other._tail = nullptr;
        }

        forward_list(const forward_list& other) : _head(make_node(other._head->_value, nullptr)), _tail(_head)
        {

            auto node_other = other._head->_next;
            auto last_node = _head;
            while (node_other != other._tail)
            {
                auto new_node = make_node(node_other->_value, nullptr);
                last_node->_next = new_node;
                last_node = new_node;
                node_other = node_other->_next;
            }
            _tail = make_node(value_type{}, nullptr);
            last_node->_next = _tail;
        }

        friend std::ostream& operator<<(std::ostream& os, const forward_list<T>& obj)
        {
            if (obj.empty()) std::cout << "List is empty.";
            else
                for (auto i : obj)
                    os << i;
            return os;
        }


        ~forward_list() = default;

        
        reference front() 
        {
            return _head->_value;
        }

        
        bool empty() const noexcept 
        { 
            return _head == _tail; 
        }


        void clear() noexcept
        {
            while (_head != _tail)
            {
                auto current_node = _head;
                _head = _head->_next;
                delete current_node;
            }
            delete _head;
        }

        void push_front(const_reference value)
        {
            auto current_node = make_node(value, _head);
            _head = current_node;
        }

        void push_back(const_reference value)
        {
            if (_head == nullptr)
                _head = make_node(value, nullptr);
            auto current = _head;
            while (_head->_next != nullptr)
                current = current->_next;
            current->_next = make_node(value, nullptr);
        }

        void push_front(value_type&& value)
        {
            auto current_node = make_node(value, _head);
            _head = current_node;
        }

        void push_back(value_type&& value)
        {
            if (_head->_value == "")
                _head = make_node(value, nullptr);
            else
            {
                auto current = _head;
                while (current->_next != nullptr)
                    current = current->_next;
                current->_next = make_node(value, nullptr);
            }
        }

        _node_pointer pop_front()
        {
            _node_pointer tmp = nullptr;
            if (_head == _tail)

                std::cout << "empty forward_list:" << std::endl;
            else
            {
                tmp = _head;
                _head = _head->_next;
                tmp->_next = nullptr;
            }
            if (tmp)
                return tmp;
        }

        iterator begin() noexcept 
        { 
            return iterator(_head); 
        }

        const_iterator begin() const noexcept 
        { 
            return iterator(_head); 
        }

        iterator end() noexcept 
        { 
            return iterator(_tail); 
        }

        const_iterator end() const noexcept 
        { 
            return iterator(_tail); 
        }


    private:
        _node_pointer _head;
        _node_pointer _tail;

        _node_pointer make_node(value_type value, _node_pointer node_pointer)
        {
            return new forward_list_node<value_type>(value, node_pointer);
        }
    };
}

#endif 
/**
#include "ForwardList_Iterator.h"
#ifndef FORWARD_LIST_CONTAINER_FORWARD_LIST_H
#define FORWARD_LIST_CONTAINER_FORWARD_LIST_H
#include <iostream>
#include <memory.h>

namespace Container 
{
    template<typename T>
    class ForwardList {
    private:
        using _ForwardList_Node = typename Container::ForwardList_Node<T>;
        using _node_pointer = typename Container::ForwardList_Node<T>*;
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const reference;
        using iterator = typename Container::ForwardList_Iterator<T>;
        using const_iterator = const iterator;


        explicit ForwardList() : _head(make_node(value_type{}, nullptr)), _tail(_head) { };

        ForwardList(ForwardList&& other) noexcept
            :_head{ std::move(other._head) }, _tail{ std::move(other._tail) }
        {
            other._head = nullptr;
            other._tail = nullptr;
        }

        ForwardList(const ForwardList& other) : _head(make_node(other._head->value, nullptr)), _tail(_head)
        {
            auto node_other = other._head->next;
            auto last_node = _head;
            while (node_other != other._tail) {
                auto new_node = make_node(node_other->_value, nullptr);
                last_node->_next = new_node;
                last_node = new_node;
                node_other = node_other->_next;
            }
            _tail = make_node(value_type{}, nullptr);
            last_node->_next = _tail;
        }

        friend std::ostream& operator<<(std::ostream& os, const ForwardList<T>& obj)
        {
            if (obj.empty()) std::cout << "Empty.";
            else
                for (auto i : obj)
                    os << i;
            return os;
        }

        ~ForwardList() = default;

        reference front()
        {
            return _head->value;
        }

        bool empty() const noexcept
        {
            return _head == _tail;
        }


        void clear() noexcept
        {
            while (_head != _tail)
            {
                auto current_node = _head;
                _head = _head->next;
                delete current_node;
            }
            delete _head;
        }

        void push_front(const_reference value)
        {
            auto current_node = make_node(value, _head);
            _head = current_node;
        }

        void push_back(const_reference value)
        {
            if (_head == nullptr)
                _head = make_node(value, nullptr);
            auto current = _head;
            while (_head->next != nullptr)
                current = current->_next;
            current->_next = make_node(value, nullptr);
        }

        void push_front(value_type&& value)
        {
            auto current_node = make_node(value, _head);
            _head = current_node;
        }

        void push_back(value_type&& value)
        {
            if (_head->value == "")
                _head = make_node(value, nullptr);
            else {
                auto current = _head;
                while (current->_next != nullptr)
                    current = current->_next;
                current->_next = make_node(value, nullptr);
            }
        }

        _node_pointer pop_front()
        {
            _node_pointer tmp = nullptr;
            if (_head == _tail)
                std::cout << "Empty ForwardList:" << std::endl;
            else {
                tmp = _head;
                _head = _head->next;
                tmp->next = nullptr;
            }
            if (tmp)
                return tmp;
        }

        iterator begin() noexcept
        {
            return iterator(_head);
        }

        const_iterator begin() const noexcept
        {
            return iterator(_head);
        }

        iterator end() noexcept
        {
            return iterator(_tail);
        }

        const_iterator end() const noexcept
        {
            return iterator(_tail);
        }

    private:
        _node_pointer _head;
        _node_pointer _tail;
        _node_pointer make_node(value_type value, _node_pointer node_pointer)
        {
            return new ForwardList_Node<value_type>(value, node_pointer);
        }
    };
}
#endif */