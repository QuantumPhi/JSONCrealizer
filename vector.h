#ifndef VECTOR_H
#define VECTOR_H

#define BASE_CAP 1
#define EXPAND_RATE 2

struct vector
{
    void *data;
    int length;
    int capacity;
} vector;

vector init_vector();

void resize();

boolean check_size(int size);

void add(void *pdata);

void merge(vector v);

void remove(int i);

void set(void *pdata, int i);

void insert(void *pdata, int i);

void subset(int i, int j);

#endif
