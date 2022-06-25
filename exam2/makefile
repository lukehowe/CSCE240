# use g++ compiler
cc = g++

# path for include directive and linter
path = ..

# compile with C++ 17 standard
flags = -std=c++17
# compile with all warnings
flags += -Wall
# compile with path on #include path
flags += -I $(path)
# compile with instrumentation for gdb
flags += -g

# compilation to intermediary .o files
compile = $(cc) $(flags) -c -o

# final linked build to binary executable
link = $(cc) $(flags) -o


# BUILD AND TEST ALL APPLICATIONS
#
test-all : test-functional-array \
           test-time-span
	./test-functional-array 0
	./test-functional-array 1
	./test-functional-array 2
	./test-functional-array 3
	@echo test-functional-array MEMORY TESTS
	@valgrind --leak-check=full --error-exitcode=1 ./test-functional-array 1
	@valgrind --leak-check=full --error-exitcode=1 ./test-functional-array 3
	@echo test-functional-array MEMORY TESTS PASSED
	./test-time-span 0
	./test-time-span 1
	./test-time-span 2
	./test-time-span 3


# PROBLEM: functional_array
#
test-functional-array : bin/functional-array.o bin/test-functional-array.o
	$(link) $@ $^

test-functional-array-style : src/functional_array.cc inc/functional_array.h
	cpplint --root=$(path) $^

test-functional-array-memory : test-functional-array
	@echo test-functional-array MEMORY TESTS
	@valgrind --leak-check=full --error-exitcode=1 ./test-functional-array 1
	@valgrind --leak-check=full --error-exitcode=1 ./test-functional-array 3
	@echo ALL MEMORY TESTS PASSED

bin/test-functional-array.o : src/test_functional_array.cc \
                              inc/test_functional_array.h \
                              inc/functional_array.h
	$(compile) $@ $<

bin/functional-array.o : src/functional_array.cc inc/functional_array.h
	$(compile)  $@ $<


# PROBLEM: TimeSpan
#
test-time-span : bin/time-span.o bin/test-time-span.o
	$(link) $@ $^

test-time-span-style : src/time_span.cc inc/time_span.h
	cpplint --root=$(path) $^

bin/test-time-span.o : src/test_time_span.cc \
                       inc/test_time_span.h \
                       inc/time_span.h
	$(compile)  $@ $<

bin/time-span.o : src/time_span.cc inc/time_span.h
	$(compile)  $@ $<


# UTILITY: removes intermediary files and executables
clean:
	rm -f bin/* test-*
