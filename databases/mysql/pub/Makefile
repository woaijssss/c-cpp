
BUILD_DIR:=build
SRC:=$(wildcard ./*.cpp)
TARGET:=libmysqlconnector.so
LVERSION:=1
SVERSION:=0
BIN:=$(TARGET).$(LVERSION).$(SVERSION)
OBJ:=$(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

CPPFLAGS:=-I. -I/usr/include/mysql
LDFLAGS:=-L/usr/lib64/mysql
LDLIBS:= -lmysqlclient

.PHONY: all release clean

all: ./$(BIN)
	@:
	
$(BIN): $(OBJ)
	@echo "(LD) $@"
	@$(CXX) $(LDFLAGS) $^ $(LDLIBS)  -shared -o $@
	@ln -sf $(BIN) $(TARGET).$(LVERSION)
	@ln -sf $(TARGET).$(LVERSION) $(TARGET)
	@rm -rf $(BUILD_DIR)
	
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "(CXX) $@"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -fPIC -c -o $@
	
clean:
	@rm -rf $(BUILD_DIR) ./$(TARGET)*

-include $(OBJ:.o=.d)