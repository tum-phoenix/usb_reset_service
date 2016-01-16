#include "usb_reset_service/usb_reset_service.h"

#include <cstdlib>
#include <iomanip>

namespace usb_reset_service {

bool UsbResetService::init() {
    return true;
}

void UsbResetService::destroy() {
}

bool UsbResetService::reset(uint16_t vendorId, uint16_t productId) {

    auto path = config().get<std::string>("path", "/usr/local/bin/usb-reset");
    if(path.empty()) {
        logger.error("path") << "Reset script path is not set or empty";
        return false;
    }

    std::stringstream command;
    command << path << " "
            << std::hex << std::showbase << std::setw(4) << std::setfill('0')
            << vendorId << " " << productId;

    logger.debug("command") << command.str();

    auto ret = std::system(command.str().c_str());

    if( EXIT_SUCCESS == ret ) {
        return true;
    } else {
        logger.error("reset") << "Unable to reset device (Exit code " << ret << ")";
        return false;
    }
}
} // namespace usb_reset_service
