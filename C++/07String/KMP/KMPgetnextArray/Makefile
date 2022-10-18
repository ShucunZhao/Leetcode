# OBJS for all .o files(dependence)
# CC for gcc/g++(cmd)
# CFLAGS for -std=gnu++11 -pedantic -Wall -Werror -ggdb3(command arguments)
# --------------version 2------------------
#  $^ for command above
#  RM for rm -f
#  $@ for corresponding object .o file
# --------------version 3-----------------
# The part of each object files generation are similar, so we gen	eralize it into a formula:
#  %.o:%.cpp
#  		$(CC) $^ -c $(CFLAGS) -o $@
#  (The % is a generic symbol)
# --------------version 4-----------------
#  .PHONY: for the fake object(clean)
# ---------------version 5---------------
#  PROGS for all the executable files
#  all: for one-by-one compile
#---------------version 6---------------

PROGS=test
OBJS=test.o
CC=g++
CFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3

all: $(PROGS)
test: test.o
	$(CC) $^ $(CFLAGS) -o $@

%.o: %.cpp
	$(CC) $^ -c $(CFLAGS) -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(PROGS) -r
