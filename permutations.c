// This code prints out all the permutations of letters from
// the given input string.
// I require 2 parameters, I don't know how to do it with one.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void
print_perm(const size_t pos, char * str)
{
        int i;
        size_t sz;

        sz = strlen(str);

        if (pos == sz) {
                printf("%s\n",str);
        }

        for (i = pos; i < sz; i++) {
                char c = str[i];
                str[i] = str[pos];
                str[pos] = c;
                print_perm(pos+1, str);
                str[pos] = str[i];
                str[i] = c;
        }
}


int
main(void)
{
        char * s = strdup("ABC");
        print_perm(0, s);
}

