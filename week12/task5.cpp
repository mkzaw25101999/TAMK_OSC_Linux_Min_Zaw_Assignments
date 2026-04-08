#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <sys/stat.h>

void print_error(const char* step, int ret) {
    std::cerr << "ERROR at step: " << step << "\n";
    std::cerr << "Return value: " << ret << "\n";
    std::cerr << "errno: " << errno << "\n";
    std::cerr << "strerror(errno): " << strerror(errno) << "\n";
    perror("perror");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source> <destination>\n";
        return 1;
    }

    const char* src = argv[1];
    const char* dst = argv[2];

    errno = 0;
    int in_fd = open(src, O_RDONLY);
    if (in_fd == -1) {
        print_error("open(source)", in_fd);
        return 1;
    }

    errno = 0;
    int out_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd == -1) {
        print_error("open(destination)", out_fd);
        close(in_fd);
        return 1;
    }

    char buffer[128];
    ssize_t bytes_read;

    while (true) {
        errno = 0;
        bytes_read = read(in_fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            print_error("read()", -1);
            close(in_fd);
            close(out_fd);
            return 1;
        }
        if (bytes_read == 0) {
            break;
        }

        errno = 0;
        ssize_t bytes_written = write(out_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            print_error("write()", -1);
            close(in_fd);
            close(out_fd);
            return 1;
        }

        if (bytes_written != bytes_read) {
            std::cerr << "Short write detected\n";
            std::cerr << "Requested: " << bytes_read << ", wrote: " << bytes_written << "\n";
            close(in_fd);
            close(out_fd);
            return 1;
        }
    }

    close(in_fd);
    close(out_fd);
    std::cout << "Copy completed successfully.\n";
    return 0;
}
