#include <iostream>

#include "dcll_impl.h"

namespace dcll
{
dcll::Status DcllImpl::insert_start(data_t new_data)
{
	Node* new_node = new Node(new_data);

	generic_insert(header.get(),new_node,header->next);
	return Status::SUCCESS; 
}

dcll::Status DcllImpl::insert_end(data_t new_data)
{
	Node* new_node = new Node(new_data);

	generic_insert(header->prev,new_node,header.get());
	return Status::SUCCESS;
}

dcll::Status DcllImpl::insert_after(data_t existing_data,data_t new_data) 
{
	Node* new_node = new Node(new_data);
	
	Node* n = nullptr;
	n = search_node(existing_data);
	if(n == nullptr)
		return Status::NOT_FOUND;

	generic_insert(n,new_node,n->next);
	return Status::SUCCESS;
}

dcll::Status DcllImpl::insert_before(data_t existing_data,data_t new_data) 
{
	Node* new_node = new Node(new_data);
	Node* n = nullptr;
	n = search_node(existing_data);
	if(n == nullptr)
		return Status::NOT_FOUND;

	generic_insert(n->prev,new_node,n);
	
	return Status::SUCCESS;
}

dcll::Status DcllImpl::remove_start() 
{
	if(is_list_empty() == true)
		return Status::LIST_EMPTY;

	generic_delete(header->next);
	return Status::SUCCESS;
}

dcll::Status DcllImpl::remove_end() 
{
	if(is_list_empty() == true)
		return Status::LIST_EMPTY;

	generic_delete(header->prev);
	return Status::SUCCESS;
}
dcll::Status DcllImpl::remove_data(data_t data) 
{
	Node* n = nullptr;
	n = search_node(data);

	if(n == nullptr)
		return Status::NOT_FOUND;
	
	generic_delete(n);
	return Status::SUCCESS;
}

std::optional<data_t> DcllImpl::get_start() const 
{
	if(is_list_empty() != true)
		return header->next->data;
	else
		return std::nullopt;
}
std::optional<data_t> DcllImpl::get_end() const 
{
	if(is_list_empty() != true)
		return header->prev->data;
	else
		return std::nullopt;
}

std::optional<data_t> DcllImpl::pop_start() 
{
	if(is_list_empty() == true)
		return std::nullopt;

	data_t data = header->next->data;

	generic_delete(header->next);
	return data;

}
std::optional<data_t> DcllImpl::pop_end() 
{
	if(is_list_empty() == true)
		return std::nullopt;

	data_t data = header->prev->data;

	generic_delete(header->prev);
	return data;
}

dcll::Status DcllImpl::clear_list() 
{
	if(is_list_empty() == true)
		return Status::SUCCESS;
	
	Node* run = header->next;
	Node* run_next;
	while(run != header.get())
	{
		run_next = run->next;

		delete run;

		run = run_next;
	}

	header->next = header.get();
	header->prev = header.get();

	return Status::SUCCESS;
}

dcll::Status DcllImpl::destroy_list() 
{
	if(!header)
		return Status::LIST_EMPTY;

	Node* run = header->next;
	while(run != header.get())
	{
		Node* temp = run;
		run = run->next;
		delete temp;
	}

	delete header.release();
	header = nullptr;

	return Status::SUCCESS;
}

dcll::Status DcllImpl::find(data_t data) const 
{
	Node* n = nullptr;
	n = search_node(data);
	if(n == nullptr)
		return Status::NOT_FOUND;
	else
		return Status::FOUND;
}

bool DcllImpl::is_list_empty() const 
{
	if(header->next == header.get() && header->prev == header.get())
		return true;
	else
		return false;
}

len_t DcllImpl::get_list_length() const 
{
	len_t count = 0;
	Node* run = header->next;
	while(run != header.get())
	{
		count++;
		run = run->next;
	}

	return count;
}
void DcllImpl::show_list() const 
{
	if(!header)
		return;

	Node* run = header->next;
	while(run != header.get())
	{
		std::cout << " " << run->data << " ";
		run = run->next;
	}

	std::cout << std::endl;
}

void DcllImpl::generic_delete(Node* delete_node)
{
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;

	delete delete_node;
}
void DcllImpl::generic_insert(Node* beg,Node* insert_node,Node* end)
{
	beg->next = insert_node;
	insert_node->prev = beg;
	end->prev = insert_node;
	insert_node->next = end;
}

Node* DcllImpl::search_node(data_t data) const
{
	Node* run = header->next;
	while(run != header.get())
	{
		if(run->data == data)
			return run;
		run = run->next;
	}

	return nullptr;
}

Dcll* create()
{
	return new DcllImpl();
}
}
