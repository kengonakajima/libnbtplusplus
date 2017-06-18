#include "io/stream_reader.h"
#include "io/izlibstream.h"
#include "nbt_tags.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv ) {
    std::string input {
        1, //tag_type::Byte
            0, //tag_type::End
            11, //tag_type::Int_Array

            0x0a, 0x0b, 0x0c, 0x0d, //0x0a0b0c0d in Big Endian

            0x00, 0x06, //String length in Big Endian
            'f', 'o', 'o', 'b', 'a', 'r',

            0 //tag_type::End (invalid with allow_end = false)
            };

    std::istringstream is(input);
    nbt::io::stream_reader reader(is);

    nbt::tag_type t = reader.read_type();

    std::cout << (int)t << std::endl;
    return 0;
}
