
mmd5: main.c md5.c md5.h
	gcc main.c md5.c -o $@

clean:
	rm -f mmd5
