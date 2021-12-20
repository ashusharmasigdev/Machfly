#pragma once

#include <Core/Defs.h>
#include <Datafly/DataLoader.h>

namespace Machfly::Datafly
{
    
    class DataPlain : public DataLoader
    {

        private:
        
            /* data */
        
        public:
        
            DataPlain(/* args */);

            /// @param _pDegree         : Specified Degree of Polynomial for Feature Mapping, If it is 1 then, Data will unchanged
            /// @param _pTrainPercent   : To Train the Only Part of the Data : Will Convert % to Column Index and will Store only Index
            /// @param _pTestPercent    : To Test the Only Part of the Data : Will Convert % to Column Index and will Store only Index

            Void
            PlainSetting(Number _pDegree, Number _pTranPercent, Number _pTestPercent);
        
            ~DataPlain();
    
    };
    

} // namespace Machfly::Datafly
