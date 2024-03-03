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

Test(and, basic, .init = redirect) {
    shellIn("tests/and/basic/.shell");
    parser("tests/and/basic/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/and/basic/.out").c_str());
}

Test(and, one, .init = redirect) {
    shellIn("tests/and/one/.shell");
    parser("tests/and/one/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/and/one/.out").c_str());
}

Test(and, other, .init = redirect) {
    shellIn("tests/and/other/.shell");
    parser("tests/and/other/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/and/other/.out").c_str());
}

Test(and, two, .init = redirect) {
    shellIn("tests/and/two/.shell");
    parser("tests/and/two/.nts");
    std::cout.flush();
    cr_assert_stdout_eq_str(shellOut("tests/and/two/.out").c_str());
}
