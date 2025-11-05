#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template <class T>
class UniquePtr {
 public:
  T* ptr;
  UniquePtr<T>();
  explicit UniquePtr<T>(T*);
  UniquePtr<T>(UniquePtr<T>&&) noexcept;
  UniquePtr<T>& operator=(UniquePtr<T>&&) noexcept;
  ~UniquePtr<T>();
  T* Release();
  void Reset(T* new_ptr = nullptr);
  void Swap(UniquePtr&);
  T* Get() const;
  T& operator*() const;
  T* operator->() const;
  explicit operator bool() const noexcept;
};

template <class T>
UniquePtr<T>::operator bool() const noexcept {
  return ptr != nullptr;
}

template <class T>
T* UniquePtr<T>::operator->() const {
  return ptr;
}

template <class T>
T& UniquePtr<T>::operator*() const {
  return *ptr;
}

template <class T>
T* UniquePtr<T>::Get() const {
  return ptr;
}

template <class T>
void UniquePtr<T>::Swap(UniquePtr& other) {
  UniquePtr temp = std::move(other);
  other = std::move(*this);
  *this = std::move(temp);
}

template <class T>
void UniquePtr<T>::Reset(T* new_ptr) {
  delete ptr;
  ptr = new_ptr;
}

template <class T>
T* UniquePtr<T>::Release() {
  auto new_ptr = ptr;
  ptr = nullptr;
  return new_ptr;
}

template <class T>
UniquePtr<T>::UniquePtr() : ptr(nullptr) {
}

template <class T>
UniquePtr<T>::UniquePtr(T* new_ptr) : ptr(new_ptr) {
}

template <class T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept : ptr(other.ptr) {
  other.ptr = nullptr;
}

template <class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept {
  if (this != &other) {
    delete ptr;
    ptr = other.ptr;
    other.ptr = nullptr;
  }
  return *this;
}

template <class T>
UniquePtr<T>::~UniquePtr() {
  delete ptr;
}

#endif
