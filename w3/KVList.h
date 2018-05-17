#ifndef W4_KVList_H
#define W4_KVList_H
#include <iostream>

	template<typename K, typename V, int N>
	class KVList
	{
		/*!Array of keys that relate values.*/
		K m_key[N];
		/*!Array of values that relate keys.*/
		V m_value[N];
		/*!Integer variable to hold number of current elements and used to iterate through parallel array indexes.*/
		int numElements;

	public:

		/*!Default constructor adopts an empty state.*/
		KVList() { numElements = 0; }
		/*!Query function that returns number of current elements KVList object holds.*/
		size_t size() const	{ return numElements; }
		/*!Query function that returns a key from the key array at the i'th index*/
		const K& key(int i) const { return m_key[i]; }
		/*!Query function that returns a value from the value array at the i'th index*/
		const V& value(int i) const { return m_value[i]; }

		/*!A function that adds a number key-value pair if the array is not full.*/
		KVList& add(const K& aKey, const V& aValue)
		{
			if (numElements < N)
			{
				this->m_key[numElements] = aKey;
				this->m_value[numElements] = aValue;
				numElements++;
			}

			return *this;
		}

		/*!A function that finds the index of an argument that matches a key in key array.*/
		int find(const K& k) const
		{
			int atIndex;

			for (size_t i = 0; i < numElements; i++)
			{
				if (this->m_key[i] == k)
				{
					atIndex = i;
				}
			}

			return atIndex;
		}

		/*!A function that replaces a key-value pair at the i'th index.*/
		KVList& replace(int i, const K& k, const V& v)
		{
			if (i > 0 && i < numElements)
			{
				this->m_key[i] = k;
				this->m_value[i] = v;
			}

			return *this;
		}
	};

#endif //W4_KVList_H