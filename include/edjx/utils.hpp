#pragma once

#include <vector>
#include <string>

namespace edjx {

/// Various helper functions.
namespace utils {

    /**
     * @brief Convert a string to a vector of bytes.
     * 
     * @param str String
     * @return String represented as a vector of ASCII bytes
     */
    std::vector<uint8_t> to_bytes(const std::string & str);

    /**
     * @brief Convert a vector of bytes to a string.
     * 
     * @param vec Vector of ASCII bytes
     * @return Vector of ASCII bytes converted into a string
     */
    std::string to_string(const std::vector<uint8_t> & vec);

}}