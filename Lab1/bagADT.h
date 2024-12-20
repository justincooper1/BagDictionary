/*
* File:   bagADT.h -- Bag ADT for CSCI 215 Assignment
* Author: Prof Terri Sipantzi
*
* Created on July 14, 2012, 11:46 AM
* Modified on 9/4/2014 -- Changed "const E& inspectTop() const" to "bool inspectTop(const E& item) const".
*   inspectTop now returns false if the bag is empty and true otherwise.
* Modified on 2/4/2015 -- updated the comments for remove(), find(), removeTop(), 
*   and inspectTop() to make them clearer.
* Modified on 05/14/2024 by Prof Sipantzi
*/

#pragma once

#include <stdlib.h>
#include "book.h"

template <class E>
class Bag {
public:
	Bag() {}            // base constructor
	virtual ~Bag() {}   // base destructor

	// Insert a new item into the bag -- return false if fails and true if
	// successful
	virtual bool addItem(const E& item) = 0;

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	virtual bool removeItem(E& item) = 0;

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	virtual bool removeTop(E& returnValue) = 0;

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	virtual bool find(E& returnValue) const = 0;

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	virtual bool inspectTop(E& item) const = 0;

	// empties the bag
	virtual void emptyBag() = 0;

	// use the += operator to add an item to the bag
	virtual bool operator+=(const E& addend) = 0;

	// get the number of items in the bag
	virtual int numItems() const = 0;

	// get the capacity of the bag (size of your bag's array)
	virtual int bagCapacity() const = 0;

	// do not make any changes to this file or you will not get
	// any credit for your work -- Prof Sipantzi (05/13/2022)

};



