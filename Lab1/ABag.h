#pragma once

#include "bagADT.h"

template <class E>
class ABag : public Bag<E> {
private:
	static const int INITIAL_CAPACITY = 10;
	E* data; // Stores items in bag
	int maxSize; // Max size of bag
	int curSize; // Current number of items

public:
	// Constructor
	ABag(size_t initCapacity = INITIAL_CAPACITY) : maxSize(initCapacity), curSize(0)
	{
		data = new E[maxSize];
	}
	// Destructor
	~ABag() override
	{
		delete[] data;
	}

	// Insert a new item into the bag -- return false if fails and true if
	// successful
	bool addItem(const E& item) override
	{
		if (curSize < bagCapacity()) // Uses bagCapacity() function
		{
			data[curSize++] = item;
			return true;
		}
		return false;
	}

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	bool removeItem(E& item) override
	{
		for (int i = 0; i < curSize; ++i)
		{
			if (data[i] == item)
			{
				item = data[i];
				for (int k = i; k < curSize - 1; ++k)
				{
					data[k] = data[k + 1];
				}
				curSize--;
				return true;
			}
		}
		return false;
	}

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue) override
	{

	}

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	bool find(E& returnValue) const override
	{
		
	}

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	bool inspectTop(E& item) const override
	{

	}

	// empties the bag
	void emptyBag() override
	{

	}

	// use the += operator to add an item to the bag
	bool operator+=(const E& addend) override
	{

	}

	// get the number of items in the bag
	int numItems() const override
	{

	}

	// get the capacity of the bag (size of your bag's array)
	int bagCapacity() const override
	{
		return maxSize;
	}
};