#ifndef _TYPES_H
#define _TYPES_H

#include <cstddef>
namespace dcll
{

enum class Status
{
	SUCCESS,
	FAILURE,
	FOUND,
	NOT_FOUND,
	LIST_EMPTY
};

using data_t = int;
using len_t = std::size_t;
	
} //namespace dcll
#endif
