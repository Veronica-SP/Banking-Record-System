#ifndef MESSAGES_H
#define MESSAGES_H

//date creation exceptions-------------------------------
const char* const DAY_INVALID_ERR = "$ Day must be between 1 and 31!";
const char* const LEAP_FEB_DAY_INVALID_ERR = "$ On leap years february has 29 days!";
const char* const FEB_DAY_INVALID_ERR = "$ February has only 28 days!";
const char* const DAYS30_INVALID_ERR = "$ That month has only 30 days!";
const char* const MONTH_INVALID_ERR = "$ Month must between 1 and 12!";
const char* const YEAR_INVALID_ERR = "$ Year must be a positive number!";

//card creation exceptions-------------------------------
const char* const CARD_NUM_LEN_ERR = "$ Card number's length must be at least 7!";
const char* const CARD_NUM_START_ERR = "$ The card number must start with \"00\"";
const char* const CARD_NUM_CONTAINS_NONDIGIT_ERR = "$ Card number must contain only digits!";
const char* const PIN_LEN_ERR = "$ PIN's length must be 4!";
const char* const PIN_CONTAINS_NONDIGIT_ERR = "$ PIN must be only digits!";

//bank account creation exceptions-----------------------
const char* const IBAN_LEN_ERR = "$ IBAN's length must be at least 13!";
const char* const IBAN_START_ERR = "$ IBAN must start with \"00MYBANK\"";
const char* const IBAN_CONTAINS_NONDIGIT_ERR = "$ IBAN must contain only digits after \"00MYBANK\"";
const char* const NEGATIVE_BALANCE_ERR = "$ Account balance must be positive!";

//database user creation exceptions----------------------
const char* const USERNAME_EMPTY_ERR = "$ Username can't be an empty string!";
const char* const USERNAME_CONTAINS_SPACE_ERR = "$ Username can't contain space characters!";
const char* const PASS_EMPTY_ERR = "$ Password can't be an empty string!";
const char* const PASS_CONTAINS_SPACE_ERR = "$ Password can't contain space characters!";

//person creation exceptions-----------------------------
const char* const EGN_CONTAINS_NONDIGIT_ERR = "$ EGN must be only digits!";
const char* const EGN_LENGTH_ERR = "$ EGN must be 10 digits!";
const char* const NAME_INVALID_ERR = "$ Invalid name!";
const char* const PHONE_CONTAINS_NONDIGIT_ERR = "$ Phone number must be only digits!";
const char* const PHONE_LENGTH_ERR = "$ Phone number must be 10 digits!";
const char* const ADDRESS_EMPTY_ERR = "$ Address can't be an empty string!";
const char* const ADDRESS_PARANTH_ERR = "$ Address must be in \"\"";

//bank account actions exceptions-------------------------
const char* const NEGATIVE_AMOUNT_DEPOSIT_ERR = "$ Deposit amount must be positive!";
const char* const NEGATIVE_AMOUNT_WITHDRAW_ERR = "$ Withdraw amount must be positive!";
const char* const NOT_ENOUGH_WITHDRAW_ERR = "$ Not enough money!";
const char* const NO_SUCH_CARD_ERR = "$ There is no card with this number!";

//client account actions exceptions-----------------------
const char* const NO_SUCH_ACCOUNT_IBAN_ERR = "$ There is no account with this IBAN!";
const char* const NO_SUCH_ACCOUNT_CARD_ERR = "$ There is no account with a card with this number!";

//bank database actions exceptions------------------------
const char* const NO_ADMIN_ERR = "$ The bank database has no admin!";
const char* const NO_SUCH_EMPLOYEE_EGN_ERR = "$ There is no employee with this EGN!";
const char* const NO_SUCH_EMPLOYEE_USER_ERR = "$ There is no employee with this username!";
const char* const NO_SUCH_CLIENT_EGN_ERR = "$ There is no client with this EGN!";
const char* const NO_SUCH_CLIENT_CARD_ERR = "$ There is no client with a card with this number!";
const char* const EXISTING_EMPLOYEE_EGN_ERR = "$ There is already an employee with this EGN!";
const char* const EXISTING_EMPLOYEE_USER_ERR = "$ There is already an employee with this username!";
const char* const EXISTING_CLIENT_ERR = "$ There is already a client with this EGN!";

//database serialization exceptions------------------------
const char* const ADMIN_FILE_ERR = "$ Admin file can't be open!";
const char* const EMPLOYEE_FILE_ERR = "$ Employee file can't be open!";
const char* const CLIENT_FILE_ERR = "$ Client file can't be open!";

//general menu messages------------------------------------
const char* const WELCOME_MESSAGE = "$ Welcome to your bank!";
const char* const HELP_MESSAGE = "$ You can use the command help to see what actions you can do!";
const char* const INVALID_COMMAND_MESSAGE = "$ Invalid command!";
const char* const LOGOUT_MESSAGE = "$ Logging out...";
const char* const SYSTEM_EXIT_MESSAGE = "$ Goodbye!";

//start menu messages--------------------------------------
const char* const LOGIN_SUCCESS_MESSAGE = "$ Successfully logged in!";
const char* const WRONG_ADMIN_USER = "$ Wrong admin username!";
const char* const PIN_WRONG_ERR = "$ Wrong PIN!";
const char* const PASS_WRONG_ERR = "$ Wrong password!";

//admin menu messages--------------------------------------
const char* const NEW_EMP_SUCCESS = "$ Successfully added new employee!";
const char* const REMOVE_EMP_SUCCESS = "$ Successfully removed employee!";

//employee menu messages-----------------------------------
const char* const NEW_CL_SUCCESS = "$ Successfully added new client!";
const char* const REMOVE_CL_SUCCESS = "$ Successfully removed client!";
const char* const NEW_ACCOUNT_SUCCESS = "$ Successfully added new account!";
const char* const REMOVE_ACCOUNT_SUCCESS = "$ Successfully removed account!";
const char* const NEW_CARD_SUCCESS = "$ Successfully added new card!";
const char* const REMOVE_CARD_SUCCESS = "$ Successfully removed card!";

//client menu messages-------------------------------------
const char* const DEPOSIT_SUCCESS = "$ Successful deposit!";
const char* const WITHDRAW_SUCCESS = "$ Successful withdraw!";

//collection template methods exceptions--------------------
const char* const NO_SUCH_ELEMENT_ERR = "$ There is no element with this key!";


#endif
