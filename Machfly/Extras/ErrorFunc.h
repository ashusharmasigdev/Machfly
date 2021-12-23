#pragma once

#include <Core/Defs.h>
#include <iostream>

using namespace std;

namespace Machfly::Extras::ErrorFunc
{
    
    Void
    ReleaseFatal(const DString _error_comment, Bool _exit_status);

    Void
    ReleaseLog(const DString _error_comment);

} // namespace Machfly::Extras::ErrorFunc