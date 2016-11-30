#include <stdlib.h>
#include <string.h>

#include "scstr.h"

/* allocate memory for a scstr */
void* scstr_malloc(unsigned int size)
{
    if(!size)
    {
        return NULL;
    }
    
    scstr* s = malloc(sizeof(scstr));
    
    if(s == NULL)
    {
        return NULL;
    }
    
    s->contents = malloc(size + 1);
    
    if(s->contents == NULL)
    {
        free(s);
        return NULL;
    }
    
    s->size = size + 1;
    
    return s;
}

/* allocate and zero-initialise memory for a scstr */
void* scstr_calloc(unsigned int num, unsigned int size)
{
    if(!num || !size)
    {
        return NULL;
    }
    
    scstr* s = scstr_malloc(num * size);
    
    if(s == NULL)
    {
        return NULL;
    }
    
    memset(s->contents, 0, s->size);
    
    return s;
}

/* free memory allocated for a scstr */
void scstr_free(scstr* s)
{
    free(s->contents);
    s->size = 0;
}

/* return the length of a scstr */
unsigned int scstr_strlen(scstr* s)
{
    if(s == NULL)
    {
        return 0;
    }
    
    return s->size - 1;
}

/* return a scstr from a raw C string */
scstr* scstr_init(const char* c)
{
    if(c == NULL)
    {
        return NULL;
    }
    
    scstr* s = scstr_calloc(strlen(c), sizeof(char));
    
    strncpy(s->contents, c, strlen(c));
    
    return s;
}

/* append a raw C string onto a scstr */
scstr* scstr_concat(scstr* s, const char* c)
{
    if(s == NULL || c == NULL)
    {
        return NULL;
    }
    
    scstr* res = scstr_calloc(scstr_strlen(s) + strlen(c), sizeof(char));
    
    memcpy(res->contents, s->contents, s->size - 1); /* drops NUL byte */
    strncpy(res->contents + (s->size - 1), c, strlen(c));
    
    res->size = scstr_strlen(s) + strlen(c) + 1;
    
    return res;
}
