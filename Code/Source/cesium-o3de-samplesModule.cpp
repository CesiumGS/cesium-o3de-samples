
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "AdjustSkyOrientationComponent.h"
#include "cesium-o3de-samplesSystemComponent.h"

namespace cesium_o3de_samples
{
    class cesium_o3de_samplesModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(cesium_o3de_samplesModule, "{51dc7162-5e33-41e8-b4cf-7d4c0883d7ad}", AZ::Module);
        AZ_CLASS_ALLOCATOR(cesium_o3de_samplesModule, AZ::SystemAllocator, 0);

        cesium_o3de_samplesModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                cesium_o3de_samplesSystemComponent::CreateDescriptor(),
                cesium_o3de_samples::AdjustSkyOrientationComponent::CreateDescriptor()
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<cesium_o3de_samplesSystemComponent>(),
            };
        }
    };
}// namespace cesium_o3de_samples

AZ_DECLARE_MODULE_CLASS(Gem_cesium_o3de_samples, cesium_o3de_samples::cesium_o3de_samplesModule)
