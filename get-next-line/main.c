#include <stdio.h>
#include <fcntl.h>   
#include <unistd.h>  
#include "get_next_line.h"  

int main(void)
{
    int fd;             
    char *line;         


    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    int i = 0;
    int n = 4; 
    while (i < n) {
        line = get_next_line(fd);
        if (line == NULL) {
          
            if (i == 0) { 
              //  perror("Failed to read any data from file");
                close(fd);
                return 1;
            }
            break; 
        }
        
        printf("%s", line);  
        free(line);  
        i++;
    }

  
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

