<< '--MULTICOMMENT--'
free comments!
--MULTICOMMENT--

# file variables
inFile="RunCollatz.in"
outFile="RunCollatz.out"
compile=false

echo UNIT TESTS...
g++ TestCollatz.c++ &> TestCollatz.c++.out

echo RUNNING PROGRAM...
g++ -ansi -pedantic -Wall RunCollatz.c++ -o RunCollatz.c++.app
valgrind RunCollatz.c++.app < $inFile >& $outFile

echo CHECKING OUTPUT...
diff -lc RunCollatz.out RunCollatz.in

echo GENERATING COMMIT LOG...
git log > Collatz.log

echo UPDATING SPHERECOLLATZ FILE...
cp Collatz.c++ SphereCollatz.c++

echo RUNNING DOXYGEN
doxygen -g
doxygen Doxyfile

