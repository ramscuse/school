#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

DirectoryIterator::DirectoryIterator(DIR *dp_arg) : dp(dp_arg) {
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	    name = p->d_name;		// C-string ⇒ C++ string
        if (!wanted()) {
            continue;
        }
	    return *this;			// Everything else, I like!
    }
    dp = nullptr;			// readdir failed; don’t try again.
    return *this;
}

bool DirectoryIterator::wanted() {
    if (name == "." || name == "..") {
        return false;
    }
    return true;
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}



//////////////// Directory methods

//fix 1
Directory::Directory(const char dirname[]) { 
    if(opendir(dirname) == nullptr) {
        string s = dirname;
        throw runtime_error("Could not open " + s);
    } else {
        dp = opendir(dirname);
    }
}

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	closedir(dp);			//   should we close it.
}

Directory::iterator Directory::begin() const {
    return iterator(dp);
}

Directory::iterator Directory::end() const {
    return iterator();
}
