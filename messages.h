#ifndef MESSAGES_H
#define MESSAGES_H

//username
const char* const USERNAME_EMPTY_ERR = "Username can't be an empty string!";
const char* const USERNAME_CONTAINS_SPACE_ERR = "Username can't contain space characters!";

//password
const char* const PASS_EMPTY_ERR = "Password can't be an empty string!";
const char* const PASS_CONTAINS_SPACE_ERR = "Password can't contain space characters!";
const char* const PASS_WRONG_ERR = "Wrong password!";

//EGN
const char* const EGN_CONTAINS_NONDIGIT_ERR = "EGN must be only digits!";
const char* const EGN_LENGTH_ERR = "EGN must be 10 digits!";

//name
const char* const NAME_INVALID_ERR = "Invalid name!";

//day
const char* const DAY_INVALID_ERR = "Day must be between 1 and 31!";
const char* const LEAP_FEB_DAY_INVALID_ERR = "On leap years february has 29 days!";
const char* const FEB_DAY_INVALID_ERR = "February has only 28 days!";

//month
const char* const DAYS30_INVALID_ERR = "That month has only 30 days!";
const char* const MONTH_IVALID_ERR = "Month must between 1 and 12!";

//year
const char* const YEAR_INVALID_ERR = "Year must be a positive number!";

//phone
const char* const PHONE_CONTAINS_NONDIGIT_ERR = "Phone number must be only digits!";
const char* const PHONE_LENGTH_ERR = "Phone number must be 10 digits!";

//address
const char* const ADDRESS_EMPTY_ERR = "Address can't be an empty string!";
const char* const ADDRESS_PARANTH_ERR = "Address must be in \"\"";

//card
const char* const CARD_NUM_LEN_ERR = "Card number's length must be at least 7!";
const char* const CARD_NUM_START_ERR = "The card number must start with \"00\"";
const char* const CARD_NUM_CONTAINS_NONDIGIT_ERR = "Card number must contain digits!";
const char* const NO_SUCH_CARD_ERR = "There is no card with this number!";

//PIN
const char* const PIN_LEN_ERR = "PIN's length must be 4!";
const char* const PIN_CONTAINS_NONDIGIT_ERR = "PIN must be only digits!";
const char* const PIN_WRONG_ERR = "Wrong PIN!";

//IBAN
const char* const IBAN_LEN_ERR = "IBAN's length must be at least 13!";
const char* const IBAN_START_ERR = "IBAN must start with \"00MYBANK\"";
const char* const IBAN_CONTAINS_NONDIGIT_ERR = "IBAN must contain only digits after \"00MYBANK\"";
const char* const NO_SUCH_ACCOUNT_ERR = "There is no account with this IBAN!";

//balance
const char* const NEGATIVE_BALANCE_ERR = "Account balance must be positive!";

//employee
const char* const NO_SUCH_EMPLOYEE_EGN_ERR = "There is no employee with this EGN!";
const char* const EXISTING_EMPLOYEE_EGN_ERR = "There is already an employee with this EGN!";
const char* const NO_SUCH_EMPLOYEE_USER_ERR = "There is no employee with this username!";
const char* const EXISTING_EMPLOYEE_USER_ERR = "There is already an employee with this username!";

//client
const char* const NO_SUCH_CLIENT_ERR = "There is no client with this EGN!";
const char* const EXISTING_CLIENT_ERR = "There is already a client with this EGN!";

//key
const char* const NO_SUCH_ELEMENT_ERR = "There is no element with this key!";

//admin file 
const char* const ADMIN_FILE_ERR = "Admin file can't be open!";

//employees file
const char* const EMPLOYEE_FILE_ERR = "Employee file can't be open!";

//clients file
const char* const CLIENT_FILE_ERR = "Client file can't be open!";

#endif
