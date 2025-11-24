#include "push_swap.h"
#include <stdlib.h>

int	get_chunk_target(int size)
{
    char *env;
    int target;

    env = getenv("PUSH_CHUNK");
    if (env)
        target = atoi(env);
    else
    {
        if (size <= 100)
            target = 20;
        else if (size <= 500)
            target = 60;
        else
            target = 40;
    }
    return (target);
}
