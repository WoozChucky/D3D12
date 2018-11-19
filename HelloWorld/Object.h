#pragma once

#include "DX12Defines.h"

/**
 * Objects should not be copied or assigned unless explicitly allowed by defining
 * the appropriate functions in the derived class.
 */
class Object
{
public:
	Object(const Object&) = delete;
	Object(Object&&) = delete;

protected:
	Object() = default;
	virtual ~Object() = default;

	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};