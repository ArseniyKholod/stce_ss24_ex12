#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#define DCO_POPEN _popen
#define DCO_PCLOSE _pclose
#else
#define DCO_POPEN popen
#define DCO_PCLOSE pclose
#endif

int execute_cmd(std::string cmd, std::string output_filename, int & lines, bool print_output = true) {
  char buffer[2048];
  FILE* pipe = DCO_POPEN(cmd.c_str(), "r");
  if (!pipe) { throw std::runtime_error("popen() failed!"); }
  lines = 0;
  std::ofstream file(output_filename.c_str());
  while (fgets(buffer, 2048, pipe) != NULL) {
    file << buffer;
    if (print_output) std::cout << buffer;
    lines++;
  }
  file.close();
  return DCO_PCLOSE(pipe);
}

int exec(const std::string cmd, const std::string output_filename, const std::string result_filename) {

  int lines;

  //** execute examples / stringent (optionally using opt file)
  //**  put stdout into file called output_filename
  int rc = execute_cmd(cmd, output_filename, lines);
  if (rc != 0) return -1;
  
  //** execute diff between output_filename and results file
#ifdef _WIN32
  std::string command = "diff --strip-trailing-cr \"" + output_filename + "\" \"" + result_filename + "\"";
#else
  std::string command = "diff --strip-trailing-cr " + output_filename + " " + result_filename;
#endif
  std::string diff_output_filename = output_filename + std::string(".diff");
  rc = execute_cmd(command, diff_output_filename, lines);
  
  return lines;
}

inline bool file_exists(const std::string& name) {
  std::ifstream f(name.c_str());
    return f.good();
}

int main(int argc, char* argv[]) {

  std::string executable = argv[1];

  if (!file_exists(executable)) { return -1; }

  std::string cmd = executable;

  std::string output_file = argv[2];
  std::string result_file = argv[3];

  if (argc > 5) {
    std::string pars = argv[5];
    
    std::size_t start = 0, end = pars.find(";");
    while ( end != std::string::npos) {
      cmd += " " + pars.substr(start, end-start);
      start = end+1;
      end = pars.find(";", start);
    }
    cmd += " " + pars.substr(start, pars.length());
  }
  
  //** return code
  int e;
  
  bool generate_into_ref_results = (std::string(argv[4]) == "0") ? false : true;
  if (generate_into_ref_results) {
    int lines;
    e = execute_cmd(cmd, result_file, lines);
  } else {
    //** needs to be executed to generate tmp result files
    e = exec(cmd, output_file, result_file);
    
    if (!file_exists(result_file)) {
      e = -1;
    }
  }

  return e;
}
