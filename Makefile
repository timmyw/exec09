
src=6809.c main.c monitor.c simple.c wpc.c

exec09: $(src)
	$(CC) $(CXFLAGS) -o $@ $^
