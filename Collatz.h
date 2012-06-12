// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2011
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

// globals
const static int DEBUG = true;
const static int CACHE_SIZE = 3*1000*1000 + 1;
int cache [CACHE_SIZE];

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    
    
    assert(i > 0);
    assert(j > 0);
    return true;}

// -------------
// cycleLength
// -------------

/**
 * returns v, the cycle length
 * @param n positive integer
 */
int cycleLength (int n) {
    assert(n > 0);
	int v = 1;
	
	for(int k = n; k != 1;){
		if(k < CACHE_SIZE && cache[k] != 0){
			//if (DEBUG) std::cout << "k = " << k << std::endl;
			assert(k < CACHE_SIZE);
			v += cache[k] - 1;
			break;
		}
		
		if (k % 2){
			k = k + (k >> 1) + 1;
			v += 2;
		}else{
			k /= 2;
			++v;
		}
	}
	if(n < CACHE_SIZE){
		assert(n < CACHE_SIZE);
		cache[n] = v;
	}
    assert(cache[0] >= 0);
	
    assert(v > 0);
	return v;
}

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    
    if (i > j){		// swap
    	int t = i;
    	i = j;
    	j = t;
    }
    
    // optimize range
    if (i < j/2){
    	i = j/2;
    }
    
    int v = 1;
    for (int x = i; x <= j; ++x){
    	int cLen = cycleLength(x);
    	if (cLen > v)
    		v = cLen;
    	
    }
    assert(v > 0);
    
    return v;}


// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
