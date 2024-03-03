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

Test(or, basic, .init = redirect) {
    shellIn("tests/or/basic/.shell");
    parser("tests/or/basic/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/or/basic/.out").c_str());
}

Test(or, one, .init = redirect) {
    shellIn("tests/or/one/.shell");
    parser("tests/or/one/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/or/one/.out").c_str());
}

Test(or, other, .init = redirect) {
    shellIn("tests/or/other/.shell");
    parser("tests/or/other/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/or/other/.out").c_str());
}

Test(or, two, .init = redirect) {
    shellIn("tests/or/two/.shell");
    parser("tests/or/two/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/or/two/.out").c_str());
}
