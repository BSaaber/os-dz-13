#include <unistd.h>

#include <stdio.h>
#include <fcntl.h>

#include <errno.h>

int main() {
    char* path =       "files/file_name.txt";
    char link[] =      "aaaaaaaaa.txt";
    char prev_link[] = "aaaaaaaaa.txt";
    int fd;
    if ((fd = creat(path, S_IRUSR | S_IWUSR)) < 0)
      perror("creat() error");
    else {
    close(fd);
    }
    int pointer = 0;
    int amount = 1;
    int res = symlink(path, link);
    if (res != 0) {
      printf("error! %d\n", res);
    }
    link[pointer]++;
    amount++;




    for (int i = 0; i < 100; ++i) {
        int res = symlink(prev_link, link);
        if (res != 0) {
          printf("error! %d\n", res);
        }


	if (access(link, F_OK) == -1){
		break;
	}

	if (link[pointer] == 'z') {
		pointer++;
		prev_link[pointer - 1]++;
		prev_link[pointer]--;
	}
	prev_link[pointer]++;
        link[pointer]++;
	amount++;
    }
    printf("%d\n", amount);
}
