#include vector.h
#include memory.h

vector init_vector()
{
    vector v = (vector) malloc(sizeof(vector));
    v -> data = (void**) malloc(sizeof(void*) * BASE_CAP);
    v -> length = 0;
    v -> cap = BASE_CAP;
    return v;
}

void resize()
{
    void *temp = realloc(data, sizeof(data) * EXPAND_RATE);
    if(temp != NULL)
        data = temp;
    else
        puts("Error growing array.");
}

boolean check_size(int size) { return size +length <= capacity; }

void add(void *pdata)
{
    if(!checksize(1))
        resize;
    data[length] = pdata;
    length++;
}

void merge(vector v)
{
    while(!check_size(&sizeof((v->data))))
        resize();
    arraycpy(v->data, 0, data, length, sizeof(v->data));
    length += sizeof(v->data);
}

void remove(int i)
{
    void **temp = malloc(sizeof(data));
    arraycpy(data, 0, temp, 0, i);
    arraycpy(data, i, temp, 0, sizeof(data) - i)
    data = temp;
}
