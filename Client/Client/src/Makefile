gcc -c -Wall -Werror -fpic functions.c
gcc -shared -o libfunctions.so functions.o
cp libfunctions.so /usr/lib/
gcc -Wall -o client client.c -lfunctions

 