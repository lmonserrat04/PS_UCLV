# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -fPIC

# Archivos
OBJS = vectors.o
STATIC_LIB = libvectorops.a
SHARED_LIB = libvectorops.so
TARGET_STATIC = programa_estatico
TARGET_SHARED = programa_dinamico

# Regla por defecto
all: $(TARGET_STATIC) $(TARGET_SHARED)

# Biblioteca estática
$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

# Biblioteca compartida
$(SHARED_LIB): $(OBJS)
	$(CC) -shared -o $@ $^

# Programa con biblioteca estática
$(TARGET_STATIC): main.c $(STATIC_LIB)
	$(CC) $< -L. -lvectorops -o $@

# Programa con biblioteca compartida
$(TARGET_SHARED): main.c $(SHARED_LIB)
	$(CC) $< -L. -lvectorops -o $@

# Compilar objeto
vectors.o: vectors.c vectors.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -f *.o *.a *.so programa_estatico programa_dinamico

# Ejecutar programa con biblioteca compartida
run: $(TARGET_SHARED)
	export LD_LIBRARY_PATH=. && ./$(TARGET_SHARED)

.PHONY: all clean run