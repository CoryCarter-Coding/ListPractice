#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

using namespace std;

template <class Item>
	class Student
	{
	public:
		// TYPEDEF
		typedef Item value_type;
		// CONSTRUCTOR
		//node(node* init_link, const Item& init_data=Item( ))
		//{ 
		//	data_field = init_data; 
		//	link_field = Student(init_link); 
		//}

		Student(Student<Item>& init_link, const Item& init_data=Item( ))
		{ 
			data_field = init_data; 
			link_field = move(init_link); 
		}
		// MODIFICATION MEMBER FUNCTIONS
		Item& data( ) { return data_field; }
		Student* link( ) { return link_field.get(); }
		Student<Item>& mv_link() { return move(link_field); }
		void set_data(const Item& new_data) { data_field = new_data; }
		//void set_link(node* new_link) { link_field = Student(new_link); }
		void set_link(Student<Item>& new_link) { link_field = move(new_link); }
		// CONST MEMBER FUNCTIONS
		const Item& data( ) const { return data_field; }
		const Student* link( ) const { return link_field.get(); }
	private:
		Item data_field;
		Student<Item> link_field;
	};

	// FUNCTIONS to manipulate a linked list:
	template <class Item>
	void list_clear(Student<Item>& head_ptr);

	template <class Item>
	void list_copy
		(const Student<Item>& source_ptr, Student<Item>& head_ptr, Student<Item>*& tail_ptr);

	template <class Item>
	void list_head_insert(Student<Item>& head_ptr, const Item& entry); 

	template <class Item>
	void list_head_remove(Student<Item>& head_ptr);

	template <class Item>
	void list_insert(Student<Item>* previous_ptr, const Item& entry);

	template <class Item>
	std::size_t list_length(const Student<Item>& head_ptr);

	template <class NodePtr, class SizeType>
	NodePtr* list_locate(Student<NodePtr>& head_ptr, SizeType position);

	template <class Item>
	void list_remove(Student<Item>& previous_ptr);

	template <class NodePtr, class Item>
	NodePtr* list_search(Student<NodePtr>& head_ptr, const Item& target);

#endif 