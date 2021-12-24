#include <Genric/Filestream.h>

namespace Machfly::Genric
{
    
    Filestream::Filestream(const std::string& _pFilepath = std::string())
        : FilePath(_pFilepath)
    {}

    void Filestream::OpenFile(const StreamingState& _pState)
    {
        DefaultStreamState = _pState;

        if(File.is_open())
        {
            File.close();
        }

        switch (DefaultStreamState)
        {
            case StreamingState::IN:
                File.open(FilePath, std::ios::in);
                break;
            case StreamingState::OUT:
                File.open(FilePath, std::ios::out);
                break;
            case StreamingState::BINARY:
                File.open(FilePath, std::ios::binary);
                break;
            default:
                File.open(FilePath, std::ios::in);
                break;
        }
    }

} // namespace Machfly::Genric
