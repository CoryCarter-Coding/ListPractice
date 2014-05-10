#ifndef STUDENT_COMMANDS_H
#define STUDENT_COMMANDS_H

#include <iostream>
#include <cassert>
#include <cstdlib>

#include "Student_Node.h"

using namespace std;

template<class Item>
int list_clear(Student<Item>& head_ptr)
{
	while (head_ptr != NULL)
	{
		list_head_remove(head_ptr);
	}    
}

template <class Item>
void list_copy(Student<Item>& source_ptr,Student<Item>& head_ptr, Student<Item>*& tail_ptr) 
{
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list
	if (source_ptr == NULL)
	    return;	

	// Make the head node for the newly created list, and put data in it
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr.get(); 
	
	// Copy rest of the nodes one at a time, adding at the tail of new list
	source_ptr = source_ptr->link( ); 
        while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
}

template <class Item>
void list_head_insert(Student<Item>& head_ptr, const Item& entry)
{
	head_ptr = Student<Item>(new Student<Item>(head_ptr, entry));
}

template <class Item>
void list_head_remove(Student<Item>& head_ptr)
{
	head_ptr = head_ptr->mv_link( );
}

template <class Item>
void list_insert(Student<Item>* previous_ptr, const Item& entry) 
{
	Student<Item> insert_ptr = Student<Item>(new Student<Item>(entry, previous_ptr->mv_link( )));
	previous_ptr->set_link(move(insert_ptr));
}

template <class Item>
std::size_t list_length(const Student<Item>& head_ptr)
    // Library facilities used: cstdlib
{
	const Student<Item> *cursor;
	std::size_t answer;
	
	answer = 0;
	for (cursor = head_ptr.get(); cursor != NULL; cursor = cursor->link( ))
	    ++answer;
	
	return answer;
}

template <class NodePtr, class SizeType>
NodePtr* list_locate(Student<NodePtr>& head_ptr, SizeType position) 
    // Library facilities used: cassert, cstdlib
{
	NodePtr* cursor;
	SizeType i;
    
	assert(0 < position);
	cursor = head_ptr.get();
	for (i = 1; (i < position) && (cursor != NULL); ++i)
	    cursor = cursor->link( );
	return cursor;
}

template <class Item>
void list_remove(Student<Item>* previous_ptr)
{
	Student<Item> *remove_ptr = previous_ptr->link( );
	previous_ptr->set_link(remove_ptr->mv_link( ));
	//delete remove_ptr;
}

template <class NodePtr, class Item>
NodePtr* list_search(Student<NodePtr>& head_ptr, const Item& target) 
    // Library facilities used: cstdlib
{
	NodePtr* cursor;
	
	for (cursor = head_ptr.get(); cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
}



#endif