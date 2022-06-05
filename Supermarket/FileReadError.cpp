#include "FileReadError.h"
#include <string>
using namespace std;
FileReadError::FileReadError(string data_file,int line) :
	invalid_argument("Data error in " + data_file + " file line "+ to_string(line)) {}