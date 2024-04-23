
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    class Container {

    private:

        // ...

    protected:

        // ...
        unsigned long size {0};//intero senza segno


        /* ************************************************************************ */

        // Default constructor
        Container() = default;//default indica che si utilizza il costruttore di default
        // Container() specifiers;


    public:

        // Destructor
        // ~Container() specifiers
        virtual ~Container() = default;
        //default indica che si utilizza il distruttore di default
        //è virtuale cosi in caso di ereditarietà si chiama il distruttore della classe derivata
        //Essendo una classe astratta ha senso creare un distruttore di default ?

        /* ************************************************************************ */


        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        Container &operator=(const Container &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        Container &operator=(Container &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const Container &) const noexcept= delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const Container &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member functions

        // type Empty() specifiers; // (concrete function should not throw exceptions)
        virtual bool Empty() const = 0; //virtual...= 0 indica che è una funzione virtuale pura e che deve essere implementata nelle classi derivate

        // type Size() specifiers; // (concrete function should not throw exceptions)
        virtual unsigned Size() const = 0;

    };

/* ************************************************************************** */

    class ClearableContainer : virtual public Container {
        // Must extend Container

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~ClearableContainer() specifiers
        // ~ClearableContainer() = default;
        virtual ~ClearableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        ClearableContainer &operator=(const ClearableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        ClearableContainer &operator=(ClearableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const ClearableContainer &) const noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const ClearableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member functions

        // type Clear() specifiers;
        virtual void Clear() const = 0;

    };

/* ************************************************************************** */
    class ResizableContainer : virtual public ClearableContainer {
        // Must extend ClearableContainer

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~ResizableContainer() specifiers
        virtual ~ResizableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        ResizableContainer &operator=(const ResizableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        ResizableContainer &operator=(ResizableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const ResizableContainer &) const = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const ResizableContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member functions

        // type Resize(argument) specifiers;
        virtual void Resize(unsigned long) = 0;


        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        // type Clear() specifiers; // Override ClearableContainer member
        void Clear() const override = 0;

    };

/* ************************************************************************** */

}

#endif
