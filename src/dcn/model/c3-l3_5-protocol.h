// DCN - C3 Protocol class
// Fuji Z, Winter 2016
#ifndef C3_L3_5_PROTOCOL_H
#define C3_L3_5_PROTOCOL_H

#include <stdint.h>

#include "ns3/ptr.h"
#include "ns3/packet.h"
#include "ns3/ipv4-l3-protocol.h"

#include "ip-l3_5-protocol.h"

namespace ns3 {

class Node;

/**
 * \ingroup dcn
 *
 * \brief c3 protocol class.
 *
 * This class implement the c3 protocol which provides
 * multi-tenant multi-objective bandwidth allocation.
 */
class C3L3_5Protocol : public IpL3_5Protocol
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  static const uint8_t PROT_NUMBER; //!< protocol number (0xfd=253)

  C3L3_5Protocol ();
  virtual ~C3L3_5Protocol ();

  /**
   * \brief This function is called by higher layer protocol when sending packets
   */
  virtual void Send (Ptr<Packet> packet, Ipv4Address source,
                     Ipv4Address destination, uint8_t protocol, Ptr<Ipv4Route> route);

  /**
   * \brief This function is called by higher layer protocol when sending packets
   */
  virtual void Send6 (Ptr<Packet> packet, Ipv6Address source,
                     Ipv6Address destination, uint8_t protocol, Ptr<Ipv6Route> route);

  // inherited from Ipv4L4Protocol
  virtual int GetProtocolNumber (void) const;
  virtual enum IpL4Protocol::RxStatus Receive (Ptr<Packet> p,
                                               Ipv4Header const &header,
                                               Ptr<Ipv4Interface> incomingInterface);
  virtual enum IpL4Protocol::RxStatus Receive (Ptr<Packet> p,
                                               Ipv6Header const &header,
                                               Ptr<Ipv6Interface> incomingInterface);
};

}

#endif // C3_L3_5_PROTOCOL_H
