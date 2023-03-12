CC=g++
WFLAGS=-std=c++17 
SOURCES=interface.cpp Model_and_Controller/controller.cpp model.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
GCOVFLAGS=--coverage
HTML_CREATE=lcov --no-external -t a.out -o rep.info -c -d .; genhtml -o report rep.info
TEST_FLAGS=-lgtest
TEST_COMPILE=$(CC) test_calc.cpp Model_and_Controller/model.cpp $(WFLAGS)$(TEST_FLAGS)
all:clean calc
clean:
	rm -rf *.o *.g* *.info *.out report src.tgz text ../build* moc* ui* calc.app *user Qmakefile
rebuild: clean all
tests: clean
	$(TEST_COMPILE)
	./a.out
gcov_report: clean
	$(CC) test_calc.cpp Model_and_Controller/model.cpp $(WFLAGS) $(TEST_FLAGS) $(GCOVFLAGS)
	./a.out
	$(HTML_CREATE)
install: calc
	cp a.out ../
uninstall:
	rm ../a.out
calc:
	qmake calc.pro -o Qmakefile
	make -f Qmakefile
	./calc.app/Contents/MacOS/calc
dist:
	tar -czf src.tgz *

