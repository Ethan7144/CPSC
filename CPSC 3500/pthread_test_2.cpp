//
// Created by Matthew Thayer on 1/11/22.
//

#include <pthread.h>
#include <iostream>

void *PrintHello(void *arg)
{
    std::cout << "Hello World!";
    return 0;
}

int main()
{
    pthread_t id;
    int rc;
    std::cout << "In main: creating thread \n";

    rc = pthread_create(&id, NULL, PrintHello, NULL);

    if (rc){
        std::cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
        return -1;
    }

    pthread_exit(0);
}
