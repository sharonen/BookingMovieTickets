#include <iostream>
#include "lib/views/views.hpp"

// Create a main function
int main()
{

    // Craete the DB object
    DB::getInstance();
    // Create the Views object
    Views::getInstance();

    return 0;
}
