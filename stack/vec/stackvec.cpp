namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data> &&s) noexcept : Vector<Data>(std::move(s)) {
    std::swap(index, s.index);
}

template <typename Data>
StackVec<Data> &StackVec<Data>::operator=(const StackVec<Data> &s) {
    Vector<Data>::operator=(s);
    index = s.index;
    return *this;
}

template <typename Data>
StackVec<Data> &StackVec<Data>::operator=(StackVec<Data> &&s) noexcept {
    Vector<Data>::operator=(std::move(s));
    std::swap(index, s.index);
    return *this;
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data> &s) const noexcept {
    if (index == s.index) {
        for (unsigned int i = 0; i < index; i++) {
            if (element[i] != s.element[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data> &s) const noexcept {
    return !(*this == s);
}

template <typename Data>
const Data &StackVec<Data>::Top() const {
    if (index == 0) {
        throw std::length_error("Stack is empty");
    }
    return element[index - 1];
}

template <typename Data>
Data &StackVec<Data>::Top() {
    if (index == 0) {
        throw std::length_error("Stack is empty");
    }
    return element[index - 1];
}

template <typename Data>
void StackVec<Data>::Pop() {
    if(index != 0) {
        Reduce();
        index--;
    } else {
        throw std::length_error("Stack is empty");
    }
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if(index != 0) {
        Reduce();
        return std::move(element[--index]);
    } else {
        throw std::length_error("Stack is empty");
    }
}

template <typename Data>
void StackVec<Data>::Push(const Data &d) {
    Expand();
    element[index++] = d;
}

template <typename Data>
void StackVec<Data>::Push(Data &&d) {
    Expand();
    element[index++] = std::move(d);
}

template <typename Data>
bool StackVec<Data>::Empty() const {
    return index == 0;
}

template <typename Data>
unsigned int StackVec<Data>::Size() const {
    return index;
}

template <typename Data>
void StackVec<Data>::Clear() {
    Vector<Data>::Resize(1);
    index = 0;
}

template <typename Data>
void StackVec<Data>::Expand() {
    if (index == size) {
        Vector<Data>::Resize(size * 2);
    }
}

template <typename Data>
void StackVec<Data>::Reduce() {
    if (index + 1 < size / 4) {
        Vector<Data>::Resize(size / 2);
    }
}
/* ************************************************************************** */

}
