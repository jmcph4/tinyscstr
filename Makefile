PROJ_NAME = tinyscstr
SRC_DIR = src
BUILD_DIR = build
CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -pedantic-errors -std=c11

$(PROJ_NAME):
	$(CC) -c $(SRC_DIR)/*.c $(CFLAGS) -g
	mv *.o $(BUILD_DIR)
	ar -cvq $(BUILD_DIR)/lib$(PROJ_NAME).a $(BUILD_DIR)/*.o
	ar -t $(BUILD_DIR)/lib$(PROJ_NAME).a
    
.PHONY: clean
clean:
	rm $(BUILD_DIR)/* -r
