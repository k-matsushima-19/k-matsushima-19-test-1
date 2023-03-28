# C++
CXX = g++
CXXFLAGS += -std=c++17
INCLUDES = ./include

# Linker
LINK = $(CXX)
LDFLAGS += -std=c++17


#
# Compile options
#
# Directory
SRCDIR = ./src
OBJDIR = ./obj
TARGETDIR = ./bin
TARGETNAME = a.out

#
# 以下たぶん変更の必要なし
#
TARGET = $(TARGETDIR)/$(TARGETNAME)
OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.cpp,%.o,$(notdir $(wildcard $(SRCDIR)/*.cpp))))

DEPS += $(addprefix $(OBJDIR)/, $(patsubst %.cpp,%.d,$(notdir $(wildcard $(SRCDIR)/*.cpp))))

.PHONY: all clean
all: $(TARGET)

$(SUBDIRS):
	@$(MAKE) -C $@

$(TARGET): $(OBJS)
	@-mkdir -p $(TARGETDIR)
	$(LINK) $(OBJS) $(LDFLAGS) -o $@


# C++
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(addprefix -I,$(INCLUDES)) $(CXXFLAGS) -o $@ -c $<

# SUBDIRSを再帰的にclean
clean: c
	@for SUBDIR in $(SUBDIRS); do $(MAKE) clean -C $$SUBDIR ; done

# このディレクトリだけclean
c:
	@-rm -rf $(TARGET) $(OBJDIR)
  
doxygen:
	@-doxygen > /dev/null

install:
	@mkdir -p $(DEST)
	@cp $(TARGET) $(DEST)

-include $(DEPS)

# dependency fileのrule
$(OBJDIR)/%.d: $(SRCDIR)/%.cpp
	@-mkdir -p $(OBJDIR)
	@g++ $(addprefix -I,$(INCLUDES)) -MM -MP -MT '$(OBJDIR)/$*.o' $< > $(OBJDIR)/$*.d
