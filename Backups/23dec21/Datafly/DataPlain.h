#pragma once

#include <Core/Defs.h>
#include <Datafly/DataLoader.h>

#include <armadillo>

namespace Machfly::Datafly
{
    
    class DataPlain : public DataLoader
    {

        private:
        
            arma::mat DataX;    /* X Matrix */
            arma::vec DataY;    /* Y Vector */

            Double* _DataX;
            Double* _DataY;
        
        public:

            Void
            ReadFileData();

            Void
            ReadCSVData();

            /// @param _pDegree         : Specified Degree of Polynomial for Feature Mapping, If it is 1 then, Data will unchanged
            /// @param _pTrainPercent   : To Train the Only Part of the Data : Will Convert % to Column Index and will Store only Index
            /// @param _pTestPercent    : To Test the Only Part of the Data : Will Convert % to Column Index and will Store only Index

            Void
            PlainSetting(Number _pDegree, Number _pTranPercent, Number _pTestPercent);

            Void
            ExtractFeatureX();

            Void
            ExtractFeatureY();
            /* Later Make Dynamic any XYZETC As ExtractFeatureSet("SETNO:49") */

            Void
            CalculateFeatures();

            Void
            MapBasicDataFeatures(); /* SigmaX, SigmaY, DataX^2, DataY^2 etc */

            Void
            Getter();

            Void
            Setter();

            Double
            GetCellFromFeatureX(Double _pX, Double _pY);

            Double
            GetCellFromFeatureY(Double _pI);
    
    };
    

} // namespace Machfly::Datafly
