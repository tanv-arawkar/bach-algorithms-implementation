#ifndef _DCLL_H
#define _DCLL_H

#include <optional>

#include "types.h"

namespace dcll
{
class Dcll
{
public:
	virtual ~Dcll() = default;

	virtual Status insert_start(data_t new_data) = 0;
	virtual Status insert_end(data_t new_data) = 0;
	virtual Status insert_after(data_t existing_data,data_t new_data) = 0;
	virtual Status insert_before(data_t existing_data,data_t new_data) = 0;

	virtual Status remove_start() = 0;
	virtual Status remove_end() = 0;
	virtual Status remove_data(data_t data) = 0;

	virtual std::optional<data_t> get_start() const = 0;
	virtual std::optional<data_t> get_end() const= 0;

	virtual std::optional<data_t> pop_start() = 0;
	virtual std::optional<data_t> pop_end() = 0;

	virtual Status clear_list() = 0;
	virtual Status destroy_list() = 0;

	virtual Status find(data_t data) const = 0;
	virtual bool is_list_empty() const = 0;
	virtual len_t get_list_length() const = 0;
	virtual void show_list() const = 0;
};

Dcll* create();
}
#endif
