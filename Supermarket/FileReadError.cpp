#include "FileReadError.h"

FileReadError::FileReadError(string data_file) :
	invalid_argument("Too much or not enough arguments in " + data_file + "file"){}