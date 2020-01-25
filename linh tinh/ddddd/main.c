#include <stdio.h>
#include <string.h>
#define fname "B17DCCN005.bin"
#define ffls while ((getchar()) != '\n')

struct data
{
    char name[1000];
    int stt;
    float a, b, c;
} s[1000];

int n, N = 0, t, i, j;

void inputfile()
{
    struct data sv;
    FILE *f = fopen(fname, "rb");
    while (fread(&sv, sizeof(sv), 1, f))
    {
        s[++N] = sv;
    }
    fclose(f);
}

void outputfile()
{
    FILE *f = fopen(fname, "wb+");
    for (int i = 1; i <= N; i++)
          fwrite(&s[i], sizeof(s[i]), 1, f);
    fclose(f);
}

void swap(struct data *x, struct data *y)
{
    struct data sv = *x;
    *x = *y;
    *y = sv;
    return;
}

int main()
{
    memset(s, 0, sizeof(s));
    inputfile();
    for (i = 1; i <= N; i++)
            for (j = i + 1; j <= N; j++)
                if (s[i].stt > s[j].stt)
                    swap(&s[i], &s[j]);
    scanf("%d", &t);
    if (t == 1)
    {
        scanf("%d", &n);
        for (i = N+1; i <= N+n; i++)
        {
            s[i].stt = i;
            ffls;
            gets(s[i].name);
            scanf("%f%f%f", &s[i].a, &s[i].b, &s[i].c);
        }
        N += n;
        printf("%d", n);
    }
    if (t == 2)
    {
        int stt;
        scanf("%d", &stt);
        ffls;
        for (int i = 0; i < 1000; i++)
            s[stt].name[i] = 0;
        gets(s[stt].name);
        scanf("%f%f%f", &s[stt].a, &s[stt].b, &s[stt].c);
        printf("%d", stt);
    }
    if (t == 3)
    {
        for (i = 1; i <= N; i++)
                printf("%d %s %.1f %.1f %.1f \n", s[i].stt, s[i].name, s[i].a, s[i].b, s[i].c);
    }
    outputfile();
    return 0;
}
