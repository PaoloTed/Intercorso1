
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace Intercorso1 {

/* ************************************************************************** */

    template<typename Data>
    class List : virtual public ClearableContainer, public LinearContainer<Data>, public DictionaryContainer<Data> {
        // Must extend ClearableContainer,
        //             LinearContainer<Data>,
        //             DictionaryContainer<Data>

    private:

        // ...

    protected:

        // using Container::???;
        using Container::size;

        struct Node {

            // Data
            // ...
            Data value;

            Node *next{nullptr};

            // Constructors
            Node() = default;

            /* ********************************************************************** */

            // Specific constructors
            // ...
            Node(const Data &);

            Node(Data &&);

            /* ********************************************************************** */

            // Copy constructor
            // ...
            Node(const Node &);

            // Move constructor
            // ...
            Node(Node &&) noexcept;

            /* ********************************************************************** */

            // Destructor
            // ...
            ~Node();//nb devi eliminare il successivo

            /* ********************************************************************** */

            // Comparison operators
            // ...
            bool operator==(const Node &) const;

            bool operator!=(const Node &) const;

            /* ********************************************************************** */

            // Specific member functions

            // ...

        };

        //Outside of struct Node
        Node *head{nullptr};
        Node *tail{nullptr};

        // ...

    public:

        // Default constructor
        // List() specifiers;
        List() = default;

        /* ************************************************************************ */

        // Specific constructor
        // List(argument) specifiers; // A list obtained from a TraversableContainer
        List(const TraversableContainer<Data> &);

        // List(argument) specifiers; // A list obtained from a MappableContainer
        List(MappableContainer<Data> &&);

        /* ************************************************************************ */

        // Copy constructor
        // List(argument) specifiers;
        List(const List &);

        // Move constructor
        // List(argument) specifiers;
        List(List &&) noexcept;

        /* ************************************************************************ */

        // Destructor
        // ~List() specifiers;
        ~List();

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument) specifiers;
        List &operator=(const List &);

        // Move assignment
        // type operator=(argument) specifiers;
        List &operator=(List &&) noexcept;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers;
        bool operator==(const List &) const;
        // type operator!=(argument) specifiers;
        bool operator!=(const List &) const;

        /* ************************************************************************ */

        // Specific member functions

        // type InsertAtFront(argument) specifier; // Copy of the value
        void InsertAtFront(const Data &);
        // type InsertAtFront(argument) specifier; // Move of the value
        void InsertAtFront(Data &&);
        // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
        void RemoveFromFront();
        // type FrontNRemove() specifier; // (must throw std::length_error when empty)
        Data FrontNRemove();

        // type InsertAtBack(argument) specifier; // Copy of the value
        void InsertAtBack(const Data &);
        // type InsertAtBack(argument) specifier; // Move of the value
        void InsertAtBack(Data &&);

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        // type Clear() specifiers; // Override ClearableContainer member
        void Clear() override;

        /* ************************************************************************ */

        // Specific member functions (inherited from DictionaryContainer)

        // type Insert(argument) specifier; // Copy of the value
        bool Insert(const Data &) override;
        // type Insert(argument) specifier; // Move of the value
        bool Insert(Data &&) override;
        // type Remove(argument) specifier;
        bool Remove(const Data &) override;

        /* ************************************************************************ */

        // Specific member functions (inherited from LinearContainer)

        // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
        const Data &operator[](unsigned long) const override;
        // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
        Data &operator[](unsigned long) override;

        // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
        const Data &Front() const override;
        // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
        Data &Front() override;

        // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
        const Data &Back() const override;
        // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
        Data &Back() override;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        // using typename TraversableContainer<Data>::TraverseFun;
        using typename TraversableContainer<Data>::TraverseFun;

        // type Traverse(arguments) specifiers; // Override TraversableContainer member
        void Traverse(TraverseFun fun) const override{
            PreOrderTraverse(fun);
        }

        /* ************************************************************************ */

        // Specific member function (inherited from PreOrderTraversableContainer)

        // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
        void PreOrderTraverse(TraverseFun fun) const override{
            PreOrderTraverse(fun, head);
        }

        /* ************************************************************************ */

        // Specific member function (inherited from PostOrderTraversableContainer)

        // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
        void PostOrderTraverse(TraverseFun fun) const override{
            PostOrderTraverse(fun, head);
        }

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)


        // using typename MappableContainer<Data>::MapFun;
        using typename MappableContainer<Data>::MapFun;

        // type Map(argument) specifiers; // Override MappableContainer member
        void Map(const MapFun fun) override{
            PreOrderMap(fun);
        }

        /* ************************************************************************ */

        // Specific member function (inherited from PreOrderMappableContainer)

        // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
        void PreOrderMap(const MapFun fun) override{
            PreOrderMap(fun, head);
        }

        /* ************************************************************************ */

        // Specific member function (inherited from PostOrderMappableContainer)

        // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
        void PostOrderMap(const MapFun fun) override{
            PostOrderMap(fun, head);
        }

    protected:

        // Auxiliary functions, if necessary!
        void PreOrderTraverse(TraverseFun fun, Node *node) const;

        void PostOrderTraverse(TraverseFun fun, Node *node) const;

        void PreOrderMap(MapFun fun, Node *node) const;

        void PostOrderMap(MapFun fun, Node *node) const;

    };

/* ************************************************************************** */

}

#include "list.cpp"

#endif
