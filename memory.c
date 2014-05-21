#include memory.h

void arraycpy(void *src, int sPos, void *dest, int dPos, int length)
{
    if((sPos < 0 || sPos + length > sizeof(src)) ||
            (dPos < 0 || dPos + length > sizeof(dest)))
        return;
    for(int i = sPos; i < sPos + length; i++)
        for(int j = dPos; j < dPos + length; j++)
            dest[j] = *src[i];
}
