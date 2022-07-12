
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Ballorama
{
    class BalloramaRequests
    {
    public:
        AZ_RTTI(BalloramaRequests, "{5f1ceeb1-3d3d-4b05-a63a-3770b234925b}");
        virtual ~BalloramaRequests() = default;
        // Put your public methods here
    };

    class BalloramaBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using BalloramaRequestBus = AZ::EBus<BalloramaRequests, BalloramaBusTraits>;
    using BalloramaInterface = AZ::Interface<BalloramaRequests>;

} // namespace Ballorama
