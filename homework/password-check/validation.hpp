#pragma once
#include <map>
#include <string>

enum ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoNotMatch
};

extern std::map<ErrorCode, std::string> codeDict;

std::string getErrorMessage(ErrorCode code);

bool doPasswordsMatch(std::string passA, std::string passB);

ErrorCode checkPasswordRules(std::string pass);

ErrorCode checkPassword(std::string passA, std::string passB);

bool has_any_of(const std::string& pass, const std::string& required);