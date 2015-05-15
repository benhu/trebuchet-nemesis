CC=g++
CC_FLAGS=-g -Wall -Werror -pedantic -W -std=c++11

BIN_NAME=main
BIN_DIR=./bin
BUILD_DIR=./build
SRC_DIR=./src
INCLUDES=-I $(SRC_DIR)/
LDFLAGS=

SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

DEPS=$(OBJECTS:.o=.d)

all: $(BIN_DIR)/$(BIN_NAME)

$(BIN_DIR)/$(BIN_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "Making simlink: $(BIN_NAME) -> $@"
	@$(RM) $(BIN_NAME)
	@ln -s $@ $(BIN_NAME)

$(OBJECTS): | $(BIN_DIR) $(BUILD_DIR)

$(BIN_DIR):
	@mkdir $@

$(BUILD_DIR):
	@mkdir $@

-include $(DEPS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(INCLUDES) -MP -MMD -c $(CC_FLAGS) $< -o $@

.PHONY: clean
clean:
	@$(RM) $(BIN_NAME)
	@$(RM) -r $(BIN_DIR)
	@$(RM) -r $(BUILD_DIR)
