#include <iostream>
#include <stdexcept>
#include "cppstring.h"
#include <cstring>
#include <algorithm>

String::String() : begin(nullptr), size_s(0), capacity(0) {
}

String::String(size_t size, char symbol) : begin(nullptr), size_s(size), capacity(size) {
  if (size != 0) {
    begin = new char[size_s];
    for (size_t i = 0; i < size; ++i) {
      begin[i] = symbol;
    }
  }
}

String::String(const char* str) : begin(nullptr), size_s(strlen(str)), capacity(strlen(str)) {
  if (size_s != 0) {
    begin = new char[size_s];
    for (size_t i = 0; i < size_s; ++i) {
      begin[i] = str[i];
    }
  }
}

String::String(const char* mass, size_t size) : begin(nullptr), size_s(size), capacity(size) {
  if (size != 0) {
    begin = new char[size];
    for (size_t i = 0; i < size_s; ++i) {
      begin[i] = mass[i];
    }
  }
}

String::String(const String& other) : begin(nullptr), size_s(other.size_s), capacity(other.capacity) {
  if (capacity != 0) {
    begin = new char[capacity];
    for (size_t i = 0; i < size_s; ++i) {
      begin[i] = other[i];
    }
  }
}

String& String::operator=(const String& other) {
  if (this == &other) {
    return *this;
  }
  delete[] begin;
  begin = nullptr;
  size_s = other.size_s;
  capacity = other.capacity;
  if (size_s != 0) {
    begin = new char[capacity];
    for (size_t i = 0; i < size_s; ++i) {
      begin[i] = other[i];
    }
  }
  return *this;
}

String::~String() {
  delete[] begin;
  begin = nullptr;
  size_s = 0;
  capacity = 0;
}

char& String::operator[](size_t i) {
  return begin[i];
}

const char& String::operator[](size_t i) const {
  return begin[i];
}

char& String::At(size_t i) {
  if (i < size_s) {
    return begin[i];
  }
  throw StringOutOfRange{};
}

const char& String::At(size_t i) const {
  if (i < size_s) {
    return begin[i];
  }
  throw StringOutOfRange{};
}

char& String::Front() {
  return begin[0];
}

const char& String::Front() const {
  return begin[0];
}

char& String::Back() {
  return begin[size_s - 1];
}

const char& String::Back() const {
  return begin[size_s - 1];
}

char* String::CStr() {
  return begin;
}

const char* String::CStr() const {
  return begin;
}

char* String::Data() {
  return begin;
}

const char* String::Data() const {
  return begin;
}

bool String::Empty() const {
  return size_s == 0;
}

size_t String::Size() const {
  return size_s;
}

size_t String::Length() const {
  return size_s;
}

size_t String::Capacity() const {
  return capacity;
}

void String::Clear() {
  size_s = 0;
}

void String::Swap(String& other) {
  std::swap(other, *this);
}

void String::PopBack() {
  --size_s;
}

void String::PushBack(char symbol) {
  ++size_s;
  if (capacity == 0) {
    capacity = 1;
    begin = new char[1];
  }
  if (capacity < size_s) {
    capacity *= 2;
    auto new_begin = new char[capacity];
    for (size_t i = 0; i < size_s - 1; ++i) {
      new_begin[i] = begin[i];
    }
    delete[] begin;
    begin = new_begin;
  }
  begin[size_s - 1] = symbol;
}

String& String::operator+=(const String& other) {
  size_t size_other = other.Size();
  for (size_t i = 0; i < size_other; ++i) {
    PushBack(other.begin[i]);
  }
  return *this;
}

void String::Resize(size_t new_size, char symbol) {
  if (new_size <= size_s) {
    size_s = new_size;
  } else {
    for (size_t i = size_s; i < new_size; ++i) {
      PushBack(symbol);
    }
  }
}

void String::Reserve(size_t new_capacity) {
  capacity = std::max(capacity, new_capacity);
}

void String::ShrinkToFit() {
  capacity = size_s;
}

String operator+(const String& other_one, const String& other_two) {
  String s = other_one;
  s += other_two;
  return s;
}

bool String::operator<(String other) const {
  for (size_t i = 0; i < std::min(size_s, other.size_s); ++i) {
    if (begin[i] < other[i]) {
      return true;
    }
    if (begin[i] > other[i]) {
      return false;
    }
  }
  return other.size_s > size_s;
}

bool String::operator>=(String other) const {
  return !(*this < other);
}

bool String::operator>(String other) const {
  return other < *this;
}

bool String::operator<=(String other) const {
  return !(*this > other);
}

bool String::operator==(String other) const {
  if (size_s == other.size_s) {
    for (size_t i = 0; i < size_s; ++i) {
      if (begin[i] != other[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool String::operator!=(String other) const {
  return !(*this == other);
}

std::ostream& operator<<(std::ostream& element, const String& str) {
  for (size_t i = 0; i < str.size_s; ++i) {
    element << str.begin[i];
  }
  return element;
}
