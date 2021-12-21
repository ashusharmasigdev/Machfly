#pragma once

#include <Core/Defs.h>
#include <iostream>

using namespace std;

namespace Machfly::Extras::ErrorFunc
{
    
    Void
    ReleaseFatal(const DString _error_comment, Bool _exit_status = true)
    {
        cerr << _error_comment << endl;
        exit(_exit_status);
    }

    Void
    ReleaseLog(const DString _error_comment)
    {
        cout << _error_comment << endl;
    }

} // namespace Machfly::Extras::ErrorFunc
