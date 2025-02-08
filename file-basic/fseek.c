#include <stdio.h>
#include <string.h>

// ftell API : 파일 포지션 - 현재 오프셋 가져오기
// fseek API : 파일 포지션 - 오프셋 설정

static int create_file(void)
{
    FILE *fp;

    if (!(fp = fopen("datafile", "w")))
    {
        printf("fopen() fail\n");
        return -1;
    }

    printf("after fopen(), offset=%ld\n", ftell(fp));

    fputs("Hello World\n", fp);
    fputs("Hello World!\n", fp);
    fputs("Hello World!!\n", fp);
    fputs("Hello World!!!\n", fp);

    printf("before fclose(), offset=%ld\n", ftell(fp));

    fclose(fp);

    return 0;
}

static int read_file(void)
{
    FILE *fp;
    char buf[1024];

    if (!(fp = fopen("datafile", "r+")))
    {
        printf("fopen() fail\n");
        return -1;
    }

    printf("after fopen(), offset=%ld\n", ftell(fp));

    memset(buf, 0, sizeof(buf));

    fgets(buf, sizeof(buf), fp);

    printf("after fgets(), offset=%ld\n", ftell(fp));

    fseek(fp, 0, SEEK_END); // 오프셋 설정

    printf("after fseek(), offset=%ld\n", ftell(fp));

    fputs("finally!\n", fp);

    printf("before fclose(), offset=%ld\n", ftell(fp));

    fclose(fp);

    return 0;
}

int main(int argc, char **argv)
{
    if (create_file())
    {
        perror("error when create file\n");
        return -1;
    }

    if (read_file())
    {
        perror("error when read file\n");
        return -1;
    }

    return 0;
}