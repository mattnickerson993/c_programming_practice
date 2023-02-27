# hashtag for comment
CC = clang
#just a macro below
OBJS=hash.o main.o


# target (rule for building targert comes after colon) target = all hash_remove = rule
all: hash_remove

# target:hash remove depends on first line(OBJS)
hash_remove: $(OBJS)
			 $(CC) -o my_program $(OBJS)

clean:
	rm -f $(OBJS) my_program