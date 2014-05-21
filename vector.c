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
    void **temp = malloc(sizeof(data) * EXPAND_RATE);
    arraycpy(data,0, temp, 0, sizeof(data));
    data = temp;
}

boolean check_size(int *size) { return *size +length <= capacity; }

void add(void *pdata)
{

}
