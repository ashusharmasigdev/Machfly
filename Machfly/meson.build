add_languages('cpp')

MachflyDirectory = '/home/nebula/Projects/_/Machfly'


MachflyVersion = '0.2'
MachflyBuilID = '20210420'


CPPArguments = [
  '-DBUILD_ID=20210420', '-DMACHFLY_VERSION=0.2'
]


LDArguments = [

]


IncludeLists = [
  include_directories('/')
]


CPPSources = [
  'Machfly.cpp',
  'Genric/Filestream.cpp',
  'SVDocument/SVDocumentParser.cpp',
  'SVDocument/SVDocument.cpp',
  'Datagrid/Gridcell.cpp'
]

LDArguments += CPPArguments

Compile = executable(MachflyDirectory + '/Binary/'+'Machfly.app',
                [CPPSources],
                include_directories: [IncludeLists],
                cpp_args: CPPArguments, link_args: LDArguments)