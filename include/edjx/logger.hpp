#pragma once

#include <string>

namespace edjx {

/// Logger API functions.
namespace logger {
    /**
     * @brief Logs a message at the info level
     * 
     * Logs an information message.
     * The "info" level designates useful information.
     * 
     * @param log_str Log message
     */
    void info(const std::string & log_str);

    /**
     * @brief Logs a message at the error level
     * 
     * Logs an error message.
     * The "error" level designates very serious errors.
     * 
     * @param log_str Log message
     */
    void error(const std::string & log_str);

    /**
     * @brief Logs a message at the warn level
     * 
     * Logs a warning message.
     * The "warn" level designates hazardous situations.
     * 
     * @param log_str Log message
     */
    void warn(const std::string & log_str);

    /**
     * @brief Logs a message at the debug level
     * 
     * Logs a debug message.
     * The "debug" level designates lower priority information.
     * 
     * @param log_str Log message
     */
    void debug(const std::string & log_str);

    /**
     * @brief Logs a message at the trace level
     * 
     * Logs a trace message.
     * The "trace" level designates very low priority, often
     * extremely verbose, information.
     * 
     * @param log_str Log message
     */
    void trace(const std::string & log_str);

    /**
     * @brief Logs a message at the fatal level
     * 
     * Logs a fatal message.
     * The "fatal" level designates fatal situations.
     * 
     * @param log_str Log message
     */
    void fatal(const std::string & log_str);

}}