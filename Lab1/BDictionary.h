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

	}

	// Insert a record
	// k: The key for the record being inserted.
	// e: The value for the record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e) override
	{

	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal) override
	{

	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue) override
	{

	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool search(const Key& k, E& returnValue) const override
	{

	}

	// Return the number of records in the dictionary.
	int size() const override
	{

	}
};