#ifndef SCSTR_H_
#define SCSTR_H_

struct _scstr
{
    unsigned int size; /* actual size */
    char* contents; /* underlying data */
};

typedef struct _scstr scstr;

/* allocators and deallocators */
void* string_malloc(unsigned int size);
void* string_calloc(unsigned int size, unsigned int num);
void string_free(scstr* s);

unsigned int scstr_strlen(scstr* s);

scstr* scstr_init(const char* c);
scstr* scstr_concat(scstr* s, const char* c);

#endif // STRING_H_
