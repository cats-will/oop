cmake_minimum_required(VERSION 3.17)
project(oop5)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop5 main.cpp IAccount.h DebitAccount.h CreditAccount.h Deposit.h MyException.h Client.h Bank.h Chain.h CreditAccount.cpp Bank.cpp Client.cpp Deposit.cpp DebitAccount.cpp Translations.cpp Translations.h)