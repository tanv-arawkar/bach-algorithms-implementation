#include <iostream>

#include "dcll.h"

int main()
{
	using namespace dcll;

	Dcll* list = create();

	list->insert_start(10);
	list->insert_start(20);
	list->insert_start(30);

	list->insert_end(100);
	list->insert_end(200);
	list->insert_end(300);

	list->insert_after(100,150);
	list->insert_after(300,350);
	list->insert_after(400,450);

	list->insert_before(30,25);
	list->insert_before(200,225);
	list->insert_before(500,25);

	list->remove_start();
	list->remove_end();
	list->remove_data(100);
	list->remove_data(225);
	list->remove_data(30);
	list->remove_data(300);

	if(auto d = list->get_start()){
		std::cout << *d << std::endl;
	}
	
	if(auto d = list->get_end()){
		std::cout << *d << std::endl;
	}
	
	if(auto d = list->pop_start()){
		std::cout << *d << std::endl;
	}
	
	if(auto d = list->pop_end()){
		std::cout << *d << std::endl;
	}

	list->clear_list();
	list->destroy_list();

	list->show_list();

	return 0;
}
