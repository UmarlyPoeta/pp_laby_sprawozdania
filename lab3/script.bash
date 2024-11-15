#!/bin/bash

# Kompilacja programu z wybranymi opcjami
echo "Rozpoczynam kompilację programu..."

# Opcje kompilacji
CFLAGS="-std=c11 -O2 -march=native"

# Nazwa pliku źródłowego i wynikowego
SOURCE="hello.c"
OUTPUT="hello"

# Kompilacja
echo "Kompiluję $SOURCE z opcjami $CFLAGS..."
gcc $CFLAGS -o $OUTPUT $SOURCE

# Sprawdzenie, czy kompilacja zakończyła się sukcesem
if [ $? -eq 0 ]; then
    echo "Kompilacja zakończona sukcesem."
    echo "Uruchamiam program..."
    ./$OUTPUT
else
    echo "Błąd podczas kompilacji."
fi

# Kompilacja z opcją -g (debugowanie)
CFLAGS_DEBUG="-std=c11 -O2 -march=native -g"
echo "Kompiluję $SOURCE z opcjami $CFLAGS_DEBUG..."
gcc $CFLAGS_DEBUG -o $OUTPUT $SOURCE

# Sprawdzenie, czy kompilacja zakończyła się sukcesem
if [ $? -eq 0 ]; then
    echo "Kompilacja zakończona sukcesem."
    echo "Uruchamiam program w trybie debugowania..."
    gdb -q -ex "break main" -ex "run" -ex "step" -ex "help" -ex "quit" ./$OUTPUT
else
    echo "Błąd podczas kompilacji."
fi

