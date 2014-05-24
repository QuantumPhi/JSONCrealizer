#ifndef VECTOR_H
#define VECTOR_H

#define BASE_CAP 1
#define EXPAND_RATE 1,5

typedef struct
{
    void **data;
    int length;
} vector;

vector init_vector();

void resize();

bool check_size(int size);

void add(void *pdata);

void merge(vector v);

void remove(int i);

void set(void *pdata, int i);

void insert(void *pdata, int i);

vector subset(int i, int j);

#endif
