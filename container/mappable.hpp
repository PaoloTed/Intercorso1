
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */
#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

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
        MappableContainer &operator=(const MappableContainer &) noexcept = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        MappableContainer &operator=(MappableContainer &&) noexcept = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const MappableContainer &) const  noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const MappableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        using MapFun = std::function<void(Data &)>;

        virtual void Map(const MapFun) = 0;

    };

/* ************************************************************************** */

    template<typename Data>
    class PreOrderMappableContainer : virtual public MappableContainer<Data>,  virtual public PreOrderTraversableContainer<Data>{
        // Must extend MappableContainer<Data>,
        //             PreOrderTraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~PreOrderMappableContainer() specifiers
        virtual ~PreOrderMappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        PreOrderMappableContainer &operator=(const PreOrderMappableContainer &)  noexcept = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const PreOrderMappableContainer &) const noexcept = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const PreOrderMappableContainer &) const  noexcept= delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename MappableContainer<Data>::MapFun;
        using typename MappableContainer<Data>::MapFun;

        // type PreOrderMap(argument) specifiers;
         virtual void PreOrderMap(const MapFun) = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // type Map(argument) specifiers; // Override MappableContainer member
        void Map(const MapFun fun) override{
            PreOrderMap(fun);
        }

    };

/* ************************************************************************** */

    template<typename Data>
    class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data>{
        // Must extend MappableContainer<Data>,
        //             PostOrderTraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~PostOrderMappableContainer() specifiers
        virtual ~PostOrderMappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const PostOrderMappableContainer &) const noexcept = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename MappableContainer<Data>::MapFun;
        using typename MappableContainer<Data>::MapFun;

        // type PostOrderMap(argument) specifiers;
        virtual void PostOrderMap(const MapFun) = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // type Map(argument) specifiers; // Override MappableContainer member
          void Map(const MapFun fun) override{
            PostOrderMap(fun);
        }

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
    class BreadthMappableContainer : public MappableContainer<Data>, public BreadthTraversableContainer<Data>{
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
