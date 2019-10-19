#include "WorkingWithCalendars/RetrieveCalendarInfo.h"

#include <WeekDayCollection.h>
#include <WeekDay.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <enums/DayType.h>
#include <cstdint>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

RTTI_INFO_IMPL_HASH(3583771765u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::RetrieveCalendarInfo, ThisTypeBaseTypesInfo);

void RetrieveCalendarInfo::Run()
{
    // ExStart:RetrieveCalendarInfo
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"RetrieveCalendarInfo.mpp");
    
    // Retrieve Calendars Information
    System::SharedPtr<CalendarCollection> alCals = project->get_Calendars();
    
    {
        auto cal_enumerator = (alCals)->GetEnumerator();
        decltype(cal_enumerator->get_Current()) cal;
        while (cal_enumerator->MoveNext() && (cal = cal_enumerator->get_Current(), true))
        {
            if (cal->get_Name() != nullptr)
            {
                System::Console::WriteLine(System::String(u"Calendar UID : ") + cal->get_Uid());
                System::Console::WriteLine(System::String(u"Calendar Name : ") + cal->get_Name());
                
                System::SharedPtr<WeekDayCollection> alDays = cal->get_WeekDays();
                
                {
                    auto wd_enumerator = (alDays)->GetEnumerator();
                    decltype(wd_enumerator->get_Current()) wd;
                    while (wd_enumerator->MoveNext() && (wd = wd_enumerator->get_Current(), true))
                    {
                        System::TimeSpan ts = wd->GetWorkingTime();
                        if (wd->get_DayWorking())
                        {
                            System::Console::WriteLine(System::ObjectExt::ToString(wd->get_DayType()) + u":");
                            System::Console::WriteLine(System::ObjectExt::ToString(ts));
                        }
                    }
                }
            }
        }
    }
    // ExEnd:RetrieveCalendarInfo
}

} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
