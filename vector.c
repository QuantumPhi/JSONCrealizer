#include "vector.h"
#include "memory.h"

vector init_vector()
{
    vector v = (vector) malloc(sizeof(vector));
    v.data = (void**) malloc(sizeof(void*) * BASE_CAP);
    v.length = 0;
    v.capacity = BASE_CAP;
    return v;
}

void resize()
{
    void **temp = (void**)realloc(data, sizeof(data) * EXPAND_RATE);
    if(temp != NULL)
        data = temp;
    else
        puts("Error growing array.");
    capacity *= EXPAND_RATE;
}

bool check_size(int size) { return size +length <= capacity; }

void add(void *pdata)
{
    if(!checksize(1))
        resize;
    data[length] = pdata;
    length++;
}

void merge(vector v)
{
    while(!check_size(sizeof(v.data)))
        resize();
    arraycpy(v.data, 0, data, length, sizeof(v.data));
    length += sizeof(v.data);
}

void remove(int i)
{
    void **temp = (void**)malloc(sizeof(data));
    arraycpy(data, 0, temp, 0, i);
    arraycpy(data, i, temp, 0, sizeof(data) - i)
    data = temp;
}

void set(void *pdata, int i)
{
    if(i < 0 || i > length)
        return;
    data[i] = pdata;
}

void insert(void *pdata, int i)
{
    void **temp;
    if(!check_size(1))
        resize();
    temp = (void**)malloc(sizeof(data));
    arraycpy(data, 0, temp, 0, i);
    temp[i] = pdata;
    arraycpy(data, i, temp, i+1, sizeof(data) - i);
    data = temp;
}

vector subset(int i, int j)
{
    if((i < 0 || j < 0) || (i > length || j > length))
        return NULL;
    vector v = init_vector();
    void *temp = malloc((i - j) + 5);
    if(temp == NULL)
        return NULL;
    arraycpy(data, i, temp, 0, (i - j) + 1);
    v.merge(temp);
}
