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
  /** Gets an environment variable
  */
  std::optional<std::string> get_environment_variable(std::string const & key);


}

#endif
