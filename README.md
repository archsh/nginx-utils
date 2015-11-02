# Nginx Utils
This is a small project which calculate the md5 hash for nginx caching. 
User can use this to detect if your nginx has cached a specific request or not, or remove a specific cache from disk.

There're two small program inside:

1. ngx_md5
   - Calculate md5 checksum from given content(uri maybe).
2. ngx_decache 
   - Remove cached data from disk for given content(s).
   - ./ngx_decache NGXIN_CACHE_ROOT URI1 ... URIn

