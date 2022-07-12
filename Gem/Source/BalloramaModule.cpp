
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "BalloramaSystemComponent.h"

namespace Ballorama
{
    class BalloramaModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(BalloramaModule, "{730002b6-9891-4078-809e-45bfd3cb77a4}", AZ::Module);
        AZ_CLASS_ALLOCATOR(BalloramaModule, AZ::SystemAllocator, 0);

        BalloramaModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                BalloramaSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<BalloramaSystemComponent>(),
            };
        }
    };
}// namespace Ballorama

AZ_DECLARE_MODULE_CLASS(Gem_Ballorama, Ballorama::BalloramaModule)
