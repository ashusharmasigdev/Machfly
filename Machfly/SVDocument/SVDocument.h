/**
 * @file SVDocument.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <Genric/Filestream.h>
#include <SVDocument/SVDocumentParser.h>

using namespace Machfly::Genric;

namespace Machfly::SVDocumentSpace
{
    
    class SVDocument : public SVDocumentParser
    {

        public:

            SVDocument(const std::string& _pFilepath);
    
    };

} // namespace Machfly
