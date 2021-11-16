#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <map>

#include "http.hpp"
#include "error.hpp"

namespace edjx {

/**
 * @brief Read-only HTTP request input for HTTP-trigger serverless functions.
 * 
 * For executing HTTP Requests, use [`edjx::fetch::HttpFetch`].
 */
namespace request {

    /**
     * @brief Request, which may include version, body, headers,
     * method, and URL.
     */
    struct HttpRequest {
        /// HTTP version of the request
        http::HttpVersion version;
        /// HTTP method of the request
        http::HttpMethod method;
        /// URL of the request
        http::Uri uri;
        /// HTTP headers of the request
        edjx::http::HttpHeaders headers;
        /// True if the request body was fetched
        bool body_present;
        /// Request body
        std::vector<uint8_t> body;

        /**
         * @brief Creates an empty request object with HTTP version set
         * to HTTP/1.1, HTTP method of NONE, and no body.
         */
        HttpRequest()
            : version(http::HttpVersion::HTTP_11),
            method(http::HttpMethod::NONE),
            body_present(false) {}


        /**
         * @brief Returns the client request being handled by the
         * serverless function.
         * 
         * Normally, this method does not need to be used explicitly.
         * EDJX sample [`C++ Serverless Application`]
         * (https://github.com/edjx/edjfunction-example-cpp) code file
         * (main.cpp) uses this method to fetch HTTP Request.
         * 
         * @param result HttpRequest in which the request will be stored
         * @param prefetch_body By passing the `prefetch_body` flag as true,
         * the whole request body will be read from request at this function
         * call time and then reside in the function memory.
         * @return Returns edjx::error::HttpError::Success on success,
         * some other value if execution failed.
         */
        static edjx::error::HttpError from_client(HttpRequest & result, bool prefetch_body);

        /**
         * @brief Returns the HTTP method of the request.
         * 
         * @return HTTP method of the request
         */
        http::HttpMethod get_method() const;

        /**
         * @brief Returns the URL from the request.
         * 
         * Returns the request URL value as [`edjx::http::Uri`] object.
         * 
         * @return URL of the request
         */
        http::Uri get_uri() const;

        /**
         * @brief Returns HTTP headers of the request.
         * 
         * Returns the map of headers in the request as a map of header names
         * to a vector of header values.
         * 
         * @return Request headers
         */
        const edjx::http::HttpHeaders & get_headers() const;

        /**
         * @brief Fetches the request body.
         * 
         * If the HTTP request body was not prefetched in the `from_client`
         * function, it can be fetched by invoking this method.
         * 
         * @return Returns edjx::error::HttpError::Success on success,
         * some other value on failure.
         */
        edjx::error::HttpError fetch_body();

        /**
         * @brief Checks whether the request body has been fetched.
         * 
         * @return true Request body was fetched.
         * @return false Request body has not been fetched.
         */
        bool is_body_present() const;

        /**
         * @brief Returns the body associated with the request as bytes.
         * 
         * If the HTTP request body was not prefetched, `fetch_body` must
         * be called first.
         * 
         * @return Request body
         */
        const std::vector<uint8_t> & get_body() const;
    };

}}