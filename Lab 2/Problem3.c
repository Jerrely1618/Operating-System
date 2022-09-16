#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    char* SourceFile = argv[1];
    char* DestinationFile = argv[2];
    int sf,df,ret,writ,off;
    
    sf = open(SourceFile,O_RDONLY);
    df = open(DestinationFile,O_WRONLY);
    
    if(sf == -1 || df == -1){
        perror("Error");
    }
    else{
        char c;
        ret = read(sf, &c, 1);
        while(ret != 0){
            writ = write(df,&c,1);
            ret = read(sf, &c, 1);
        }
        close(sf);
        close(df);
    }
    
    
    return 0;
}