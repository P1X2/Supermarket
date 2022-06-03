#include "FileReadError.h"
#include <string>
using namespace std;
FileReadError::FileReadError(string data_file,int line) :
	invalid_argument("Data error in" + data_file + "file"+ to_string(line)+"line") {}