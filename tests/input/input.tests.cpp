#include "utils.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fstream>
#include "../shellInputs.hpp"

static void redirect(void) {
    cr_redirect_stdout();
}

static void shellIn(const std::string &path) {
    std::ifstream shell(path);
    shellInputs << shell.rdbuf();
}

static std::string shellOut(const std::string &path) {
    std::ifstream file(path);
    std::string out((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return (out);
}

Test(input, basic, .init = redirect) {
    shellIn("tests/input/basic/.shell");
    parser("tests/input/basic/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/input/basic/.out").c_str());
}
