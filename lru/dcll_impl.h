#ifndef _DCLL_IMPL_H
#define _DCLL_IMPL_H

#include <optional>
#include <memory>

#include "dcll.h"
#include "node.h"

namespace dcll
{
class DcllImpl : public Dcll
{
public:
	DcllImpl()
	{
		header = std::make_unique<Node>();
		header->next = header.get();
		header->prev = header.get();
	}
	
	~DcllImpl() override = default;
	
	/** DI **/
	Status insert_start(data_t new_data) override;
	Status insert_end(data_t new_data) override;
	Status insert_after(data_t existing_data,data_t new_data) override;
	Status insert_before(data_t existing_data,data_t new_data) override;

	Status remove_start() override;
	Status remove_end() override;
	Status remove_data(data_t data) override;

	std::optional<data_t> get_start() const override;
	std::optional<data_t> get_end() const override;

	std::optional<data_t> pop_start() override;
	std::optional<data_t> pop_end() override;

	Status clear_list() override;
	Status destroy_list() override;

	Status find(data_t data) const override;
	bool is_list_empty() const override;
	len_t get_list_length() const override;
	void show_list() const override;

private:
	void generic_delete(Node* delete_node);
	void generic_insert(Node* beg,Node* insert_node,Node* end);
	Node* search_node(data_t data) const;

private:
	std::unique_ptr<Node> header;
};
}	//namespace dcll
#endif
