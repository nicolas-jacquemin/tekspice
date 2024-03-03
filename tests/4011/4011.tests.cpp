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

Test(nand4011, basic, .init = redirect) {
    shellIn("tests/4011/basic/.shell");
    parser("tests/4011/basic/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/4011/basic/.out").c_str());
}

Test(nand4011, advanced, .init = redirect) {
    shellIn("tests/4011/advanced/.shell");
    parser("tests/4011/advanced/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/4011/advanced/.out").c_str());
}
