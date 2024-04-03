namespace Intercorso1 {


/* ************************************************************************** */

// ...
    template<typename Data>
    template<typename Accumulator>
    // type Fold(arguments) specifiers;
    Accumulator TraversableContainer<Data>::Fold(TraversableContainer<Data>::FoldFun<Accumulator> fun, Accumulator acc) const {
        Traverse(
                [&acc,fun](const Data &data) {
                    acc = fun(data, acc);
                }
        );
        return acc;
    }

    /* ************************************************************************ */

    // Specific member function (inherited from TestableContainer)

    // type Exists(argument) specifiers; // Override TestableContainer member
    template<typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data &data) const noexcept {
        bool finded = false;
        Traverse(
                [&finded,data](const Data &d) {
                    finded = finded || (d == data);
                }
        );
        return finded;
    }

/* ************************************************************************** */

}
