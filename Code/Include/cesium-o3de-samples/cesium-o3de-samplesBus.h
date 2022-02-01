
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace cesium_o3de_samples
{
    class cesium_o3de_samplesRequests
    {
    public:
        AZ_RTTI(cesium_o3de_samplesRequests, "{748b472b-fd71-4578-980e-0a9cd9912862}");
        virtual ~cesium_o3de_samplesRequests() = default;
        // Put your public methods here
    };
    
    class cesium_o3de_samplesBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using cesium_o3de_samplesRequestBus = AZ::EBus<cesium_o3de_samplesRequests, cesium_o3de_samplesBusTraits>;
    using cesium_o3de_samplesInterface = AZ::Interface<cesium_o3de_samplesRequests>;

} // namespace cesium_o3de_samples
