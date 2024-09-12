#pragma once

#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"
#include <memory>

template <class Key, class E>

class BDictionary : public Dictionary<Key, E>
{
private:
	std::unique_ptr<ABag<KVpair<Key, E>>> bag;

public:
	// Constructor
    BDictionary(size_t initSize = 0) {
        if (initSize > 0) {
            bag = std::make_unique<ABag<KVpair<Key, E>>>(initSize);
        }
        else {
            bag = std::make_unique<ABag<KVpair<Key, E>>>();
        }
    }

    // Destructor
    ~BDictionary() override {};

	// Reinitialize dictionary
	void clear() override
	{
		bag->emptyBag(); //Uses emptyBag()
	}

	// Insert a record
	// k: The key for the record being inserted.
	// e: The value for the record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e) override
	{
		KVpair<Key, E> kv(k, e);
		return *bag += kv; // Uses += operator
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal) override
	{
		if (search(k, rtnVal))
		{
			KVpair<Key, E> kv(k, rtnVal);
			bag->removeItem(kv); // Uses removeItem()
			rtnVal = kv.value();
			return true;
		}
		return false;
	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue) override
	{
		KVpair<Key, E> kv;

		if (bag->removeTop(kv)) // Uses removeTop()
		{
			returnValue = kv.value();
			return true;
		}
		return false;
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool search(const Key& k, E& returnValue) const override
	{
		KVpair<Key, E> kv;
		kv.setKey(k);

		if (bag->find(kv)) // Uses find()
		{
			returnValue = kv.value();
			return true;
		}
		return false;
	}

	// Return the number of records in the dictionary.
	int size() const override
	{
		return bag->numItems(); // Uses numItems()
	}
};