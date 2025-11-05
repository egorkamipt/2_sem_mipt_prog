#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
  char* mass;
  int64_t size;
  int64_t capacity;
  String();
  String(int64_t, const char*);
  explicit String(const char*); // NOLINT
  String(const char*, int64_t);
  ~String();
  String(const char&);
  const char* operator=(const char*);

};

#endif
