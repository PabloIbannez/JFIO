#include "../ThirdParty/pybind11_json.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <fstream>

nlohmann::json readJSONFromFile(std::string filename){

  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open file " + filename);
  }

  nlohmann::json j;
  file >> j;

  return std::move(j);
}

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(readJSONFromFile,m)
{
  m.doc() = "read";

  m.def("readJSONFromFile", &readJSONFromFile, "Read JSON from file");
}
