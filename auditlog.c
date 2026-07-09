#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define FILE_NAME "audit.log"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return 1;
    }

    // Add message
    if (strcmp(argv[1], "--add") == 0)
    {
        int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0)
        {
            printf("Cannot open file\n");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    // View log
    else if (strcmp(argv[1], "--view") == 0)
    {
        int fd = open(FILE_NAME, O_RDONLY);

        if (fd < 0)
        {
            printf("Log file not found\n");
            return 1;
        }

        char ch;
        int line = 1;

        printf("%d: ", line);

        while (read(fd, &ch, 1) > 0)
        {
            write(1, &ch, 1);

            if (ch == '\n')
            {
                line++;
                printf("%d: ", line);
            }
        }

        close(fd);
    }

    else
    {
        printf("Invalid command\n");
    }

    return 0;
}