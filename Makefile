CC=gcc
CXX=g++
EXEC=main
LIB=libmyFile.so
LDFLAGS=-lmyFile -L$(shell pwd)

$(EXEC): $(LIB) main.o
	@echo "... Generating $(EXEC) Executable ..."
	@$(CC) main.o $(LDFLAGS) -o $(EXEC)

$(LIB): myFile.o
	@echo "... Creating $(LIB) ..."
	@$(CC) $< -shared -fPIC -Wl,-soname,$(LIB).1 -o $(LIB).1.0
	@ln -s $(LIB).1.0 $(LIB).1
	@ln -s $(LIB).1 $(LIB)

%.o: %.c
	@$(CC) -c $^

clean:
	@echo "... Cleaning ..."
	@rm -f *.o $(LIB)* $(EXEC)
