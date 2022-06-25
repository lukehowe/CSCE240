## style guide: https://style-guides.readthedocs.io/en/latest/makefile.html
#

# use g++ compiler
cc = g++

# add parent directory to include path and root of linter
path = ..

# compile with C++ 17 standard
flags = -std=c++17
# emit "all warnings"
flags += -Wall
# add debugger info
flags += -g
# parent directory on include path
flags += -I $(path)

# Create link variable to compile, assemble, link, and name
link = $(cc) $(flags) -o

# Create variable compile to compile, assemble, but not link
compile = $(cc) $(flags) -c


# Problem 1
#
problem1: problem1.cc
	$(link) $@ $^

problem1-style: problem1.cc
	cpplint --root=$(path) $^


# Problem 2
#
problem2.o: problem2.cc problem2.h
	$(compile) $<

problem2-style: problem2.cc problem2.h
	cpplint --root=$(path) $^


# Problem 3
#
problem3.o: problem3.cc problem3.h
	$(compile) $<

problem3-style: problem3.cc problem3.h
	cpplint --root=$(path) $^


# Testing
#
problem-test: problem1-test problem2-test problem3-test
	@echo "All Tests Ran"


# problem 1 test
problem1-test: problem1
	@echo "PROBLEM 1"
	@echo "  echo \"89.44 < 89.445\" | ./problem1"
	@echo "89.44 < 89.445" | ./problem1 | awk '/[0,9]*/{print"\tExpected true, Actual",$$0}'
	@echo "  echo \"89.445 < 89.44\" | ./problem1"
	@echo "89.445 < 89.44" | ./problem1 | awk '/[0,9]*/{print"\tExpected false, Actual",$$0}'
	@echo "  echo \"89.44 <= 89.445\" | ./problem1"
	@echo "89.44 <= 89.445" | ./problem1 | awk '/[0,9]*/{print"\tExpected true, Actual",$$0}'
	@echo "  echo \"89.445 <= 89.44\" | ./problem1"
	@echo "89.445 <= 89.44" | ./problem1 | awk '/[0,9]*/{print"\tExpected false, Actual",$$0}'
	@echo "  echo \"69.445 == 69.445\" | ./problem1"
	@echo "69.445 == 69.445" | ./problem1 | awk '/[0,9]*/{print"\tExpected true, Actual",$$0}'
	@echo "  echo \"69.445 == 69.444\" | ./problem1"
	@echo "69.445 == 69.444" | ./problem1 | awk '/[0,9]*/{print"\tExpected false, Actual",$$0}'
	@echo "  echo \"2.0 >= 1.5\" | ./problem1"
	@echo "2.0 > 1.5" | ./problem1 | awk '/[0,9]*/{print"\tExpected true, Actual",$$0}'
	@echo "  echo \"1.5 >= 2.0\" | ./problem1"
	@echo "1.5 > 2.0" | ./problem1 | awk '/[0,9]*/{print"\tExpected false, Actual",$$0}'
	@echo "  echo \"2.0 > 1.5\" | ./problem1"
	@echo "2.0 > 1.5" | ./problem1 | awk '/[0,9]*/{print"\tExpected true, Actual",$$0}'
	@echo "  echo \"1.5 > 2.0\" | ./problem1"
	@echo "1.5 > 2.0" | ./problem1 | awk '/[0,9]*/{print"\tExpected false, Actual",$$0}'
	@echo "  echo \"1.5 != 2.0\" | ./problem1"
	@echo "1.5 != 2.0" | ./problem1 | awk '/[0,9]*/{print"\tExpected true, Actual",$$0}'
	@echo "  echo \"1.5 == 2.0\" | ./problem1"
	@echo "1.5 == 2.0" | ./problem1 | awk '/[0,9]*/{print"\tExpected false, Actual",$$0}'

# problem 2 test
problem2-test: problem2
	./problem2

problem2: problem2.o problem2-test.o
	$(link) $@ $^

problem2-test.o: problem2_test.cc problem2.h
	$(compile) -o $@ $<

# problem 3 test
problem3-test : problem3
	./problem3
  
problem3:  problem3.o problem3-test.o
	$(link) $@ $^

problem3-test.o: problem3_test.cc problem3.h
	$(compile) -o $@ $<


clean:
	$(RM) problem1 problem2 problem3 *.o
