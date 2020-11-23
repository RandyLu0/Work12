#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h> 
#include <stdio.h>

int main(){
    DIR *d;
    d = opendir(".");
    struct dirent *entry;
    struct stat file;
    int size = 0;
	printf("regular files:\n");

    do{
        entry = readdir(d);
        stat(entry->d_name,&file);
		if(entry){
			if(entry->d_type > 4){
				printf("%s\n",entry->d_name);
				size += file.st_size;
			}
		}        
    }while(entry);

	printf("\n directories:\n");
	rewinddir(d);
	
	do{
        entry = readdir(d);
		if(entry){
			if(entry->d_type <= 4){
				printf("%s\n",entry->d_name);
			}
		}        
    }while(entry);

    printf("\nsize of directory in bytes: %d\n",size);
    closedir(d);
    return 0;
}