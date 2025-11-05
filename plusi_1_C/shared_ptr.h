#include <stdexcept>
#include <iostream>
#ifndef SHARED_PTR_H
#define SHARED_PTR_H

template <class T>
class SharedPtr {
 public:
  T* ptr = nullptr;
  int64_t* counter = nullptr;
  SharedPtr<T>();
  ~SharedPtr<T>();
  SharedPtr<T>(T* new_ptr);  // NOLINT
  SharedPtr<T>(const SharedPtr<T>& other);
  SharedPtr<T>& operator=(const SharedPtr<T>& other);
  SharedPtr<T>(SharedPtr<T>&& other) noexcept;
  SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept;
  void Reset(T* new_ptr = nullptr);
  void Swap(SharedPtr<T>& other);
  T* Get() const;
  int64_t UseCount() const;
  T& operator*() const;
  T* operator->() const;
  explicit operator bool() const {
    return ptr;
  }
};

template <class T>
SharedPtr<T>::~SharedPtr() {
  if (counter == nullptr) {
    return;
  }
  if (*counter == 1) {
    delete counter;
    delete ptr;
  } else {
    --(*counter);
  }
  counter = nullptr;
  ptr = nullptr;
}

template <class T>
T* SharedPtr<T>::operator->() const {
  return ptr;
}

template <class T>
T& SharedPtr<T>::operator*() const {
  return *ptr;
}

template <class T>
int64_t SharedPtr<T>::UseCount() const {
  if (ptr == nullptr) {
    return 0;
  }
  return *counter;
}

template <class T>
T* SharedPtr<T>::Get() const {
  return ptr;
}

template <class T>
void SharedPtr<T>::Swap(SharedPtr<T>& other) {
  std::swap(other, *this);
}

template <class T>
void SharedPtr<T>::Reset(T* new_ptr) {
  --(*counter);
  if (*counter == 0) {
    delete counter;
    delete ptr;
    counter = nullptr;
    ptr = nullptr;
  }
  counter = new int64_t;
  *counter = 1;
  ptr = new_ptr;
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  if (counter != nullptr) {
    if (*counter == 1) {
      delete counter;
      delete ptr;
    } else {
      --(*counter);
    }
  }
  ptr = other.ptr;
  counter = other.counter;
  other.ptr = nullptr;
  other.counter = nullptr;
  return *this;
}

template <class T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& other) noexcept {
  ptr = other.ptr;
  counter = other.counter;
  other.ptr = nullptr;
  other.counter = nullptr;
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other) {
  if (this == &other) {
    return *this;
  }
  if (counter != nullptr) {
    if (*counter == 1) {
      delete ptr;
      delete counter;
    } else {
      --(*counter);
    }
  }
  ptr = other.ptr;
  if (other.counter != nullptr) {
    ++(*other.counter);
  }
  counter = other.counter;
  return *this;
}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other) {
  ptr = other.ptr;
  if (other.counter != nullptr) {
    ++(*(other.counter));
  }
  counter = other.counter;
}

template <class T>
SharedPtr<T>::SharedPtr(T* new_ptr) : ptr(new_ptr) {
  if (new_ptr != nullptr) {
    counter = new int64_t;
    *counter = 1;
  }
}

template <class T>
SharedPtr<T>::SharedPtr() : ptr(nullptr), counter(nullptr) {
}

#endif
