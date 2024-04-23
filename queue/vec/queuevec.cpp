
namespace lasd {

/* ************************************************************************** */

// ...
    template<typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data> &traCon) : Vector<Data>(traCon) {
        tail(size);
        Vector<Data>::Resize(size * 2);
    }

    template<typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> &&mapCon) : Vector<Data>(std::move(mapCon)) {
        tail(size);
        Vector<Data>::Resize(size * 2);
    }


    template<typename Data>
    QueueVec<Data>::QueueVec(const QueueVec &queue) : Vector<Data>(queue) {
        head = queue.head;
        tail = queue.tail;
    }

    template<typename Data>
    QueueVec<Data>::QueueVec(QueueVec &&queue) noexcept : Vector<Data>(std::move(queue)) {
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
    }


    template<typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec &queue) {
        Vector<Data>::operator=(queue);
        head = queue.head;
        tail = queue.tail;
        return *this;
    }

    template<typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(QueueVec &&queue) noexcept {
        Vector<Data>::operator=(std::move(queue));
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
        return *this;
    }

    template<typename Data>
    bool QueueVec<Data>::operator==(const QueueVec &queue) const noexcept {
        if (Size() == queue.Size()) {

            for (unsigned long idx1 = head, unsigned long idx2 = queue.head; idx1<tail; idx1++, idx2++) {
                idx1 %= size;
                idx2 %= queue.size;
                if (Elements[idx1] != queue.Elements[idx2]) {
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
            return Elements[head];
        } else {
            throw std::length_error("Queue is empty");
        }
    }

    template<typename Data>
    Data &QueueVec<Data>::Head() {
        if (head != tail) {
            return Elements[head];
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
        if(head != tail){
            Reduce();
            Data headEl = std::move(Elements[head]);
            head = (head + 1) % size;
            return std::move(headEl);
        }else{
            throw std::length_error("Queue is empty");
        }
    }

    template<typename Data>
    void QueueVec<Data>::Enqueue(const Data &data) {
        Expand();
        Elements[tail] = data;
        tail++;
        tail %= size;
    }

    template<typename Data>
    void QueueVec<Data>::Enqueue(Data &&data) {
        Expand();
        Elements[tail] = std::move(data);
        tail++;
        tail %= size;
    }

template<typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Resize(4);
    head = 0;
    tail = 0;
}

template<typename Data>
void QueueVec<Data>::Resize(unsigned long new_size, unsigned long num){
    Data *new_elements = new Data[new_size];
    unsigned max = (num<= new_size) ? num : new_size;
    for (unsigned long indx1 = head, indx2 = 0; indx2 < max; ++indx1 %= size, ++indx2) {
        new_elements[indx2] = std::move(Elements[indx1]);
    }
}

template<typename Data>
void QueueVec<Data>::Reduce() {
    unsigned long new_size = Size();
    if (new_size + 1 < size / 4) {
        Resize(size / 2, new_size);
    }
}

template<typename Data>
void QueueVec<Data>::Expand() {
    unsigned long new_size = Size();
    if (new_size +1 == size) {
        Resize(size * 2, new_size);
    }
}

/* ************************************************************************** */

}
