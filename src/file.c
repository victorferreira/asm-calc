#include <stdio.h>
#include <errno.h>
#include <string.h>

void process_line(char* line) {
    line = strcat(line, "\n");
    FILE* output;
    write_file(output, line);
}

int read_file(FILE* input) {
    char buffer[1024] ;
    char *record,*line;
    input = fopen("src/input.txt", "r");
    if (input == NULL) {
        printf ("Cannot read file, errno = %d\n", errno);
        return 1;
    }

    while((line=fgets(buffer,sizeof(buffer),input))!=NULL) {
        record = strtok(line,"\n");
        process_line(record);
    }

    fclose(input);

    return 0;
}

int write_file(FILE* output, char* data) {
    output = fopen ("src/result.txt","a");
    if (output == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
    fprintf (output, data); // if you want something in the file.
    fclose (output);
    // printf ("File created okay\n");
    return 0;
}

int main (void) {
    FILE *input;
    read_file(input);
    return 0;
}