TARGET = rtos-microkernel

SRCS = $(shell find src -name "*.c")

CFLAGS += -I src/kernel -I src/config

all:
	$(CC) $(SRCS) $(CFLAGS) -o $(TARGET)
