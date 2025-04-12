##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=KursFinal
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/media/sf_Projects/CC++/KursFinal
ProjectPath            :=/media/sf_Projects/CC++/KursFinal/KursFinal
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=04/12/25
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="KursFinal.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/network.cpp$(ObjectSuffix) $(IntermediateDirectory)/io.cpp$(ObjectSuffix) $(IntermediateDirectory)/exceptions.cpp$(ObjectSuffix) $(IntermediateDirectory)/filer.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ui.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/network.cpp$(ObjectSuffix): network.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/network.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/network.cpp$(DependSuffix) -MM network.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/sf_Projects/CC++/KursFinal/KursFinal/network.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/network.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/network.cpp$(PreprocessSuffix): network.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/network.cpp$(PreprocessSuffix) network.cpp

$(IntermediateDirectory)/io.cpp$(ObjectSuffix): io.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io.cpp$(DependSuffix) -MM io.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/sf_Projects/CC++/KursFinal/KursFinal/io.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io.cpp$(PreprocessSuffix): io.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io.cpp$(PreprocessSuffix) io.cpp

$(IntermediateDirectory)/exceptions.cpp$(ObjectSuffix): exceptions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/exceptions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/exceptions.cpp$(DependSuffix) -MM exceptions.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/sf_Projects/CC++/KursFinal/KursFinal/exceptions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/exceptions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/exceptions.cpp$(PreprocessSuffix): exceptions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/exceptions.cpp$(PreprocessSuffix) exceptions.cpp

$(IntermediateDirectory)/filer.cpp$(ObjectSuffix): filer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/filer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/filer.cpp$(DependSuffix) -MM filer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/sf_Projects/CC++/KursFinal/KursFinal/filer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/filer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/filer.cpp$(PreprocessSuffix): filer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/filer.cpp$(PreprocessSuffix) filer.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/sf_Projects/CC++/KursFinal/KursFinal/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/ui.cpp$(ObjectSuffix): ui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ui.cpp$(DependSuffix) -MM ui.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/sf_Projects/CC++/KursFinal/KursFinal/ui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ui.cpp$(PreprocessSuffix): ui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ui.cpp$(PreprocessSuffix) ui.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


