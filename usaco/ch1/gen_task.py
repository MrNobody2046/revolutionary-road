template = """/*
ID:sphy1
LANG: C
TASK: %s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "%s.in"
#define OUTPUT "%s.out"


int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);

    exit(0);
}
"""

if __name__ == "__main__":
    import sys

    name = sys.argv[1]
    t = template % (name, name, name)
    with open("%s.c" % name, "w") as c:
        c.write(t)
    with open("%s.in" % name, "w") as c:
        c.write("")