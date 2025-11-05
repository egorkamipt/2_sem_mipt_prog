#ifndef OPTIONAL_H_
#define OPTIONAL_H_
#include <iostream>
#include <string>

class BadOptionalAccess : public std::runtime_error {
 public:
  explicit BadOptionalAccess() : std::runtime_error("BadOptionalAccess") {
  }
};

template <class A>
class Optional {
 public:
  char memory[sizeof(A)];
  bool is_alive = false;
  Optional();
  Optional(const Optional& other);
  Optional(Optional&& other);
  explicit Optional(const A& other);
  explicit Optional(A&& other);
  ~Optional();
  Optional<A>& operator=(const Optional& other);
  Optional<A>& operator=(Optional&& other);
  Optional<A>& operator=(const A& other);
  Optional<A>& operator=(A&& other);
  bool HasValue() const;
  explicit operator bool() const noexcept;
  A& Value();
  const A& Value() const;
  A& operator*();
  const A& operator*() const;
  template <class... Arg>
  A& Emplace(Arg&&... args);
  void Reset();
  void Swap(Optional& other);
};

template <class A>
Optional<A>::Optional() {
  is_alive = false;
}

template <class A>
Optional<A>::Optional(const Optional& other) {
  if (other.is_alive) {
    is_alive = true;
    new (memory) A(other.Value());
  }
}

template <class A>
Optional<A>::Optional(Optional&& other) {
  if (other.is_alive) {
    is_alive = true;
    new (memory) A(std::move(other.Value()));
  }
}

template <class A>
Optional<A>::Optional(const A& other) {
  is_alive = true;
  new (memory) A(other);
}

template <class A>
Optional<A>::Optional(A&& other) {
  is_alive = true;
  new (memory) A(std::move(other));
}

template <class A>
Optional<A>::~Optional() {
  if (!is_alive) {
    return;
  }
  Value().~A();
  is_alive = false;
}

template <class A>
Optional<A>& Optional<A>::operator=(const Optional& other) {
  if (this == &other) {
    return *this;
  }
  if (!other.is_alive && is_alive) {
    Value().~A();
    is_alive = false;
  }
  if (other.is_alive && is_alive) {
    Value() = other.Value();
  }
  if (other.is_alive && !is_alive) {
    is_alive = true;
    new (memory) A(other.Value());
  }
  return *this;
}

template <class A>
Optional<A>& Optional<A>::operator=(Optional&& other) {
  if (this == &other) {
    return *this;
  }
  if (!other.is_alive && is_alive) {
    Value().~A();
    is_alive = false;
  }
  if (other.is_alive && is_alive) {
    Value() = std::move(other.Value());
  }
  if (other.is_alive && !is_alive) {
    is_alive = true;
    new (memory) A(std::move(other.Value()));
  }
  return *this;
}

template <class A>
Optional<A>& Optional<A>::operator=(const A& other) {
  if (is_alive) {
    Value().~A();
  }
  is_alive = true;
  new (memory) A(other);
  return *this;
}

template <class A>
Optional<A>& Optional<A>::operator=(A&& other) {
  if (is_alive) {
    Value().~A();
  }
  is_alive = true;
  new (memory) A(std::move(other));
  other = std::move(A());
  return *this;
}

template <class A>
bool Optional<A>::HasValue() const {
  return is_alive;
}

template <class A>
Optional<A>::operator bool() const noexcept {
  return is_alive;
}

template <class A>
A& Optional<A>::Value() {
  if (!is_alive) {
    throw BadOptionalAccess{};
  }
  return *reinterpret_cast<A*>(memory);
}

template <class A>
const A& Optional<A>::Value() const {
  if (!is_alive) {
    throw BadOptionalAccess{};
  }
  return *reinterpret_cast<const A*>(memory);
}

template <class A>
A& Optional<A>::operator*() {
  return *reinterpret_cast<A*>(memory);
}

template <class A>
const A& Optional<A>::operator*() const {
  return *reinterpret_cast<const A*>(memory);
}

template <class A>
template <class... Arg>
A& Optional<A>::Emplace(Arg&&... args) {
  if (is_alive) {
    Value().~A();
  }
  is_alive = true;
  return *(new (memory) A(std::forward<Arg>(args)...));
}

template <class A>
void Optional<A>::Reset() {
  if (is_alive) {
    Value().~A();
    is_alive = false;
  }
}

template <class A>
void Optional<A>::Swap(Optional& other) {
  std::swap(other, *this);
}

#endif
