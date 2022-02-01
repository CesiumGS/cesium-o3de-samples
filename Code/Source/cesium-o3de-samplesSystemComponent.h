
#pragma once

#include <AzCore/Component/Component.h>

#include <cesium-o3de-samples/cesium-o3de-samplesBus.h>

namespace cesium_o3de_samples
{
    class cesium_o3de_samplesSystemComponent
        : public AZ::Component
        , protected cesium_o3de_samplesRequestBus::Handler
    {
    public:
        AZ_COMPONENT(cesium_o3de_samplesSystemComponent, "{14637e5f-64d1-45b4-a196-ab33411bcef2}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        cesium_o3de_samplesSystemComponent();
        ~cesium_o3de_samplesSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // cesium_o3de_samplesRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
