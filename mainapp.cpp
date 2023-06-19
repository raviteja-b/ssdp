#include "ssdp_manager.hpp"

#include <sdeventplus/event.hpp>

int main()
{
    auto bus = sdbusplus::bus::new_default();
    std::string busName = "xyz.openbmc_project.SSDPManager";
    bus.request_name(busName.c_str());

    static constexpr auto objPath = "/xyz/openbmc_project/ssdp";

    // Get default event loop
    auto event = sdeventplus::Event::get_default();

    // Attach the bus to sd_event to service user requests
    bus.attach_event(event.get(), SD_EVENT_PRIORITY_NORMAL);

    // Add sdbusplus ObjectManager
    sdbusplus::server::manager::manager objManager(bus, objPath);

    ssdp::manager::SSDPMgr manager(bus, event, objPath);
    event.loop();
    return 0;
}
