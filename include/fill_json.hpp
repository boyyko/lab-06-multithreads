// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_FILL_JSON_HPP_
#define INCLUDE_FILL_JSON_HPP_

#include <iostream>
#include <picosha/picosha2.h>
#include <nlohmann/json.hpp>
#include <atomic>
#include <string>
#include <boost/log/trivial.hpp>

std::vector<nlohmann::json> content_json_file;
nlohmann::json j;
std:: string file_name;
const std::string end_str = "0000";

void fill_json()
{
  std::string rand_data = std::to_string(std::rand());
  std::string hash = picosha2::hash256_hex_string(rand_data);
  std::string time;

  if (hash.substr(hash.size() - end_str.size()) == end_str) // (hash.substr(60) - end_str.size()) == end_str)
  {
    BOOST_LOG_TRIVIAL(info) << "data:"       << rand_data
                            << "hash:"       << hash
                            << "timestamp:"  << time << std::endl;

    j =
        {
            {"timestamp", time},
            {"hash"     , hash},
            {"data"     , rand_data}
        };

    content_json_file.emplace_back(j);
  }
  else
  {
    BOOST_LOG_TRIVIAL(trace) << "data:"  << rand_data
                             << "hash:"  << hash << std::endl;

  }
}

void create_file()
{
  std::ofstream file;
  file.open(file_name + ".json");
  for (unsigned i = 0;i < content_json_file.size();++i)
  {
    file << content_json_file[i].dump(4) << std::endl;
  }
file.close();
}

#endif // INCLUDE_FILL_JSON_HPP_
