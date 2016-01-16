set(SOURCES
    "src/usb_reset_service.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/usb_reset_service/usb_reset_service.h"
)

include_directories(include)
add_library(usb_reset_service SHARED ${SOURCES} ${HEADERS})
target_link_libraries(usb_reset_service PRIVATE lmscore)
