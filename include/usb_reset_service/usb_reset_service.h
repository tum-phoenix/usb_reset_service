#ifndef USB_RESET_SERVICE_H
#define USB_RESET_SERVICE_H

#include <lms/service.h>

namespace usb_reset_service {

/**
 * @brief LMS service usb_reset_service
 **/
class UsbResetService : public lms::Service {
public:
    bool init() override;
    void destroy() override;
};

} // namespace usb_reset_service

#endif // USB_RESET_SERVICE_H
