def set_new() :
    """Return a new set"""
    return []

def set_remove(s, value): 
    """Remove the given value from the set s"""
    # perform some type checking to see that the user
    # has provided the right kind of input:
    if type(s)!=type([]) :
        raise ValueError
    # we can simply use the "remove" method of a list:
    s.remove(value)
    # to be complete before returning we should make sure there are no duplicates - not shown
    return s
    
def remove_dup(s1):
    res = []
    for i in s1:
	if i not in res:
	    res.append(i)
    return res
	

def set_union(s1, s2) :
    """Return the union of sets s1 and s2 as a list"""
    if type(s1)!=type([]) or type(s2)!=type([]):
        raise ValueError
    res = s1 + s2
    return remove_dup(res)

def set_intersection(s1, s2) :
    """Return the intersection of sets s1 and s2 as a list"""
    if type(s1)!=type([]) or type(s2)!=type([]):
        raise ValueError
    res = []
    for i in s1:
	if i in s2:
	    res.append(i)
    return res

def set_membership(s, value):
    """Return True if value is in the set s, and False otherwise"""
    if type(s)!=type([]) :
        raise ValueError    
    return value in s

def set_equals(s1, s2) :
    """Return True if the sets s1 and s2 have exactly the same elements"""
    if type(s1)!=type([]) or type(s2)!=type([]):
        raise ValueError    
    for i in s1:
	if i not in s2:
	    return false
	else:
	    set_remove(s2, i)
    return len(s2) > 0

def set_difference(s1, s2) :
    """Return the set difference of s1 and s2"""
    if type(s1)!=type([]) or type(s2)!=type([]):
        raise ValueError
    res = []
    for i in s1:
	if i not in s2:
	    res.append(i)
    return res

def is_subset(s1, s2) :
    """Return True if s1 is a subset of s2"""
    if type(s1)!=type([]) or type(s2)!=type([]):
        raise ValueError
    s1 = remove_dup(s1)
    s2 = remove_dup(s2)
    for i in s1:
	if i not in s2:
	     return false;
    return len(s1) <= len(s2)

def is_proper_subset(s1, s2) :
    """Return True if s1 is a proper subset of s2"""
    if type(s1)!=type([]) or type(s2)!=type([]):
        raise ValueError
    s1 = remove_dup(s1)
    s2 = remove_dup(s2)
    for i in s1:
	if i not in s2:
	     return false;
    return len(s1) < len(s2)


