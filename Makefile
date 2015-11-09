
all: ngx_decache ngx_md5 ngx_murmur_hash2

ngx_md5: ngx_md5.c md5.c md5.h
	gcc ngx_md5.c md5.c -o $@

ngx_decache: ngx_decache.c md5.c md5.h
	gcc ngx_decache.c md5.c -o $@

ngx_murmur_hash2: ngx_murmur_hash2.c
	gcc ngx_murmur_hash2.c -o $@

clean:
	rm -f ngx_md5 ngx_decache
