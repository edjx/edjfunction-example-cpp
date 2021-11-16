#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "error.hpp"

namespace edjx {

/// APIs for interacting with EDJX KV-Store.
namespace kv {

    /**
     * @brief Returns the value associated with the provided key.
     * 
     * @param result Returned value associated with the key
     * @param key Key
     * @return Returns edjx::error::KVError::Success on success,
     * some other value on failure
     */
    edjx::error::KVError get(
        std::vector<uint8_t> & result,
        const std::string & key
    );

    /**
     * @brief Inserts a key-value pair into the KV store.
     * 
     * @param key Key
     * @param val Value to be inserted for the corresponding key
     * @return Returns edjx::error::KVError::Success on success,
     * some other value on failure
     */
    edjx::error::KVError put(
        const std::string & key,
        const std::vector<uint8_t> & val
    );

    /**
     * @brief Inserts a key-value pair into the KV store.
     * 
     * @param key Key
     * @param val Value to be inserted for the corresponding key
     * @return Returns edjx::error::KVError::Success on success,
     * some other value on failure
     */
    edjx::error::KVError put(
        const std::string & key,
        const std::string & val
    );

    /**
     * @brief Inserts a key-value pair into the KV store.
     * 
     * @param key Key
     * @param val Value to be inserted for the corresponding key
     * @param ttl Time to live (TTL) value in seconds
     * @return Returns edjx::error::KVError::Success on success,
     * some other value on failure
     */
    edjx::error::KVError put(
        const std::string & key,
        const std::vector<uint8_t> & val,
        uint64_t ttl
    );

    /**
     * @brief Inserts a key-value pair into the KV store.
     * 
     * @param key Key
     * @param val Value to be inserted for the corresponding key
     * @param ttl Time to live (TTL) value in seconds
     * @return Returns edjx::error::KVError::Success on success,
     * some other value on failure
     */
    edjx::error::KVError put(
        const std::string & key,
        const std::string & val,
        uint64_t ttl
    );

    /**
     * @brief Removes an entry from the KV store.
     * 
     * @param key Key
     * @return Returns edjx::error::KVError::Success on success,
     * some other value on failure
     */
    edjx::error::KVError remove(const std::string & key);

}}