/**
 * @file iapplication.hpp
 * @author Patrik Baso (492811@mail.muni.cz)
 * @brief Basic Application Interface
 * @version 0.1
 * @date 2021-05-01
 */

#include <cstdint>

class IApplication {
    uint32_t x;

public:

    IApplication(uint32_t id);
};
