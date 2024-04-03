
namespace Intercorso1 {

/* ************************************************************************** */

// ...
    template<typename Data>
    void MappableContainer<Data>::Map(MapFun f) {
        Traverse(
                [&f](Data &data) {
                    f(data);
                }
        );
    }

/* ************************************************************************** */

}
