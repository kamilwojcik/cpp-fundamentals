#include "validation.hpp"
#include <algorithm>

std::map<ErrorCode, std::string> codeDict{
    {Ok, "Ok"},
    {PasswordNeedsAtLeastNineCharacters, "Password needs to have at least nine characters"},
    {PasswordNeedsAtLeastOneNumber, "Password needs to have at least one number"},
    {PasswordNeedsAtLeastOneSpecialCharacter, "Password needs to have at least one special character"},
    {PasswordNeedsAtLeastOneUppercaseLetter, "Password needs to have at least one uppercase letter"},
    {PasswordsDoNotMatch, "Passwords do not match"}};

std::string getErrorMessage(ErrorCode code) {
    return codeDict[code];
}

bool doPasswordsMatch(std::string passA, std::string passB) {
    return passA == passB;
}

bool hasMinimumLength(std::string pass) {
    return pass.size() >= 9;
}

bool has_any_of(const std::string& pass, const std::string& required )
{
    return pass.end() != find_first_of(pass.begin(), pass.end(), required.begin(), required.end());
}


ErrorCode checkPasswordRules(std::string pass) {
    std::string digits = "0123456789";
    std::string specials = "~!@#$%^&*()?><.,/;;";
    std::string capitals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (!hasMinimumLength(pass))
        return PasswordNeedsAtLeastNineCharacters;
    else if (!has_any_of(pass, digits))
        return PasswordNeedsAtLeastOneNumber;
    else if (!has_any_of(pass, specials))
        return PasswordNeedsAtLeastOneSpecialCharacter;
    else if (!has_any_of(pass, capitals))
        return PasswordNeedsAtLeastOneUppercaseLetter;
    return Ok;
}

ErrorCode checkPassword(std::string passA, std::string passB) {
    if (doPasswordsMatch(passA, passB))
        return checkPasswordRules(passA);
    else
        return PasswordsDoNotMatch;
}
