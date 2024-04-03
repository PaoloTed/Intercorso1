
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace Intercorso1 {

/* ************************************************************************** */

    template<typename Data>
    class TraversableContainer : virtual public TestableContainer<Data> {
        // Must extend TestableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~TraversableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        TraversableContainer &operator=(const TraversableContainer &) = delete;// delete indica che la funzione non puo' essere chiamata

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        TraversableContainer &operator=(TraversableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator==(const TraversableContainer &) const noexcept = delete;// perche' delete se sopra dice che potrebbe essere possibile?

        // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator!=(const TraversableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        using TraverseFun = std::function<void(const Data &)>;
        // std::function<void(const Data &)> è un tipo di funzione che accetta
        // un riferimento costante a Data come parametro e non restituisce nulla (void).

        // type Traverse(arguments) specifiers;
        virtual void Traverse(TraverseFun) const = 0;
        //template<typename Accumulator>
        template<typename Accumulator>
        // using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;
        using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

        template<typename Accumulator>
        // type Fold(arguments) specifiers;
        inline Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;

        /* ************************************************************************ */

        // Specific member function (inherited from TestableContainer)

        // type Exists(argument) specifiers; // Override TestableContainer member
        inline bool Exists(const Data &) const noexcept override;
    };

/* ************************************************************************** */

    template<typename Data>
    class PreOrderTraversableContainer : virtual public TraversableContainer<Data> {
        // Must extend TraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~PreOrderTraversableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        PreOrderTraversableContainer &operator=(const PreOrderTraversableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        PreOrderTraversableContainer &operator=(PreOrderTraversableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator==(const PreOrderTraversableContainer &) const

        noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator!=(const PreOrderTraversableContainer &) const

        noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename TraversableContainer<Data>::TraverseFun;

        // type PreOrderTraverse(arguments) specifiers;

        // template <typename Accumulator>
        // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        // template <typename Accumulator>
        // type PreOrderFold(arguments) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        // type Traverse(arguments) specifiers; // Override TraversableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class PostOrderTraversableContainer : virtual public TraversableContainer<Data> {
        // Must extend TraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~PostOrderTraversableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        PostOrderTraversableContainer &operator=(const PostOrderTraversableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        PostOrderTraversableContainer &operator=(PostOrderTraversableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator==(const PostOrderTraversableContainer &) const noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator!=(const PostOrderTraversableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename TraversableContainer<Data>::TraverseFun;

        // type PostOrderTraverse(arguments) specifiers;

        // template <typename Accumulator>
        // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        // template <typename Accumulator>
        // type PostOrderFold(arguments) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        // type Traverse(arguments) specifiers; // Override TraversableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class InOrderTraversableContainer : virtual public TraversableContainer<Data> {
        // Must extend TraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~InOrderTraversableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        InOrderTraversableContainer &operator=(const InOrderTraversableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        InOrderTraversableContainer &operator=(InOrderTraversableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator==(const InOrderTraversableContainer &) const noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
        bool operator!=(const InOrderTraversableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        // using typename TraversableContainer<Data>::TraverseFun;

        // type InOrderTraverse(arguments) specifiers;

        // template <typename Accumulator>
        // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        // template <typename Accumulator>
        // type InOrderFold(arguments) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        // type Traverse(arguments) specifiers; // Override TraversableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class BreadthTraversableContainer {
        // Must extend TraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~BreadthTraversableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
        // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

        /* ************************************************************************ */

        // Specific member function

        // using typename TraversableContainer<Data>::TraverseFun;

        // type BreadthTraverse(arguments) specifiers;

        // template <typename Accumulator>
        // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        // template <typename Accumulator>
        // type BreadthFold(arguments) specifiers;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        // type Traverse(arguments) specifiers; // Override TraversableContainer member

    };

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
