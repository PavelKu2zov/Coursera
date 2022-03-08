#include "phone_number.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number)
{
    stringstream inSStream;
    if (international_number.size()!=0)
    {
        inSStream << international_number;

        char sym;
        inSStream >> sym;
        string country_code,city_code,local_number;
        if (sym == '+') {
            if (!inSStream.eof()) {
                getline(inSStream, country_code, '-');
                if (country_code.size() == 0)
                    throw std::invalid_argument("Invalid country code");
            } else
                throw std::invalid_argument("Invalid country code");

            if (!inSStream.eof())
            {
                getline(inSStream, city_code, '-');
                if (city_code.size() == 0)
                    throw std::invalid_argument("Invalid city code");
            }
            else
                throw std::invalid_argument("Invalid city code");

            if (!inSStream.eof())
            {
                getline(inSStream, local_number);
                if (local_number.size() == 0)
                    throw std::invalid_argument("Invalid local number");
                country_code_ = country_code;
                city_code_ = city_code;
                local_number_ = local_number;
            }
            else
                throw std::invalid_argument("Invalid local number");
        }
        else
        {
            throw std::invalid_argument("Invalid sym +");
        }
    }
    else
    {
        throw std::invalid_argument("Invalid phone number");
    }
}

string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}

string  PhoneNumber::GetInternationalNumber() const
{
    if((country_code_.size()!=0) && (city_code_.size()!=0) && (local_number_.size()!=0))
        return "+"+GetCountryCode()+"-"+GetCityCode()+"-"+GetLocalNumber();
    else
        return "";
}