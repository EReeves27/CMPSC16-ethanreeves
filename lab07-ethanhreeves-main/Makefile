CXX = g++ -std=c++11
CXXFLAGS = -Wall -Wno-uninitialized
BINARIES = removeKFromFrontTest strTest elementwiseSumTest spliceTest findKthNodeTest deleteKthNodeTest sumTest largestValueTest

all: ${BINARIES}

tests: ${BINARIES}
	./strTest
	./sumTest
	./largestValueTest
	./findKthNodeTest
	./deleteKthNodeTest
	./removeKFromFrontTest
	./elementwiseSumTest
	./spliceTest

sumTest: sumTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

largestValueTest: largestValueTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

findKthNodeTest: findKthNodeTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

deleteKthNodeTest: deleteKthNodeTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

removeKFromFrontTest: removeKFromFrontTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

spliceTest: spliceTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

elementwiseSumTest: elementwiseSumTest.o linkedListFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

strTest: strTest.o strFuncs.o tddFuncs.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

clean:
	/bin/rm -f $(BINARIES) *.o
