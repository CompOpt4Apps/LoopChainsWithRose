
## This assumes that Project dir and lcir are either set
## or they are at the same level.
PROJECT_DIR ?= $(PWD)
LCIR ?= $(PROJECT_DIR)/../LoopChainIR
DEPS = $(PROJECT_DIR)/lib/libloopchainIR.a

BIN=$(PROJECT_DIR)/bin
SRC=$(PROJECT_DIR)/src
OBJ=$(PROJECT_DIR)/obj
UTIL=$(PROJECT_DIR)/util
DOC_PATH = $(PROJECT_DIR)/doxygen

# Compiler and flags
CXX=g++
CXXFLAGS += -g -Wall -Wextra -Werror -pthread
CPPFLAGS += --std=c++11 -isystem $(INC)

UNIT_TESTS = LC_factory_test

test: $(UNIT_TESTS)

$(UNIT_TESTS): $(EXE) $(DEPS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(SRC) -c $(SRC)/$@.cpp \
                                            -o $(OBJ)/$@.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(SRC) -Wl,-rpath -Wl,$(LIB) -lpthread \
             $(OBJ)/$@.o $^ -lisl -L$(LIB) -o $(BIN)/$@
	$(BIN)/$@

$(PROJECT_DIR)/lib/libloopchainIR.a: 
	make -C $(LCIR) LoopChainIR.a
	mkdir -p $(PROJECT_DIR)/lib
	cp 	$(LCIR)/lib/libloopchainIR.a $(PROJECT_DIR)/lib

$(OBJ)/*.o: $(SRC)/*.cpp


# Cleaning
neat:
	- rm $(BIN)/*.o

clean-doc:
	- rm -r $(DOC_PATH)

clean-third-party:
	- rm -rf $(THIRD_PARTY_INSTALL) $(THIRD_PARTY_BUILD)
	- rm $(INITED_FILE)

clean-test:
	- rm -r $(UNIT_TEST_BIN)/* $(REG_TEST_DIR)/*.log $(REG_TEST_DIR)/*.dir

clean: clean-test
	- rm $(BIN)/*
	
