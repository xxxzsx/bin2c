// Binary to C converter.

#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {

    if (argc != 3) {

        fputs("Converts binary file into compileable C file.\n"
              "\n"
              "Usage:\n"
              "        bin2c <file> <identifier>\n"
              "\n"
              "<file>       - source (binary) file. Use \"-\" to read standard input\n"
              "<identifier> - name of global identifier that will be used to access\n"
              "               the file from the code. It must be standrad C identifier.\n"
              "               Program also creates <identifier>_length variable cointaining\n"
              "               length of the file in bytes\n"
              "\n"
              "Result is sent to the standard output\n"
              "\n", stderr);

        return 1;

    } else {

        FILE *f = strcmp(argv[1],"-") == 0 ? stdin : fopen(argv[1], "rb");
        if (f == NULL) {
            fprintf(stderr, "Can't open input file '%s'", argv[1]);
            return errno;
        }

        printf("const char *%s=\"", argv[2]);

        int i = fgetc(f);
        int cnt = 0;
        unsigned int size = 0;

        while (i != -1) {
            size++;

            if (i >= 32 && i != '"' && i != '\\' && i < 128) {
                putchar(i); cnt++;
            } else if (i == '"') {
                putchar('\\'); putchar('"'); cnt += 2;
            } else if (i == '\\') {
                putchar('\\'); putchar('\\'); cnt += 2;
            } else if (i == '\n') {
                putchar('\\'); putchar('n'); cnt += 2;
            } else if (i == '\r') {
                putchar('\\'); putchar('r'); cnt += 2;
            } else if (i == '\t') {
                putchar('\\'); putchar('t'); cnt += 2;
            } else {
                printf("\\%03o", i); cnt += 4;
            }

            if (cnt >= 80) {
                printf("\"\n\"");
                cnt = 0;
            }

            i = fgetc(f);
        }

        fclose(f);

        printf("\";\n");
        printf("unsigned int %s_length=%u;\n", argv[2], size);

    }

}
