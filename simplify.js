function recurse(num, denom, start) {

    if (start > num || start > denom) return 1;

    else {
        if (num % start == 0 && denom % start == 0) {
            return recurse(num/start, denom/start, start);
        } else {
            return recurse(num, denom, start+1);
        }
    }
    
    recurse(num, denom, start);
}


// recurse(12, 8, 2);
// recurse(202, 303, 2);
recurse(5, 7, 2);
