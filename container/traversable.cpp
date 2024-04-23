
namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    template<typename Accumulator>
    // type Fold(arguments) specifiers;
    Accumulator TraversableContainer<Data>::Fold(FoldFun <Accumulator> fun, Accumulator acc) const {
        Traverse(
                [&acc, fun](const Data &data) {
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
                [&finded, data](const Data &d) {
                    finded = finded || (d == data);
                }
        );
        return finded;
    }

    /* ************************************************************************ */
    //PreOrderTraversableContainer member functions implementation

    template<typename Data>
    void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
        PreOrderFold(fun);
    }

    template<typename Data>
    template<typename Accumulator>
    inline Accumulator
    PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun <Accumulator> fun, Accumulator acc) const {
        PreOrderTraverse(
                [&acc, fun](const Data &data) {
                    acc = fun(data, acc);
                }
        );
        return acc;
    }

/* ************************************************************************** */

    //PostOrderTraversableContainer member functions implementation

    template<typename Data>
    void PostOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
        PostOrderFold(fun);
    }

    template<typename Data>
    template<typename Accumulator>
    inline Accumulator
    PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun <Accumulator> fun, Accumulator acc) const {
        PostOrderTraverse(
                [&acc, fun](const Data &data) {
                    acc = fun(data, acc);
                }
        );
        return acc;
    }


}
