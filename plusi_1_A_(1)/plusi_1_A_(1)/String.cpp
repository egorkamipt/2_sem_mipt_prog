#include "String.h"

String::String() {
	size = 0;
	capacity = 0;
	mass = nullptr;
}

String::String(int64_t new_size, const char* new_mass) : size(new_size), mass((char*) new_mass), capacity(new_size) {
	
}

String::String(const char* new_mass) : mass((char*) new_mass), size(sizeof(new_mass) / sizeof(char)), capacity(sizeof(new_mass) / sizeof(char)) {
}

String::String(const char* new_mass, int64_t new_size) : size(new_size), capacity(new_size) {
	mass = new char[new_size];
	for (int i = 0; i < new_size; ++i) {
		mass[i] = new_mass[i];
	}
}
