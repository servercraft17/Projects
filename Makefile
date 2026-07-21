compiler := g++

exec := project.exe
bin := ./bin

src_dir = ./src
obj_dir := ./obj

inc := inc

libinc :=\
	-I inc/lib\

flags :=\
#	-Wl,--stack,4194304 # increases stack size to 4mb


libs := \

src := $(wildcard $(src_dir)/*.cpp) $(src_dir)/os/Windows/osfunc.cpp
obj := $(src:.cpp=.o)
obj := $(addprefix $(obj_dir)/,$(notdir $(obj)))

$(bin)/$(exec): $(obj)
	$(compiler) $(flags) $(libs) $(obj) -o $@
	

$(obj_dir)/%.o: $(src_dir)/%.cpp
	$(compiler) -I $(inc) $(libinc) $(flags) -c $< -o $@

$(obj_dir)/osfunc.o: $(src_dir)/os/Windows/osfunc.cpp
	$(compiler) -I $(inc) $(libinc) $(flags) -c $< -o $@

.PHONY: clean
clean:
	del /q $(subst /,\,$(bin))\$(exec) $(subst /,\,$(obj))

.PHONY: run
run: $(bin)/$(exec)
	$(bin)\$(exec)