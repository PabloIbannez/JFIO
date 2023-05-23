#include "../ThirdParty/pybind11_json.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <fstream>

void writeJSON2File(std::string filename,const nlohmann::json& data,bool formatted){

  std::string outputBuffer = data.dump();
  std::ofstream out(filename);

  if(!formatted){
    out << outputBuffer;
  } else {
    //Write outputBuffer to file, char by char
    uint dictLevel = 0;
    uint listLevel = 0;

    std::string indent = "  ";
    for (uint i = 0 ; i < outputBuffer.size(); i++){

      char& c = outputBuffer[i];

      char& prevC = std::string(" ")[0];
      char& nextC = std::string(" ")[0];

      if (i > 0){
        prevC = outputBuffer[i-1];
      }
      if (i < outputBuffer.size()-1){
        nextC = outputBuffer[i+1];
      }

      if (c == '{'){dictLevel++;}
      if (c == '}'){dictLevel--;}

      if (c == '['){listLevel++;}
      if (c == ']'){listLevel--;}

      std::string currentIndent = std::string(dictLevel*indent.size(),' ');

      bool written = false;
      if (c == ',' and (listLevel == 0 or (listLevel == 1 and prevC == ']'))){
        out << c << '\n' << currentIndent ;
        written = true;
      }

      if (c == '[' and prevC == ':' and nextC == '['){
        out << c << '\n' << currentIndent ;
        written = true;
      }

      if (c == ']' and nextC == '}'){
        out << c ;
        written = true;
      }

      if (c == '{'){
        out << c << '\n' << currentIndent ;
        written = true;
      }

      if (c == '}'){
        out << '\n' << currentIndent << c ;
        written = true;
      }

      if (!written){
        out << c;
      }
    }
  }

  return;
}

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(writeJSON2File,m)
{
  m.doc() = "write";

  m.def("writeJSON2File", &writeJSON2File, "Write JSON to file");
}
