/**
 @file rpnx/environment.hpp

 This file provides the conveyor template class.
 
 After declaring an instance of a conveyor c, you can
 call c.allocate() to get a pointer to a conveyor 
 allocated object.
 
 When a conveyor is destroyed, all objects allocated 
 by the conveyor are destroyed and associated memory
 deallocated automatically.
 
 There is no way to free or delete individual objects
 allocated by a conveyor independently of eachother.

*/

#ifndef RPNX_DOC_CONVEYOR_HPP
#define RPNX_DOC_CONVEYOR_HPP

#include <filesystem>
#include <string>
#include <optional>
#include <memory>

namespace rpnx
{
	


}

#endif
