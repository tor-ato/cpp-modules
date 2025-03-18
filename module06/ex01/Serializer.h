#ifndef CPP_MODULES_SERIALIZER_H
#define CPP_MODULES_SERIALIZER_H

#include "Data.h"
#include <stdint.h>

class Serializer {
private:
	Serializer() {}

public:
	static uintptr_t serialize(Data *ptr);

	static Data *deserialize(uintptr_t raw);
};

#endif
