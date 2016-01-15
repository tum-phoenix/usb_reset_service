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

    /**
     * @brief Reset USB device by VID/PID
     * @param vendorId The USB Vendor ID of the device
     * @param productId The USB Product ID of the device
     * @return True on success, false on failure
     */
    bool reset(uint16_t vendorId, uint16_t productId);
};

} // namespace usb_reset_service

#endif // USB_RESET_SERVICE_H
