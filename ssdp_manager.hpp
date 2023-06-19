#pragma once

#include "xyz/openbmc_project/SSDP/SSDPManager/server.hpp"
#include <sdbusplus/bus.hpp>
#include <sdbusplus/server/object.hpp>
#include <sdeventplus/source/event.hpp>

namespace ssdp {
namespace manager {

class SSDPMgr;
using iface = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::SSDP::server::SSDPManager>;

/** @class Manager
 *  @brief Implementation for the ssdp manager
 */
class SSDPMgr : public iface {
public:
  SSDPMgr() = delete;
  SSDPMgr(const SSDPMgr &) = delete;
  SSDPMgr &operator=(const SSDPMgr &) = delete;
  SSDPMgr(SSDPMgr &&) = delete;
  SSDPMgr &operator=(SSDPMgr &&) = delete;
  virtual ~SSDPMgr() = default;

  /** @brief Constructor to put object onto bus at a dbus path.
   *  @param[in] bus - Bus to attach to.
   *  @param[in] path - Path to attach at.
   */
  SSDPMgr(sdbusplus::bus_t& bus, sdeventplus::Event &event,
             const char *path)
      : iface(bus, path), bus(bus), event(event), objectPath(path){};

private:
  /** @brief sdbusplus DBus bus connection. */
  sdbusplus::bus_t& bus;
  // sdevent Event handle
  sdeventplus::Event &event;
  /** @brief object path */
  std::string objectPath;
};

} // namespace manager
} // namespace ssdp
