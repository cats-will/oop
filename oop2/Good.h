#pragma  once

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <limits>
#include <cstddef>
#include <utility>
#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class Good {
private:
    boost::uuids::uuid UUID_;
    std::string name_;
public:
//    Good() = default;

    Good(std::string name) : UUID_(boost::uuids::random_generator()()), name_(std::move(name)) {}

    boost::uuids::uuid Get_UUID() const {
        return UUID_;
    }

    std::string Get_Name() const {
        return name_;
    }

    friend std::ostream& operator<<(std::ostream& out, Good &good) {
        return out << "UUID:" << good.UUID_ << ", " << "name:" << good.name_ << '\n';
    }
};