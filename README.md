# USB Reset Service

This service lets modules reset a hanging USB device by its Vendor and Product ID

## Config

```xml
<framework>
    <service>
        <name>USB_RESET</name>
        <realName>usb_reset_service</realName>
        <config>
            <path>/usr/bin/usb-reset</path>
        </config>
    </service>
</framework>
```

## Dependencies

- libusb-1.0

## Usage

```cpp
#include <usb_reset_service/usb_reset_service.h>
// ...
{
    auto service = getService<usb_reset_service::UsbResetService>("USB_RESET");
    if(service.isValid())
    {
        uint16_t vendorId = 0xDEAD;
        uint16_t productId = 0xBEEF;
        service->reset(vendorId, productId);
    }
}
```