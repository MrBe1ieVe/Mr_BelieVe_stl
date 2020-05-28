//
// Created by Mr.BelieVe on 2020/5/28.
//

#ifndef MRBELIEVE_STL_STL_ALLOC_H
#define MRBELIEVE_STL_STL_ALLOC_H

#include <cstdlib> //malloc, free
#include <cstdio>
__STL_BEGIN_NAMESPACE
template<int __inst>
class __malloc_alloc_template{
public:
    static void *allocate(size_t size){
        void *__result = malloc(size);
        if (0 == __result){
            fprintf(stderr, "out of memory\n");
            exit(1);
        }
        return __result;
    }
    static void *deallocate(){
        free();
        return ;
    }
}





#endif //MRBELIEVE_STL_STL_ALLOC_H
