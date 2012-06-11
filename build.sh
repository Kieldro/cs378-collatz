

# file variables
source="SphereCollatz.c++"
inFile="test.in"
outFile="RunCollatz.out"
compile=true
unit=false

if $unit; then
	echo UNIT TESTS...
	ls /usr/include/cppunit/
	locate libcppunit.a
	g++ -ansi -pedantic -lcppunit -ldl -Wall TestCollatz.c++ -o TestCollatz.c++.app
	valgrind TestCollatz.c++.app >& TestCollatz.c++.out
fi

echo COMPILING...
g++ -ansi -pedantic -Wall $source -o $source.app

echo RUNNING PROGRAM...
$source.app < $inFile
#valgrind Sphere.c++.app < $inFile #>& $outFile


<< '--MULTICOMMENT--'
free comments!

echo CHECKING OUTPUT...
diff -lc RunCollatz.out RunCollatz.in

echo GENERATING COMMIT LOG...
git log > Collatz.log

#echo UPDATING SPHERECOLLATZ FILE...
#cp Collatz.c++ SphereCollatz.c++

echo RUNNING DOXYGEN
doxygen -g
doxygen Doxyfile

--MULTICOMMENT--
