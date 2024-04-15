
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace Intercorso1 {

/* ************************************************************************** */

    template<typename Data>
    class MappableContainer : virtual public TraversableContainer<Data> {
        // Must extend TraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~MappableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        MappableContainer &operator=(const MappableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        MappableContainer &operator=(MappableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const MappableContainer &) const = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const MappableContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member function

        using MapFun = std::function<void(Data &)>;

        void Map(MapFun);

    };

/* ************************************************************************** */

    template<typename Data>
    class PreOrderMappableContainer : public MappableContainer<Data>, public PreOrderTraversableContainer<Data>
        // Must extend MappableContainer<Data>,
        //             PreOrderTraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~PreOrderMappableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const PreOrderMappableContainer &) const = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const PreOrderMappableContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename MappableContainer<Data>::MapFun;

        // type PreOrderMap(argument) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // type Map(argument) specifiers; // Override MappableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class PostOrderMappableContainer : public MappableContainer<Data>, public PostOrderTraversableContainer<Data>{
        // Must extend MappableContainer<Data>,
        //             PostOrderTraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~PostOrderMappableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const PostOrderMappableContainer &) const = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const PostOrderMappableContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename MappableContainer<Data>::MapFun;

        // type PostOrderMap(argument) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // type Map(argument) specifiers; // Override MappableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class InOrderMappableContainer : public MappableContainer<Data>, public InOrderTraversableContainer<Data>{
        // Must extend MappableContainer<Data>,
        //             InOrderTraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~InOrderMappableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        InOrderMappableContainer &operator=(const InOrderMappableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        InOrderMappableContainer &operator=(InOrderMappableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const InOrderMappableContainer &) const = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const InOrderMappableContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename MappableContainer<Data>::MapFun;

        // type InOrderMap(argument) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // type Map(argument) specifiers; // Override MappableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class BreadthMappableContainer : public MappableContainer<Data>, public BreadthTraversableContainer<Data>
        // Must extend MappableContainer<Data>,
        //             BreadthTraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~BreadthMappableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

        /* ************************************************************************ */

        // Specific member function

        // using typename MappableContainer<Data>::MapFun;

        // type BreadthMap(argument) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // type Map(argument) specifiers; // Override MappableContainer member

    };

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif