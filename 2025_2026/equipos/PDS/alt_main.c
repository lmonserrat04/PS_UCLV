#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./libvectorops.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    double* (*crear_vector)(size_t) = dlsym(handle, "crear_vector");
    if (!crear_vector) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    size_t n = 3;
    double* v = crear_vector(n);
    printf("Vector creado dinámicamente con tamaño %zu\n", n);

    free(v);
    dlclose(handle);
    return 0;
}