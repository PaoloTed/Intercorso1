
namespace lasd {

/* ************************************************************************** */

// ...

    template<typename Data>
    QueueVec<Data>::QueueVec(): Vector<Data>::Vector<Data>(4) {}
    template<typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data> &traCon) : Vector<Data>(traCon){
        numElement = traCon.Size();
        tail = traCon.Size();
        Vector<Data>::Resize(size * 2);
    }

    template<typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> &&mapCon) : Vector<Data>(std::move(mapCon)) {
        numElement = mapCon.Size();
        tail(mapCon.Size());
        Vector<Data>::Resize(size * 2);
    }


    template<typename Data>
    QueueVec<Data>::QueueVec(const QueueVec &queue) : Vector<Data>(queue) {
        numElement = queue.numElement;
        head = queue.head;
        tail = queue.tail;
    }

    template<typename Data>
    QueueVec<Data>::QueueVec(QueueVec &&queue) noexcept : Vector<Data>(std::move(queue)) {
        std::swap(numElement, queue.numElement);
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
    }


    template<typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec &queue) {
        Vector<Data>::operator=(queue);
        numElement = queue.numElement;
        head = queue.head;
        tail = queue.tail;
        return *this;
    }

    template<typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(QueueVec &&queue) noexcept {
        Vector<Data>::operator=(std::move(queue));
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
        std::swap(numElement, queue.numElement);
        return *this;
    }

    template<typename Data>
    bool QueueVec<Data>::operator==(const QueueVec &queue) const noexcept {
        if (Size() == queue.Size()) {

            for (unsigned int idx1 = head, idx2 = queue.head; idx1<tail; idx1++, idx2++) {
                idx1 %= size;
                idx2 %= queue.size;
                if (element[idx1] != queue.element[idx2]) {
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
    template<typename Data>
    const Data &QueueVec<Data>::Head() const {
        if (head != tail) {
            return element[head];
        } else {
            throw std::length_error("Queue is empty");
        }
    }

    template<typename Data>
    Data &QueueVec<Data>::Head() {
        if (head != tail) {
            return element[head];
        } else {
            throw std::length_error("Queue is empty");
        }
    }

    template<typename Data>
    void QueueVec<Data>::Dequeue() {
        if (head != tail) {
            Reduce();
            head = (head + 1) % size;
        } else {
            throw std::length_error("Queue is empty");
        }
    }

    template<typename Data>
    Data QueueVec<Data>::HeadNDequeue() {
        Data temp = Head();
        Dequeue();
        return temp;
    }

    template<typename Data>
    void QueueVec<Data>::Enqueue(const Data &data) {
        if (numElement == size) {
            Expand();
        }
        element[tail] = data;
        tail++;
        tail %= size;
        numElement++;
    }

    template<typename Data>
    void QueueVec<Data>::Enqueue(Data &&data) {
        if (numElement == size) {
            Expand();
        }
        element[tail] = std::move(data);
        tail++;
        tail %= size;

        numElement++;
    }

template<typename Data>
void QueueVec<Data>::Clear() {
    Resize(4,Size());
    head = 0;
    tail = 0;
    numElement = 0;
}

template<typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return numElement == 0;
}

template<typename Data>
unsigned int QueueVec<Data>::Size() const noexcept {
    return numElement;
}

template<typename Data>
void QueueVec<Data>::Resize(unsigned int new_size, unsigned int num){
    Data *new_element = new Data[new_size];
    unsigned max = (num<= new_size) ? num : new_size;
    for (unsigned int indx1 = head, indx2 = 0; indx2 < max; ++indx1 %= size, ++indx2) {
        new_element[indx2] = std::move(element[indx1]);
    }
}

template<typename Data>
void QueueVec<Data>::Reduce() {
    unsigned int new_size = Size();
    if (new_size + 1 < size / 4) {
        Resize(size / 2, new_size);
    }
}

template<typename Data>
void QueueVec<Data>::Expand() {
    unsigned int new_size = Size();
    if (new_size +1 == size) {
        Resize(size * 2, new_size);
    }
}

/* ************************************************************************** */

}
