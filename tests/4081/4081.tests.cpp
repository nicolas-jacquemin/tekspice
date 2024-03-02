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

Test(and4081, basic, .init = redirect) {
    shellIn("tests/4081/basic/.shell");
    parser("tests/4081/basic/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/4081/basic/.out").c_str());
}

Test(and4081, out_03, .init = redirect) {
    shellIn("tests/4081/out_03/.shell");
    parser("tests/4081/out_03/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/4081/out_03/.out").c_str());
}

Test(and4081, out_11, .init = redirect) {
    shellIn("tests/4081/out_11/.shell");
    parser("tests/4081/out_11/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/4081/out_11/.out").c_str());
}
