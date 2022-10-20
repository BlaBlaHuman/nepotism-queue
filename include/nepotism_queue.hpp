#ifndef NEPOTISM_QUEUE_HPP_
#define NEPOTISM_QUEUE_HPP_

#include <queue>
#include <utility>

template<typename T>
class nepotism_queue {
public:
    nepotism_queue() = default;
    nepotism_queue(const nepotism_queue& other);
    nepotism_queue& operator=(const nepotism_queue& other);
    ~nepotism_queue() = default;

    std::size_t size() const;
    bool empty() const;

    void push(const T& val);
    void push_nep(const T& val);
    void pop();

    T& front();
    const T& front() const;


private:
    std::queue<T> nep_;
    std::queue<T> not_nep_;
};

template<typename T>
nepotism_queue<T>::nepotism_queue(const nepotism_queue& other) {
    *this = other;
}

template<typename T>
nepotism_queue<T>& nepotism_queue<T>::operator=(const nepotism_queue& other) {
    this->nep_ = other.nep_;
    this->not_nep_ = other.not_nep_;
    return *this;
}

template<typename T>
std::size_t nepotism_queue<T>::size() const { return nep_.size() + not_nep_.size(); }

template<typename T>
bool nepotism_queue<T>::empty() const { return size() == 0; }

template<typename T>
void nepotism_queue<T>::push(const T& val) {
    not_nep_.push(val);
}

template<typename T>
void nepotism_queue<T>::push_nep(const T& val) {
    nep_.push(val);
}

template<typename T>
void nepotism_queue<T>::pop() {
    if (nep_.size())
        nep_.pop();
    else
        not_nep_.pop();
}

template<typename T>
T& nepotism_queue<T>::front() {
    if (nep_.size())
        return nep_.front();
    return not_nep_.front();
}

template<typename T>
const T& nepotism_queue<T>::front() const {
    if (nep_.size())
        return nep_.front();
    return not_nep_.front();
}


#endif