
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */
#include "container.hpp"
/* ************************************************************************** */

namespace Intercorso1 {

/* ************************************************************************** */
    template <typename Data>
    class TestableContainer: virtual public Container {
        // Must extend Container

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~TestableContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        TestableContainer &operator=(const TestableContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        TestableContainer &operator=(TestableContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const TestableContainer &) const = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const TestableContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member function

        // type Exists(argument) specifiers; // (concrete function should not throw exceptions)
        virtual bool Exists(const Data&) const = 0;
    };

/* ************************************************************************** */

}

#endif
