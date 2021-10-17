#pragma once

#include <string>
#include <vector>
#include <map>
#include <strings.h>

#include "utils.hpp"

namespace edjx {

/// Data types used by HTTP-related functions.
namespace http {

    /**
     * @brief Enum containing an HTTP version
     */
    enum class HttpVersion {
        HTTP_09, ///< HTTP version HTTP/0.9
        HTTP_10, ///< HTTP version HTTP/1.0
        HTTP_11, ///< HTTP version HTTP/1.1
        HTTP_2,  ///< HTTP version HTTP/2.0
        HTTP_3   ///< HTTP version HTTP/3.0
    };

    /**
     * @brief Enum containing a number of common HTTP methods.
     */
    enum class HttpMethod {
        NONE = 0,
        GET = 1,
        HEAD = 2,
        POST = 3,
        PUT = 4,
        DELETE = 5,
        CONNECT = 6,
        OPTIONS = 7,
        TRACE = 8,
        PATCH = 9,
    };

    /**
     * @brief A map<string, ...> comparator that achieves case-insensitive keys.
     */
    struct CaseInsensitiveKeys {
        bool operator() (const std::string &lhs, const std::string &rhs) const {
            return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
        }
    };

    /**
     * @brief A map of HttpHeaders where keys are case-insensitive header names.
     */
    typedef std::map<std::string, std::vector<std::string>, CaseInsensitiveKeys> HttpHeaders;

    /**
     * @brief HTTP status code (e.g., value 200 means OK,
     * value 404 means Not Found)
     */
    typedef uint16_t HttpStatusCode;

    /**
     * @brief Class that represents a URL
     * 
     * Common URL format: "scheme://host:port/path?query"
     */
    class Uri {
    public:
        /**
         * @brief Default constructor
         */
        inline Uri() {}

        /**
         * @brief Construct URL from a string
         * 
         * @param url URL string (e.g., "scheme://host:port/path?query")
         */
        inline Uri(const std::string & url) {
            this->url = url;
        }

        /**
         * @brief Construct URL from a C string
         * 
         * @param url URL string (e.g., "scheme://host:port/path?query")
         */
        inline Uri(const char * url) {
            this->url = std::string(url);
        }

        /**
         * @brief Construct URL from a vector of ASCII characters
         * 
         * @param url URL string (e.g., "scheme://host:port/path?query")
         * represented as ASCII characters
         */
        inline Uri(const std::vector<uint8_t> & url) {
            this->url = edjx::utils::to_string(url);
        }

        /**
         * @brief Returns URL as a string
         * 
         * @return URL ("scheme://host:port/path?query")
         */
        inline std::string as_string() const {
            return url;
        }

    private:
        std::string url;
    };

}}