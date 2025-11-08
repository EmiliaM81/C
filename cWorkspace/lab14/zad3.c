#include <stdio.h>



size_t copy_file(const char *src_file_name, const char *dest_file_name);

int main()
{

    return 0;
}


size_t copy_file(const char *src_file_name, const char *dest_file_name)
{

    _Bool is_there = 0;
    FILE *fp_d = fopen(dest_file_name, "rb");

    if (fp_d == NULL)
    {
        is_there = 0;
    } else {
        is_there = 1;
    }

    fclose(fp_d);

    



}

/// DOKONCZYC
