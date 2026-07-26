#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) != 0) {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    /* File Type */
    printf("File Type:            ");

    if (S_ISREG(fileStat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic Link\n");
    else
        printf("Other\n");

    /* Permissions */
    printf("Permissions:          %04o\n", fileStat.st_mode & 0777);

    /* Size */
    printf("File Size:            %ld bytes\n", fileStat.st_size);

    /* Hard Links */
    printf("Hard Links Count:     %ld\n", fileStat.st_nlink);

    /* Owner */
    printf("Owner (UID):          %d\n", fileStat.st_uid);

    /* Group */
    printf("Group (GID):          %d\n", fileStat.st_gid);

    /* Times */
    printf("Last Access Time:     %s", ctime(&fileStat.st_atime));
    printf("Last Modification:    %s", ctime(&fileStat.st_mtime));
    printf("Status Change Time:   %s", ctime(&fileStat.st_ctime));

    return 0;
}