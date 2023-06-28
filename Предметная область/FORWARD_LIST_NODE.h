#ifndef FORWARD_LIST_CONTAINER_FORWARD_LIST_NODE_H
#define FORWARD_LIST_CONTAINER_FORWARD_LIST_NODE_H

# include<memory>
namespace Container
{
    template <typename T> class forward_list; 
    template<typename T> class forward_list_iterator; 

    template<typename T>
    class forward_list_node
    {
        friend class forward_list_iterator<T>;
        friend class forward_list<T>;
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using _forward_list_node = typename Container::forward_list_node<T>;
        using _node_pointer = typename Container::forward_list_node<T>*;

    private:
        value_type _value;
        _node_pointer _next;
        explicit forward_list_node(const_reference value = value_type{}, _node_pointer next = nullptr) : _value(value), _next(next) {};
        ~forward_list_node() = default;
    };
}

#endif 
/**

#ifndef FORWARD_LIST_CONTAINER_FORWARD_LIST_H
#define FORWARD_LIST_CONTAINER_FORWARD_LIST_H
#include<memory>

namespace Container 
{
    template <typename T>
    class ForwardList;

    template<typename T>
    class ForwardList_Iterator;

    template<typename T>
    class ForwardList_Node 
    {
        friend class ForwardList_Iterator<T>;
        friend class ForwardList<T>;
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using _forward_list_node = typename Container::ForwardList_Node<T>;
        using _node_pointer = typename Container::ForwardList_Node<T>*;

    private:
        value_type value;
        _node_pointer next;
        explicit ForwardList_Node(const_reference value = value_type{}, _node_pointer next = nullptr) : value(value), next(next) {};
        ~ForwardList_Node() = default;
    };
}

#endif */