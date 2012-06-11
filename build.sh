

# file variables
source="RunCollatz.c++"
unitFile="TestCollatz.c++"
inFile="RunCollatz.in"
outFile="RunCollatz.out"
compile=true
unit=true

if $unit; then
	echo UNIT TESTS...
	g++ -ansi -pedantic -lcppunit -ldl -Wall $unitFile -o $unitFile.app
	valgrind $unitFile.app >& $unitFile.out
fi

echo COMPILING...
g++ -ansi -pedantic -Wall $source -o $source.app

#echo RUNNING PROGRAM...
$source.app < $inFile > $outFile
valgrind $source.app < $inFile >& $outFile

echo CHECKING OUTPUT...
diff -lc RunCollatz.out RunCollatz.in

echo GENERATING COMMIT LOG...
git log > Collatz.log

echo RUNNING DOXYGEN...
#doxygen Doxyfile

<< '--MULTICOMMENT--'
free comments!

#echo UPDATING SPHERECOLLATZ FILE...
#cp Collatz.c++ SphereCollatz.c++

--MULTICOMMENT--
