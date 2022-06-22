#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for advance()

// Each hset_iter contains a reference to its associated hash,
// and an int indicating progress within the hash.

template <typename T>
class hset_iter {
  private:
    using table_t = typename std::vector<std::list<T>>;
    const table_t &parent;  // reference to the hash table we’re iterating over
    int vector_index;		    // how far along we are.  0=first item
    int list_index;

  public:
    hset_iter(table_t &table, int n) : parent(table), vector_index(n) { }

    bool operator==(const hset_iter &rhs) const {
	    return vector_index == rhs.vector_index;
    }

    bool operator!=(const hset_iter &rhs) const {
	    return !(*this == rhs);
    }

    // Return a pointer to the vector_index'th element,
    // where vector_index==0 is the first element.

    T operator*() const {
	    unsigned int remaining = vector_index;
	    int i;
	    // First, find the right list:
	    for (i=0; parent[i].size() <= remaining; i++)
	        remaining -= parent[i].size();

	    // Second, find the right slot within that list:
	    auto it = parent[i].begin();
	    advance(it, remaining);  // go forward that many steps
	    return *it;
    }

    // Pre-increment
    void operator++() {
	    ++vector_index;
    }
};

#endif /* HSET_ITER_H_INCLUDED */
