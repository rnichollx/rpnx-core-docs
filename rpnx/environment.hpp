/**
 @file rpnx/environment.hpp

 This file provides functions to access the environment in a thread safe manner.
 Note that POSIX functions such as getenv and putenv are not thread-safe.
 The functions in this file are thread-safe if they are exclusively used to
 access environment variables.

 Alternatively, you can lock rpnx::environment_mutex before using functions like
 getenv for thread safety.

*/

#ifndef RPNX_DOC_ENVIRONMENT_HPP
#define RPNX_DOC_ENVIRONMENT_HPP

#include <filesystem>
#include <string>
#include <optional>

namespace rpnx
{



	/** This mutex is locked when using environment functions, to prevent race conditions.
	*/
	std::mutex environment_mutex;

	/** Gets an environment variable in a thread safe manner by locking rpnx::environment_mutex.
	  
	 <b>Example</b>
	 @code
      std::string username = rpnx::get_environment_variable("USERNAME").value_or("");
     @endcode

	 <b>Header</b>
	 @code
	  #include "rpnx/environment.hpp"
	 @endcode
	*/
	std::optional<std::string> get_environment_variable(std::string const& key);


	/** Sets an environment variable in a thread safe manner by locking rpnx::environment_mutex.
	  
	 <b>Example</b>
	 @code
      rpnx::set_environment_variable("FOO", "BAR");
     @endcode

	 <b>Header</b>
	 @code
	  #include "rpnx/environment.hpp"
	 @endcode
	*/
	void set_environment_variable(std::string const& key, std::string const& value);


    /** Gets the directories in the path in a thread safe manner by locking rpnx::environment_mutex.
	 
	 This function works by looking at the PATH variable (when on POSIX systems) or the equivalent
	 on other operating systems, and splitting it via the OS's preferred path separator (usually : or ;).
	  
	 <b>Example</b>
	 @code
     auto path = rpnx::get_path();

     for (std::filesystem::path const & x : path)
     {
         std::cout << "Path Value=" << x << std::endl;
     }
     @endcode

	 <b>Header</b>
	 @code
	  #include "rpnx/environment.hpp"
	 @endcode


	*/
    std::vector<std::filesystem::path> get_path();

	/** Like std::filesystem::current_path, except thread-safe when used exclusively with other rpnx functions to mutate the environment.
	 
	 <b>Example</b>
	 @code
       std::cout << "Current working directory is: " << rpnx::current_path() << std::endl;
     @endcode

	 <b>Header</b>
	 @code
	  #include "rpnx/environment.hpp"
	 @endcode
     */
    std::filesystem::path current_path();


}

#endif
