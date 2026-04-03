#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat failed");
        return 1;
    }

    printf("=== File Properties: %s ===\n", argv[1]);
    printf("File size:        %ld bytes\n", st.st_size);
    printf("inode number:     %ld\n", st.st_ino);
    printf("Hard link count:  %ld\n", st.st_nlink);
    printf("Block size:       %ld bytes\n", st.st_blksize);
    printf("Blocks allocated: %ld\n", st.st_blocks);
    printf("User ID (owner):  %d\n", st.st_uid);
    printf("Group ID:         %d\n", st.st_gid);
    printf("Last access:      %s", ctime(&st.st_atime));
    printf("Last modified:    %s", ctime(&st.st_mtime));
    printf("Last status chg:  %s", ctime(&st.st_ctime));

    printf("File type:        ");
    if (S_ISREG(st.st_mode))  printf("Regular file\n");
    else if (S_ISDIR(st.st_mode)) printf("Directory\n");
    else if (S_ISLNK(st.st_mode)) printf("Symbolic link\n");

    printf("Permissions:      %o\n", st.st_mode & 0777);

    return 0;
}
