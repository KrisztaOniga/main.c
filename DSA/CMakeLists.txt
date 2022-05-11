cmake_minimum_required(VERSION 3.20)
project(DSA C)

set(CMAKE_C_STANDARD 11)

add_executable(DSA sapi_sales/src/main.c sapi_sales/headers/manager/lab2.h sapi_sales/headers/manager/lab_manager.h sapi_sales/headers/models/product.h sapi_sales/headers/models/user.h sapi_sales/src/manager/lab2.c sapi_sales/src/manager/lab_manager.c sapi_sales/src/models/product.c sapi_sales/src/models/user.c shared/headers/errors.h shared/headers/messages.h shared/headers/useful.h shared/src/errors.c shared/src/messages.c sapi_sales/src/manager/lab3.c sapi_sales/headers/manager/lab3.h sapi_sales/headers/models/user_array.h sapi_sales/src/models/product_array.c sapi_sales/src/models/user_array.c sapi_sales/headers/stack/product_stack.h sapi_sales/src/stack/product_stack.c sapi_sales/headers/manager/lab5.h sapi_sales/src/manager/lab5.c sapi_sales/headers/models/product_array.h sapi_sales/headers/queue/user_queue.h sapi_sales/src/queue/user_queue.c sapi_sales/headers/manager/lab8.h sapi_sales/src/manager/lab8.c sapi_sales/headers/list/user_list.h sapi_sales/src/list/user_list.c sapi_sales/headers/manager/lab9.h sapi_sales/src/manager/lab9.c sapi_sales/headers/binary_search_tree/user_bst.h sapi_sales/src/binary_search_tree/user_bst.c sapi_sales/headers/manager/lab10.h sapi_sales/src/manager/lab10.c sapi_sales/src/manager/lab12.c sapi_sales/headers/manager/lab12.h sapi_sales/headers/hash/product_hash.h sapi_sales/src/hash/product_hash.c)
include_directories(sapi_sales/headers/manager sapi_sales/headers/models shared/headers sapi_sales/headers/stack shared/headers
        sapi_sales/headers/queue sapi_sales/src/queue
        sapi_sales/headers/list sapi_sales/src/list
        sapi_sales/headers/binary_search_tree sapi_sales/src/binary_search_tree
        sapi_sales/headers/hash sapi_sales/src/hash
        )