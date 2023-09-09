#ifndef STL_DEMO_H
#define STL_DEMO_H

#include <iostream>
#include "map.h"
#include "set.h"
#include "list.h"
#include "vector.h"

// 命名空间
namespace stl_demo 
{
    // vector
    int test_vector(){
        std::cout << "[stl_verctor_make()     function]" << std::endl;
        stl_verctor_make();
        std::cout << "[stl_verctor_at()       function]" << std::endl;
        stl_verctor_at();
        std::cout << "[stl_verctor_erase()    function]" << std::endl;
        stl_verctor_erase();
        std::cout << "[stl_verctor_iterator() function]" << std::endl;
        stl_verctor_iterator();
        return 0;
    }
    // map
    int test_map(){
        std::cout << "[map_make()     function]" << std::endl;
        map_make();
        std::cout << "[map_iterator() function]" << std::endl;
        map_iterator();
        std::cout << "[map_find()     function]" << std::endl;
        map_find();
        std::cout << "[map_erase()    function]" << std::endl;
        map_erase();
        return 0;
    }
    // list
    int test_list(){
        std::cout << "[list_make()     function]" << std::endl;
        list_make();
        std::cout << "[list_iterator() function]" << std::endl;
        list_iterator();
        std::cout << "[list_remove()   function]" << std::endl;
        list_remove();
        return 0;
    }
    // set
    int test_set(){
        std::cout << "[stl_set()       function]" << std::endl;
        stl_set();
        return 0;
    }
}

#endif 