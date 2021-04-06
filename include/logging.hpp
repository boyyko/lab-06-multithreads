//
// Created by boyyko on 03.04.2021.
//

#ifndef TEMPLATE_LOGGING_HPP
#define TEMPLATE_LOGGING_HPP

#include <boost/log/utility/setup/console.hpp>
#include <boost/log/expressions/attr.hpp>
#include <boost/log/expressions/attr_fwd.hpp>
#include <boost/log/expressions/keyword.hpp>
#include <boost/log/expressions/keyword_fwd.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

void init()
{
std::string format = "%TimeStamp% <%Severity%> (%ThreadID%): %Message%";

auto  sink_trace = boost::log::add_file_log(
      boost::log::keywords::file_name = "logs/trace/log_trace_%N.log",
      boost::log::keywords::rotation_size = 10 * 1024 * 1024,
      boost::log::keywords::format = format);
      sink_trace->set_filter(boost::log::trivial::severity == boost::log::trivial::trace);

auto  sink_info = boost::log::add_file_log(
      boost::log::keywords::file_name = "logs/info/log_info_%N.log",
      boost::log::keywords::rotation_size = 10 * 1024 * 1024,
      boost::log::keywords::format = format);
      sink_info->set_filter(boost::log::trivial::severity == boost::log::trivial::info);

auto  sink_console = boost::log::add_console_log(std::cout,boost::log::keywords::format = format);
      sink_console->set_filter(boost::log::trivial::severity == boost::log::trivial::info);


boost::log::add_common_attributes();
}

#endif  // TEMPLATE_LOGGING_HPP
