#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <class T>
class Vector {
 public:
  using ValueType = T;
  using Pointer = T*;
  using ConstPointer = const T*;
  using Reference = T&;
  using ConstReference = const T&;
  using SizeType = size_t;
  using Iterator = T*;
  using ConstIterator = const T*;
  using ReverseIterator = std::reverse_iterator<Iterator>;
  using ConstReverseIterator = std::reverse_iterator<ConstIterator>;
  T* ptr;
  size_t size;
  size_t capacity;
  Vector();
  explicit Vector(size_t new_size);
  Vector(size_t new_size, const T& value);
  template <class Iterator, class = std::enable_if_t<std::is_base_of_v<
                                std::forward_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>>>
  Vector(Iterator begin, Iterator end) {
    size = std::distance(begin, end);
    capacity = size;
    if (size == 0) {
      ptr = nullptr;
    } else {
      ptr = new T[size];
      try {
        for (size_t i = 0; i < size; ++i) {
          ptr[i] = *(begin + i);
        }
      } catch (...) {
        delete[] ptr;
        throw;
      }
    }
  }
  Vector(std::initializer_list<T> initializer) : Vector(initializer.begin(), initializer.end()) {
  }
  Vector(const Vector& other);
  Vector(Vector&& other);
  Vector& operator=(const Vector& other);
  Vector& operator=(Vector&& other) noexcept;
  ~Vector();
  size_t Size() const noexcept;
  size_t Capacity() const noexcept;
  bool Empty() const noexcept;
  const T& operator[](size_t i) const noexcept;
  T& operator[](size_t i) noexcept;
  const T& At(const size_t& i) const;
  T& At(const size_t& i);
  const T& Front() const;
  T& Front();
  T& Back();
  const T& Back() const;
  const T* Data() const;
  T* Data();
  void Swap(Vector& other);
  void Resize(size_t new_size);
  void Resize(size_t new_size, const T& value);
  void Reserve(size_t new_capacity);
  void ShrinkToFit();
  void Clear();
  void PushBack(const T& value);
  void PushBack(T&& value);
  void PopBack();
  Iterator begin();                      // NOLINT
  Iterator end();                        // NOLINT
  ConstIterator begin() const;           // NOLINT
  ConstIterator end() const;             // NOLINT
  ConstIterator cbegin() const;          // NOLINT
  ConstIterator cend() const;            // NOLINT
  ReverseIterator rbegin();              // NOLINT
  ReverseIterator rend();                // NOLINT
  ConstReverseIterator rbegin() const;   // NOLINT
  ConstReverseIterator rend() const;     // NOLINT
  ConstReverseIterator crbegin() const;  // NOLINT
  ConstReverseIterator crend() const;    // NOLINT
  bool operator<(const Vector& other) const;
  bool operator>(const Vector& other) const;
  bool operator<=(const Vector& other) const;
  bool operator>=(const Vector& other) const;
  bool operator==(const Vector& other) const;
  bool operator!=(const Vector& other) const;
};

template <class T>
bool Vector<T>::operator<(const Vector& other) const {
  for (size_t i = 0; i < std::min(size, other.size); ++i) {
    if (ptr[i] > other.ptr[i]) {
      return false;
    }
    if (ptr[i] < other.ptr[i]) {
      return true;
    }
  }
  return (size < other.size);
}

template <class T>
bool Vector<T>::operator>(const Vector& other) const {
  for (size_t i = 0; i < std::min(size, other.size); ++i) {
    if (ptr[i] < other.ptr[i]) {
      return false;
    }
    if (ptr[i] > other.ptr[i]) {
      return true;
    }
  }
  return (size > other.size);
}

template <class T>
bool Vector<T>::operator<=(const Vector& other) const {
  return !(*this > other);
}

template <class T>
bool Vector<T>::operator>=(const Vector& other) const {
  return !(*this < other);
}

template <class T>
bool Vector<T>::operator==(const Vector& other) const {
  return (!(*this < other) && !(*this > other));
}

template <class T>
bool Vector<T>::operator!=(const Vector& other) const {
  return (*this < other || *this > other);
}

template <class T>
using Iterator = T*;

template <class T>
using ConstIterator = const T*;

template <class T>
using ReverseIterator = std::reverse_iterator<T*>;

template <class T>
using ConstReverseIterator = std::reverse_iterator<const T*>;

template <class T>
Iterator<T> Vector<T>::begin() {  // NOLINT
  return ptr;
}

template <class T>
Iterator<T> Vector<T>::end() {  // NOLINT
  return (ptr + size);
}

template <class T>
ConstIterator<T> Vector<T>::begin() const {  // NOLINT
  return ptr;
}

template <class T>
ConstIterator<T> Vector<T>::end() const {  // NOLINT
  return (ptr + size);
}

template <class T>
ConstIterator<T> Vector<T>::cbegin() const {  // NOLINT
  return ptr;
}

template <class T>
ConstIterator<T> Vector<T>::cend() const {  // NOLINT
  return (ptr + size);
}

template <class T>
ReverseIterator<T> Vector<T>::rbegin() {  // NOLINT
  return std::reverse_iterator(ptr + size);
}

template <class T>
ReverseIterator<T> Vector<T>::rend() {  // NOLINT
  return std::reverse_iterator(ptr);
}

template <class T>
ConstReverseIterator<T> Vector<T>::rbegin() const {  // NOLINT
  return std::reverse_iterator(ptr + size);
}

template <class T>
ConstReverseIterator<T> Vector<T>::rend() const {  // NOLINT
  return std::reverse_iterator(ptr);
}

template <class T>
ConstReverseIterator<T> Vector<T>::crbegin() const {  // NOLINT
  return std::reverse_iterator(ptr + size);
}

template <class T>
ConstReverseIterator<T> Vector<T>::crend() const {  // NOLINT
  return std::reverse_iterator(ptr);
}

template <class T>
void Vector<T>::PopBack() {
  if (size == 0) {
    return;
  }
  ptr[size - 1].~T();
  --size;
}

template <class T>
void Vector<T>::PushBack(const T& value) {
  if (size != capacity) {
    try {
      ptr[size] = value;
    } catch (...) {
      ptr[size].~T();
      throw;
    }
    ++size;
    return;
  }
  if (size == 0) {
    auto* tmp = new T[1];
    try {
      *tmp = value;
    } catch (...) {
      delete[] tmp;
      throw;
    }
    delete[] ptr;
    ptr = tmp;
    ++size;
    capacity = size;
  } else {
    auto* tmp = new T[capacity * 2];
    try {
      for (size_t i = 0; i <= size; ++i) {
        if (i == size) {
          tmp[i] = value;
        } else {
          tmp[i] = ptr[i];
        }
      }
    } catch (...) {
      delete[] tmp;
      throw;
    }
    delete[] ptr;
    ptr = tmp;
    capacity *= 2;
    ++size;
  }
}

template <class T>
void Vector<T>::PushBack(T&& value) {
  if (size != capacity) {
    ptr[size] = std::move(value);
    ++size;
    return;
  }
  if (size == 0) {
    auto* tmp = new T[1];
    *tmp = std::move(value);
    delete[] ptr;
    ptr = tmp;
    ++size;
    capacity = size;
  } else {
    auto* tmp = new T[capacity * 2];
    for (size_t i = 0; i <= size; ++i) {
      if (i == size) {
        tmp[i] = std::move(value);
      } else {
        tmp[i] = std::move(ptr[i]);
      }
    }
    capacity *= 2;
    ++size;
    delete[] ptr;
    ptr = tmp;
  }
}

template <class T>
void Vector<T>::Clear() {
  size = 0;
}

template <class T>
void Vector<T>::ShrinkToFit() {
  if (size == 0) {
    delete[] ptr;
    capacity = 0;
    ptr = nullptr;
  } else {
    auto* tmp = new T[size];
    for (size_t i = 0; i < size; ++i) {
      tmp[i] = std::move(ptr[i]);
    }
    delete[] ptr;
    capacity = size;
    ptr = tmp;
  }
}

template <class T>
void Vector<T>::Reserve(size_t new_capacity) {
  if (new_capacity > capacity) {
    auto* tmp = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) {
      tmp[i] = std::move(ptr[i]);
    }
    delete[] ptr;
    ptr = tmp;
  }
  capacity = new_capacity;
}

template <class T>
void Vector<T>::Resize(size_t new_size, const T& value) {
  if (new_size <= capacity) {
    try {
      for (size_t i = size; i < new_size; ++i) {
        ptr[i] = value;
      }
    } catch (...) {
      for (size_t i = size; i < new_size; ++i) {
        ptr[i].~T();
      }
      throw;
    }
  } else {
    auto* temp = new T[new_size]{};
    try {
      for (size_t i = size; i < new_size; ++i) {
        temp[i] = value;
      }
    } catch (...) {
      delete[] temp;
      throw;
    }
    for (size_t i = 0; i < size; ++i) {
      temp[i] = std::move(ptr[i]);
    }
    delete[] ptr;
    ptr = temp;
    capacity = new_size;
  }
  size = new_size;
}

template <class T>
void Vector<T>::Resize(size_t new_size) {
  if (new_size <= capacity) {
    size = new_size;
    return;
  }
  auto* temp = new T[new_size]{};
  for (size_t i = 0; i < size; ++i) {
    temp[i] = std::move(ptr[i]);
  }
  delete[] ptr;
  ptr = temp;
  capacity = new_size;
  size = new_size;
}

template <class T>
void Vector<T>::Swap(Vector& other) {
  std::swap(size, other.size);
  std::swap(capacity, other.capacity);
  std::swap(ptr, other.ptr);
}

template <class T>
T* Vector<T>::Data() {
  return ptr;
}

template <class T>
const T* Vector<T>::Data() const {
  return ptr;
}

template <class T>
const T& Vector<T>::Back() const {
  return *(ptr + size - 1);
}

template <class T>
T& Vector<T>::Back() {
  return *(ptr + size - 1);
}

template <class T>
const T& Vector<T>::Front() const {
  return *(ptr);
}

template <class T>
T& Vector<T>::Front() {
  return *(ptr);
}

template <class T>
const T& Vector<T>::At(const size_t& i) const {
  if (i >= size) {
    throw std::out_of_range("out_of_range");
  }
  return ptr[i];
}

template <class T>
T& Vector<T>::At(const size_t& i) {
  if (i >= size) {
    throw std::out_of_range("out_of_range");
  }
  return ptr[i];
}

template <class T>
T& Vector<T>::operator[](size_t i) noexcept {
  return ptr[i];
}

template <class T>
const T& Vector<T>::operator[](size_t i) const noexcept {
  return ptr[i];
}

template <class T>
bool Vector<T>::Empty() const noexcept {
  return (size == 0);
}

template <class T>
size_t Vector<T>::Capacity() const noexcept {
  return capacity;
}

template <class T>
size_t Vector<T>::Size() const noexcept {
  return size;
}

template <class T>
Vector<T>::~Vector() {
  size = 0;
  delete[] ptr;
  capacity = 0;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
  if (this != &other) {
    delete[] ptr;
    size = other.size;
    other.size = 0;
    ptr = other.ptr;
    other.ptr = nullptr;
    capacity = other.capacity;
    other.capacity = 0;
  }
  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
  if (this != &other) {
    if (other.size > capacity) {
      delete[] ptr;
      try {
        ptr = new T[other.size];
      } catch (...) {
        size = 0;
        capacity = 0;
        ptr = nullptr;
        throw;
      }
      capacity = other.size;
    }
    size = other.size;
    try {
      for (size_t i = 0; i < size; ++i) {
        ptr[i] = other.ptr[i];
      }
    } catch (...) {
      size = 0;
      throw;
    }
  }
  return *this;
}

template <class T>
Vector<T>::Vector(Vector&& other) {
  size = other.size;
  capacity = other.capacity;
  other.size = 0;
  other.capacity = 0;
  if (size == 0) {
    capacity = 0;
    ptr = nullptr;
  } else {
    ptr = other.ptr;
  }
  other.ptr = nullptr;
}

template <class T>
Vector<T>::Vector(const Vector& other) {
  size = other.size;
  capacity = other.capacity;
  if (size == 0) {
    ptr = nullptr;
    capacity = 0;
  } else {
    ptr = new T[other.capacity];
    try {
      for (size_t i = 0; i < size; ++i) {
        ptr[i] = other.ptr[i];
      }
    } catch (...) {
      delete[] ptr;
      throw;
    }
  }
}

template <class T>
Vector<T>::Vector(size_t new_size, const T& value) {
  size = new_size;
  capacity = new_size;
  if (size == 0) {
    ptr = nullptr;
  } else {
    ptr = new T[new_size];
    try {
      for (size_t i = 0; i < new_size; ++i) {
        ptr[i] = value;
      }
    } catch (...) {
      delete[] ptr;
      throw;
    }
  }
}

template <class T>
Vector<T>::Vector(size_t new_size) {
  size = new_size;
  capacity = new_size;
  if (new_size == 0) {
    ptr = nullptr;
  } else {
    ptr = new T[new_size]{};
  }
}

template <class T>
Vector<T>::Vector() : ptr(nullptr), size(0), capacity(0) {
}

#endif
