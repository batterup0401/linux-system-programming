#include <stdio.h>
#include <string.h>

// fopen API : 파일 열기
// fclose API : 파일 닫기

int write_to_file(void)
{
    FILE *fp;

    fp = fopen("data", "w");
    if (fp == NULL)
    {
        perror("fopen error\n");
        return -1;
    }

    fputs("Hello World!\n", fp);

    fclose(fp);

    return 0;
}

int read_from_file(void)
{
    FILE *fp;
    char buf[1024]; // 1MB

    fp = fopen("data", "r");
    if (fp == NULL)
    {
        perror("fopen error\n");
        return -1;
    }

    memset(buf, 0, sizeof(buf));

    fgets(buf, sizeof(buf), fp);

    fclose(fp);

    printf("%s\n", buf);

    return 0;
}

int main(int argc, char **argv)
{
    if (write_to_file())
    {
        perror("error when write to file\n");
        return -1;
    }

    if (read_from_file())
    {
        perror("error when read from file\n");
        return -1;
    }

    return 0;
}