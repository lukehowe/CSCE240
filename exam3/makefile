cc = g++  # use g++ compiler

path = ..  # use parent dir for project path

flags = -std=c++17 # use C++ 17 standard
flags += -Wall # emit all warnings
flags += -I $(path) # update preprocessor #include path
flags += -g # add gdb instrumentation

link = $(cc) $(flags) -o  # final linked build to binary executable
compile = $(cc) $(flags) -c -o  # compilation to intermediary .o files


# PROBLEM: char_matrix
#
test-char-matrix : bin/char-matrix.o bin/test-char-matrix.o
	$(link) $@ $^

test-char-matrix-style: src/char_matrix.cc inc/char_matrix.h
	cpplint --root=$(path) $^

test-char-matrix-memory : test-char-matrix
	@echo test-char-matrix MEMORY TESTS
	@valgrind --leak-check=full --error-exitcode=1 ./test-char-matrix 0
	@valgrind --leak-check=full --error-exitcode=1 ./test-char-matrix 1
	@valgrind --leak-check=full --error-exitcode=1 ./test-char-matrix 2
	@echo ALL TESTS PASSED

bin/test-char-matrix.o : src/test_char_matrix.cc \
                         inc/test_char_matrix.h \
                         inc/char_matrix.h
	$(compile) $@ $<

bin/char-matrix.o : src/char_matrix.cc inc/char_matrix.h
	$(compile) $@ $<


# PROBLEM: Employee Inheritance
#
test-employee: bin/employee.o bin/test-employee.o
	$(link) $@ $^

test-employee-style: src/employee.cc inc/employee.h
	cpplint --root=$(path) $^

bin/test-employee.o : src/test_employee.cc inc/test_employee.h inc/employee.h
	$(compile) $@ $<

bin/employee.o : src/employee.cc inc/employee.h
	$(compile) $@ $<


# PROBLEM: Smart Appliance
#
test-smart-appliance : test-smart-light test-smart-thermostat

test-smart-appliance-style: src/smart_appliance.cc inc/smart_appliance.h
	cpplint --root=$(path) $^

test-smart-light: bin/smart-appliance.o bin/test-smart-light.o
	$(link) $@ $^

test-smart-thermostat: bin/smart-appliance.o bin/test-smart-thermostat.o
	$(link) $@ $^

bin/test-smart-light.o : src/test_smart_light.cc \
                         inc/test_smart_appliance.h \
                         inc/smart_appliance.h
	$(compile) $@ $<

bin/test-smart-thermostat.o : src/test_smart_thermostat.cc \
                              inc/test_smart_appliance.h \
                              inc/smart_appliance.h
	$(compile) $@ $<

bin/smart-appliance.o : src/smart_appliance.cc inc/smart_appliance.h
	$(compile) $@ $<


# PROBLEM: TightVector
#
test-tight-vector : bin/tight-vector.o bin/test-tight-vector.o
	$(link) $@ $^

test-tight-vector-style: src/tight_vector.cc inc/tight_vector.h
	cpplint --root=$(path) $^

test-tight-vector-memory : test-tight-vector
	@echo test-tight-vector MEMORY TESTS
	@valgrind --leak-check=full --error-exitcode=1 ./test-tight-vector 1
	@valgrind --leak-check=full --error-exitcode=1 ./test-tight-vector 3
	@echo ALL TESTS PASSED

bin/test-tight-vector.o : src/test_tight_vector.cc \
                          inc/test_tight_vector.h \
                          inc/tight_vector.h
	$(compile) $@ $<

bin/tight-vector.o : src/tight_vector.cc inc/tight_vector.h
	$(compile) $@ $<


# UTILITY: removes intermediary files and executables
clean:
	rm -f bin/* test-char-matrix test-employee test-smart-light test-smart-thermostat test-tight-vector
