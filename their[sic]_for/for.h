#pragma once

template<typename type_i>
bool less_than(type_i i, type_i max_i)
{
	return i < max_i;
}

template<typename type_i>
void empty_body(type_i i) { return; }

//you can use your own type with std_inc
//if you implement the prefix increment
template<typename type_i>
type_i std_inc(type_i i)
{
	return ++i;
}

//lambda for loop - reduce code size?
//no capture, converted to function pointer
template<typename type_i>
type_i lambda_for(type_i start_i = 0, type_i max_i = 10,
	bool(*conditional)(type_i, type_i) = less_than,
	void(*body)(type_i) = empty_body,
	type_i(*incrementor)(type_i) = std_inc)
{
	for (; conditional(start_i, max_i); start_i = incrementor(start_i))
	{
		body(start_i);
	}

	return start_i;
}