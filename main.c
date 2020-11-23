#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
	DIR *path;
	path = opendir(".");

	struct dirent *re;
	re = readdir(path);

	struct stat meta;
	int dir_size = 0;

	printf("\nCurrent Directory Information\n");

   	printf("\nRegular Files:\n");
   	while (re) {
		if (re->d_type == DT_REG) {
			stat(re->d_name, &meta);
        	dir_size += meta.st_size;
       		printf("%s\t\t%ld bytes\n", re->d_name, meta.st_size);
       	}	
        re = readdir(path);  		
   	}
	
   	rewinddir(path);

   	re = readdir(path);

   	printf("\nDirectories:\n");
	while(re){
       if (re->d_type == DT_DIR) {
       		printf("%s\n", re->d_name);
       }
       re = readdir(path);

   	}
   	printf("\nTotal Directory Size (Excluding Directories): %d bytes\n", dir_size);

   	closedir(path);
	return 0;
}