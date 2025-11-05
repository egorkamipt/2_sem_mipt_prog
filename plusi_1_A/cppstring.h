#ifndef CPPSTRING_H
#define CPPSTRING_H
#include <iostream>

class StringOutOfRange : public std::out_of_range {
 public:
  StringOutOfRange() : std::out_of_range("StringOutOfRange") {
  }
};

class String {
 public:
  char* begin;
  size_t size_s;
  size_t capacity;
  String();
  String(size_t, char);
  String(const char*);  // NOLINT
  String(const char*, size_t);
  String(const String&);
  String& operator=(const String&);
  ~String();
  char& operator[](size_t);
  const char& operator[](size_t) const;
  char& At(size_t);
  const char& At(size_t) const;
  char& Front();
  const char& Front() const;
  char& Back();
  const char& Back() const;
  char* CStr();
  const char* CStr() const;
  char* Data();
  const char* Data() const;
  bool Empty() const;
  size_t Size() const;
  size_t Length() const;
  size_t Capacity() const;
  void Clear();
  void Swap(String&);
  void PopBack();
  void PushBack(char);
  String& operator+=(const String&);
  void Resize(size_t, const char);
  void Reserve(size_t);
  void ShrinkToFit();
  bool operator<(String) const;
  bool operator>(String) const;
  bool operator<=(String) const;
  bool operator>=(String) const;
  bool operator==(String) const;
  bool operator!=(String) const;
};

String operator+(const String&, const String&);
std::ostream& operator<<(std::ostream& element, const String& str);

#endif
