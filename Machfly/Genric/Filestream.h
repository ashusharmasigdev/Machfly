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

#include <iostream>
#include <fstream>
#include <vector>

namespace Machfly::Genric
{

    enum class StreamingState
    {
        IN,     /* std::ios::in */
        OUT,    /* std::ios::out */
        BINARY  /* std::ios::binary */
    };
    
    class Filestream
    {

        public:

            Filestream(const std::string& _pFilepath);

            void OpenFile(const StreamingState& _pState);

            std::fstream& RetreiveStream();

            std::vector<std::string> GetDocumentLines();

            inline bool GetFileStatus() { return OpenStatus; }
            inline StreamingState GetStreamStatus() { return DefaultStreamState; }

        private:

            std::string FilePath;
            std::fstream File;
            bool OpenStatus = false;
            StreamingState DefaultStreamState = StreamingState::IN;
    
    };

} // namespace Machfly
