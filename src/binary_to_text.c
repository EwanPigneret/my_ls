#include "my_ls.h"

char* binary_to_text(int binary_input) {
    if (binary_input == 1) {
        return ">";
    }
    else {
        return "<";
    }
}