#include "GetResourceAssignmentStopResumeDates.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Project.h>
#include <Key.h>
#include <enums/AsnKey.h>
#include <Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(3990632245u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GetResourceAssignmentStopResumeDates, ThisTypeBaseTypesInfo);

void GetResourceAssignmentStopResumeDates::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceAssignmentStopResumeDates
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceAssignmentStopResumeDates.mpp");
    
    // Print resource assignment's stop and resume dates
    
    {
        auto ra_enumerator = (project1->get_ResourceAssignments())->GetEnumerator();
        decltype(ra_enumerator->get_Current()) ra;
        while (ra_enumerator->MoveNext() && (ra = ra_enumerator->get_Current(), true))
        {
            if (ra->Get<System::DateTime>(Asn::Stop()).ToShortDateString() == u"1/1/2000")
            {
                System::Console::WriteLine(u"NA");
            }
            else
            {
                System::Console::WriteLine(ra->Get<System::DateTime>(Asn::Stop()).ToShortDateString());
            }
            
            if (ra->Get<System::DateTime>(Asn::Resume()).ToShortDateString() == u"1/1/2000")
            {
                System::Console::WriteLine(u"NA");
            }
            else
            {
                System::Console::WriteLine(ra->Get<System::DateTime>(Asn::Resume()).ToShortDateString());
            }
        }
    }
    // ExEnd:GetResourceAssignmentStopResumeDates
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose