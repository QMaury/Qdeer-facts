CFLAGS= -c 
LDFLAGS=

SOURCES= $(wildcard src/*.c)
OBJECTS= $(SOURCES:.c=.o)
EXECUTABLE = qdeerfacts

all: $(SOURCES) $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@
		chmod 0777 $(EXECUTABLE)


.c.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -f core.* vgcore.* callgrind.out.*

install:
	cp $(EXECUTABLE) /usr/bin/$(EXECUTABLE)
