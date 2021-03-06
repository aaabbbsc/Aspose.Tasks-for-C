/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithOutlineCodes.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <OutlineValueCollection.h>
#include <OutlineValue.h>
#include <OutlineMaskCollection.h>
#include <OutlineMask.h>
#include <OutlineCodeDefinitionCollection.h>
#include <OutlineCodeDefinition.h>
#include <enums/OutlineValueType.h>
#include <enums/MaskType.h>
#include <enums/ExtendedAttributeTask.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(1983464473u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithOutlineCodes, ThisTypeBaseTypesInfo);

void WorkingWithOutlineCodes::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    //ReadOutlineCodes(dataDir);
    CheckOutlineCodeIdUniqueness(dataDir);
}

void WorkingWithOutlineCodes::ReadOutlineCodes(System::String dataDir)
{
    // ExStart:ReadOutlineCodes
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"OutlineCodes.mpp");
    
    
    {
        auto ocd_enumerator = (project->get_OutlineCodes())->GetEnumerator();
        decltype(ocd_enumerator->get_Current()) ocd;
        while (ocd_enumerator->MoveNext() && (ocd = ocd_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(u"Alias = ") + ocd->get_Alias());
            if (ocd->get_AllLevelsRequired())
            {
                System::Console::WriteLine(u"It contains property: must have all levels");
            }
            else
            {
                System::Console::WriteLine(u"It does not contain property: must have all levels");
            }
            if (ocd->get_Enterprise())
            {
                System::Console::WriteLine(u"It is an enterprise custom outline code.");
            }
            else
            {
                System::Console::WriteLine(u"It is not an enterprise custom outline code.");
            }
            
            System::Console::WriteLine(System::String(u"Reference to another custom field for which this outline code definition is an alias is = ") + ocd->get_EnterpriseOutlineCodeAlias());
            System::Console::WriteLine(System::String(u"Field Id = ") + ocd->get_FieldId());
            System::Console::WriteLine(System::String(u"Field Name = ") + ocd->get_FieldName());
            System::Console::WriteLine(System::String(u"Phonetic Alias = ") + ocd->get_PhoneticAlias());
            System::Console::WriteLine(System::String(u"Guid = ") + ocd->get_Guid());
            
            // Display outline code masks
            
            {
                auto outlineMask_enumerator = (ocd->get_Masks())->GetEnumerator();
                decltype(outlineMask_enumerator->get_Current()) outlineMask;
                while (outlineMask_enumerator->MoveNext() && (outlineMask = outlineMask_enumerator->get_Current(), true))
                {
                    System::Console::WriteLine(System::String(u"Level of a mask = ") + outlineMask->get_Level());
                    System::Console::WriteLine(System::String(u"Mask = ") + System::ObjectExt::ToString(outlineMask));
                }
            }
            
            // Display out line code values
            
            {
                auto outlineMask1_enumerator = (ocd->get_Values())->GetEnumerator();
                decltype(outlineMask1_enumerator->get_Current()) outlineMask1;
                while (outlineMask1_enumerator->MoveNext() && (outlineMask1 = outlineMask1_enumerator->get_Current(), true))
                {
                    System::Console::WriteLine(System::String(u"Description of outline value = ") + outlineMask1->get_Description());
                    System::Console::WriteLine(System::String(u"Value Id = ") + outlineMask1->get_ValueId());
                    System::Console::WriteLine(System::String(u"Value = ") + outlineMask1->get_Value());
                    System::Console::WriteLine(System::String(u"Type = ") + System::ObjectExt::ToString(outlineMask1->get_Type()));
                }
            }
        }
    }
    // ExEnd:ReadOutlineCodes
}

void WorkingWithOutlineCodes::CheckOutlineCodeIdUniqueness(System::String dataDir)
{
    // ExStart:CheckOutlineCodeIdUniqueness
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"OutlineValues2010.mpp");
    
    System::SharedPtr<OutlineCodeDefinition> textOutline = System::MakeObject<OutlineCodeDefinition>();
    textOutline->set_FieldId(System::Convert::ToString((int)Aspose::Tasks::ExtendedAttributeTask::OutlineCode7));
    textOutline->set_Alias(u"My Outline Code");
    
    project->get_OutlineCodes()->Add(textOutline);
    
    System::SharedPtr<OutlineMask> mask = System::MakeObject<OutlineMask>();
    mask->set_Type(Aspose::Tasks::MaskType::Characters);
    textOutline->get_Masks()->Add(mask);
    
    System::SharedPtr<OutlineValue> textValue = System::MakeObject<OutlineValue>();
    textValue->set_Value(u"Text value 1");
    textValue->set_ValueId(1);
    textValue->set_Type(Aspose::Tasks::OutlineValueType::Text);
    textValue->set_Description(u"Text value descr 1");
    textOutline->get_Values()->Add(textValue);
    
    project->Save(dataDir + u"MultipleOutlineValues.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
    // ExEnd:CheckOutlineCodeIdUniqueness
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
